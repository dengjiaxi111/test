#!/usr/bin/env python3
"""有界无图形物理验收：原平移链＋旋转/停转＋新增TF。不会运行GPU传感器。"""
from pathlib import Path
import os,subprocess,time,signal,json,resource,fcntl,math
import numpy as np
from scipy.spatial.transform import Rotation as Rot
import rclpy
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data
from nav_msgs.msg import Odometry
from sensor_msgs.msg import JointState
from geometry_msgs.msg import Twist
from std_msgs.msg import Float64,Bool
from tf2_ros import Buffer,TransformListener

T=Path(__file__).resolve().parents[1]
lock=(T/'.run.lock').open('w');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
os.environ.update(ROS_DOMAIN_ID='187',GZ_PARTITION='slopehole_test',GZ_LOG_PATH=str(T/'logs/gazebo'),ROS_LOG_DIR=str(T/'logs/ros'),OMP_NUM_THREADS='1',OPENBLAS_NUM_THREADS='1')
procs=[];logs=[]
def start(cmd,name):
    out=(T/'logs'/('rotation_'+name+'.log')).open('w');logs.append(out)
    def limit():
        os.nice(10);resource.setrlimit(resource.RLIMIT_AS,(2500*1024**2,2500*1024**2));resource.setrlimit(resource.RLIMIT_CORE,(0,0))
    p=subprocess.Popen(cmd,cwd=T,stdout=out,stderr=subprocess.STDOUT,start_new_session=True,preexec_fn=limit);procs.append(p)

class Probe(Node):
    def __init__(self):
        super().__init__('rotation_probe');self.set_parameters([rclpy.parameter.Parameter('use_sim_time',value=True)])
        self.odom=None;self.feedback=None;self.stopped=False;self.samples=[];self.phase='warmup'
        self.create_subscription(Odometry,'/wheel/odometry',lambda m:setattr(self,'odom',m),qos_profile_sensor_data)
        self.create_subscription(JointState,'/rotation/feedback',self.on_feedback,10)
        self.create_subscription(Bool,'/rotation/stopped',lambda m:setattr(self,'stopped',m.data),10)
        self.cmd=self.create_publisher(Twist,'/cmd_vel',10)
        self.spin=self.create_publisher(Float64,'/rotation/world_yaw_rate',10)
        self.stop=self.create_publisher(Bool,'/rotation/stop',10)
        self.align=self.create_publisher(Float64,'/hole_alignment_target',10)
        self.tf=Buffer();self.listener=TransformListener(self.tf,self)
    def on_feedback(self,m):
        self.feedback=m
        if self.odom:
            p=self.odom.pose.pose.position
            self.samples.append(dict(phase=self.phase,t=self.get_clock().now().nanoseconds*1e-9,x=p.x,y=p.y,rates=list(m.velocity),yaw=list(m.position)))
    def step(self,seconds,velocity=0.,spin=0.,stop=None,alignment=None):
        end=time.monotonic()+seconds
        while time.monotonic()<end:
            cmd=Twist();cmd.linear.x=velocity;self.cmd.publish(cmd)
            self.spin.publish(Float64(data=spin))
            if stop is not None:self.stop.publish(Bool(data=stop))
            if alignment is not None:self.align.publish(Float64(data=alignment))
            rclpy.spin_once(self,timeout_sec=.02)
            assert all(p.poll() is None for p in procs),'仿真子进程退出'
            pending=[p.pid for p in procs];seen=set();rss=0
            while pending:
                pid=pending.pop()
                if pid in seen:continue
                seen.add(pid)
                try:
                    rss+=int(Path(f'/proc/{pid}/statm').read_text().split()[1])*os.sysconf('SC_PAGE_SIZE')
                    pending.extend(map(int,Path(f'/proc/{pid}/task/{pid}/children').read_text().split()))
                except (OSError,ValueError,IndexError):pass
            assert rss<3*1024**3,'本组进程驻留内存超过3GiB'

