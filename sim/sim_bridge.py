#!/usr/bin/env python3
"""Gazebo真值和真实关节→导航接口。不是按等待时间伪造完成的模拟器。"""
import math,time
import yaml
import xml.etree.ElementTree as ET
from pathlib import Path
import numpy as np
from scipy.spatial.transform import Rotation as Rot
import rclpy
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data, QoSProfile, DurabilityPolicy
from nav_msgs.msg import Odometry
from robots_msgs.msg import ChassisOdom
from geometry_msgs.msg import Twist, TransformStamped
from sensor_msgs.msg import JointState
from std_msgs.msg import Float64,String,Bool
from rotation_control import RotationControl,horizontal_child,ground_yaw_rate
from tf2_ros import TransformBroadcaster,StaticTransformBroadcaster
from nav_interfaces.msg import HoleStructureRequest as Request,HoleStructureFeedback as Feedback,NavigationPlan

class SimBridge(Node):
    def __init__(self):
        super().__init__('hole_gazebo_bridge')
        self.world_offset=np.array([float(self.declare_parameter('world_offset_'+axis,0.).value) for axis in ('x','y','z')])
        cfg=yaml.safe_load(Path(__file__).with_name('rotation_control.yaml').read_text())
        if any(not math.isfinite(float(v)) or v<=0 for v in cfg.values()):raise ValueError('invalid rotation configuration')
        self.rotation_config=cfg
        self.rotation=RotationControl(cfg['heading_gain'],cfg['max_chassis_rate'],cfg['max_joint_rate'],cfg['heading_deadband'])
        self.spin_rate=0.;self.spin_received=-1.;self.rotation_stop=False;self.rotation_stable=-1.
        self.q={};self.qv={};self.joint_received=-1.;self.joint_stamp=None;self.odom=None;self.odom_received=-1.
        self.request=None;self.req_time=0.;self.start_lift=0.;self.target=.30;self.cancelled=False;self.completed=False
        self.command=Twist();self.command_received=-1.;self.align=float('nan');self.align_received=-1.;self.plan=None
        self.pub_lio=self.create_publisher(Odometry,'/Odometry',10)
        self.pub_chassis_feedback=self.create_publisher(ChassisOdom,'/ChassisOdom',10)
        self.pub_feedback=self.create_publisher(Feedback,'hole_structure/feedback',10)
        self.pub_lift=self.create_publisher(Float64,'/lift/position',10)
        self.pub_motion=self.create_publisher(Twist,'/cmd_vel_chassis',10)
        self.pub_yaw=self.create_publisher(Float64,'/gimbal/cmd_vel',10)
        self.pub_rotation=self.create_publisher(JointState,'/rotation/feedback',10)
        self.pub_rotation_stopped=self.create_publisher(Bool,'/rotation/stopped',10)
        self.model=ET.parse(Path(__file__).with_name('robot.sdf')).getroot().find('model')
        self.description=self.create_publisher(String,'robot_description',QoSProfile(depth=1,durability=DurabilityPolicy.TRANSIENT_LOCAL))
        self.description.publish(String(data=Path(__file__).with_name('robot.urdf').read_text()))
        self.tf=TransformBroadcaster(self);self.static=StaticTransformBroadcaster(self)
        s=TransformStamped();s.header.frame_id='map';s.child_frame_id='odom';s.transform.rotation.w=1.;self.static.sendTransform(s)
        self.create_subscription(Odometry,'/wheel/odometry',self.on_odom,qos_profile_sensor_data)
        self.create_subscription(JointState,'/joint_states',self.on_joints,qos_profile_sensor_data)
        self.create_subscription(Twist,'/navigation/cmd_vel',self.on_cmd,10)
        self.create_subscription(Float64,'hole_alignment_target',self.on_align,10)
        self.create_subscription(Float64,'/rotation/world_yaw_rate',self.on_spin,10)
        self.create_subscription(Bool,'/rotation/stop',self.on_rotation_stop,10)
        self.create_subscription(Request,'hole_structure/request',self.on_request,10)
        qos=QoSProfile(depth=1,durability=DurabilityPolicy.TRANSIENT_LOCAL)
        self.create_subscription(NavigationPlan,'navigation_plan',self.on_plan,qos)
        self.create_timer(.02,self.tick)
    def simtime(self):return self.get_clock().now().nanoseconds*1e-9
    def on_plan(self,m):self.plan=m
    def on_odom(self,m):self.odom=m;self.odom_received=self.simtime()
    def on_joints(self,m):
        self.q=dict(zip(m.name,m.position));self.qv=dict(zip(m.name,m.velocity));self.joint_received=self.simtime();self.joint_stamp=m.header.stamp
    def on_cmd(self,m):self.command=m;self.command_received=self.simtime()
    def on_align(self,m):self.align=m.data;self.align_received=self.simtime()
    def on_spin(self,m):
        if math.isfinite(m.data):self.spin_rate=m.data;self.spin_received=self.simtime()
    def on_rotation_stop(self,m):
        invalidate=m.data or self.rotation_stop
        self.rotation_stop=m.data
        # 停转后必须收到新的旋转请求才重启，旧缓存命令不能复活。
        if invalidate:self.spin_rate=0.;self.spin_received=-1.
    def on_request(self,m):
        if m.cancel_motion:
            if self.request and (m.session_id,m.goal_id)==(self.request.session_id,self.request.goal_id):
                self.target=self.q.get('lift_joint',0.);self.start_lift=self.target;self.req_time=self.simtime();self.cancelled=True
            return
        key=lambda q:(q.session_id,q.goal_id,q.request_id,q.requirement_revision,q.target)
        if self.request is None or key(m)!=key(self.request):
            self.req_time=self.simtime();self.start_lift=self.q.get('lift_joint',0.)
            self.target=0. if m.target==Request.LOW else (.30 if m.target==Request.NORMAL else self.start_lift)
            self.cancelled=False
            self.completed=False
        self.request=m
    def tick(self):
        now=self.simtime()
        if (self.odom is None or not 0<=now-self.odom_received<=.2 or
            not 0<=now-self.joint_received<=.2 or
            'lift_joint' not in self.q or 'gimbal_yaw_joint' not in self.q or 'gimbal_yaw_joint' not in self.qv):
            self.pub_motion.publish(Twist());self.pub_yaw.publish(Float64(data=0.))
            self.pub_rotation_stopped.publish(Bool(data=False));self.rotation_stable=-1.;return
        od=self.odom;p=od.pose.pose.position;qq=od.pose.pose.orientation
        chassis_position=np.array([p.x,p.y,p.z])-self.world_offset
        rotation=Rot.from_quat([qq.x,qq.y,qq.z,qq.w]);cyaw=rotation.as_euler('xyz')[2]
        gyaw=self.q['gimbal_yaw_joint'];lift=self.q['lift_joint'];lv=self.qv.get('lift_joint',0.)
        upper_r=rotation*Rot.from_euler('z',1.6032+gyaw)
        offset=rotation.apply([0.,0.,-.07185+lift]);position=chassis_position+offset
        vt=od.twist.twist.linear;wt=od.twist.twist.angular
        world_v=rotation.apply([vt.x,vt.y,vt.z]);world_w=rotation.apply([wt.x,wt.y,wt.z])
        point_v=world_v+np.cross(world_w,offset)+rotation.apply([0.,0.,lv])
        stamp=self.get_clock().now().to_msg()
        transforms=[]
        def tf(parent,child,xyz,r):
            t=TransformStamped();t.header.stamp=stamp;t.header.frame_id=parent;t.child_frame_id=child
            t.transform.translation.x,t.transform.translation.y,t.transform.translation.z=map(float,xyz)
            t.transform.rotation.x,t.transform.rotation.y,t.transform.rotation.z,t.transform.rotation.w=map(float,r.as_quat());transforms.append(t)
        tf('odom','chassis',chassis_position,rotation)
        tf('chassis','chassiss',[0,0,0],horizontal_child(rotation))
        tf('chassis','lift_carriage',[0,0,-.08835+lift],Rot.identity())
        tf('lift_carriage','base_link',[0,0,.0165],Rot.from_euler('z',1.6032+gyaw))
        tf('base_link','livox_frame',[.045,.123,0],Rot.from_euler('x',-.785))
        for joint in self.model.findall('joint'):
            name=joint.get('name')
            if name in ('lift_joint','gimbal_yaw_joint','radar_mount'):continue
            pose=list(map(float,(joint.findtext('pose') or '0 0 0 0 0 0').split()))
            r=Rot.from_euler('xyz',pose[3:]);axis=joint.findtext('axis/xyz')
            if axis:r=r*Rot.from_rotvec(np.array(list(map(float,axis.split())))*self.q.get(name,0.))
            tf(joint.findtext('parent'),joint.findtext('child'),pose[:3],r)
        self.tf.sendTransform(transforms)
        for pub,child,r in [(self.pub_lio,'base_link',upper_r)]:
            m=Odometry();m.header.stamp=stamp;m.header.frame_id='odom';m.child_frame_id=child
            m.pose.pose.position.x,m.pose.pose.position.y,m.pose.pose.position.z=map(float,position)
            m.pose.pose.orientation.x,m.pose.pose.orientation.y,m.pose.pose.orientation.z,m.pose.pose.orientation.w=map(float,r.as_quat())
            v=r.inv().apply(point_v);omega=r.inv().apply(world_w+rotation.apply([0.,0.,self.qv['gimbal_yaw_joint']]))
            m.twist.twist.linear.x,m.twist.twist.linear.y,m.twist.twist.linear.z=map(float,v)
            m.twist.twist.angular.x,m.twist.twist.angular.y,m.twist.twist.angular.z=map(float,omega)
            pub.publish(m)
        # MCU-style feedback in the physical gimbal frame, as the original bridge expects.
        fvel=upper_r.inv().apply(point_v);chassis_feedback=ChassisOdom()
        chassis_feedback.speed_x=float(fvel[0]);chassis_feedback.speed_y=float(fvel[1])
        self.pub_chassis_feedback.publish(chassis_feedback)
        # 1.5s smooth requested trajectory; completion below is based on measured joint.
        ratio=np.clip((now-self.req_time)/1.5,0.,1.);s=ratio*ratio*(3.-2.*ratio)
        desired=self.start_lift+(self.target-self.start_lift)*s
        self.pub_lift.publish(Float64(data=float(desired)))
        # 唯一旋转指令出口：导航平移不变，旋转在此合并；外部勿直接抢发关节命令。
        cmd=Twist()
        if now-self.command_received<.2:
            cmd.linear.x=self.command.linear.x;cmd.linear.y=self.command.linear.y
        timeout=self.rotation_config['command_timeout']
        alignment=self.align if math.isfinite(self.align) and 0<=now-self.align_received<timeout else None
        spin=self.spin_rate if 0<=now-self.spin_received<timeout else 0.
        try:
            cmd.angular.z,joint_rate=self.rotation.update(rotation,upper_r,world_w,alignment,spin,self.rotation_stop)
            actual_chassis_rate=ground_yaw_rate(rotation,world_w)
            actual_gimbal_rate=ground_yaw_rate(upper_r,world_w+rotation.apply([0.,0.,self.qv['gimbal_yaw_joint']]))
        except ValueError:
            self.pub_motion.publish(Twist());self.pub_yaw.publish(Float64(data=0.))
            self.pub_rotation_stopped.publish(Bool(data=False));self.rotation_stable=-1.;return
        self.pub_yaw.publish(Float64(data=joint_rate))
        self.pub_motion.publish(cmd)
        frot=JointState();frot.header.stamp=stamp;frot.header.frame_id='odom'
        # 反馈沿用最旧的源采样时刻，定时重复发布不能刷新旧测量的年龄。
        source_stamps=[od.header.stamp,self.joint_stamp]
        frot.header.stamp=min(source_stamps,key=lambda s:s.sec+s.nanosec*1e-9)
        frot.name=['chassis_world_yaw','gimbal_world_yaw']
        frot.position=[float(cyaw),float(upper_r.as_euler('xyz')[2])]
        frot.velocity=[actual_chassis_rate,actual_gimbal_rate];self.pub_rotation.publish(frot)
        source_stamp=frot.header.stamp.sec+frot.header.stamp.nanosec*1e-9
        if 0<=now-source_stamp<=timeout and max(abs(actual_chassis_rate),abs(actual_gimbal_rate))<self.rotation_config['stopped_rate']:
            if self.rotation_stable<0:self.rotation_stable=now
        else:self.rotation_stable=-1.
        self.pub_rotation_stopped.publish(Bool(data=self.rotation_stable>=0 and now-self.rotation_stable>=self.rotation_config['settle_time']))
        if self.request is None and self.plan is None:return
        q=self.request
        if q is None:
            # Capability heartbeat before A; request 0 cannot acknowledge a LOW action.
            q=Request();q.session_id=self.plan.session_id;q.goal_id=self.plan.goal_id;q.target=q.KEEP
        f=Feedback();f.header.stamp=stamp;f.header.frame_id='map'
        f.session_id=q.session_id;f.goal_id=q.goal_id;f.request_id=q.request_id;f.requirement_revision=q.requirement_revision;f.target=q.target
        stopped=abs(lv)<.015;at_target=abs(lift-self.target)<.005
        if stopped and at_target:self.completed=True
        # Completion is terminal for this request; contact-induced velocity noise
        # cannot silently restart it. Actual departure from the position band fails.
        lost_posture=self.completed and abs(lift-self.target)>(.004 if q.target==q.LOW else .008)
        f.status=(f.CANCELLED if self.cancelled else (f.FAILED if lost_posture else (f.COMPLETED if self.completed else f.EXECUTING)))
        if lost_posture:f.fault_code=1
        if hasattr(f,'action_stopped'):f.action_stopped=stopped and (self.cancelled or at_target)
        if hasattr(f,'retry_allowed'):f.retry_allowed=f.action_stopped
        f.moving_transition_supported=True;f.simulated=True
        occupied=False;clear=[]
        if self.plan and (self.plan.session_id,self.plan.goal_id)==(q.session_id,q.goal_id):
            for passage in self.plan.passages:
                e,x=passage.events[2],passage.events[3]
                if not e.point_valid or not x.point_valid:continue
                a=np.array([e.point.x,e.point.y]);b=np.array([x.point.x,x.point.y]);v=b-a;length=np.linalg.norm(v)
                if length<1e-6:continue
                u=v/length;delta=chassis_position[:2]-a;along=float(delta@u);lateral=abs(float(delta[0]*u[1]-delta[1]*u[0]))
                # Conservative square-body support along actual world directions.
                chassis_planar=Rot.from_euler('z',cyaw)
                ux=chassis_planar.apply([1.,0.,0.])[:2];uy=chassis_planar.apply([0.,1.,0.])[:2]
                radius=.30*(abs(u@ux)+abs(u@uy))+.02
                if along-radius>length:clear.append(passage.traversal_uid)
                if -radius<=along<=length+radius and lateral<.5:occupied=True
        f.cleared_traversal_uids=clear;f.whole_vehicle_clear=not occupied;f.normal_clearance=not occupied
        self.pub_feedback.publish(f)

def main():
    rclpy.init();n=SimBridge()
    try:rclpy.spin(n)
    except KeyboardInterrupt:pass
    finally:
        n.destroy_node()
        if rclpy.ok():rclpy.shutdown()
if __name__=='__main__':main()
