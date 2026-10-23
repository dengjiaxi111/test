#!/usr/bin/env python3
from pathlib import Path
import xml.etree.ElementTree as E
import copy,yaml,argparse,subprocess,sys
T=Path(__file__).resolve().parents[1];R=T.parent
pa=argparse.ArgumentParser();pa.add_argument('--case',choices=['single','upper','upper_approach','lower','long','crest','demo','flat_nav'],default='upper');pa.add_argument('--baseline',action='store_true');pa.add_argument('--boost-speed','--uphill-speed',dest='boost_speed',type=float,default=None);pa.add_argument('--model-sdf',type=Path,default=T/'sim/robot.sdf');pa.add_argument('--diagnostic-contacts',action='store_true');a=pa.parse_args()
model=E.parse(a.model_sdf).getroot().find('model')
has_lift=model.find("joint[@name='lift_joint']") is not None
a.baseline=a.baseline or not has_lift
cases={'single':((1.67238,-5.43273),(-5.51016,-5.02066)),'upper':((4.694,6.),(-2.,7.604)),'lower':((2.,-4.306),(-4.6935,-2.6)),'long':((6.82189,-1.35343),(-6.72366,1.21869)),'crest':((4.694,5.),(4.694,7.604))}
cases['demo']=((-10.,3.),(4.694,8.1)) # 原world出生点(4.5,11)减去地图平移，目标完整越过出口延长段。
cases['flat_nav']=((-10.,3.),(-8.,3.)) # 无坡洞的普通导航终点回归。
cases['upper_approach']=((4.694,5.),(-2.,7.604)) # 完整A前准备→A2上坡→B2下坡；不改变规划。
start,goal=cases[a.case]
# Reuse the original world and boundary walls; substitute the test-only field mesh.
subprocess.run([sys.executable,str(T/'scripts/generate_roofless_field.py')],check=True)
s=E.parse(R/'navigatiosim2/src/sentry_velocity/gazeboworld/worlds/rmuc_2026_world.sdf');w=s.getroot().find('world')
if a.diagnostic_contacts:
    E.SubElement(w,'plugin',filename='gz-sim-contact-system',name='gz::sim::systems::Contact')
w.find("model[@name='rmuc_2026']/include/uri").text=str(T/'sim/roofless_2026')
world_offset=(14.5,8.,.35865612)
i=E.SubElement(w,'include');E.SubElement(i,'uri').text=str(a.model_sdf.resolve())
spawn_z=.65 if a.case=='demo' else .34+world_offset[2]
E.SubElement(i,'pose').text=f'{start[0]+world_offset[0]} {start[1]+world_offset[1]} {spawn_z} 0 0 0'
E.indent(s);s.write(T/'sim'/f'{a.case}.sdf',encoding='unicode',xml_declaration=True)
p=yaml.safe_load((R/'navigate/src/my_navigation/nav_bringup/config/nav_params.yaml').read_text());n=p['nav_server']['ros__parameters']
n.update(use_sim_time=True,debug_reset_odom_to_base_link=False,enable_static_layer=True,enable_dynamic_layer=False,map_file=str(T/'map/map.yaml'),terrain_file=str(T/'map/terrain.yaml'),hole_passages_file=str(T/'map/hole_passages.yaml'),controller_timeout=8.,controller_progress_threshold=.05,goal_timeout=300.,path_check_period=.3)
n['hole_state_machine']={'config_file':str(T/'src/my_navigation/nav_bringup/config/hole_state_machine.yaml')}
if a.baseline:
    b=yaml.safe_load((T/'src/my_navigation/nav_bringup/config/hole_state_machine.yaml').read_text());b['hole_state_machine']['enabled']=False
    (T/'sim/baseline_hole.yaml').write_text(yaml.safe_dump(b,sort_keys=False));n['hole_state_machine']['config_file']=str(T/'sim/baseline_hole.yaml')
