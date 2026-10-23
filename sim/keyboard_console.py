#!/usr/bin/env python3
"""原键盘接口＋隔离仿真在线调参；只通过适配服务改变公开数值参数。"""
import os,sys,math,time,select,termios,tty
import rclpy
from rclpy.node import Node
from rclpy.clock import Clock
from rclpy.clock_type import ClockType
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry
from sensor_msgs.msg import JointState
from std_msgs.msg import String,Float64,Bool
from rcl_interfaces.srv import GetParameters,SetParametersAtomically
from rcl_interfaces.msg import Parameter,ParameterValue,ParameterType
from nav_interfaces.msg import HoleTraversalState

FIELDS=[('flat_speed','普通速度'),('boost_speed','补速目标'),('minimum_entry_speed','坡底最低'),
        ('minimum_slope_speed','坡中最低'),('restore_speed','恢复速度'),('max_linear_accel','NMPC加速度')]
STATE_NAMES=('NORMAL','PREPARE','TRAVERSE','RESTORE','HOLD')
DECISION_NAMES=('CONTINUE','STOP','REPLAN','RECOVERY','FAILURE')

class KeyboardConsole:
    def __init__(self,node):
        self.node=node;self.fd=sys.stdin.fileno();self.old=termios.tcgetattr(self.fd)
        self.mode='navigation';self.command=Twist();self.yaw=0.;self.yaw_key=-1.;self.selected=1
        self.manual_speed=1.0 # 沿用原keyboard_teleop的linear_speed默认值，单位m/s。
        self.values={};self.message='选择1～6后按+/-调参；仅作用于test副本。';self.pending=False;self.query=None
        self.speed=0.;self.command_speed=0.;self.rotation=[];self.rotation_mode='WAIT_FEEDBACK';self.state=None;self.last_query=self.last_draw=0.
        self.logs_only=False
        self.last_state_key=None;self.last_state_log=-1.
        self.cmd=node.create_publisher(Twist,'/keyboard/cmd_vel_gimbal',10)
        self.gimbal=node.create_publisher(Float64,'/keyboard/gimbal_cmd_vel',10)
        self.control=node.create_publisher(String,'/control_mode',10);self.stop=node.create_publisher(Bool,'/rotation/stop',10)
        self.set=node.create_client(SetParametersAtomically,'/hole_runtime/set_parameters_atomically')
        self.get=node.create_client(GetParameters,'/nav_server/get_parameters')
        self.subs=[node.create_subscription(Odometry,'/Odometry/fake',self.on_odom,10),
            node.create_subscription(Twist,'/cmd_vel_chassis',lambda m:setattr(self,'command_speed',math.hypot(m.linear.x,m.linear.y)),10),
            node.create_subscription(JointState,'/rotation/feedback',lambda m:setattr(self,'rotation',list(m.velocity)),10),
            node.create_subscription(String,'/rotation/mode',lambda m:setattr(self,'rotation_mode',m.data),10),
            node.create_subscription(HoleTraversalState,'hole_traversal_state',self.on_execution_state,10)]
        self.timer=node.create_timer(.05,self.tick,clock=Clock(clock_type=ClockType.STEADY_TIME))
        tty.setcbreak(self.fd)
    def on_odom(self,m):self.speed=math.hypot(m.twist.twist.linear.x,m.twist.twist.linear.y)
    def on_execution_state(self,m):
        self.state=m
        if hasattr(self.node,'poll_runtime_logs'):
            key=(m.state,m.decision,m.reason,m.attempt,m.recovery_phase)
            if key!=self.last_state_key or time.monotonic()-self.last_state_log>=2.:
                self.last_state_key=key;self.last_state_log=time.monotonic()
                state=STATE_NAMES[m.state] if m.state<len(STATE_NAMES) else str(m.state)
                decision=DECISION_NAMES[m.decision] if m.decision<len(DECISION_NAMES) else str(m.decision)
                self.node.runtime_logs.record('FSM',f'{state} / {decision} 进度={m.s_progress:.3f}m 限速={m.speed_limit:.3f}m/s 原因={m.reason}')
    def apply(self,name,value):
        if self.pending or not self.set.service_is_ready():self.message='调参服务未就绪或上一请求尚未完成';return
        v=ParameterValue(type=ParameterType.PARAMETER_BOOL,bool_value=True) if name=='save' else ParameterValue(type=ParameterType.PARAMETER_DOUBLE,double_value=float(value))
        req=SetParametersAtomically.Request();req.parameters=[Parameter(name=name,value=v)]
        self.pending=True
        def done(future):
            self.pending=False
            try:
                result=future.result().result;self.message=('成功：' if result.successful else '拒绝：')+result.reason
                if result.successful and name!='save':self.values[name]=value
            except Exception as e:self.message='接口异常：'+str(e)
        self.set.call_async(req).add_done_callback(done)
    def key(self,key):
        k=key.lower()
        if k=='v':
            self.logs_only=not self.logs_only
            if self.logs_only:self.last_log_status=None
            print('\n连续日志视图：1～6选择，+/-调参，[/]调手动速度，V返回面板' if self.logs_only else '\n返回键盘面板',flush=True)
            return
        if key in '123456':self.selected=int(key)-1;return
        if key in '[]':
            self.manual_speed=round(min(3.5,max(.1,self.manual_speed+(.1 if key==']' else -.1))),4);return
        if key in '+-=':
            name=FIELDS[self.selected][0]
            if name not in self.values:self.message='等待读取当前参数';return
            step=1. if name=='max_linear_accel' else .1
            self.apply(name,round(self.values[name]+(-step if key=='-' else step),4));return
        if k=='p':self.apply('save',True);return
        if k in ('k','n'):
            self.mode='keyboard' if k=='k' else 'navigation';self.command=Twist();self.yaw=0.
            self.control.publish(String(data=self.mode));self.stop.publish(Bool(data=False));return
        if k=='r':self.stop.publish(Bool(data=False));self.message='解除停转；NAV模式恢复自动策略';return
        if key==' ':
            self.command=Twist();self.yaw=0.;self.stop.publish(Bool(data=True));return
        if k=='x':raise KeyboardInterrupt
        if self.mode!='keyboard':return
        if k in ('q','e'):
            self.yaw=(1. if k=='q' else -1.)*math.radians(100.);self.yaw_key=time.monotonic();return
        cmd=Twist()
        if k=='w':cmd.linear.x=-self.manual_speed
        elif k=='s':cmd.linear.x=self.manual_speed
        elif k=='a':cmd.linear.y=self.manual_speed
        elif k=='d':cmd.linear.y=-self.manual_speed
        elif k=='j':cmd.angular.z=1.2
        elif k=='l':cmd.angular.z=-1.2
        else:return
        self.command=cmd
    def tick(self):
        now=time.monotonic()
        if hasattr(self.node,'poll_runtime_logs'):self.node.poll_runtime_logs()
        # 直接读取终端fd；TextIOWrapper会预读后续按键，使select看不到缓冲中的+/-。
        while select.select([self.fd],[],[],0)[0]:
            keys=os.read(self.fd,1024)
            if not keys:break
            for key in keys.decode(errors='ignore'):self.key(key)
        self.cmd.publish(self.command);self.gimbal.publish(Float64(data=self.yaw if now-self.yaw_key<.2 else 0.))
        if now-self.last_query>1. and self.get.service_is_ready() and (self.query is None or self.query.done()):
            names=['hole_runtime.'+n if n!='max_linear_accel' else 'nmpc.max_linear_accel' for n,_ in FIELDS]
            req=GetParameters.Request();req.names=names+['nmpc.max_linear_vel','nmpc.speed_profile.v_cruise']
            self.last_query=now;self.query=self.get.call_async(req)
            def read(future):
                try:
                    for (name,_),v in zip(FIELDS,future.result().values):
                        if v.type==ParameterType.PARAMETER_DOUBLE:self.values[name]=v.double_value
                except Exception:pass
            self.query.add_done_callback(read)
        if now-self.last_draw>.25:
            self.last_draw=now
            if self.logs_only:
                name,label=FIELDS[self.selected]
                value=self.values.get(name,'等待参数');unit='m/s²' if name=='max_linear_accel' else 'm/s'
                status=(self.selected,value,self.manual_speed,self.message)
                if status!=getattr(self,'last_log_status',None):
                    self.last_log_status=status
                    print(f'[调参] {self.selected+1} {label}: {value} {unit} | 手动目标: {self.manual_speed:.1f}m/s（下次方向键生效） | {self.message}',flush=True)
                return
            lines=['仿真键盘 / 在线调参（原导航源码不改）',
                'K手动 N导航 | W/S=-X/+X A/D=+Y/-Y（云台系） J/L底盘 Q/E云台',
                '空格=停车并停转 R=解除停转 X/Ctrl+C=全部关闭 V=连续日志 | 1～6选择 +/-调整 P保存',
                f'[/] 调手动平移目标：{self.manual_speed:.1f}m/s（下次方向键生效，不持久化）',
                f'模式={self.mode}  实测速度={self.speed:.3f}m/s  底盘指令={self.command_speed:.3f}m/s',
                f'旋转模式={self.rotation_mode}  地面实测角速度[dps]='+str([round(math.degrees(v),1) for v in self.rotation])]
            if self.state:
                state=STATE_NAMES[self.state.state] if self.state.state<len(STATE_NAMES) else str(self.state.state)
                lines.append(f'状态={state} 有效上限={self.state.speed_limit:.3f}m/s  {self.state.reason}')
            for i,(name,label) in enumerate(FIELDS):lines.append(f'{">" if i==self.selected else " "} {i+1} {label}: {self.values.get(name,"等待参数")} '+('m/s²' if name=='max_linear_accel' else 'm/s'))
            lines.append(self.message)
            if hasattr(self.node,'runtime_logs'):
                lines.append('── 导航 / 坡洞状态机最近输出（V看连续日志）──')
                lines.extend(line[:180] for line in list(self.node.runtime_logs.lines)[-8:])
            print('\033[H\033[J'+'\n'.join(lines),flush=True)
    def close(self):
        try:
            self.node.destroy_timer(self.timer)
            if rclpy.ok(context=self.node.context):
                self.cmd.publish(Twist());self.gimbal.publish(Float64(data=0.));self.stop.publish(Bool(data=True))
        finally:
            # ROS context已关闭时publish可抛异常，仍须恢复终端供后续Ctrl+C/命令使用。
            termios.tcsetattr(self.fd,termios.TCSANOW,self.old);print('\n键盘终端关闭。',flush=True)

