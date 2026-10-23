#!/usr/bin/env python3
"""连接已启动的隔离仿真：验证实际参数接口、自动旋转、正式六字母及RViz订阅。"""
import os,time,json,subprocess,math
from pathlib import Path
os.environ.update(ROS_DOMAIN_ID='187',GZ_PARTITION='slopehole_test')
import rclpy,yaml
from rclpy.node import Node
from rclpy.qos import QoSProfile,DurabilityPolicy
from std_msgs.msg import String
from sensor_msgs.msg import JointState
from geometry_msgs.msg import PoseStamped
from nav_interfaces.msg import NavigationPlan
from visualization_msgs.msg import MarkerArray,Marker
from rcl_interfaces.srv import SetParametersAtomically,GetParameters
from rcl_interfaces.msg import Parameter,ParameterValue,ParameterType
T=Path(__file__).resolve().parents[1]
rclpy.init();n=Node('verify_live_controls');n.set_parameters([rclpy.parameter.Parameter('use_sim_time',value=True)])
set_client=n.create_client(SetParametersAtomically,'/hole_runtime/set_parameters_atomically')
get_client=n.create_client(GetParameters,'/nav_server/get_parameters')
def spin(seconds):
    end=time.monotonic()+seconds
    while time.monotonic()<end:rclpy.spin_once(n,timeout_sec=.02)
def wait(future):
    end=time.monotonic()+10
    while not future.done() and time.monotonic()<end:rclpy.spin_once(n,timeout_sec=.02)
    assert future.done(),'接口回复超时'
    return future.result()
def get():
    req=GetParameters.Request();req.names=['hole_runtime.boost_speed','nmpc.max_linear_accel','nmpc.max_linear_vel']
    return [x.double_value for x in wait(get_client.call_async(req)).values]
def update(values):
    req=SetParametersAtomically.Request();req.parameters=[Parameter(name=k,value=ParameterValue(type=ParameterType.PARAMETER_DOUBLE,double_value=float(v))) for k,v in values.items()]
    return wait(set_client.call_async(req)).result
report={};old=None
try:
    assert set_client.wait_for_service(timeout_sec=10) and get_client.wait_for_service(timeout_sec=10)
    old=get();assert not update({'boost_speed':-1}).successful;assert get()==old
    assert not update({'unknown_physics_parameter':1.}).successful;assert get()==old
    assert update({'boost_speed':3.,'max_linear_accel':10.}).successful
    changed=get();assert changed[0]==3. and changed[1]==10. and changed[2]>=3.
    report.update(tuning_valid_values=changed,tuning_invalid_batch_rejected=True)
    assert update({'boost_speed':old[0],'max_linear_accel':old[1]}).successful
    rates=[];n.create_subscription(JointState,'/rotation/feedback',lambda m:rates.append(list(m.velocity)),10)
    q=QoSProfile(depth=1,durability=DurabilityPolicy.TRANSIENT_LOCAL)
    data={};n.create_subscription(NavigationPlan,'navigation_plan',lambda m:data.update(plan=m),q)
    n.create_subscription(MarkerArray,'hole_execution_markers',lambda m:data.update(markers=m),q)
    goal=n.create_publisher(PoseStamped,'goal_pose',10);spin(2.)
    assert rates and abs(sum(x[0] for x in rates)/len(rates)-math.radians(50))<.15,'默认底盘50dps未实测跟上'
    report['automatic_world_rates_dps']=[math.degrees(sum(x[i] for x in rates)/len(rates)) for i in (0,1)]
    pause=['gz','service','-s','/world/default/control','--reqtype','gz.msgs.WorldControl','--reptype','gz.msgs.Boolean','--timeout','3000','--req','pause: true']
    response=subprocess.run(pause,capture_output=True,text=True,timeout=5)
    assert response.returncode==0,'无法暂停现场用于查看字母'
    case=yaml.safe_load((T/'sim/case.yaml').read_text());target=PoseStamped();target.header.frame_id='map';target.pose.orientation.w=1.
    target.pose.position.x,target.pose.position.y=case['goal'];goal.publish(target)
    end=time.monotonic()+30
    while time.monotonic()<end:
        spin(.1)
        if data.get('plan') and data.get('markers') and data['plan'].passages:
            current=data['plan'];markers=data['markers'].markers
            letters=[m.text for m in markers if m.type==Marker.TEXT_VIEW_FACING and len(m.text)==1]
            caption=any(m.text.startswith(f'plan={current.plan_id} ') for m in markers)
            if caption and letters==list('ASEXTD')*len(current.passages):break
    assert data.get('plan') and data['plan'].passages,'未取得实际规划过洞计划'
    letters=[m.text for m in data['markers'].markers if m.type==Marker.TEXT_VIEW_FACING and len(m.text)==1]
    count=len(data['plan'].passages);assert letters==list('ASEXTD')*count,letters
    subscribers=[s.node_name for s in n.get_subscriptions_info_by_topic('/hole_execution_markers')]
    assert any('rviz' in name for name in subscribers),'RViz没有订阅六点话题'
    report.update(passages=[p.hole_id for p in data['plan'].passages],letters=letters,rviz_subscribers=subscribers)
    report['result']='PASS';print(json.dumps(report,ensure_ascii=False,indent=2))
finally:
    if old is not None:
        try:update({'boost_speed':old[0],'max_linear_accel':old[1]})
        except Exception:pass
    (T/'results/live_controls.json').write_text(json.dumps(report,ensure_ascii=False,indent=2))
    n.destroy_node();rclpy.try_shutdown()
