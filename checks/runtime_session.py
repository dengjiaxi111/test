"""一次有界无渲染验收：真实终端启动、日志、键盘、连续Ctrl+C及整组退出。"""
from pathlib import Path
import fcntl, json, os, pty, select, signal, struct, subprocess, sys, termios, time

T=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(T/'scripts'))
from runtime_support import process_identity

master,slave=pty.openpty()
fcntl.ioctl(slave,termios.TIOCSWINSZ,struct.pack('HHHH',40,180,0,0))
def controlling_terminal():fcntl.ioctl(0,termios.TIOCSCTTY,0)
p=subprocess.Popen([sys.executable,str(T/'scripts/run_case.py'),'--case','demo','--manual','--max-wall','45'],stdin=slave,stdout=slave,stderr=slave,start_new_session=True,preexec_fn=controlling_terminal)
os.close(slave);result={'result':'FAIL'};captured=bytearray();owned={}
def drain(seconds):
 end=time.monotonic()+seconds
 while time.monotonic()<end:
  if select.select([master],[],[],.05)[0]:
   try:captured.extend(os.read(master,65536))
   except OSError:break
def children(pid):
 pending=[pid];seen=set()
 while pending:
  parent=pending.pop()
  if parent in seen:continue
  seen.add(parent)
  try:pending.extend(map(int,Path(f'/proc/{parent}/task/{parent}/children').read_text().split()))
  except OSError:pass
 return seen-{pid}
try:
 deadline=time.monotonic()+32
 while b'READY:' not in captured and time.monotonic()<deadline and p.poll() is None:drain(.2)
 assert b'READY:' in captured,captured.decode(errors='replace')[-2000:]
 os.write(master,b'v');drain(.5)
 # 平地短目标只验证日志链，不将它冒充上下坡验收。
 os.environ['ROS_DOMAIN_ID']='187'
 import rclpy
 from geometry_msgs.msg import PoseStamped
 rclpy.init();node=rclpy.create_node('runtime_session_check')
 pub=node.create_publisher(PoseStamped,'goal_pose',10)
 end=time.monotonic()+1.5
 while time.monotonic()<end:rclpy.spin_once(node,timeout_sec=.05)
 target=PoseStamped();target.header.frame_id='map';target.pose.position.x=-8.5;target.pose.position.y=3.;target.pose.orientation.w=1.
 pub.publish(target)
 deadline=time.monotonic()+6
 while b'[FSM]' not in captured and time.monotonic()<deadline:drain(.2)
 assert b'[nav_server]' in captured,'没有导航日志'
 assert b'[FSM]' in captured and b'NORMAL' in captured,'没有可读状态机输出'
 assert '连续日志视图'.encode() in captured,'V未切换日志视图'
 node.destroy_node();rclpy.try_shutdown()
 for pid in children(p.pid):
  identity=process_identity(pid)
  if identity:owned[pid]=identity[0]
 assert len(owned)>=8,owned
 os.write(master,b'\x03');drain(.1);os.write(master,b'\x03')
 deadline=time.monotonic()+10
 while p.poll() is None and time.monotonic()<deadline:drain(.1)
 assert p.poll() is not None,'Ctrl+C后管理器未退出'
 drain(.2)
 remaining=[pid for pid,start in owned.items() if (identity:=process_identity(pid)) and identity[0]==start]
 assert not remaining,remaining
 report=json.loads((T/'results/demo.json').read_text())
 assert report['cleanup_remaining_pids']==[],report
 assert '本次仿真进程清理完成'.encode() in captured
 result.update(result='PASS',navigation_logs=True,readable_fsm=True,log_view_toggle=True,repeated_ctrl_c=True,owned_process_count=len(owned),remaining_pids=[])
except Exception as exc:result['error']=str(exc)
finally:
 if p.poll() is None:
  os.kill(p.pid,signal.SIGTERM)
  try:p.wait(timeout=9)
  except subprocess.TimeoutExpired:p.kill();p.wait()
 for pid in children(p.pid)|set(owned):
  identity=process_identity(pid)
  if identity and (pid not in owned or identity[0]==owned[pid]):
   try:os.kill(pid,signal.SIGKILL)
   except ProcessLookupError:pass
 os.close(master)
 (T/'logs/runtime_session.log').write_bytes(captured)
 (T/'results/runtime_session.json').write_text(json.dumps(result,indent=2));print(result,flush=True)
raise SystemExit(0 if result['result']=='PASS' else 1)
