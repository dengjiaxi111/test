"""复用实际按键回调，验证模式切换、停车和调参请求，避免只测显示文字。"""
import sys
from pathlib import Path
from types import SimpleNamespace
sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'sim'))
from keyboard_console import KeyboardConsole
from geometry_msgs.msg import Twist
out=[];changes=[]
pub=SimpleNamespace(publish=out.append)
n=SimpleNamespace(mode='navigation',command=Twist(),yaw=0.,yaw_key=-1.,control=pub,stop=pub,
    selected=1,values={'boost_speed':2.},apply=lambda k,v:changes.append((k,v)),message='',manual_speed=1.)
key=lambda k:KeyboardConsole.key(n,k)
key('k');assert n.mode=='keyboard' and out[-2].data=='keyboard'
key('w');assert n.command.linear.x==-1.
key(']');key('s');assert n.command.linear.x==1.1
key('j');assert n.command.angular.z==1.2
key('q');assert n.yaw>1.7
key(' ');assert n.command.linear.x==0. and n.command.angular.z==0. and n.yaw==0. and out[-1].data
key('2');key('+');assert changes[-1]==('boost_speed',2.1)
n.values['max_linear_accel']=10.;key('6');key('+');assert changes[-1]==('max_linear_accel',11.)
key('p');assert changes[-1]==('save',True)
key('n');assert n.mode=='navigation' and not out[-1].data
print('PASS: 原按键方向、K/N仲裁、停车、选择/增减/保存请求')
