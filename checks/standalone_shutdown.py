"""复现只退出独立键盘的用法，确认现在会关闭后台整套test。"""
from pathlib import Path
import fcntl,json,os,pty,select,signal,subprocess,sys,termios,time
T=Path(__file__).resolve().parents[1]
os.environ['ROS_DOMAIN_ID']='187'
out=(T/'logs/standalone_manager.log').open('wb')
manager=subprocess.Popen([sys.executable,str(T/'scripts/run_case.py'),'--case','demo','--manual','--max-wall','40'],stdin=subprocess.DEVNULL,stdout=out,stderr=subprocess.STDOUT,start_new_session=True)
keyboard=None;master=None;captured=bytearray();result={'result':'FAIL'}
try:
 end=time.monotonic()+30
 while time.monotonic()<end:
  if b'READY:' in (T/'logs/standalone_manager.log').read_bytes():break
  assert manager.poll() is None,'后台启动失败'
  time.sleep(.1)
 else:raise AssertionError('后台启动超时')
 master,slave=pty.openpty()
 def controlling_terminal():fcntl.ioctl(0,termios.TIOCSCTTY,0)
 keyboard=subprocess.Popen([sys.executable,str(T/'sim/keyboard_console.py')],stdin=slave,stdout=slave,stderr=slave,start_new_session=True,preexec_fn=controlling_terminal)
 os.close(slave)
 def drain(seconds):
  end=time.monotonic()+seconds
  while time.monotonic()<end:
   if select.select([master],[],[],.05)[0]:
    try:captured.extend(os.read(master,65536))
    except OSError:break
 end=time.monotonic()+5
 while '仿真键盘'.encode() not in captured and time.monotonic()<end:drain(.1)
 assert '仿真键盘'.encode() in captured,'独立键盘未就绪'
 os.write(master,b'\x03');drain(.1);os.write(master,b'\x03')
 end=time.monotonic()+10
 while keyboard.poll() is None and time.monotonic()<end:drain(.1)
 assert keyboard.poll()==0,captured.decode(errors='replace')[-1800:]
 manager.wait(timeout=5);drain(.2)
 assert manager.returncode==0,manager.returncode
 report=json.loads((T/'results/last_stop_demo.json').read_text())
 assert len(report['matched_test_roots'])>=8 and not report['remaining_pids'],report
 assert json.loads((T/'results/demo.json').read_text())['cleanup_remaining_pids']==[]
 result.update(result='PASS',standalone_keyboard_stops_whole_test=True,repeated_ctrl_c=True,matched_process_count=len(report['matched_test_roots']),remaining_pids=[])
except Exception as e:result['error']=str(e)
finally:
 for p in (keyboard,manager):
  if p and p.poll() is None:
   p.send_signal(signal.SIGTERM)
   try:p.wait(timeout=9)
   except subprocess.TimeoutExpired:p.kill();p.wait()
 if master is not None:os.close(master)
 out.close();(T/'logs/standalone_keyboard.log').write_bytes(captured)
 (T/'results/standalone_shutdown.json').write_text(json.dumps(result,indent=2));print(result,flush=True)
raise SystemExit(0 if result['result']=='PASS' else 1)
