"""观察真实文件增量，不丢分段行，支持键盘面板/连续输出两种视图。"""
from pathlib import Path
import sys,tempfile
sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'scripts'))
from runtime_support import RuntimeLogs
with tempfile.TemporaryDirectory() as d:
 p=Path(d)/'nav.log';p.write_bytes(b'nav started\npar')
 view=RuntimeLogs(echo=lambda:False);view.watch('nav_server',p);view.poll()
 assert list(view.lines)==['[nav_server] nav started']
 with p.open('ab') as f:f.write(b'tial\n')
 view.poll();assert view.lines[-1]=='[nav_server] partial'
 count=len(view.lines);view.poll();assert len(view.lines)==count
 p.write_text('reset\n');view.poll();assert view.lines[-1]=='[nav_server] reset'
print('PASS: incremental log relay and retained dashboard lines')
