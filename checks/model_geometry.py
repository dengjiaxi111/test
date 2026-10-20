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
assert m.find("joint[@name='gimbal_yaw_joint']/pose").text=='0 0 .0165 0 0 1.6032'
assert m.find("link[@name='livox_frame']/pose").text=='.045 .123 0 -.785 0 0'
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
(T/'results/model_geometry.json').write_text(json.dumps(result,indent=2));print(result)
