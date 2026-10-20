#!/usr/bin/env python3
"""真实回调顺序回归：周期发送false不能吞掉同周期旋转命令。"""
from pathlib import Path
import sys
from types import SimpleNamespace
sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'sim'))
from sim_bridge import SimBridge
from std_msgs.msg import Float64,Bool
n=SimpleNamespace(rotation_stop=False,spin_rate=0.,spin_received=-1.,simtime=lambda:1.)
SimBridge.on_spin(n,Float64(data=.35))
SimBridge.on_rotation_stop(n,Bool(data=False))
assert n.spin_rate==.35 and n.spin_received==1.,'重复false错误清除了有效旋转请求'
SimBridge.on_rotation_stop(n,Bool(data=True))
assert n.rotation_stop and n.spin_rate==0. and n.spin_received<0
SimBridge.on_spin(n,Float64(data=.35))
SimBridge.on_rotation_stop(n,Bool(data=False))
assert not n.rotation_stop and n.spin_rate==0. and n.spin_received<0,'解除停转不能复活旧请求'
SimBridge.on_spin(n,Float64(data=.35))
assert n.spin_rate==.35
print('PASS: 连续false不吞命令、true清除缓存、解除后仅新请求启动')
