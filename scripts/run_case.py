#!/usr/bin/env python3
"""有界导航闭环；测试副本NavServer + 真实Gazebo舵轮/升降，原算法不启动。"""
from pathlib import Path
import os,subprocess,time,signal,json,resource,argparse,yaml,math,fcntl,sys,hashlib
import rclpy
from scipy.spatial.transform import Rotation
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data,QoSProfile,DurabilityPolicy
from rclpy.action import ActionClient
from nav_msgs.msg import Odometry
from sensor_msgs.msg import JointState
from geometry_msgs.msg import Twist,PoseStamped
from std_msgs.msg import Bool,String
from visualization_msgs.msg import MarkerArray,Marker
from nav_interfaces.action import Navigate
from nav_interfaces.msg import NavigationPlan,HoleTraversalState,HoleTraversalEvent
from nav_interfaces.msg import HoleStructureRequest,HoleStructureFeedback
from runtime_support import RuntimeLogs,ProcessSupervisor
from model_selection import select_model
T=Path(__file__).resolve().parents[1]
parser=argparse.ArgumentParser();parser.add_argument('--case',default='upper',choices=['single','upper','upper_approach','lower','long','crest','demo','flat_nav']);parser.add_argument('--max-wall',type=float,default=180.);parser.add_argument('--hold-open',action='store_true');parser.add_argument('--gui',action='store_true');parser.add_argument('--to-crest',action='store_true');parser.add_argument('--manual',action='store_true');parser.add_argument('--topic-goal',action='store_true');parser.add_argument('--baseline',action='store_true');parser.add_argument('--boost-speed','--uphill-speed',dest='boost_speed',type=float,default=None);parser.add_argument('--stop-on-hold',action='store_true');parser.add_argument('--render',choices=['software','nvidia'],default='software')
models=parser.add_mutually_exclusive_group()
models.add_argument('--model',type=int,choices=(1,2,3),help='1原模型 / 2大底盘原云台 / 3简化模型；默认2')
models.add_argument('--model-sdf',type=Path,help='兼容已有自定义SDF入口')
parser.add_argument('--diagnostic-contacts',action='store_true',help='记录真实碰撞接触；使用临时模型副本，不改变控制')
args=parser.parse_args()
selected_model=select_model(args.model,args.model_sdf,interactive=sys.stdin.isatty())
args.model_sdf=selected_model.path
bridge_path=T/'sim/bridge.yaml';contact_topics=[]
if args.diagnostic_contacts:
    from contact_diagnostics import prepare_contacts
    args.model_sdf,bridge_path,contact_topics=prepare_contacts(args.model_sdf)
args.baseline=args.baseline or not selected_model.has_lift
print(f'已选模型 {selected_model.number or "自定义"}：{selected_model.label}',flush=True)
if not selected_model.has_lift:print('该模型无升降机构：自动关闭坡洞状态机，仅进行运动对照。',flush=True)
lock=(T/'.run.lock').open('w');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
supervisor=ProcessSupervisor();console=None
runtime_logs=RuntimeLogs(echo=lambda:console is None or console.logs_only)
# SIGTERM（例如终端关闭）走同一finally；Ctrl+C仍由Python/ROS正常中断处理。
def request_shutdown(signum,frame):raise KeyboardInterrupt
signal.signal(signal.SIGTERM,request_shutdown)
signal.signal(signal.SIGHUP,request_shutdown)
os.environ.update(ROS_DOMAIN_ID='187',GZ_PARTITION='slopehole_test',GZ_LOG_PATH=str(T/'logs/gazebo'),ROS_LOG_DIR=str(T/'logs/ros'),OMP_NUM_THREADS='1',OPENBLAS_NUM_THREADS='1')
os.environ.update(PYTHONUNBUFFERED='1',RCUTILS_CONSOLE_STDOUT_LINE_BUFFERED='1')
if args.gui and args.render=='software':os.environ.update(LIBGL_ALWAYS_SOFTWARE='1',GALLIUM_DRIVER='llvmpipe',__GLX_VENDOR_LIBRARY_NAME='mesa',QT_QUICK_BACKEND='opengl',QSG_RENDER_LOOP='basic',LP_NUM_THREADS='2',MALLOC_ARENA_MAX='2',GSETTINGS_BACKEND='memory',QT_QPA_PLATFORMTHEME='')
if args.gui and args.render=='nvidia':
    for key in ('LIBGL_ALWAYS_SOFTWARE','GALLIUM_DRIVER','MESA_LOADER_DRIVER_OVERRIDE','QT_QUICK_BACKEND','__EGL_VENDOR_LIBRARY_FILENAMES'):
        os.environ.pop(key,None)
    os.environ.update(__GLX_VENDOR_LIBRARY_NAME='nvidia',__NV_PRIME_RENDER_OFFLOAD='1',__VK_LAYER_NV_optimus='NVIDIA_only',QSG_RENDER_LOOP='basic',MALLOC_ARENA_MAX='2')
