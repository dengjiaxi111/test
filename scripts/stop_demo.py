#!/usr/bin/env python3
"""清理本隔离测试的旧进程；精确匹配路径与分区，不使用pkill/killall。"""
from pathlib import Path
import argparse, json, os, signal, time
from runtime_support import process_identity

T=Path(__file__).resolve().parents[1]
parser=argparse.ArgumentParser();parser.add_argument('--check',action='store_true')
parser.add_argument('--exclude-pid',type=int,default=0,help='调用方键盘进程自行退出，不对它发信号')
args=parser.parse_args()
scripts={str(T/'scripts/run_case.py'),*(str(T/'sim'/name) for name in ('sim_bridge.py','original_fake_bridge.py','navigation_to_chassis.py','plan_markers.py','keyboard_console.py'))}
managers=set()
def roots():
 found={}
 for entry in Path('/proc').iterdir():
  if not entry.name.isdigit() or int(entry.name) in (os.getpid(),args.exclude_pid):continue
  try:
   argv=[v.decode(errors='replace') for v in (entry/'cmdline').read_bytes().split(b'\0') if v]
   if not argv:continue
   # 只读取两个用于确认测试归属的环境键，不输出环境内容。
   env=(entry/'environ').read_bytes().split(b'\0')
   # 管理器在启动后才setenv，/proc/environ不保证反映更新；其绝对脚本路径可独立确认归属。
   is_manager=str(T/'scripts/run_case.py') in argv
   if not is_manager and (b'GZ_PARTITION=slopehole_test' not in env or b'ROS_DOMAIN_ID=187' not in env):continue
   command=' '.join(argv)
   matched=(any(a in scripts for a in argv) or argv[0]==str(T/'install/nav_components/lib/nav_components/nav_server')
    or (argv[0]=='/opt/ros/jazzy/lib/ros_gz_bridge/parameter_bridge' and str(T/'sim/bridge.yaml') in command)
    or argv[0]==str(T.parent/'navigatiosim2/install/seu_sentry_sim_control/lib/seu_sentry_sim_control/swerve_sim_controller_node')
    or (argv[0]=='/opt/ros/jazzy/lib/rviz2/rviz2' and str(T/'sim')+'/' in command)
    or (argv[0].startswith('gz sim') and (' -g' in command or str(T/'sim')+'/' in command)))
   identity=process_identity(int(entry.name))
   if matched and identity and identity[1]!='Z':
    found[int(entry.name)]=identity[0]
    if is_manager:managers.add(int(entry.name))
  except (OSError,ValueError):pass
 return found

owned=roots();initial=sorted(owned)
if not args.check:
 def refresh():
  owned.update(roots());pending=list(owned);seen=set()
  while pending:
   pid=pending.pop()
   if pid in seen:continue
   seen.add(pid);identity=process_identity(pid)
   if not identity or identity[0]!=owned[pid]:continue
   try:
    for child in map(int,Path(f'/proc/{pid}/task/{pid}/children').read_text().split()):
     value=process_identity(child)
     if value:owned[child]=value[0];pending.append(child)
   except OSError:pass
  return [pid for pid,start in owned.items() if (value:=process_identity(pid)) and value[0]==start and value[1]!='Z']
 # 管理器在时先让它独立收尾，避免工具和管理器对节点重复SIGINT，打断节点析构。
 if managers:
  refresh()
  for pid in managers:
   value=process_identity(pid)
   if value and value[0]==owned[pid]:
    try:os.kill(pid,signal.SIGINT)
    except ProcessLookupError:pass
  end=time.monotonic()+5.5
  while refresh() and time.monotonic()<end:time.sleep(.05)
 stages=((signal.SIGTERM,1.),(signal.SIGKILL,1.)) if managers else ((signal.SIGINT,2.),(signal.SIGTERM,2.),(signal.SIGKILL,1.))
 for sig,seconds in stages:
  end=time.monotonic()+seconds;sent=set()
  while live:=refresh():
   for pid in set(live)-sent:
    try:os.kill(pid,sig)
    except ProcessLookupError:pass
    sent.add(pid)
   if time.monotonic()>=end:break
   time.sleep(.05)
 remaining=refresh()
else:remaining=initial
report={'mode':'check' if args.check else 'cleanup','matched_test_roots':initial,'remaining_pids':remaining}
print(json.dumps(report,ensure_ascii=False))
if not args.check:(T/'results/last_stop_demo.json').write_text(json.dumps(report,indent=2))
raise SystemExit(1 if remaining else 0)
