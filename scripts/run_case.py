#!/usr/bin/env python3
"""有界导航闭环；测试副本NavServer + 真实Gazebo舵轮/升降，原算法不启动。"""
from pathlib import Path
import os,subprocess,time,signal,json,resource,argparse,yaml,math,fcntl
import rclpy
from scipy.spatial.transform import Rotation
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data,QoSProfile,DurabilityPolicy
from rclpy.action import ActionClient
from nav_msgs.msg import Odometry
from sensor_msgs.msg import JointState
from geometry_msgs.msg import Twist,PoseStamped
from std_msgs.msg import Bool
from visualization_msgs.msg import MarkerArray,Marker
from nav_interfaces.action import Navigate
from nav_interfaces.msg import NavigationPlan,HoleTraversalState,HoleTraversalEvent
T=Path(__file__).resolve().parents[1]
parser=argparse.ArgumentParser();parser.add_argument('--case',default='upper',choices=['single','upper','lower','long','crest']);parser.add_argument('--max-wall',type=float,default=180.);parser.add_argument('--hold-open',action='store_true');parser.add_argument('--gui',action='store_true');parser.add_argument('--to-crest',action='store_true');parser.add_argument('--manual',action='store_true');parser.add_argument('--topic-goal',action='store_true');parser.add_argument('--baseline',action='store_true');parser.add_argument('--uphill-speed',type=float,default=2.);parser.add_argument('--stop-on-hold',action='store_true');parser.add_argument('--render',choices=['software','nvidia'],default='software');args=parser.parse_args()
lock=(T/'.run.lock').open('w');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
os.environ.update(ROS_DOMAIN_ID='187',GZ_PARTITION='slopehole_test',GZ_LOG_PATH=str(T/'logs/gazebo'),ROS_LOG_DIR=str(T/'logs/ros'),OMP_NUM_THREADS='1',OPENBLAS_NUM_THREADS='1')
if args.gui and args.render=='software':os.environ.update(LIBGL_ALWAYS_SOFTWARE='1',GALLIUM_DRIVER='llvmpipe',__GLX_VENDOR_LIBRARY_NAME='mesa',QT_QUICK_BACKEND='opengl',QSG_RENDER_LOOP='basic',LP_NUM_THREADS='2',MALLOC_ARENA_MAX='2',GSETTINGS_BACKEND='memory',QT_QPA_PLATFORMTHEME='')
if args.gui and args.render=='nvidia':
    for key in ('LIBGL_ALWAYS_SOFTWARE','GALLIUM_DRIVER','MESA_LOADER_DRIVER_OVERRIDE','QT_QUICK_BACKEND','__EGL_VENDOR_LIBRARY_FILENAMES'):
        os.environ.pop(key,None)
    os.environ.update(__GLX_VENDOR_LIBRARY_NAME='nvidia',__NV_PRIME_RENDER_OFFLOAD='1',__VK_LAYER_NV_optimus='NVIDIA_only',QSG_RENDER_LOOP='basic',MALLOC_ARENA_MAX='2')
subprocess.run(['/usr/bin/python3',str(T/'scripts/generate_world.py'),'--case',args.case,'--uphill-speed',str(args.uphill_speed),*(['--baseline'] if args.baseline else [])],check=True)
case=yaml.safe_load((T/'sim/case.yaml').read_text());procs=[];logs=[]
def start(cmd,name):
    f=(T/'logs'/f'{args.case}_{name}.log').open('w');logs.append(f)
    def limit():
        os.nice(10)
        # NVIDIA maps GPU virtual memory: an AS cap can prevent GL startup.
        # Bound resident memory in the supervisor instead of GPU address space.
        if not (name in ('gui','rviz') and args.render=='nvidia'):
            cap=(6000 if name in ('gui','rviz') else 2500)*1024**2
            resource.setrlimit(resource.RLIMIT_AS,(cap,cap))
        resource.setrlimit(resource.RLIMIT_CORE,(0,0))
    p=subprocess.Popen(cmd,cwd=T,stdout=f,stderr=subprocess.STDOUT,start_new_session=True,preexec_fn=limit);procs.append(p);return p