result={'result':'FAIL'};n=None
try:
    start(['gz','sim','-s','-r',str(T/'sim/flat.sdf')],'gazebo')
    start(['/opt/ros/jazzy/lib/ros_gz_bridge/parameter_bridge','--ros-args','-p','config_file:='+str(T/'sim/bridge.yaml'),'-p','use_sim_time:=true'],'ros')
    start([str(T.parent/'navigatiosim2/install/seu_sentry_sim_control/lib/seu_sentry_sim_control/swerve_sim_controller_node'),'--ros-args','--params-file',str(T.parent/'navigatiosim2/src/seu_sentry_sim_control/config/swerve_sim_controller.yaml'),'-p','use_sim_time:=true'],'swerve')
    start(['/usr/bin/python3',str(T/'sim/sim_bridge.py'),'--ros-args','-p','use_sim_time:=true'],'adapter')
    start(['/usr/bin/python3',str(T/'sim/original_fake_bridge.py'),'--ros-args','-p','use_sim_time:=true'],'fake')
    start(['/usr/bin/python3',str(T/'sim/navigation_to_chassis.py'),'--ros-args','-p','use_sim_time:=true','-p','input_frame:=base_link_fake','-p','input_topic:=/cmd_vel'],'conversion')
    rclpy.init();n=Probe();n.step(7)
    assert n.feedback is not None and n.odom is not None,'缺实际关节/底盘反馈'
    n.phase='spin_translate';n.step(6,velocity=.3,spin=.35,stop=False)
    moving=[p for p in n.samples if p['phase']=='spin_translate']
    assert moving[-1]['x']-moving[0]['x']>.4,'旋转时没有沿原平移方向行走'
    assert abs(moving[-1]['y']-moving[0]['y'])<.25,'旋转时横向漂移过大'
    yaw_change=float(np.unwrap([s['yaw'][0] for s in moving])[-1]-np.unwrap([s['yaw'][0] for s in moving])[0])
    assert abs(yaw_change)>.2,'底盘未实际旋转'
    active=[s for s in moving[len(moving)//2:] if abs(s['rates'][0])>.05]
    assert active,'未取得有效旋转反馈'
    rate_error=float(np.median([abs(s['rates'][0]+s['rates'][1]) for s in active]))
    assert rate_error<.1,f'地面反向同速误差过大:{rate_error}'
    n.phase='stop_translate';n.step(5,velocity=.3,stop=True)
    stopped=[p for p in n.samples if p['phase']=='stop_translate']
    assert n.stopped and max(map(abs,n.feedback.velocity))<.03,'未收到实际稳定停转反馈'
    assert stopped[-1]['x']-stopped[0]['x']>.3,'停转命令错误地停止了导航平移'
    n.phase='align';n.step(6,alignment=0.,stop=False)
    assert abs(math.remainder(n.feedback.position[0],2*math.pi))<.05,'底盘未完成朝向对准'
    assert n.stopped,'对准后未确认停转'
    for child,expected_yaw in [('base_link_fake',0.),('chassiss',n.feedback.position[0])]:
        tf=n.tf.lookup_transform('odom',child,rclpy.time.Time());q=tf.transform.rotation
        roll,pitch,yaw=Rot.from_quat([q.x,q.y,q.z,q.w]).as_euler('xyz')
        assert max(abs(roll),abs(pitch))<1e-5,child+'未保持水平'
        assert abs(math.remainder(yaw-expected_yaw,2*math.pi))<.01,child+'朝向不符'
    result.update(result='PASS',spin_translation_m=moving[-1]['x']-moving[0]['x'],lateral_drift_m=moving[-1]['y']-moving[0]['y'],chassis_yaw_change_rad=yaw_change,opposite_rate_error_rad_s=rate_error,stop_feedback=True,alignment_feedback=True,original_fake_and_new_chassiss=True)
except Exception as exc:
    result['error']=str(exc)
finally:
    if n:result['trace']=n.samples
    (T/'results/rotation_smoke.json').write_text(json.dumps(result,indent=2))
    if rclpy.ok():rclpy.shutdown()
    for p in reversed(procs):
        if p.poll() is None:os.killpg(p.pid,signal.SIGINT)
    for p in procs:
        try:p.wait(timeout=5)
        except subprocess.TimeoutExpired:os.killpg(p.pid,signal.SIGKILL);p.wait()
    for f in logs:f.close()
print({k:v for k,v in result.items() if k!='trace'},flush=True)
raise SystemExit(0 if result['result']=='PASS' else 1)
