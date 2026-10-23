#!/usr/bin/env python3
"""无GUI验收：实际键盘接口运动和在线参数保存，保留用户已有调参文件。"""
from pathlib import Path
import os,time,signal,subprocess,json,math
os.environ.update(ROS_DOMAIN_ID='187',GZ_PARTITION='slopehole_test',OMP_NUM_THREADS='1')
import rclpy,yaml
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data
from std_msgs.msg import String,Bool
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry
from rcl_interfaces.srv import SetParametersAtomically
from rcl_interfaces.msg import Parameter,ParameterValue,ParameterType
T=Path(__file__).resolve().parents[1]
saved=T/'sim/runtime_tuning.yaml';backup=saved.read_bytes() if saved.exists() else None
out=(T/'logs/manual_controls_world.log').open('w')
p=subprocess.Popen(['/usr/bin/python3',str(T/'scripts/run_case.py'),'--case','demo','--manual','--max-wall','50'],stdout=out,stderr=subprocess.STDOUT,start_new_session=True)
result={'result':'FAIL'};n=None
try:
    rclpy.init();n=Node('verify_manual_controls')
    n.set_parameters([rclpy.parameter.Parameter('use_sim_time',value=True)])
    data={};n.create_subscription(Odometry,'/Odometry',lambda m:data.update(pose=m),qos_profile_sensor_data)
    cmd=n.create_publisher(Twist,'/keyboard/cmd_vel_gimbal',10);mode=n.create_publisher(String,'/control_mode',10);stop=n.create_publisher(Bool,'/rotation/stop',10)
    service=n.create_client(SetParametersAtomically,'/hole_runtime/set_parameters_atomically')
    def step(seconds,command=None):
        end=time.monotonic()+seconds
        while time.monotonic()<end:
            if command is not None:cmd.publish(command)
            rclpy.spin_once(n,timeout_sec=.02)
            assert p.poll() is None,'仿真提前结束'
    assert service.wait_for_service(timeout_sec=25),'未找到在线调参接口'
    step(1.);assert 'pose' in data
    mode.publish(String(data='keyboard'));step(.8,Twist())
    a=data['pose'].pose.pose.position;start=(a.x,a.y)
    moving=Twist();moving.linear.x=.3;step(3.,moving);step(1.,Twist())
    b=data['pose'].pose.pose.position;distance=math.hypot(b.x-start[0],b.y-start[1]);assert distance>.3,distance
    req=SetParametersAtomically.Request();req.parameters=[Parameter(name='save',value=ParameterValue(type=ParameterType.PARAMETER_BOOL,bool_value=True))]
    future=service.call_async(req)
    end=time.monotonic()+5
    while not future.done() and time.monotonic()<end:step(.05,Twist())
    assert future.done() and future.result().result.successful,'保存接口失败'
    record=yaml.safe_load(saved.read_text());assert record['boost_speed']>0 and record['max_linear_accel']>0
    stop.publish(Bool(data=True));mode.publish(String(data='navigation'));step(.3,Twist())
    result.update(result='PASS',keyboard_translation_m=distance,explicit_save_verified=True)
except Exception as e:result['error']=str(e)
finally:
    if p.poll() is None:os.killpg(p.pid,signal.SIGINT)
    try:p.wait(timeout=10)
    except subprocess.TimeoutExpired:os.killpg(p.pid,signal.SIGKILL);p.wait()
    if backup is None:saved.unlink(missing_ok=True)
    else:saved.write_bytes(backup)
    if n:n.destroy_node()
    if rclpy.ok():rclpy.shutdown()
    out.close();(T/'results/manual_controls_smoke.json').write_text(json.dumps(result,indent=2));print(result,flush=True)
raise SystemExit(0 if result['result']=='PASS' else 1)