class Probe(Node):
    def __init__(self):
        super().__init__('execution_probe');self.set_parameters([rclpy.parameter.Parameter('use_sim_time',value=True)])
        self.plan=None;self.state=None;self.pose=None;self.joints={};self.events=[];self.transitions=[];self.trace=[];self.last_trace=-1.;self.command=Twist();self.plans=[];self.markers=None
        self.rotation=None;self.rotation_stopped=False
        self.action=ActionClient(self,Navigate,'navigate');q=QoSProfile(depth=1,durability=DurabilityPolicy.TRANSIENT_LOCAL)
        self.create_subscription(NavigationPlan,'navigation_plan',self.on_plan,q)
        self.create_subscription(MarkerArray,'hole_execution_markers',lambda m:setattr(self,'markers',m),q)
        self.create_subscription(HoleTraversalState,'hole_traversal_state',self.on_state,10)
        self.create_subscription(HoleTraversalEvent,'hole_traversal_event',self.on_event,10)
        self.create_subscription(Odometry,'/Odometry',self.on_pose,qos_profile_sensor_data)
        self.create_subscription(Twist,'/cmd_vel',lambda m:setattr(self,'command',m),10)
        self.create_subscription(JointState,'/joint_states',lambda m:setattr(self,'joints',dict(zip(m.name,m.position))),qos_profile_sensor_data)
        self.create_subscription(JointState,'/rotation/feedback',lambda m:setattr(self,'rotation',m),10)
        self.create_subscription(Bool,'/rotation/stopped',lambda m:setattr(self,'rotation_stopped',m.data),10)
    def on_plan(self,m):
        self.plan=m;print('PLAN',m.plan_id,m.status,[(p.hole_id,p.uphill_entry) for p in m.passages],flush=True)
        self.plans.append(dict(id=m.plan_id,status=m.status,length=m.path_length,passages=[dict(uid=p.traversal_uid,hole=p.hole_id,uphill=p.uphill_entry,events=[dict(type=e.type,arc=e.s_path,range=e.range_status,x=e.point.x,y=e.point.y) for e in p.events]) for p in m.passages]))
    def on_state(self,m):
        old=self.state;self.state=m
        key=lambda s:(s.state,s.decision,s.reason,s.attempt,s.recovery_phase)
        if old is None or key(old)!=key(m):
            self.transitions.append(dict(t=self.get_clock().now().nanoseconds*1e-9,state=m.state,decision=m.decision,reason=m.reason,attempt=m.attempt,recovery=m.recovery_phase))
            print('STATE',self.transitions[-1],flush=True)
    def on_event(self,m):
        self.events.append(dict(uid=m.traversal_uid,type=m.type,sequence=m.sequence,attempt=m.attempt,arc=m.event_arc,progress=m.progress,lift=self.joints.get('lift_joint'),rotation_rates=list(self.rotation.velocity) if self.rotation else None,rotation_stopped=self.rotation_stopped))
        print('EVENT',self.events[-1],flush=True)
    def on_pose(self,m):
        self.pose=m;t=self.get_clock().now().nanoseconds*1e-9
        if t-self.last_trace>=.1:
            q=m.pose.pose.orientation;roll,pitch,yaw=Rotation.from_quat([q.x,q.y,q.z,q.w]).as_euler('xyz')
            self.last_trace=t;self.trace.append(dict(t=t,x=m.pose.pose.position.x,y=m.pose.pose.position.y,z=m.pose.pose.position.z,lift=self.joints.get('lift_joint'),roll=roll,pitch=pitch,yaw=yaw,vx=m.twist.twist.linear.x,vy=m.twist.twist.linear.y,command_x=self.command.linear.x,command_y=self.command.linear.y,progress=self.state.s_progress if self.state else None,limit=self.state.speed_limit if self.state else None))
            self.trace[-1].update(chassis_yaw=self.rotation.position[0] if self.rotation else None,rotation_rates=list(self.rotation.velocity) if self.rotation else None,rotation_stopped=self.rotation_stopped)
    def spin(self,seconds):
        end=time.monotonic()+seconds
        while time.monotonic()<end:rclpy.spin_once(self,timeout_sec=.02)
        # Sum this launch's descendants only; no changes to other applications.
        pending=[p.pid for p in procs if p.poll() is None];seen=set();rss=0
        while pending:
            pid=pending.pop()
            if pid in seen:continue
            seen.add(pid)
            try:
                rss+=int(Path(f'/proc/{pid}/statm').read_text().split()[1])*os.sysconf('SC_PAGE_SIZE')
                pending.extend(map(int,Path(f'/proc/{pid}/task/{pid}/children').read_text().split()))
            except (OSError,IndexError,ValueError):pass
        if rss>3*1024**3:raise RuntimeError('本次仿真驻留内存超过3GiB，停止本组进程')
