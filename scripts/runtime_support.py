"""隔离仿真的日志观察与进程收尾；不介入导航或运动计算。"""
from collections import deque
import ctypes
import os
from pathlib import Path
import signal
import time


class RuntimeLogs:
    def __init__(self, echo=lambda: True):
        self.lines = deque(maxlen=10)
        self.files = {}
        self.echo = echo

    def watch(self, name, path):
        self.files[name] = [Path(path), 0, b'']

    def record(self, source, message):
        line = f'[{source}] {message}'.replace('\x00', '').replace('\x1b', '')
        self.lines.append(line)
        if self.echo():
            print(line, flush=True)

    def poll(self):
        for name, item in self.files.items():
            path, offset, pending = item
            try:
                if path.stat().st_size < offset:
                    offset, pending = 0, b''
                with path.open('rb') as stream:
                    stream.seek(offset)
                    data = stream.read(32768)
                    item[1] = stream.tell()
            except OSError:
                continue
            chunks = (pending + data).split(b'\n')
            item[2] = chunks.pop()[-8192:]
            for chunk in chunks:
                if chunk.strip():
                    self.record(name, chunk.decode(errors='replace'))


def process_identity(pid):
    """含启动时刻的身份，避免对已经复用的PID发送信号。"""
    try:
        fields = Path(f'/proc/{pid}/stat').read_text().rsplit(') ', 1)[1].split()
        return (int(fields[19]), fields[0], int(fields[2]))
    except (OSError, IndexError, ValueError):
        return None


class ProcessSupervisor:
    def __init__(self):
        # 收养Gazebo/GUI启动器退出后留下的后代，包括另建session的进程。
        libc = ctypes.CDLL(None, use_errno=True)
        if libc.prctl(36, 1, 0, 0, 0) != 0:  # Linux PR_SET_CHILD_SUBREAPER
            raise OSError(ctypes.get_errno(), '不能启用子进程收养，拒绝无管理启动')
        self.roots = []
        self.owned = {}

    def track(self, process):
        self.roots.append(process)
        self.refresh()

    def refresh(self):
        pending = [os.getpid()]
        seen = set()
        while pending:
            pid = pending.pop()
            if pid in seen:
                continue
            seen.add(pid)
            if pid != os.getpid():
                identity = process_identity(pid)
                if identity:
                    self.owned[pid] = identity[0]
            try:
                pending.extend(map(int, Path(f'/proc/{pid}/task/{pid}/children').read_text().split()))
            except (OSError, ValueError):
                pass
        # 先让Popen取得自身返回值，再回收收养的孤儿，防止留下僵尸进程。
        for process in self.roots:
            process.poll()
        while True:
            try:
                if os.waitpid(-1, os.WNOHANG)[0] == 0:
                    break
            except ChildProcessError:
                break
        live = {}
        for pid, start in self.owned.items():
            identity = process_identity(pid)
            if identity and identity[0] == start and identity[1] != 'Z':
                live[pid] = identity
        return live

    def cleanup(self):
        # 重复Ctrl+C不能打断finally；各阶段使用统一期限，而不是每个进程等5秒。
        previous = {s: signal.signal(s, signal.SIG_IGN) for s in (signal.SIGINT, signal.SIGTERM, signal.SIGHUP)}
        try:
            for sig, seconds in ((signal.SIGINT, 2.), (signal.SIGTERM, 2.), (signal.SIGKILL, 1.)):
                deadline = time.monotonic() + seconds
                sent = set()
                while True:
                    live = self.refresh()
                    if not live:
                        return []
                    # 每个后代单独发送，也覆盖已退出启动器及另建进程组的GUI。
                    for pid in live.keys() - sent:
                        try:
                            os.kill(pid, sig)
                        except ProcessLookupError:
                            pass
                        sent.add(pid)
                    if time.monotonic() >= deadline:
                        break
                    time.sleep(.05)
            return sorted(self.refresh())
        finally:
            for sig, handler in previous.items():
                signal.signal(sig, handler)
