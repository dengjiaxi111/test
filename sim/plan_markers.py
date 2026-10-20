#!/usr/bin/env python3
"""只从正式NavigationPlan绘制执行六事件，绝不反向驱动状态机。"""
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile,DurabilityPolicy
from nav_interfaces.msg import NavigationPlan,HoleTraversalState
from visualization_msgs.msg import Marker,MarkerArray
class Display(Node):
    def __init__(self):
        super().__init__('execution_plan_markers');q=QoSProfile(depth=1,durability=DurabilityPolicy.TRANSIENT_LOCAL)
        self.pub=self.create_publisher(MarkerArray,'hole_execution_markers',q);self.plan=None;self.state=None
        self.create_subscription(NavigationPlan,'navigation_plan',self.on_plan,q)
        self.create_subscription(HoleTraversalState,'hole_traversal_state',self.on_state,10)
    def on_plan(self,m):self.plan=m;self.draw()
    def on_state(self,m):
        old=self.state;self.state=m
        if old is None or (old.state,old.reason,old.recovery_phase)!=(m.state,m.reason,m.recovery_phase):self.draw()
    def draw(self):
        if self.plan is None:return
        p=self.plan;out=MarkerArray();clear=Marker();clear.action=Marker.DELETEALL;out.markers.append(clear)
        colors=[(1.,.7,0.),(.2,.7,1.),(1.,.1,.1),(.2,1.,.2),(.7,.4,1.),(1.,.5,.7)]
        uid=0
        def mark(kind,xyz,color,scale,text=''):
            nonlocal uid
            m=Marker();m.header=p.header;m.ns='accepted_execution';m.id=uid;uid+=1;m.type=kind;m.action=Marker.ADD;m.pose.orientation.w=1.
            m.pose.position.x,m.pose.position.y,m.pose.position.z=xyz
            m.scale.x,m.scale.y,m.scale.z=scale;m.color.r,m.color.g,m.color.b=color;m.color.a=1.;m.text=text;out.markers.append(m)
        active=p.status==p.ACTIVE
        # Keep the last formal plan visible on failure; grey geometry grants no motion.
        for passage in p.passages:
            for i,e in enumerate(passage.events):
                if not e.point_valid:continue
                label='ASEXTD'[i];color=colors[i] if active else (.55,.55,.55)
                mark(Marker.SPHERE,(e.point.x,e.point.y,.08),color,(.10,.10,.10))
                mark(Marker.TEXT_VIEW_FACING,(e.point.x-.15,e.point.y,.30+i*.10),color,(0.,0.,.14),f'{passage.hole_id} {label} s={e.s_path:.2f} range={e.range_status}')
        if p.path.poses:
            status='ACTIVE' if active else f'INACTIVE({p.status})'
            message=f'plan={p.plan_id} {status}'
            if self.state:message+=f' state={self.state.state} attempt={self.state.attempt} recovery={self.state.recovery_phase}\n{self.state.reason}'
            if not active:message+='\n'+p.reason
            mark(Marker.TEXT_VIEW_FACING,(p.path.poses[0].pose.position.x,p.path.poses[0].pose.position.y,1.),(1.,1.,1.),(0.,0.,.15),message)
        self.pub.publish(out)
def main():
    rclpy.init();n=Display()
    try:rclpy.spin(n)
    finally:n.destroy_node();rclpy.try_shutdown()
if __name__=='__main__':main()
