"""真实终端一次到达多个按键时，实际tick必须全部处理，无须再按键唤醒。"""
import io
from contextlib import redirect_stdout
import os
from pathlib import Path
import pty
import sys
import time
from types import SimpleNamespace
import tty

from geometry_msgs.msg import Twist

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'sim'))
from keyboard_console import KeyboardConsole


def replay(keys, draw_logs=False):
    master, slave = pty.openpty()
    tty.setcbreak(slave)
    stream = io.TextIOWrapper(io.BufferedReader(io.FileIO(slave, 'r', closefd=False)))
    original = sys.stdin
    changes = []
    pub = SimpleNamespace(publish=lambda message: None)
    console = SimpleNamespace(
        fd=slave, node=SimpleNamespace(), mode='navigation', command=Twist(),
        yaw=0., yaw_key=-1., control=pub, stop=pub, selected=1,
        values={'flat_speed': 1., 'boost_speed': 2.}, message='', manual_speed=1.,
        apply=lambda name, value: changes.append((name, value)),
        cmd=pub, gimbal=pub, last_query=time.monotonic(), last_draw=time.monotonic(),
        get=SimpleNamespace(service_is_ready=lambda: False), logs_only=False,
    )
    console.key = lambda key: KeyboardConsole.key(console, key)
    try:
        sys.stdin = stream
        if draw_logs:console.last_draw=0.
        os.write(master, keys)
        for _ in range(2):
            KeyboardConsole.tick(console)
        return console, changes
    finally:
        sys.stdin = original
        stream.close()
        os.close(master)
        os.close(slave)


console, changes = replay(b'1+')
assert changes == [('flat_speed', 1.1)], f'调速按键滞留，未发出请求：{changes}'
console, _ = replay(b'k]w')
assert console.mode == 'keyboard'
assert console.manual_speed == 1.1 and console.command.linear.x == -1.1, '手动调速/方向按键滞留'
output=io.StringIO()
with redirect_stdout(output):
    console, changes = replay(b'v1+', draw_logs=True)
assert console.logs_only and changes == [('flat_speed', 1.1)], 'V日志模式阻断调速请求'
assert '[调参]' in output.getvalue() and '普通速度' in output.getvalue(), 'V日志模式隐藏了调参反馈'
print('PASS: 连续选择/调速、手动模式/调速/行驶按键均由实际tick完整处理')
