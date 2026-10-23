#!/usr/bin/env python3
"""独立模型生成；只读取原轮组，不覆盖原SDF。所有长度为m。"""
from pathlib import Path
import xml.etree.ElementTree as E
import copy, yaml, argparse
args=argparse.ArgumentParser();args.add_argument("--wheel-friction",type=float,default=.2);options=args.parse_args()
R=Path(__file__).resolve().parents[2]; T=R/'test'
def sub(p,t,text=None,**a):
    q=E.SubElement(p,t,a)
    if text is not None:q.text=str(text)
    return q
def box(link,name,size,pose,color='0.25 0.45 0.7 1'):
    for typ in ('visual','collision'):
        n=sub(link,typ,name=name+'_'+typ);sub(n,'pose',pose)
        sub(sub(sub(n,'geometry'),'box'),'size',size)
        if typ=='visual':sub(sub(n,'material'),'diffuse',color)
def plugin(m,filename,name,params=None):
    p=sub(m,'plugin',filename=filename,name=name)
    for k,v in (params or {}).items():sub(p,k,v)
    return p
raw=E.parse(R/'navigatiosim2/src/seu_sentry_description/resource/models/new_seu_sentry/seu_sentry.def.xmacro')
root=E.Element('sdf',version='1.9');m=sub(root,'model',name='sentry')
sub(m,'pose','0 0 0.29 0 0 0')
block=raw.getroot().find('xmacro_define_block')
for node in block:
    if node.tag not in ('link','joint'):continue
    if node.get('name') in ('gimbal_yaw_joint','base_link','gimbal_yaw','gimbal_yaw_frame_joint'):continue
    m.append(copy.deepcopy(node))
c=m.find("link[@name='chassis']")
for n in list(c):
    if n.tag in ('visual','collision'):c.remove(n)
# 用户指定底盘20kg：沿用原重心与惯量分布，张量按质量20/12同比缩放。
original_mass=float(c.findtext('inertial/mass'))
c.find('inertial/mass').text='20.0'
for value in c.find('inertial/inertia'):value.text=str(float(value.text)*20./original_mass)
# Nominal wheel-ground plane is chassis.z - 0.28585. Deck top = 0.20m.
# Top pocket contains the original Mid360 mounting envelope at low posture.
for name,size,pose in (
 ('deck_left','.03 .60 .04','-.285 0 -.10585 0 0 0'),
 ('deck_right','.03 .60 .04','.285 0 -.10585 0 0 0'),
 ('deck_front','.54 .03 .04','0 -.285 -.10585 0 0 0'),
 ('deck_rear','.54 .03 .04','0 .285 -.10585 0 0 0'),
 ('pocket_floor','.60 .60 .11','0 0 -.18085 0 0 0')):box(c,name,size,pose)
# Contact-parameter A/B test only; wheel geometry, joints and motor loops stay original.
for l in m.findall('link'):
    if 'wheel_link' in l.get('name',''):
        for mu in l.findall('collision/surface/friction/ode/*'):
            if mu.tag in ('mu','mu2'):mu.text=str(options.wheel_friction)
# Simplified visual geometry only; preserve every original wheel joint/axis/collision.
for link in m.findall('link'):
    if link is c:continue
    for n in list(link.findall('visual')):link.remove(n)
    collision=link.find('collision')
    if collision is not None:
        v=sub(link,'visual',name='simple_visual')
        if collision.find('pose') is not None:v.append(copy.deepcopy(collision.find('pose')))
        v.append(copy.deepcopy(collision.find('geometry')))
        sub(sub(v,'material'),'diffuse','0.08 0.08 0.09 1')
lift=sub(m,'joint',name='lift_joint',type='prismatic')
sub(lift,'pose','0 0 -0.08835 0 0 0',relative_to='chassis')
sub(lift,'parent','chassis');sub(lift,'child','lift_carriage')
a=sub(lift,'axis');sub(a,'xyz','0 0 1');lim=sub(a,'limit')
for k,v in [('lower',0),('upper',.30),('effort',300),('velocity',.25)]:sub(lim,k,v)
car=sub(m,'link',name='lift_carriage');sub(car,'pose','0 0 0 0 0 0',relative_to='lift_joint')
inert=sub(car,'inertial');sub(inert,'mass',.15);ii=sub(inert,'inertia')
for k,v in [('ixx',.001),('iyy',.001),('izz',.001)]:sub(ii,k,v)
yaw=sub(m,'joint',name='gimbal_yaw_joint',type='revolute');sub(yaw,'parent','lift_carriage');sub(yaw,'child','base_link')
# Preserve the original yaw-joint mounting transform; only its parent can lift.
sub(yaw,'pose','0 0 .0165 0 0 1.6032',relative_to='lift_carriage');a=sub(yaw,'axis');sub(a,'xyz','0 0 1');lim=sub(a,'limit')
for k,v in [('lower',-1000000),('upper',1000000),('effort',100),('velocity',20)]:sub(lim,k,v)
b=sub(m,'link',name='base_link');sub(b,'pose','0 0 0 0 0 0',relative_to='gimbal_yaw_joint')
# 恢复原0.8kg云台及极小yaw惯量，减小旋转反作用；不是严格零耦合模型。
b.append(copy.deepcopy(block.find("link[@name='base_link']/inertial")))
box(b,'upper','.40 .10 .04','0 0 0 0 0 0','0.75 0.3 0.15 1')
box(b,'muzzle','.06 .055 .025','.22 0 0 0 0 0','0.03 0.03 0.04 1')
box(b,'muzzle_direction','.004 .035 .014','.252 0 0 0 0 0','0.0 0.85 0.85 1')
# Original radar mesh + fixed mounting. Ground truth replaces only sensing/LIO.
rad=sub(m,'link',name='livox_frame');sub(rad,'pose','.045 .123 0 -.785 0 0',relative_to='base_link')
ir=sub(rad,'inertial');sub(ir,'pose','0 0 .02 0 0 0');sub(ir,'mass',.005);ii=sub(ir,'inertia')
for k,v in [('ixx',.005*(3*.04**2+.04**2)/12),('iyy',.005*(3*.04**2+.04**2)/12),('izz',.005*.04**2/2)]:sub(ii,k,v)
j=sub(m,'joint',name='radar_mount',type='fixed');sub(j,'parent','base_link');sub(j,'child','livox_frame')
radar_mesh=R/'navigatiosim2/src/pb2025_robot_description/resource/models/mid360/meshes/mid360.dae'
for typ in ('visual',):
    v=sub(rad,typ,name='original_mid360_'+typ);sub(v,'pose','0 0 0 0 0 3.141592653589793')
    sub(sub(sub(v,'geometry'),'mesh'),'uri',radar_mesh)
