"""真实进程回归：启动器已退出、后代setsid且忽略信号、重复Ctrl+C。"""
from pathlib import Path
import json, os, signal, subprocess, sys, tempfile, time

T=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(T/'scripts'))
from runtime_support import process_identity

fixture='''
import os,signal,subprocess,sys,time
from pathlib import Path
sys.path.insert(0,sys.argv[1])
from runtime_support import ProcessSupervisor
supervisor=ProcessSupervisor()
child_code="import os,signal,time;os.setsid();signal.signal(signal.SIGINT,signal.SIG_IGN);signal.signal(signal.SIGTERM,signal.SIG_IGN);time.sleep(60)"
launcher="import subprocess,sys;from pathlib import Path;p=subprocess.Popen([sys.executable,'-c',sys.argv[2]]);Path(sys.argv[1]).write_text(str(p.pid))"
p=subprocess.Popen([sys.executable,'-c',launcher,sys.argv[2],child_code],start_new_session=True)
supervisor.track(p)
while not Path(sys.argv[2]).exists():time.sleep(.02)
p.wait()
time.sleep(.1)
Path(sys.argv[3]).write_text('ready')
remaining=supervisor.cleanup()
assert not remaining,remaining
print('PASS: adopted detached grandchild cleaned',flush=True)
'''
result={'result':'FAIL'}
outsider=subprocess.Popen([sys.executable,'-c','import time;time.sleep(60)'],start_new_session=True)
p=None;orphan=None
try:
 with tempfile.TemporaryDirectory() as d:
  pidfile=Path(d)/'child';ready=Path(d)/'ready'
  p=subprocess.Popen([sys.executable,'-c',fixture,str(T/'scripts'),str(pidfile),str(ready)],stdout=subprocess.PIPE,stderr=subprocess.STDOUT,start_new_session=True,text=True)
  deadline=time.monotonic()+5
  while not ready.exists() and time.monotonic()<deadline:time.sleep(.02)
  assert ready.exists(),'fixture not ready'
  orphan=int(pidfile.read_text());assert process_identity(orphan)
  os.kill(p.pid,signal.SIGINT);time.sleep(.1);os.kill(p.pid,signal.SIGINT)
  output=p.communicate(timeout=8)[0];assert p.returncode==0,output
  assert process_identity(orphan) is None,'detached descendant survived'
  assert outsider.poll() is None,'unrelated process was killed'
  result.update(result='PASS',orphan_reaped=True,repeated_ctrl_c=True,unrelated_process_untouched=True,output=output.strip())
finally:
 for process in (p,outsider):
  if process and process.poll() is None:process.kill()
  if process:process.wait()
 if orphan and process_identity(orphan):os.kill(orphan,signal.SIGKILL)
 (T/'results/runtime_cleanup.json').write_text(json.dumps(result,indent=2))
print(result)