subprocess.run(['/usr/bin/python3',str(T/'scripts/generate_world.py'),'--case',args.case,'--model-sdf',str(args.model_sdf.resolve()),*(['--boost-speed',str(args.boost_speed)] if args.boost_speed is not None else []),*(['--baseline'] if args.baseline else []),*(['--diagnostic-contacts'] if args.diagnostic_contacts else [])],check=True)
case=yaml.safe_load((T/'sim/case.yaml').read_text());procs=[];logs=[]
def start(cmd,name):
    path=T/'logs'/f'{args.case}_{name}.log'
    f=path.open('w');logs.append(f);runtime_logs.watch(name,path)
    def limit():
        os.nice(10)
        # NVIDIA maps GPU virtual memory: an AS cap can prevent GL startup.
        # Bound resident memory in the supervisor instead of GPU address space.
        if not (name in ('gui','rviz') and args.render=='nvidia'):
            cap=(6000 if name in ('gui','rviz') else 2500)*1024**2
            resource.setrlimit(resource.RLIMIT_AS,(cap,cap))
        resource.setrlimit(resource.RLIMIT_CORE,(0,0))
    p=subprocess.Popen(cmd,cwd=T,stdout=f,stderr=subprocess.STDOUT,start_new_session=True,preexec_fn=limit);procs.append(p);supervisor.track(p);return p
