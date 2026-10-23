#!/usr/bin/env python3
"""仅截取本次RViz窗口，作为实际显示验收；不读取整个桌面。"""
import re,subprocess,ctypes,time
from pathlib import Path
from PyQt5.QtGui import QGuiApplication
lines=subprocess.check_output(['xwininfo','-root','-tree'],text=True).splitlines()
windows=[]
for line in lines:
    if '("rviz2" "rviz2")' not in line:continue
    shape=re.search(r'(\d+)x(\d+)\+',line)
    if shape:windows.append((int(shape[1])*int(shape[2]),int(line.strip().split()[0],16)))
assert windows,'没有找到本次RViz窗口'
window=max(windows)[1]
x=ctypes.CDLL('libX11.so.6');x.XOpenDisplay.restype=ctypes.c_void_p
x.XMoveResizeWindow.argtypes=[ctypes.c_void_p,ctypes.c_ulong,ctypes.c_int,ctypes.c_int,ctypes.c_uint,ctypes.c_uint]
x.XRaiseWindow.argtypes=[ctypes.c_void_p,ctypes.c_ulong];x.XSync.argtypes=[ctypes.c_void_p,ctypes.c_int];x.XCloseDisplay.argtypes=[ctypes.c_void_p]
d=x.XOpenDisplay(None);assert d
x.XMoveResizeWindow(d,window,20,20,1280,800);x.XRaiseWindow(d,window);x.XSync(d,False);x.XCloseDisplay(d)
time.sleep(.6)
app=QGuiApplication([]);p=Path(__file__).resolve().parents[1]/'results/rviz_letters.png'
assert app.primaryScreen().grabWindow(window).save(str(p))
print(p)
