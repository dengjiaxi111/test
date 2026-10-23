#!/usr/bin/env python3
"""有界物理测试：真舵轮移动、实测升降到位。进程一律在finally结束。"""
from pathlib import Path
import os,sys,subprocess,time,signal,json,resource,argparse,fcntl
import xml.etree.ElementTree as ET
import rclpy
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry
from sensor_msgs.msg import JointState
from nav_interfaces.msg import HoleStructureRequest as Request,HoleStructureFeedback as Feedback
from model_selection import select_model
from runtime_support import ProcessSupervisor
T=Path(__file__).resolve().parents[1]
parser=argparse.ArgumentParser();parser.add_argument('--model',type=int,choices=(1,2,3),default=2);args=parser.parse_args()
choice=select_model(args.model)
lock=(T/'.run.lock').open('w');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
subprocess.run([sys.executable,str(T/'scripts/generate_world.py'),'--case','demo','--model-sdf',str(choice.path)],check=True)
world=ET.parse(T/'sim/flat.sdf');world.getroot().find('world/include/uri').text=str(choice.path)
world.write(T/'sim/model_smoke.sdf',encoding='unicode',xml_declaration=True)
os.environ.update(ROS_DOMAIN_ID='187',GZ_PARTITION='slopehole_test',GZ_LOG_PATH=str(T/'logs/gazebo'),ROS_LOG_DIR=str(T/'logs/ros'),OMP_NUM_THREADS='1')
procs=[];logs=[];supervisor=ProcessSupervisor()
def start(args,name):
    f=(T/'logs'/name).open('w');logs.append(f)
    def limit():
        os.nice(10);resource.setrlimit(resource.RLIMIT_AS,(2200*1024**2,2200*1024**2))
    p=subprocess.Popen(args,cwd=T,stdout=f,stderr=subprocess.STDOUT,start_new_session=True,preexec_fn=limit);procs.append(p);supervisor.track(p);return p
class Probe(Node):
    def __init__(self):
        super().__init__('model_probe');self.set_parameters([rclpy.parameter.Parameter('use_sim_time',value=True)])
        self.odom=None;self.feedback=None;self.joints={}
        self.create_subscription(JointState,"/joint_states",lambda m:setattr(self,"joints",dict(zip(m.name,m.position))),qos_profile_sensor_data)
        self.create_subscription(Odometry,'/wheel/odometry',lambda m:setattr(self,'odom',m),qos_profile_sensor_data)
        self.create_subscription(Feedback,'hole_structure/feedback',lambda m:setattr(self,'feedback',m),10)
        self.request=self.create_publisher(Request,'hole_structure/request',10);self.cmd=self.create_publisher(Twist,'/cmd_vel',10)
    def step(self,seconds,command=None,request=None):
        end=time.monotonic()+seconds
        while time.monotonic()<end:
            if command:self.cmd.publish(command)
            if request:self.request.publish(request)
            rclpy.spin_once(self,timeout_sec=.02)
try:
    start(['gz','sim','-s','-r',str(T/'sim/model_smoke.sdf')],'model_gazebo.log')
    start(['/opt/ros/jazzy/lib/ros_gz_bridge/parameter_bridge','--ros-args','-p','config_file:='+str(T/'sim/bridge.yaml'),'-p','use_sim_time:=true'],'model_ros_bridge.log')
    swerve=T.parent/'navigatiosim2/install/seu_sentry_sim_control/lib/seu_sentry_sim_control/swerve_sim_controller_node'
    cfg=T.parent/'navigatiosim2/src/seu_sentry_sim_control/config/swerve_sim_controller.yaml'
    start([str(swerve),'--ros-args','--params-file',str(cfg),'-p','use_sim_time:=true'],'model_swerve.log')
    start(['/usr/bin/python3',str(T/'sim/sim_bridge.py'),'--ros-args','-p','use_sim_time:=true','-p','model_sdf:='+str(choice.path)],'model_adapter.log')
    start(['/usr/bin/python3',str(T/'sim/original_fake_bridge.py'),'--ros-args','-p','use_sim_time:=true'],'model_fake.log')
    start(['/usr/bin/python3',str(T/'sim/navigation_to_chassis.py'),'--ros-args','-p','use_sim_time:=true','-p','input_frame:=base_link_fake','-p','input_topic:=/cmd_vel'],'model_conversion.log')
    rclpy.init();n=Probe();n.step(8.)
    assert n.odom is not None,'无Gazebo里程计'
    start_pos=(n.odom.pose.pose.position.x,n.odom.pose.pose.position.y)
    q=Request();q.session_id='model_smoke';q.goal_id='smoke';q.request_id=1;q.requirement_revision=1;q.target=q.LOW
    n.step(4.,request=q)
    assert n.feedback is not None,'无关节动作反馈'
    if choice.has_lift:assert n.feedback.status==n.feedback.COMPLETED,'下降未实测完成'
    else:assert n.feedback.status==n.feedback.FAILED and n.feedback.fault_code==2 and not n.feedback.retry_allowed,'无升降模型错误确认低姿态'
    cmd=Twist();cmd.linear.x=.35;n.step(3.,command=cmd,request=q)
    n.step(1.,command=Twist(),request=q)
    distance=((n.odom.pose.pose.position.x-start_pos[0])**2+(n.odom.pose.pose.position.y-start_pos[1])**2)**.5
    assert distance>.4,f'舵轮未有效移动：{distance}'
    q.request_id=2;q.target=q.NORMAL;n.step(6.,request=q)
    print('final feedback',n.feedback,'joints',n.joints,flush=True)
    assert n.feedback.request_id==2,'恢复请求反馈编号错误'
    if choice.has_lift:assert n.feedback.status==n.feedback.COMPLETED,'恢复未实测完成'
    else:assert n.feedback.status==n.feedback.FAILED and n.feedback.fault_code==2,'无升降模型错误确认恢复完成'
    result={'result':'PASS','model':args.model,'wheel_distance_m':distance,'low_and_normal_joint_feedback':choice.has_lift,'unsupported_structure_request':not choice.has_lift}
    (T/'results/model_smoke.json').write_text(json.dumps(result,indent=2))
    (T/'results'/f'model_{args.model}_smoke.json').write_text(json.dumps(result,indent=2));print(result)
finally:
    if rclpy.ok():rclpy.shutdown()
    remaining=supervisor.cleanup()
    for f in logs:f.close()
    assert not remaining,f'残留进程：{remaining}'