class Probe(Node):
    def __init__(self):
        super().__init__('execution_probe');self.set_parameters([rclpy.parameter.Parameter('use_sim_time',value=True)])
        self.plan=None;self.state=None;self.pose=None;self.joints={};self.events=[];self.transitions=[];self.trace=[];self.last_trace=-1.;self.command=Twist();self.plans=[];self.markers=None
        self.rotation=None;self.rotation_stopped=False
        self.final_command=Twist();self.final_command_received=None;self.joint_velocities={};self.wheel_odom=None;self.feedback_snapshot=None
        self.contacts={}
        if args.diagnostic_contacts:
            from ros_gz_interfaces.msg import Contacts
            for topic in contact_topics:
                self.create_subscription(Contacts,topic,lambda m,topic=topic:self.on_contacts(topic,m),qos_profile_sensor_data)
        self.rotation_mode='WAIT_FEEDBACK'
        self.runtime_logs=runtime_logs;self.last_status_wall=-1.;self.last_request=None;self.last_feedback=None
        self.action=ActionClient(self,Navigate,'navigate');q=QoSProfile(depth=1,durability=DurabilityPolicy.TRANSIENT_LOCAL)
        self.create_subscription(NavigationPlan,'navigation_plan',self.on_plan,q)
        self.create_subscription(MarkerArray,'hole_execution_markers',lambda m:setattr(self,'markers',m),q)
        self.create_subscription(HoleTraversalState,'hole_traversal_state',self.on_state,10)
        self.create_subscription(HoleTraversalEvent,'hole_traversal_event',self.on_event,10)
        self.create_subscription(Odometry,'/Odometry',self.on_pose,qos_profile_sensor_data)
        self.create_subscription(Twist,'/cmd_vel',lambda m:setattr(self,'command',m),10)
        self.create_subscription(Twist,'/cmd_vel_chassis',self.on_final_command,10)
        self.create_subscription(JointState,'/joint_states',self.on_joints,qos_profile_sensor_data)
        self.create_subscription(Odometry,'/wheel/odometry',lambda m:setattr(self,'wheel_odom',m),qos_profile_sensor_data)
        self.create_subscription(JointState,'/rotation/feedback',lambda m:setattr(self,'rotation',m),10)
        self.create_subscription(String,'/rotation/mode',self.on_rotation_mode,10)
        self.create_subscription(Bool,'/rotation/stopped',lambda m:setattr(self,'rotation_stopped',m.data),10)
        self.create_subscription(HoleStructureRequest,'hole_structure/request',self.on_request,10)
        self.create_subscription(HoleStructureFeedback,'hole_structure/feedback',self.on_feedback,10)
    def on_plan(self,m):
        self.plan=m;runtime_logs.record('PLAN',f'版本={m.plan_id} 状态={m.status} 洞口='+str([(p.hole_id,'上坡' if p.uphill_entry else '下坡') for p in m.passages]))
        self.plans.append(dict(id=m.plan_id,status=m.status,length=m.path_length,path_frame=m.path.header.frame_id,
            path=[[p.pose.position.x,p.pose.position.y,p.pose.position.z] for p in m.path.poses],
            speed_regions=[dict(begin=r.s_begin,end=r.s_end,limit=r.speed_limit,kind=r.kind) for r in m.speed_regions],
            passages=[dict(uid=p.traversal_uid,hole=p.hole_id,uphill=p.uphill_entry,events=[dict(type=e.type,arc=e.s_path,range=e.range_status,x=e.point.x,y=e.point.y) for e in p.events]) for p in m.passages]))
    def on_contacts(self,topic,m):
        stamp=m.header.stamp.sec+m.header.stamp.nanosec*1e-9
        self.contacts[topic]=dict(stamp=stamp,contacts=[dict(collision1=c.collision1.name,collision2=c.collision2.name,
            positions=[[p.x,p.y,p.z] for p in c.positions[:2]],normals=[[p.x,p.y,p.z] for p in c.normals[:2]],
            depths=list(c.depths[:2]),forces_body1=[[w.body_1_wrench.force.x,w.body_1_wrench.force.y,w.body_1_wrench.force.z]
                for w in c.wrenches[:2]]) for c in m.contacts[:8]])
    def on_final_command(self,m):
        self.final_command=m;self.final_command_received=self.get_clock().now().nanoseconds*1e-9
    def on_joints(self,m):
        self.joints=dict(zip(m.name,m.position));self.joint_velocities=dict(zip(m.name,m.velocity))
    def on_rotation_mode(self,m):
        if m.data!=self.rotation_mode:
            self.rotation_mode=m.data
            runtime_logs.record('ROTATION',m.data)
    def on_state(self,m):
        old=self.state;self.state=m
        key=lambda s:(s.state,s.decision,s.reason,s.attempt,s.recovery_phase)
        if old is None or key(old)!=key(m):
            self.transitions.append(dict(t=self.get_clock().now().nanoseconds*1e-9,state=m.state,decision=m.decision,reason=m.reason,attempt=m.attempt,recovery=m.recovery_phase))
        changed=old is None or key(old)!=key(m)
        if changed or time.monotonic()-self.last_status_wall>=2.:
            self.last_status_wall=time.monotonic()
            state=('NORMAL','PREPARE','TRAVERSE','RESTORE','HOLD')
            decision=('CONTINUE','STOP','REPLAN','RECOVERY','FAILURE')
            runtime_logs.record('FSM',f'{state[m.state] if m.state<len(state) else m.state} / {decision[m.decision] if m.decision<len(decision) else m.decision} '
                f'进度={m.s_progress:.3f}m 限速={m.speed_limit:.3f}m/s 重试={m.attempt} 退让阶段={m.recovery_phase} 原因={m.reason}')
    def on_request(self,m):
        key=(m.session_id,m.goal_id,m.request_id,m.requirement_revision,m.target,m.cancel_motion)
        if key!=self.last_request:
            self.last_request=key
            runtime_logs.record('机构请求',f'编号={m.request_id} 目标={m.target}(0保持/1降低/2恢复) 取消={m.cancel_motion}')
    def on_feedback(self,m):
        self.feedback_snapshot=dict(stamp=m.header.stamp.sec+m.header.stamp.nanosec*1e-9,
            request_id=m.request_id,requirement_revision=m.requirement_revision,target=m.target,status=m.status,
            action_stopped=m.action_stopped,retry_allowed=m.retry_allowed,fault_code=m.fault_code,
            whole_vehicle_clear=m.whole_vehicle_clear,normal_clearance=m.normal_clearance,
            cleared_traversal_uids=list(m.cleared_traversal_uids))
        key=(m.session_id,m.goal_id,m.request_id,m.requirement_revision,m.status,m.action_stopped,m.fault_code)
        if key!=self.last_feedback:
            self.last_feedback=key
            runtime_logs.record('机构反馈',f'编号={m.request_id} 状态={m.status}(0执行/1完成/2失败/3取消) 已停={m.action_stopped} 故障码={m.fault_code}')
    def on_event(self,m):
        self.events.append(dict(uid=m.traversal_uid,type=m.type,sequence=m.sequence,attempt=m.attempt,arc=m.event_arc,progress=m.progress,lift=self.joints.get('lift_joint'),rotation_rates=list(self.rotation.velocity) if self.rotation else None,rotation_stopped=self.rotation_stopped))
        runtime_logs.record('EVENT',f'{"ASEXTD"[m.type] if m.type<6 else m.type} 通行={m.traversal_uid} 尝试={m.attempt} 进度={m.progress:.3f}m 升降={self.joints.get("lift_joint")}')
    def on_pose(self,m):
        self.pose=m;t=self.get_clock().now().nanoseconds*1e-9
        if t-self.last_trace>=.1:
            q=m.pose.pose.orientation;roll,pitch,yaw=Rotation.from_quat([q.x,q.y,q.z,q.w]).as_euler('xyz')
            self.last_trace=t;self.trace.append(dict(t=t,x=m.pose.pose.position.x,y=m.pose.pose.position.y,z=m.pose.pose.position.z,lift=self.joints.get('lift_joint'),roll=roll,pitch=pitch,yaw=yaw,vx=m.twist.twist.linear.x,vy=m.twist.twist.linear.y,command_x=self.command.linear.x,command_y=self.command.linear.y,progress=self.state.s_progress if self.state else None,limit=self.state.speed_limit if self.state else None))
            self.trace[-1].update(chassis_yaw=self.rotation.position[0] if self.rotation else None,rotation_rates=list(self.rotation.velocity) if self.rotation else None,rotation_stopped=self.rotation_stopped,rotation_mode=self.rotation_mode)
            # Sample the entire command/physics chain at the existing bounded 10Hz trace rate.
            final=self.final_command;wheel=self.wheel_odom
            wheel_snapshot=None
            if wheel is not None:
                p=wheel.pose.pose.position;q=wheel.pose.pose.orientation
                wheel_snapshot=dict(stamp=wheel.header.stamp.sec+wheel.header.stamp.nanosec*1e-9,
                    frame=wheel.header.frame_id,child_frame=wheel.child_frame_id,
                    position=[p.x,p.y,p.z],orientation=[q.x,q.y,q.z,q.w],
                    linear=[wheel.twist.twist.linear.x,wheel.twist.twist.linear.y,wheel.twist.twist.linear.z],
                    angular=[wheel.twist.twist.angular.x,wheel.twist.twist.angular.y,wheel.twist.twist.angular.z])
            self.trace[-1].update(final_command=dict(x=final.linear.x,y=final.linear.y,wz=final.angular.z,received=self.final_command_received),
                joint_velocities=dict(self.joint_velocities),wheel_odometry=wheel_snapshot,
                structure_feedback=self.feedback_snapshot)
            if args.diagnostic_contacts:
                self.trace[-1]['active_contacts']={topic:data for topic,data in self.contacts.items()
                    if data['contacts'] and 0<=t-data['stamp']<=.3}
    def spin(self,seconds):
        end=time.monotonic()+seconds
        while time.monotonic()<end:rclpy.spin_once(self,timeout_sec=.02)
        runtime_logs.poll();supervisor.refresh()
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
initial_parameters=yaml.safe_load((T/'sim/nav_params.yaml').read_text())['nav_server']['ros__parameters']
initial_hole=yaml.safe_load(Path(initial_parameters['hole_state_machine']['config_file']).read_text())
result={'case':args.case,'model':selected_model.number,'model_sdf':str(args.model_sdf),'baseline':args.baseline,'result':'FAIL',
        'initial_nmpc':initial_parameters['nmpc'],'initial_hole':initial_hole['hole_state_machine'],
        'model_sha256':hashlib.sha256(args.model_sdf.read_bytes()).hexdigest()};n=None;goal_handle=None;console=None