result={'case':args.case,'result':'FAIL'};n=None;goal_handle=None
try:
    start(['gz','sim','-s','-r',str(T/'sim'/f'{args.case}.sdf')],'gazebo')
    start(['/opt/ros/jazzy/lib/ros_gz_bridge/parameter_bridge','--ros-args','-p','config_file:='+str(T/'sim/bridge.yaml'),'-p','use_sim_time:=true'],'ros_bridge')
    start([str(T.parent/'navigatiosim2/install/seu_sentry_sim_control/lib/seu_sentry_sim_control/swerve_sim_controller_node'),'--ros-args','--params-file',str(T.parent/'navigatiosim2/src/seu_sentry_sim_control/config/swerve_sim_controller.yaml'),'-p','use_sim_time:=true'],'swerve')
    start(['/usr/bin/python3',str(T/'sim/sim_bridge.py'),'--ros-args','-p','use_sim_time:=true',*sum((['-p',f'world_offset_{axis}:={value}'] for axis,value in zip(('x','y','z'),case['world_offset'])),[])],'adapter')
    start(['/usr/bin/python3',str(T/'sim/original_fake_bridge.py'),'--ros-args','-p','use_sim_time:=true','-p','odom_timeout:=0.5','-p','feedback_timeout:=0.5','-p','feedback_pose_max_skew:=0.35'],'fake')
    start(['/usr/bin/python3',str(T/'sim/navigation_to_chassis.py'),'--ros-args','-p','use_sim_time:=true','-p','input_frame:=base_link_fake','-p','input_topic:=/cmd_vel'],'conversion')
    start(['/usr/bin/python3',str(T/'sim/plan_markers.py'),'--ros-args','-p','use_sim_time:=true'],'markers')
    if args.gui:
        start(['gz','sim','-g','--gui-config',str(T/'sim'/('nvidia_gui.config' if args.render=='nvidia' else 'demo_gui.config'))],'gui')
        start(['/opt/ros/jazzy/lib/rviz2/rviz2','-d',str(T/'sim/crest.rviz'),'--ros-args','-p','use_sim_time:=true'],'rviz')
    rclpy.init();n=Probe();n.spin(8)
    assert n.pose is not None,'无Gazebo真值位姿'
    assert all(p.poll() is None for p in procs),'场景或显示进程启动失败'
    start([str(T/'install/nav_components/lib/nav_components/nav_server'),'--ros-args','--params-file',str(T/'sim/nav_params.yaml')],'nav_server')
    assert n.action.wait_for_server(timeout_sec=20.),'NavServer action不可用'
    n.spin(2.)  # Allow original odometry/TF subscriptions to match before the first goal.
    if args.manual:
        result['result']='MANUAL_SESSION'
        print('READY: RViz顶部 2D Goal Pose 选择目标；当前起点=(4.694,5.000)，推荐单洞目标=(4.694,7.604)。Ctrl+C关闭本组进程。',flush=True)
        deadline=time.monotonic()+args.max_wall
        while time.monotonic()<deadline:
            n.spin(.1)
            if any(p.poll() is not None for p in procs):
                print('一个窗口或子进程已退出，关闭本组演示。',flush=True);break
        raise SystemExit(0)
    goal=Navigate.Goal();goal.goal_pose.header.frame_id='map';goal.goal_pose.pose.position.x=case['goal'][0];goal.goal_pose.pose.position.y=case['goal'][1];goal.goal_pose.pose.orientation.w=1.
    if args.topic_goal:
        target_pub=n.create_publisher(PoseStamped,'goal_pose',10);n.spin(.5)
        target_pub.publish(goal.goal_pose)
        def finished():
            if args.baseline:
                log=(T/'logs'/f'{args.case}_nav_server.log').read_text(errors='replace')
                return '导航成功' in log or '导航失败' in log
            return n.plan is not None and n.plan.status in (NavigationPlan.COMPLETED,NavigationPlan.FAILED,NavigationPlan.CANCELLED)
    else:
        future=n.action.send_goal_async(goal)
        response_deadline=time.monotonic()+10.
        while not future.done() and time.monotonic()<response_deadline:n.spin(.05)
        assert future.done(),'目标接收确认超时'
        goal_handle=future.result();assert goal_handle.accepted,'目标被拒绝';done=goal_handle.get_result_async()
        finished=done.done
    deadline=time.monotonic()+args.max_wall
    paused=False
    while not finished() and time.monotonic()<deadline:
        n.spin(.1)
        if args.stop_on_hold and n.state and n.state.state==4:raise RuntimeError('诊断停止于首次HOLD: '+n.state.reason)
        if args.to_crest and n.state and n.plan:
            crests=[r.s_begin for r in n.plan.speed_regions if r.kind==4]
            reached=bool(crests) and n.state.s_progress>=min(crests)
            if reached or n.state.state==4:
                subprocess.run(['gz','service','-s','/world/default/control','--reqtype','gz.msgs.WorldControl','--reptype','gz.msgs.Boolean','--timeout','3000','--req','pause: true'],timeout=5,check=True)
                result['result']='DEMO_PAUSED';result['pause_reason']='crest reached' if reached else n.state.reason;paused=True;break
        if any(p.poll() is not None for p in procs):raise RuntimeError('子进程提前退出，请查看日志')
    if paused:
        print('DEMO PAUSED:',result['pause_reason'],'; windows remain open for inspection',flush=True)
        result.update(plans=n.plans,events=n.events,transitions=n.transitions,trace=n.trace)
        (T/'results'/f'{args.case}{"_baseline" if args.baseline else ""}.json').write_text(json.dumps(result,indent=2))
        end=time.monotonic()+600.
        while args.hold_open and time.monotonic()<end and all(p.poll() is None for p in procs):n.spin(.1)
        raise SystemExit(0)
    assert finished(),'闭环测试墙钟时间到期'
    if args.topic_goal:
        if args.baseline:
            result['action_success']='导航成功' in (T/'logs'/f'{args.case}_nav_server.log').read_text(errors='replace');result['message']='original navigation baseline'
        else:result['action_success']=n.plan.status==NavigationPlan.COMPLETED;result['message']=n.plan.reason
    else:
        response=done.result();result['action_success']=response.result.success;result['message']=response.result.message
    assert result['action_success'],result['message']
    n.spin(.3)
    result['visible_event_points']=sum(m.type==Marker.SPHERE and m.action==Marker.ADD for m in n.markers.markers) if n.markers else 0
    if not args.baseline:assert result['visible_event_points']>=6,'未收到六点Marker显示'
    needed=1 if args.case in ('single','crest') else 2
    entered={e['uid'] for e in n.events if e['type']==2};exited={e['uid'] for e in n.events if e['type']==3}
    if not args.baseline:assert len(entered)>=needed and entered<=exited,'通行事件不完整'
    assert all(e['lift'] is not None and e['lift']<.008 for e in n.events if e['type']==2),'未低姿态就进入'
    result['result']='PASS'
except KeyboardInterrupt:
    print('收到Ctrl+C，关闭本组仿真进程。',flush=True)
except Exception as exc:
    result['error']=str(exc);print('FAIL',str(exc),flush=True)
finally:
    if n:
        result.update(plans=n.plans,events=n.events,transitions=n.transitions,trace=n.trace)
        result['visible_event_points']=sum(m.type==Marker.SPHERE and m.action==Marker.ADD for m in n.markers.markers) if n.markers else 0
        if goal_handle and not result.get('action_success'):
            try:goal_handle.cancel_goal_async();n.spin(.3)
            except Exception:pass
    (T/'results'/f'{args.case}{"_baseline" if args.baseline else ""}.json').write_text(json.dumps(result,indent=2))
    if rclpy.ok():rclpy.shutdown()
    for p in reversed(procs):
        if p.poll() is None:os.killpg(p.pid,signal.SIGINT)
    for p in procs:
        try:p.wait(timeout=5)
        except subprocess.TimeoutExpired:os.killpg(p.pid,signal.SIGKILL);p.wait()
    for f in logs:f.close()
print(result['result'],result.get('error',''),flush=True)
sys_exit=0 if result['result']=='PASS' else 1
raise SystemExit(sys_exit)
