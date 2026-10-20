#!/usr/bin/env python3
from pathlib import Path
import xml.etree.ElementTree as E
import copy,yaml,argparse
T=Path(__file__).resolve().parents[1];R=T.parent
pa=argparse.ArgumentParser();pa.add_argument('--case',choices=['single','upper','lower','long','crest'],default='upper');pa.add_argument('--baseline',action='store_true');pa.add_argument('--uphill-speed',type=float,default=2.);a=pa.parse_args()
cases={'single':((1.67238,-5.43273),(-5.51016,-5.02066)),'upper':((4.694,6.),(-2.,7.604)),'lower':((2.,-4.306),(-4.6935,-2.6)),'long':((6.82189,-1.35343),(-6.72366,1.21869)),'crest':((4.694,5.),(4.694,7.604))}
start,goal=cases[a.case]
# Reuse the original world, complete field model and boundary collisions.
s=E.parse(R/'navigatiosim2/src/sentry_velocity/gazeboworld/worlds/rmuc_2026_world.sdf');w=s.getroot().find('world')
w.find("model[@name='rmuc_2026']/include/uri").text=str(R/'navigatiosim2/src/sentry_velocity/gazeboworld/models/rmuc_2026')
world_offset=(14.5,8.,.35865612)
i=E.SubElement(w,'include');E.SubElement(i,'uri').text=str(T/'sim/robot.sdf')
E.SubElement(i,'pose').text=f'{start[0]+world_offset[0]} {start[1]+world_offset[1]} {.34+world_offset[2]} 0 0 0'
E.indent(s);s.write(T/'sim'/f'{a.case}.sdf',encoding='unicode',xml_declaration=True)
p=yaml.safe_load((R/'navigate/src/my_navigation/nav_bringup/config/nav_params.yaml').read_text());n=p['nav_server']['ros__parameters']
n.update(use_sim_time=True,debug_reset_odom_to_base_link=False,enable_static_layer=True,enable_dynamic_layer=False,map_file=str(T/'map/map.yaml'),terrain_file=str(T/'map/terrain.yaml'),hole_passages_file=str(T/'map/hole_passages.yaml'),controller_timeout=8.,controller_progress_threshold=.05,goal_timeout=300.,path_check_period=.3)
n['hole_state_machine']={'config_file':str(T/'src/my_navigation/nav_bringup/config/hole_state_machine.yaml')}
if a.baseline:
    b=yaml.safe_load((T/'src/my_navigation/nav_bringup/config/hole_state_machine.yaml').read_text());b['hole_state_machine']['enabled']=False
    (T/'sim/baseline_hole.yaml').write_text(yaml.safe_dump(b,sort_keys=False));n['hole_state_machine']['config_file']=str(T/'sim/baseline_hole.yaml')
n['nmpc'].update(max_linear_vel=2.,max_linear_accel=100.,pose_timeout_sec=.5,chassis_velocity_timeout_sec=.5)
n['nmpc'].setdefault('speed_profile',{}).update(v_cruise=2.)
if not a.baseline:
    active=yaml.safe_load((T/'src/my_navigation/nav_bringup/config/hole_state_machine.yaml').read_text());active['hole_state_machine']['uphill_speed']=a.uphill_speed
    (T/'sim/active_hole.yaml').write_text(yaml.safe_dump(active,sort_keys=False));n['hole_state_machine']['config_file']=str(T/'sim/active_hole.yaml')
    n['nmpc']['max_linear_vel']=max(2.,a.uphill_speed)
(T/'sim/nav_params.yaml').write_text('# 仅供隔离测试；不修改原算法配置。\n'+yaml.safe_dump(p,sort_keys=False))
(T/'sim/case.yaml').write_text(yaml.safe_dump({'case':a.case,'start':list(start),'goal':list(goal),'world_offset':list(world_offset)}))
# URDF for RViz only. TF is supplied from truth+actual joints, not duplicate RSP.
model=E.parse(T/'sim/robot.sdf').getroot().find('model');u=E.Element('robot',name='sentry_lift_test')
for link in model.findall('link'):
    ul=E.SubElement(u,'link',name=link.get('name'))
    for v in link.findall('visual'):
        uv=E.SubElement(ul,'visual');pose=(v.findtext('pose') or '0 0 0 0 0 0').split();E.SubElement(uv,'origin',xyz=' '.join(pose[:3]),rpy=' '.join(pose[3:]))
        g=E.SubElement(uv,'geometry');shape=list(v.find('geometry'))[0]
        if shape.tag=='box':E.SubElement(g,'box',size=shape.findtext('size'))
        elif shape.tag=='cylinder':E.SubElement(g,'cylinder',radius=shape.findtext('radius'),length=shape.findtext('length'))
        elif shape.tag=='mesh':E.SubElement(g,'mesh',filename=shape.findtext('uri'),scale=shape.findtext('scale') or '1 1 1')
for j in model.findall('joint'):
    typ=j.get('type');uj=E.SubElement(u,'joint',name=j.get('name'),type='continuous' if typ=='revolute' else typ)
    E.SubElement(uj,'parent',link=j.findtext('parent'));E.SubElement(uj,'child',link=j.findtext('child'))
    pose=(j.findtext('pose') or '0 0 0 0 0 0').split();E.SubElement(uj,'origin',xyz=' '.join(pose[:3]),rpy=' '.join(pose[3:]))
    if j.find('axis') is not None:E.SubElement(uj,'axis',xyz=j.findtext('axis/xyz'))
    if typ=='prismatic':E.SubElement(uj,'limit',lower='0',upper='.3',effort='300',velocity='.25')
E.indent(u);E.ElementTree(u).write(T/'sim/robot.urdf',encoding='unicode',xml_declaration=True)
print(a.case,start,'->',goal)