# 仿真NMPC二维速度范数上限，单位m/s；不改变巡航目标、轮胎或电机参数。
n['nmpc'].update(max_linear_vel=4.,max_linear_accel=10.,pose_timeout_sec=.5,chassis_velocity_timeout_sec=.5)
n['nmpc']['R_linear']=1.0  # 测试轮系的加速度代价，抑制原0.01权重下的急加减速。
n['nmpc']['contouring_weight']=100.0  # 加强弯道后回到中心线，S—T仍保留0.15m偏差限制。
n['nmpc']['esdf_safe_dist']=0.32  # 60cm底盘半宽+2cm；0.5m软净距无法容纳0.74~0.90m通道。
n['nmpc'].setdefault('speed_profile',{}).update(v_cruise=2.)
if not a.baseline:
    active=yaml.safe_load((T/'src/my_navigation/nav_bringup/config/hole_state_machine.yaml').read_text())
    saved=yaml.safe_load((T/'sim/runtime_tuning.yaml').read_text()) if (T/'sim/runtime_tuning.yaml').exists() else {}
    allowed={'flat_speed','boost_speed','minimum_entry_speed','minimum_slope_speed','restore_speed'}
    for k,v in (saved or {}).items():
        if k in {'downhill_speed','restricted_speed','post_slope_distance','prepare_speed'}:
            print('已取消该速度限制，忽略保存字段：'+k);continue
        if k=='uphill_speed':k='boost_speed'  # 旧保存值迁移为补速目标
        if k in allowed:active['hole_state_machine'][k]=float(v)
        elif k=='max_linear_accel':n['nmpc']['max_linear_accel']=float(v);active['hole_state_machine']['acceleration_limit']=float(v)
        else:raise ValueError('unknown saved simulation tuning: '+k)
    if a.boost_speed is not None:active['hole_state_machine']['boost_speed']=a.boost_speed
    (T/'sim/active_hole.yaml').write_text(yaml.safe_dump(active,sort_keys=False));n['hole_state_machine']['config_file']=str(T/'sim/active_hole.yaml')
    n['nmpc']['max_linear_vel']=max([4.]+[active['hole_state_machine'][k] for k in allowed])
n['hole_runtime']={'save_file':str(T/'sim/runtime_tuning.yaml')}
(T/'sim/nav_params.yaml').write_text('# 仅供隔离测试；不修改原算法配置。\n'+yaml.safe_dump(p,sort_keys=False))
(T/'sim/case.yaml').write_text(yaml.safe_dump({'case':a.case,'start':list(start),'goal':list(goal),'world_offset':list(world_offset),'model_sdf':str(a.model_sdf.resolve()),'has_lift':has_lift,'baseline':a.baseline}))
# URDF for RViz only. TF is supplied from truth+actual joints, not duplicate RSP.
model=E.parse(a.model_sdf).getroot().find('model');u=E.Element('robot',name='sentry_lift_test')
for link in model.findall('link'):
    ul=E.SubElement(u,'link',name=link.get('name'))
    for v in link.findall('visual'):
        uv=E.SubElement(ul,'visual');pose=(v.findtext('pose') or '0 0 0 0 0 0').split();E.SubElement(uv,'origin',xyz=' '.join(pose[:3]),rpy=' '.join(pose[3:]))
        g=E.SubElement(uv,'geometry');shape=list(v.find('geometry'))[0]
        if shape.tag=='box':E.SubElement(g,'box',size=shape.findtext('size'))
        elif shape.tag=='cylinder':E.SubElement(g,'cylinder',radius=shape.findtext('radius'),length=shape.findtext('length'))
        elif shape.tag=='mesh':
            uri=shape.findtext('uri');uri=Path(uri).as_uri() if uri.startswith('/') else uri
            E.SubElement(g,'mesh',filename=uri,scale=shape.findtext('scale') or '1 1 1')
for j in model.findall('joint'):
    typ=j.get('type');uj=E.SubElement(u,'joint',name=j.get('name'),type='continuous' if typ=='revolute' else typ)
    E.SubElement(uj,'parent',link=j.findtext('parent'));E.SubElement(uj,'child',link=j.findtext('child'))
    pose=(j.findtext('pose') or '0 0 0 0 0 0').split();E.SubElement(uj,'origin',xyz=' '.join(pose[:3]),rpy=' '.join(pose[3:]))
    if j.find('axis') is not None:E.SubElement(uj,'axis',xyz=j.findtext('axis/xyz'))
    if typ=='prismatic':E.SubElement(uj,'limit',lower='0',upper='.3',effort='300',velocity='.8')
E.indent(u);E.ElementTree(u).write(T/'sim/robot.urdf',encoding='unicode',xml_declaration=True)
print(a.case,start,'->',goal)
