"""Regression: a failed plan must remain visibly marked invalid, not disappear."""
import sys
from pathlib import Path
from types import SimpleNamespace
sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'sim'))
from plan_markers import Display
from nav_interfaces.msg import NavigationPlan,HoleTraversal
from geometry_msgs.msg import PoseStamped
from visualization_msgs.msg import Marker
p=NavigationPlan();p.header.frame_id='map';p.plan_id=1;p.path.poses=[PoseStamped()]
v=HoleTraversal();v.hole_id='one'
for i,e in enumerate(v.events):e.type=i;e.point_valid=True;e.point.x=float(i);e.s_path=float(i)
p.passages=[v];outputs=[]
d=SimpleNamespace(plan=p,state=None,pub=SimpleNamespace(publish=outputs.append))
for status in [p.ACTIVE,p.INVALIDATED]:
 p.status=status;Display.draw(d)
 count=sum(m.type==Marker.SPHERE and m.action==Marker.ADD for m in outputs[-1].markers)
 print('plan status',status,'visible event points',count,flush=True)
 assert count==6