def main():
    import os,signal,subprocess
    from rclpy.executors import ExternalShutdownException
    if not sys.stdin.isatty():raise SystemExit('请在交互终端运行键盘控制。')
    rclpy.init();node=Node('hole_keyboard_console');console=KeyboardConsole(node)
    try:
        from pathlib import Path
        import yaml
        test_root=Path(__file__).resolve().parents[1]
        sys.path.insert(0,str(test_root/'scripts'))
        from runtime_support import RuntimeLogs
        view=RuntimeLogs(echo=lambda:console.logs_only)
        case=yaml.safe_load((test_root/'sim/case.yaml').read_text())['case']
        if case not in ('single','upper','lower','long','crest','demo'):raise ValueError('unknown test case')
        view.watch('nav_server',test_root/'logs'/f'{case}_nav_server.log')
        node.runtime_logs=view;node.poll_runtime_logs=view.poll
        rclpy.spin(node)
    except (KeyboardInterrupt,ExternalShutdownException):pass
    finally:
        for sig in (signal.SIGINT,signal.SIGTERM,signal.SIGHUP):signal.signal(sig,signal.SIG_IGN)
        try:
            try:console.close()
            finally:node.destroy_node();rclpy.try_shutdown()
        finally:
            # 独立键盘终端也按用户要求结束整套test，避免只关键盘留下仿真。
            from pathlib import Path
            tool=Path(__file__).resolve().parents[1]/'scripts/stop_demo.py'
            subprocess.run([sys.executable,str(tool),'--exclude-pid',str(os.getpid())],timeout=9,check=True)
if __name__=='__main__':main()
