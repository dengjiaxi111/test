"""Check original wheel/mounting invariants and real low-envelope vertices."""
from pathlib import Path
import xml.etree.ElementTree as E,json
import numpy as np
from scipy.spatial.transform import Rotation as R
T=Path(__file__).resolve().parents[1];W=T.parent
m=E.parse(T/'sim/robot.sdf').getroot().find('model')
old=E.parse(W/'navigatiosim2/src/seu_sentry_description/resource/models/new_seu_sentry/seu_sentry.def.xmacro').getroot().find('xmacro_define_block')
def tree(n):return (n.tag,dict(n.attrib),(n.text or '').strip(),[tree(c) for c in n])
for j in old.findall('joint'):
 if 'wheel_joint' in j.get('name','') or 'steer_joint' in j.get('name',''):assert tree(j)==tree(m.find(f"joint[@name='{j.get('name')}']"))
for l in old.findall('link'):
 if 'wheel_link' in l.get('name','') or 'steer_link' in l.get('name',''):
  assert tree(l.find('collision'))==tree(m.find(f"link[@name='{l.get('name')}']/collision"))
assert float(m.findtext("link[@name='chassis']/inertial/mass"))==20.
assert tree(m.find("link[@name='base_link']/inertial"))==tree(old.find("link[@name='base_link']/inertial"))
assert m.find("link[@name='livox_frame']/collision") is None
assert float(m.findtext("link[@name='livox_frame']/inertial/mass"))==.005
assert m.find("joint[@name='gimbal_yaw_joint']/pose").text=='0 0 .0165 0 0 1.6032'
assert m.find("link[@name='livox_frame']/pose").text=='.045 .123 0 -.785 0 0'
# 名义平地上检查实际外观和碰撞包络：底面上移5cm，顶部/凹槽/轮系不动。
chassis=m.find("link[@name='chassis']")
bounds={}
for kind in ('visual','collision'):
 parts=[]
 for node in chassis.findall(kind):
  size=np.fromstring(node.findtext('geometry/box/size'),sep=' ')
  pose=np.fromstring(node.findtext('pose'),sep=' ')
  assert np.allclose(pose[3:],0)
  parts.append((pose[2]-size[2]/2+.28585,pose[2]+size[2]/2+.28585))
 bounds[kind]=(min(p[0] for p in parts),max(p[1] for p in parts))
assert np.allclose(bounds['visual'],[.10,.20]),bounds
assert np.allclose(bounds['collision'],bounds['visual']),bounds
floor=chassis.find("collision[@name='pocket_floor_collision']")
floor_top=float(floor.findtext('pose').split()[2])+float(floor.findtext('geometry/box/size').split()[2])/2+.28585
assert abs(floor_top-.16)<1e-9
urdf=E.parse(T/'sim/robot.urdf').getroot()
floor_visual=next(v for v in urdf.findall("link[@name='chassis']/visual") if v.find('geometry/box') is not None and v.find('geometry/box').get('size')=='.60 .60 .06')
assert np.allclose(np.fromstring(floor_visual.find('origin').get('xyz'),sep=' '),[0,0,-.15585])
ns={'c':'http://www.collada.org/2005/11/COLLADASchema'}
d=E.parse(W/'navigatiosim2/src/pb2025_robot_description/resource/models/mid360/meshes/mid360.dae').getroot()
vertices=[]
for scene in d.findall('.//c:visual_scene/c:node',ns):
 matrix=np.fromstring(scene.find('c:matrix',ns).text,sep=' ').reshape(4,4)
 geom=scene.find('c:instance_geometry',ns).get('url')[1:]
 src=d.find(f".//c:geometry[@id='{geom}']/c:mesh/c:source",ns)
 points=np.fromstring(src.find('c:float_array',ns).text,sep=' ').reshape(-1,3)
 vertices.append((np.c_[points,np.ones(len(points))]@matrix.T)[:,:3])
v=np.concatenate(vertices)
v=R.from_euler('z',np.pi).apply(v)
v=R.from_euler('x',-.785).apply(v)+[.045,.123,0]
radar_z=(float(v[:,2].min()+.214),float(v[:,2].max()+.214))
assert radar_z[0]>.16 and radar_z[1]<.25,radar_z
assert np.linalg.norm(v[:,:2],axis=1).max()<.27
result={'wheel_joints_and_collisions_unchanged':True,'yaw_mount_radians':1.6032,'radar_mount_xyz_rpy':[.045,.123,0,-.785,0,0],'radar_low_world_z_bounds_m':radar_z,'low_total_height_m':max(.234,radar_z[1]),'deck_top_m':.20,'pocket_floor_m':.16,'gun_body_m':[.4,.1,.04],'chassis_outer_footprint_m':[.6,.6]}
result.update(chassis_mass_kg=20.,gimbal_mass_kg=.8,gimbal_inertia_kg_m2=[.0087,.0087,1e-6],radar_mass_kg=.005,radar_collision=False)
result.update(chassis_bottom_clearance_m=bounds['collision'][0],chassis_shell_height_m=bounds['collision'][1]-bounds['collision'][0])
(T/'results/model_geometry.json').write_text(json.dumps(result,indent=2));print(result)