try:
    start(['gz','sim','-s','-r',str(T/'sim'/f'{args.case}.sdf')],'gazebo')
    start(['/opt/ros/jazzy/lib/ros_gz_bridge/parameter_bridge','--ros-args','-p','config_file:='+str(bridge_path),'-p','use_sim_time:=true'],'ros_bridge')
    start([str(T.parent/'navigatiosim2/install/seu_sentry_sim_control/lib/seu_sentry_sim_control/swerve_sim_controller_node'),'--ros-args','--params-file',str(T.parent/'navigatiosim2/src/seu_sentry_sim_control/config/swerve_sim_controller.yaml'),'-p','use_sim_time:=true'],'swerve')
    start(['/usr/bin/python3',str(T/'sim/sim_bridge.py'),'--ros-args','-p','use_sim_time:=true','-p',f'model_sdf:={args.model_sdf.resolve()}',*sum((['-p',f'world_offset_{axis}:={value}'] for axis,value in zip(('x','y','z'),case['world_offset'])),[])],'adapter')
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
        print(f"READY: RViz 2D Goal Pose选目标；map起点={case['start']}，推荐目标={case['goal']}。",flush=True)
        if sys.stdin.isatty():
            sys.path.insert(0,str(T/'sim'));from keyboard_console import KeyboardConsole
            console=KeyboardConsole(n)
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
            # 旧坡顶低速区已取消，暂停观察仅使用正式路径与坡几何。
            from slope_sections import uphill_exits
            crests=uphill_exits([(p.pose.position.x,p.pose.position.y) for p in n.plan.path.poses],
                yaml.safe_load((T/'map/terrain.yaml').read_text())['regions'])
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
    # 规划器可能选择只经过一个洞；验收正式接纳路线，不按场景名伪定洞数。
    needed=sum(p.events[2].range_status==p.events[2].ON_PATH for p in n.plan.passages) if n.plan else 0
    expected_markers=sum(e.point_valid for p in n.plan.passages for e in p.events) if n.plan else 0
    if not args.baseline and needed:assert result['visible_event_points']>=expected_markers,'正式路径范围内的事件Marker不完整'
    entered={e['uid'] for e in n.events if e['type']==2};exited={e['uid'] for e in n.events if e['type']==3}
    if not args.baseline:assert len(entered)>=needed and entered<=exited,'通行事件不完整'
    assert all(e['lift'] is not None and e['lift']<.008 for e in n.events if e['type']==2),'未低姿态就进入'
    result['result']='PASS'
    if args.hold_open:
        print('导航成功；保留窗口。可在RViz继续选目标，Ctrl+C结束本组仿真。',flush=True)
        while all(p.poll() is None for p in procs):n.spin(.1)