plugin(m,'gz-sim-joint-state-publisher-system','gz::sim::systems::JointStatePublisher')
plugin(m,'gz-sim-odometry-publisher-system','gz::sim::systems::OdometryPublisher',{'odom_frame':'odom','robot_base_frame':'chassis','dimensions':3,'odom_publish_frequency':50,'odom_topic':'/wheel/odometry'})
plugin(m,'gz-sim-joint-position-controller-system','gz::sim::systems::JointPositionController',{'joint_name':'lift_joint','topic':'/lift/position','p_gain':3000,'i_gain':0,'d_gain':70,'cmd_max':300,'cmd_min':-300,'initial_position':.30})
plugin(m,'gz-sim-joint-controller-system','gz::sim::systems::JointController',{'joint_name':'gimbal_yaw_joint','topic':'/gimbal/cmd_vel','use_force_commands':'false','p_gain':.2,'i_gain':.01})
plugin(m,str(R/'navigatiosim2/install/seu_sentry_sim_control/lib/libsentry_motor_controller.so'),'seu_sentry_sim_control::SentryMotorController',{'wheel_kp':.28,'wheel_ki':.08,'wheel_kd':.000005,'steer_kp':12,'steer_ki':.15,'steer_kd':.12,'wheel_torque_limit':2,'steer_torque_limit':5,'integral_limit':1,'command_timeout':.2})
E.indent(root);E.ElementTree(root).write(T/'sim/robot.sdf',encoding='unicode',xml_declaration=True)
wroot=E.Element('sdf',version='1.9');w=sub(wroot,'world',name='default')
p=sub(w,'physics',name='physics',type='ignored');sub(p,'max_step_size',.001);sub(p,'real_time_factor',1)
for file,name in [('physics','Physics'),('user-commands','UserCommands'),('scene-broadcaster','SceneBroadcaster')]:plugin(w,'gz-sim-'+file+'-system','gz::sim::systems::'+name)
f=sub(w,'model',name='floor');sub(f,'static','true');l=sub(f,'link',name='floor');box(l,'floor','40 30 .1','0 0 -.05 0 0 0','0.65 0.65 0.65 1')
i=sub(w,'include');sub(i,'uri',str(T/'sim/robot.sdf'));sub(i,'pose','0 0 .30 0 0 0')
light=sub(w,'light',name='sun',type='directional');sub(light,'pose','0 0 10 0 0 0');sub(light,'diffuse','1 1 1 1');sub(light,'direction','0 0 -1')
E.indent(wroot);E.ElementTree(wroot).write(T/'sim/flat.sdf',encoding='unicode',xml_declaration=True)
bridge=yaml.safe_load((R/'navigatiosim2/src/seu_sentry_sim_control/config/swerve_bridge.yaml').read_text())
bridge=[b for b in bridge if not b['ros_topic_name'].startswith('/simulation/') and 'gimbal_yaw_joint' not in b['ros_topic_name']]
for topic,typ,gtyp,d in [('/clock','rosgraph_msgs/msg/Clock','gz.msgs.Clock','GZ_TO_ROS'),('/lift/position','std_msgs/msg/Float64','gz.msgs.Double','ROS_TO_GZ'),('/gimbal/cmd_vel','std_msgs/msg/Float64','gz.msgs.Double','ROS_TO_GZ')]:
    bridge.append(dict(ros_topic_name=topic,gz_topic_name=topic,ros_type_name=typ,gz_type_name=gtyp,direction=d))
(T/'sim/bridge.yaml').write_text(yaml.safe_dump(bridge,sort_keys=False))
print('Original swerve + 60cm deck/pocket + long gimbal/muzzle; original yaw/radar mounting; low maximum ~0.246m')