except KeyboardInterrupt:
    if result['result']!='PASS':result['result']='INTERRUPTED'
    print('收到Ctrl+C，关闭本组仿真进程。',flush=True)
except Exception as exc:
    result['result']='FAIL';result['error']=str(exc);print('FAIL',str(exc),flush=True)
finally:
    # 先保护退出流程；连续Ctrl+C、TTY恢复或ROS关闭异常都不能跳过进程清理。
    signal.signal(signal.SIGINT,signal.SIG_IGN);signal.signal(signal.SIGTERM,signal.SIG_IGN);signal.signal(signal.SIGHUP,signal.SIG_IGN)
    try:
        if console:
            try:console.close()
            except Exception as exc:print('键盘收尾：',exc,flush=True)
            console=None
        if n:
            result.update(plans=n.plans,events=n.events,transitions=n.transitions,trace=n.trace)
            result['visible_event_points']=sum(m.type==Marker.SPHERE and m.action==Marker.ADD for m in n.markers.markers) if n.markers else 0
            if goal_handle and not result.get('action_success'):
                try:goal_handle.cancel_goal_async();n.spin(.3)
                except Exception:pass
        try:rclpy.try_shutdown()
        except Exception as exc:print('ROS收尾：',exc,flush=True)
    finally:
        remaining=supervisor.cleanup();runtime_logs.poll()
        result['cleanup_remaining_pids']=remaining
        for f in logs:f.close()
        (T/'results'/f'{args.case}{"_baseline" if args.baseline else ""}.json').write_text(json.dumps(result,indent=2))
        print('本次仿真进程清理完成。' if not remaining else f'仍未退出的本次进程：{remaining}',flush=True)
print(result['result'],result.get('error',''),flush=True)
sys_exit=0 if result['result'] in ('PASS','MANUAL_SESSION','INTERRUPTED','DEMO_PAUSED') and not result.get('cleanup_remaining_pids') else 1
raise SystemExit(sys_exit)
