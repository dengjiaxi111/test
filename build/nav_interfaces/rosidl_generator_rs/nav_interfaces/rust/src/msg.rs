#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to nav_interfaces__msg__HoleEvent
/// 一个计划事件的位置说明；嵌套在 HoleTraversal.events 内。
/// 对应交接文档5.3；是“事件在哪里”，不是“事件已经触发”的通知。
/// A不一定在S前：允许在S—E内开始变形，但必须在E前完成。
/// 当前草稿缺少文档要求的reason字段；UNKNOWN/越界不能伪造有效坐标。

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct HoleEvent {
    /// 事件类型0—5，取A/S/E/X/T/D；与下面的range_status是两套不同编码。
    pub type_: u8,

    /// 事件相对当前路径的范围状态0—3，取ON_PATH/BEFORE_PATH/AFTER_PATH/UNKNOWN。
    pub range_status: u8,

    /// 沿当前NavigationPlan.path起点累计到事件的弧长，单位m；不是两点直线距离。未知时不可使用。
    pub s_path: f64,

    /// 地图中的真实事件坐标x/y/z，单位m；只有point_valid为true时才可使用。
    pub point: geometry_msgs::msg::Point,

    /// 是否有可靠的真实事件坐标；false时默认(0,0,0)不表示事件位于地图原点。
    pub point_valid: bool,

}

impl HoleEvent {
    /// 事件类型常量0：开始准备的路径事件。
    pub const A: u8 = 0;

    /// 事件类型常量1：入口固定直线开始。
    pub const S: u8 = 1;

    /// 事件类型常量2：真实入口边界；人工配置必须在此之前确认准备完成。
    pub const E: u8 = 2;

    /// 事件类型常量3：真实出口边界；参考点越过不代表整车退出。
    pub const X: u8 = 3;

    /// 事件类型常量4：出口固定直线结束；后续路径才可按规划转弯。
    pub const T: u8 = 4;

    /// 事件类型常量5：离开阶段边界；人工配置D=T，仍需反馈确认结构释放。
    pub const D: u8 = 5;

    /// 范围常量0：事件位于当前最终路径范围内。
    pub const ON_PATH: u8 = 0;

    /// 范围常量1：位于当前剩余路径起点之前，不证明准备/通过动作已经完成。
    pub const BEFORE_PATH: u8 = 1;

    /// 范围常量2：位于当前路径终点之后，不证明机器人已到达或退出。
    pub const AFTER_PATH: u8 = 2;

    /// 范围常量3：信息不足，不能可靠确定，禁止把默认坐标作为真实事件。
    pub const UNKNOWN: u8 = 3;

}


impl Default for HoleEvent {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::HoleEvent::default())
  }
}

impl rosidl_runtime_rs::Message for HoleEvent {
  type RmwMsg = super::msg::rmw::HoleEvent;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        type_: msg.type_,
        range_status: msg.range_status,
        s_path: msg.s_path,
        point: geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Owned(msg.point)).into_owned(),
        point_valid: msg.point_valid,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      type_: msg.type_,
      range_status: msg.range_status,
      s_path: msg.s_path,
        point: geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Borrowed(&msg.point)).into_owned(),
      point_valid: msg.point_valid,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      type_: msg.type_,
      range_status: msg.range_status,
      s_path: msg.s_path,
      point: geometry_msgs::msg::Point::from_rmw_message(msg.point),
      point_valid: msg.point_valid,
    }
  }
}


// Corresponds to nav_interfaces__msg__HoleStraight
/// 当前最终路径上需要保持直线的区间；嵌套在 HoleTraversal.straight_segments。
/// 对应交接文档5.2：严格模式S—T；free模式S—E和X—T。
/// 方向是地图中的运动切线，不是机身yaw对准要求。

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct HoleStraight {
    /// 直线区间起点的路径累计弧长，单位m，相对当前NavigationPlan.path起点。
    pub s_begin: f64,

    /// 直线区间终点的路径累计弧长，单位m，应不小于s_begin。
    pub s_end: f64,

    /// 地图坐标系的运动方向向量，草稿使用二维切向x/y；不是机身朝向角，也不是速度大小。
    pub direction: geometry_msgs::msg::Vector3,

    /// true表示当前只能声明剩余直线片段；false声明完整区间，不等于该段已经走完。
    pub remaining: bool,

}



impl Default for HoleStraight {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::HoleStraight::default())
  }
}

impl rosidl_runtime_rs::Message for HoleStraight {
  type RmwMsg = super::msg::rmw::HoleStraight;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        s_begin: msg.s_begin,
        s_end: msg.s_end,
        direction: geometry_msgs::msg::Vector3::into_rmw_message(std::borrow::Cow::Owned(msg.direction)).into_owned(),
        remaining: msg.remaining,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      s_begin: msg.s_begin,
      s_end: msg.s_end,
        direction: geometry_msgs::msg::Vector3::into_rmw_message(std::borrow::Cow::Borrowed(&msg.direction)).into_owned(),
      remaining: msg.remaining,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      s_begin: msg.s_begin,
      s_end: msg.s_end,
      direction: geometry_msgs::msg::Vector3::from_rmw_message(msg.direction),
      remaining: msg.remaining,
    }
  }
}


// Corresponds to nav_interfaces__msg__HoleSpeedRegion
/// 最终路径上的分段速度上限；嵌套在 NavigationPlan.speed_regions。
/// 为上下坡及坡顶后限速补充的结构；它描述限制，不负责生成加减速指令。
/// 不改变A/S/E/X/T/D几何；具体上限由配置和控制器共同处理。

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct HoleSpeedRegion {
    /// 限速区间起点的路径累计弧长，单位m。
    pub s_begin: f64,

    /// 限速区间终点的路径累计弧长，单位m；按当前最终路径解释。
    pub s_end: f64,

    /// 区间平移速度模长上限，单位m/s；允许更慢或停车，不是强制目标速度。
    pub speed_limit: f64,

    /// 当前C++编码：0平地FLAT，1上坡UPHILL，2下坡DOWNHILL，3受限RESTRICTED；消息尚未声明对应命名常量。
    pub kind: u8,

}



impl Default for HoleSpeedRegion {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::HoleSpeedRegion::default())
  }
}

impl rosidl_runtime_rs::Message for HoleSpeedRegion {
  type RmwMsg = super::msg::rmw::HoleSpeedRegion;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        s_begin: msg.s_begin,
        s_end: msg.s_end,
        speed_limit: msg.speed_limit,
        kind: msg.kind,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      s_begin: msg.s_begin,
      s_end: msg.s_end,
      speed_limit: msg.speed_limit,
      kind: msg.kind,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      s_begin: msg.s_begin,
      s_end: msg.s_end,
      speed_limit: msg.speed_limit,
      kind: msg.kind,
    }
  }
}


// Corresponds to nav_interfaces__msg__HoleTraversal
/// 一次具体穿洞的计划记录；嵌套在 NavigationPlan.passages 内，不单独发布。
/// 对应交接文档5.2。同一个物理洞再次穿越，应有另一条通行记录。
/// 当前草稿尚未完整导出文档列出的顺序、完整性、细分校验结果和容差等信息。

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct HoleTraversal {
    /// 本任务中这一次具体穿越的稳定编号；同次通行重规划匹配保留，再穿同一个洞应另编号。
    pub traversal_uid: std::string::String,

    /// 地形配置中的物理洞口区域ID；同一个洞可关联不同次通行，不能单独用来动作去重。
    pub hole_id: std::string::String,

    /// 本次选中的洞口多边形入口边索引，编号规则来自规划器。
    pub entry_edge_id: i32,

    /// 本次选中的洞口多边形出口边索引，与入口共同确定通行方向。
    pub exit_edge_id: i32,

    /// true为严格中心线模式，false为free；默认只接纳严格模式，除非配置显式允许free。
    pub centerline: bool,

    /// 当前候选校验是否通过；不能替代文档全部细分保证，不能表示机构准备已完成。
    pub validated: bool,

    /// 准备要求的修订身份；要求变化后旧完成反馈不可授权新要求。当前版本组合算法仍待完善。
    pub requirement_revision: u64,

    /// 固定六项，存储顺序A/S/E/X/T/D；此数组顺序不代表事件的实际弧长顺序，A可能晚于S。
    pub events: [super::msg::HoleEvent; 6],

    /// 本路径中有效的固定直线区间，区分完整段和剩余段，不能由恢复动作任意破坏。
    pub straight_segments: Vec<super::msg::HoleStraight>,

    /// 本次入口方向与关联坡上坡方向一致；首版只允许此类失败后退让。
    pub uphill_entry: bool,

}



impl Default for HoleTraversal {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::HoleTraversal::default())
  }
}

impl rosidl_runtime_rs::Message for HoleTraversal {
  type RmwMsg = super::msg::rmw::HoleTraversal;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        traversal_uid: msg.traversal_uid.as_str().into(),
        hole_id: msg.hole_id.as_str().into(),
        entry_edge_id: msg.entry_edge_id,
        exit_edge_id: msg.exit_edge_id,
        centerline: msg.centerline,
        validated: msg.validated,
        requirement_revision: msg.requirement_revision,
        events: msg.events
          .map(|elem| super::msg::HoleEvent::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned()),
        straight_segments: msg.straight_segments
          .into_iter()
          .map(|elem| super::msg::HoleStraight::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        uphill_entry: msg.uphill_entry,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        traversal_uid: msg.traversal_uid.as_str().into(),
        hole_id: msg.hole_id.as_str().into(),
      entry_edge_id: msg.entry_edge_id,
      exit_edge_id: msg.exit_edge_id,
      centerline: msg.centerline,
      validated: msg.validated,
      requirement_revision: msg.requirement_revision,
        events: msg.events
          .iter()
          .map(|elem| super::msg::HoleEvent::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect::<Vec<_>>()
          .try_into()
          .unwrap(),
        straight_segments: msg.straight_segments
          .iter()
          .map(|elem| super::msg::HoleStraight::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      uphill_entry: msg.uphill_entry,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      traversal_uid: msg.traversal_uid.to_string(),
      hole_id: msg.hole_id.to_string(),
      entry_edge_id: msg.entry_edge_id,
      exit_edge_id: msg.exit_edge_id,
      centerline: msg.centerline,
      validated: msg.validated,
      requirement_revision: msg.requirement_revision,
      events: msg.events
        .map(super::msg::HoleEvent::from_rmw_message),
      straight_segments: msg.straight_segments
          .into_iter()
          .map(super::msg::HoleStraight::from_rmw_message)
          .collect(),
      uphill_entry: msg.uphill_entry,
    }
  }
}


// Corresponds to nav_interfaces__msg__NavigationPlan
/// 完整导航计划；导航侧发布到 navigation_plan，供执行/观察方读取。
/// 对应交接文档5.1；路径、逐洞事件和版本一起发送，不能混用不同计划的数据。
/// speed_regions 是为分段限速补充的设计。此文件仍是审阅稿，不能视为实车已接通。

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct NavigationPlan {
    /// 公共消息头：stamp为发送方填写的ROS时间；frame_id标注坐标系。不会自动填时间或转换坐标。
    pub header: std_msgs::msg::Header,

    /// 导航本次运行的身份，程序自动生成；重启时更换，同次运行的重规划不更换。用于拒绝旧会话消息。
    pub session_id: std::string::String,

    /// 本次最终导航任务的身份；同一个最终目标的重规划保持不变，不是路径点编号。
    pub goal_id: std::string::String,

    /// 当前计划版本；同一会话内接纳新版本/失效等会更新。不能单凭换版重复执行已完成动作。
    pub plan_id: u64,

    /// 实际计划状态，使用上面的0—4；ACTIVE且passages为空表示有效无洞路线，不等于失效。
    pub status: u8,

    /// 计划状态原因说明，例如路径受阻；这是说明文字，不应依赖解析文本作为稳定协议。
    pub reason: std::string::String,

    /// 该计划是否声明启用过洞规划/校验约束；不等同于机构已准备完成。
    pub constraints_enabled: bool,

    /// 本次采用的地形几何版本，例如洞口几何更新后改变。
    pub terrain_revision: u64,

    /// 本次采用的规划配置版本；当前来自所选规划快照的configuration_revision，不代表所有参数均已纳入。
    pub parameter_revision: u64,

    /// 本次校验采用的地图快照身份；草稿为地图摘要，不是时间戳或递增更新次数。
    pub map_revision: u64,

    /// 正式接纳的最终路径，位姿点与header声明的坐标系一致；事件弧长均相对此路径。
    pub path: nav_msgs::msg::Path,

    /// 该最终折线路径的二维累计长度，单位m；不是机器人已行驶距离。
    pub path_length: f64,

    /// 该版本的通行记录列表，数据与path应来自同一接纳快照；空列表可以是合法绕行。
    pub passages: Vec<super::msg::HoleTraversal>,

    /// 沿当前path定义的限速区间列表，可同时含坡面及坡顶后受限区。
    pub speed_regions: Vec<super::msg::HoleSpeedRegion>,

}

impl NavigationPlan {
    /// 常量0：当前有效计划。不是给status自动赋值。
    pub const ACTIVE: u8 = 0;

    /// 常量1：旧计划已失效，不可继续执行。
    pub const INVALIDATED: u8 = 1;

    /// 常量2：任务已取消。
    pub const CANCELLED: u8 = 2;

    /// 常量3：任务已结束为成功；不单凭此值解除洞内结构要求。
    pub const COMPLETED: u8 = 3;

    /// 常量4：任务失败；不意味着可以自动抬高姿态。
    pub const FAILED: u8 = 4;

}


impl Default for NavigationPlan {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::NavigationPlan::default())
  }
}

impl rosidl_runtime_rs::Message for NavigationPlan {
  type RmwMsg = super::msg::rmw::NavigationPlan;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        session_id: msg.session_id.as_str().into(),
        goal_id: msg.goal_id.as_str().into(),
        plan_id: msg.plan_id,
        status: msg.status,
        reason: msg.reason.as_str().into(),
        constraints_enabled: msg.constraints_enabled,
        terrain_revision: msg.terrain_revision,
        parameter_revision: msg.parameter_revision,
        map_revision: msg.map_revision,
        path: nav_msgs::msg::Path::into_rmw_message(std::borrow::Cow::Owned(msg.path)).into_owned(),
        path_length: msg.path_length,
        passages: msg.passages
          .into_iter()
          .map(|elem| super::msg::HoleTraversal::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        speed_regions: msg.speed_regions
          .into_iter()
          .map(|elem| super::msg::HoleSpeedRegion::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        session_id: msg.session_id.as_str().into(),
        goal_id: msg.goal_id.as_str().into(),
      plan_id: msg.plan_id,
      status: msg.status,
        reason: msg.reason.as_str().into(),
      constraints_enabled: msg.constraints_enabled,
      terrain_revision: msg.terrain_revision,
      parameter_revision: msg.parameter_revision,
      map_revision: msg.map_revision,
        path: nav_msgs::msg::Path::into_rmw_message(std::borrow::Cow::Borrowed(&msg.path)).into_owned(),
      path_length: msg.path_length,
        passages: msg.passages
          .iter()
          .map(|elem| super::msg::HoleTraversal::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        speed_regions: msg.speed_regions
          .iter()
          .map(|elem| super::msg::HoleSpeedRegion::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      session_id: msg.session_id.to_string(),
      goal_id: msg.goal_id.to_string(),
      plan_id: msg.plan_id,
      status: msg.status,
      reason: msg.reason.to_string(),
      constraints_enabled: msg.constraints_enabled,
      terrain_revision: msg.terrain_revision,
      parameter_revision: msg.parameter_revision,
      map_revision: msg.map_revision,
      path: nav_msgs::msg::Path::from_rmw_message(msg.path),
      path_length: msg.path_length,
      passages: msg.passages
          .into_iter()
          .map(super::msg::HoleTraversal::from_rmw_message)
          .collect(),
      speed_regions: msg.speed_regions
          .into_iter()
          .map(super::msg::HoleSpeedRegion::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to nav_interfaces__msg__HoleStructureRequest
/// 导航侧发往 hole_structure/request 的机构要求，机构控制侧接收并执行。
/// 对应交接文档5.4、7.3、8：请求身份、修订、同形态动作复用及多洞需求。
/// 组织方式参考旧stair_mode，但本文件的数字含义不复用台阶模式值。
/// LOW/NORMAL/KEEP具体怎样映射为真实下位机指令，尚需机构侧实现。

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct HoleStructureRequest {
    /// 公共消息头：stamp为发送方填写的ROS时间；frame_id标注坐标系。不会自动填时间或转换坐标。
    pub header: std_msgs::msg::Header,

    /// 导航本次运行的身份，程序自动生成；重启时更换，同次运行的重规划不更换。用于拒绝旧会话消息。
    pub session_id: std::string::String,

    /// 本次最终导航任务的身份；同一个最终目标的重规划保持不变，不是路径点编号。
    pub goal_id: std::string::String,

    /// 机构动作请求编号；新动作换号，同一个动作的消息重发沿用原编号。反馈必须回填匹配。
    pub request_id: u64,

    /// 准备要求的修订身份；要求变化后旧完成反馈不可授权新要求。当前版本组合算法仍待完善。
    pub requirement_revision: u64,

    /// 本次实际目标，填KEEP/LOW/NORMAL；上面的常量不会自动赋给它，须发送代码显式填写。
    pub target: u8,

    /// 当前共同需要该姿态的通行编号列表；连续两洞可同时存在，同形态可复用动作。
    pub traversal_uids: Vec<std::string::String>,

    /// 取消的是机构变形，不是底盘运动；草稿用true配KEEP按session/goal停止当前变形，不自动抬高。request_id=0为任务级取消约定，真实机构侧尚需实现。
    pub cancel_motion: bool,

}

impl HoleStructureRequest {
    /// 常量0：保持当前适用形态，不等于正常姿态；中间位置如何安全保持须由真实机构侧定义。
    pub const KEEP: u8 = 0;

    /// 常量1：要求低姿态；具体腿长/执行器目标由真实机构接口定义。
    pub const LOW: u8 = 1;

    /// 常量2：要求正常姿态；与KEEP不同，应在释放和净空条件成立后请求。
    pub const NORMAL: u8 = 2;

}


impl Default for HoleStructureRequest {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::HoleStructureRequest::default())
  }
}

impl rosidl_runtime_rs::Message for HoleStructureRequest {
  type RmwMsg = super::msg::rmw::HoleStructureRequest;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        session_id: msg.session_id.as_str().into(),
        goal_id: msg.goal_id.as_str().into(),
        request_id: msg.request_id,
        requirement_revision: msg.requirement_revision,
        target: msg.target,
        traversal_uids: msg.traversal_uids
          .into_iter()
          .map(|elem| elem.as_str().into())
          .collect(),
        cancel_motion: msg.cancel_motion,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        session_id: msg.session_id.as_str().into(),
        goal_id: msg.goal_id.as_str().into(),
      request_id: msg.request_id,
      requirement_revision: msg.requirement_revision,
      target: msg.target,
        traversal_uids: msg.traversal_uids
          .iter()
          .map(|elem| elem.as_str().into())
          .collect(),
      cancel_motion: msg.cancel_motion,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      session_id: msg.session_id.to_string(),
      goal_id: msg.goal_id.to_string(),
      request_id: msg.request_id,
      requirement_revision: msg.requirement_revision,
      target: msg.target,
      traversal_uids: msg.traversal_uids
          .into_iter()
          .map(|elem| elem.to_string())
          .collect(),
      cancel_motion: msg.cancel_motion,
    }
  }
}


// Corresponds to nav_interfaces__msg__HoleStructureFeedback
/// 机构侧发往 hole_structure/feedback，导航侧接收的动作与净空反馈。
/// 对应交接文档5.4、8及结构释放要求；净空、移动变形和模拟来源字段为具体补充设计。
/// 真正到位/净空判断必须有真实来源；消息定义本身不测量姿态、包络或空间。
/// 反馈须持续更新且与当前请求匹配；仅发一次“完成”不能永久授权运动。

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct HoleStructureFeedback {
    /// 公共消息头：stamp为发送方填写的ROS时间；frame_id标注坐标系。不会自动填时间或转换坐标。
    pub header: std_msgs::msg::Header,

    /// 导航本次运行的身份，程序自动生成；重启时更换，同次运行的重规划不更换。用于拒绝旧会话消息。
    pub session_id: std::string::String,

    /// 本次最终导航任务的身份；同一个最终目标的重规划保持不变，不是路径点编号。
    pub goal_id: std::string::String,

    /// 机构动作请求编号；新动作换号，同一个动作的消息重发沿用原编号。反馈必须回填匹配。
    pub request_id: u64,

    /// 准备要求的修订身份；要求变化后旧完成反馈不可授权新要求。当前版本组合算法仍待完善。
    pub requirement_revision: u64,

    /// 本反馈所对应请求的目标姿态：0 KEEP，1 LOW，2 NORMAL；须匹配当前请求。
    pub target: u8,

    /// 本条反馈的实际执行状态0—2；仅COMPLETED可确认动作到位。
    pub status: u8,

    /// 整车与相关结构的占用释放确认；不能由参考点过D直接推断。多洞时该总标志与逐洞列表的真实生成口径仍须对接明确。
    pub whole_vehicle_clear: bool,

    /// 正常形态及变形过程包络具备所需净空；移动恢复时须持续成立，不能只确认一次。
    pub normal_clearance: bool,

    /// 真实机构侧确认当前动作允许伴随底盘移动；不单凭此值授权运动，未知/false应停车等待。
    pub moving_transition_supported: bool,

    /// 可解除结构占用的通行编号列表；解除洞1不能顺带清除洞2需求。须与整车/净空标志共同解释。
    pub cleared_traversal_uids: Vec<std::string::String>,

    /// 测试来源标记：真实机构填false，隔离模拟器填true。当前适配器要求与simulation_only配置一致；不需要在实车启动模拟器。
    pub simulated: bool,

    /// 旧动作已结束/取消且关节停止；并非“上位机已经发出零指令”。
    pub action_stopped: bool,

    /// 机构当前明确允许发起新动作；未知时false。
    pub retry_allowed: bool,

    /// 0无故障；具体故障码由机构适配端定义。
    pub fault_code: u16,

}

impl HoleStructureFeedback {
    /// 状态常量0：动作正在执行，不可当作准备已完成。
    pub const EXECUTING: u8 = 0;

    /// 状态常量1：所请求姿态动作已完成，仍须校验身份和时效。
    pub const COMPLETED: u8 = 1;

    /// 状态常量2：机构报告动作失败；不编码详细故障原因，当前接口仍缺细分诊断。
    pub const FAILED: u8 = 2;

    /// 状态3：旧动作取消，仍需action_stopped确认。
    pub const CANCELLED: u8 = 3;

}


impl Default for HoleStructureFeedback {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::HoleStructureFeedback::default())
  }
}

impl rosidl_runtime_rs::Message for HoleStructureFeedback {
  type RmwMsg = super::msg::rmw::HoleStructureFeedback;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        session_id: msg.session_id.as_str().into(),
        goal_id: msg.goal_id.as_str().into(),
        request_id: msg.request_id,
        requirement_revision: msg.requirement_revision,
        target: msg.target,
        status: msg.status,
        whole_vehicle_clear: msg.whole_vehicle_clear,
        normal_clearance: msg.normal_clearance,
        moving_transition_supported: msg.moving_transition_supported,
        cleared_traversal_uids: msg.cleared_traversal_uids
          .into_iter()
          .map(|elem| elem.as_str().into())
          .collect(),
        simulated: msg.simulated,
        action_stopped: msg.action_stopped,
        retry_allowed: msg.retry_allowed,
        fault_code: msg.fault_code,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        session_id: msg.session_id.as_str().into(),
        goal_id: msg.goal_id.as_str().into(),
      request_id: msg.request_id,
      requirement_revision: msg.requirement_revision,
      target: msg.target,
      status: msg.status,
      whole_vehicle_clear: msg.whole_vehicle_clear,
      normal_clearance: msg.normal_clearance,
      moving_transition_supported: msg.moving_transition_supported,
        cleared_traversal_uids: msg.cleared_traversal_uids
          .iter()
          .map(|elem| elem.as_str().into())
          .collect(),
      simulated: msg.simulated,
      action_stopped: msg.action_stopped,
      retry_allowed: msg.retry_allowed,
      fault_code: msg.fault_code,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      session_id: msg.session_id.to_string(),
      goal_id: msg.goal_id.to_string(),
      request_id: msg.request_id,
      requirement_revision: msg.requirement_revision,
      target: msg.target,
      status: msg.status,
      whole_vehicle_clear: msg.whole_vehicle_clear,
      normal_clearance: msg.normal_clearance,
      moving_transition_supported: msg.moving_transition_supported,
      cleared_traversal_uids: msg.cleared_traversal_uids
          .into_iter()
          .map(|elem| elem.to_string())
          .collect(),
      simulated: msg.simulated,
      action_stopped: msg.action_stopped,
      retry_allowed: msg.retry_allowed,
      fault_code: msg.fault_code,
    }
  }
}


// Corresponds to nav_interfaces__msg__HoleTraversalState
/// 导航侧发布 hole_traversal_state：当前五态、决策、进度和逐洞阶段。
/// 对应交接文档5.4、7.1。包含云台朝向保持指令；本消息不是独立的平移运动许可协议。
/// 当前准备信息只包含需求标记，不完整表达准备中/就绪/故障；此为草稿缺口。

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct HoleTraversalState {
    /// 公共消息头：stamp为发送方填写的ROS时间；frame_id标注坐标系。不会自动填时间或转换坐标。
    pub header: std_msgs::msg::Header,

    /// 导航本次运行的身份，程序自动生成；重启时更换，同次运行的重规划不更换。用于拒绝旧会话消息。
    pub session_id: std::string::String,

    /// 本次最终导航任务的身份；同一个最终目标的重规划保持不变，不是路径点编号。
    pub goal_id: std::string::String,

    /// 当前计划版本；同一会话内接纳新版本/失效等会更新。不能单凭换版重复执行已完成动作。
    pub plan_id: u64,

    /// 当前五态编码：0 NORMAL，1 PREPARE，2 TRAVERSE，3 RESTORE，4 HOLD；不是顶层导航状态。
    pub state: u8,

    /// 导航决策编码：0 CONTINUE，1 STOP，2 REPLAN，3 RECOVERY，4 FAILURE；HOLD状态可输出不同决策。
    pub decision: u8,

    /// 机器人参考点在当前路径上的可靠累计进度，单位m；不是总里程。
    pub s_progress: f64,

    /// 本周期允许的平移速度模长上限，单位m/s；不能单凭观察消息绕过运动许可。
    pub speed_limit: f64,

    /// 当前状态/决策或暂停原因的说明文字；草稿部分分支仍比较字符串，尚非完整故障码协议。
    pub reason: std::string::String,

    /// 核心当前保留的通行编号列表，可能包含已完成记录；顺序与下面两个数组必须一一对应。
    pub traversal_uids: Vec<std::string::String>,

    /// 逐通行空间阶段：0 PENDING，1 ENTRY_STRAIGHT，2 IN_HOLE，3 EXIT_STRAIGHT，4 DEPARTING，5 COMPLETE。到D可先标记COMPLETE，不单凭此值证明占用已释放。
    pub phases: Vec<u8>,

    /// 逐通行的结构需求标记，实际来自Visit.demand；true不代表正在变形，也不证明准备完成，进入洞内后仍可为true。
    pub preparing_required: Vec<bool>,

    /// 本次通行尝试编号，0为首次，1/2为两次重试。
    pub attempt: u32,

    /// 专用恢复阶段：0无，1停稳，2校验，3退让，4目标停稳，5重入检查。
    pub recovery_phase: u8,

    /// 状态机明确输出的云台朝向保持指令，非从state/preparing_required推断。
    /// LOW和实测对准完成后为true；连续洞含洞间连接段保持true，
    /// 最后相关D及整车净空确认、请求NORMAL时变为false。
    /// 执行器保持第一次已完成对准的地面朝向，true持续期间不得重选朝向或恢复自旋。
    /// 不限制底盘普通旋转；HOLD/故障/退让等安全停转指令优先。
    pub hold_gimbal_heading: bool,

}



impl Default for HoleTraversalState {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::HoleTraversalState::default())
  }
}

impl rosidl_runtime_rs::Message for HoleTraversalState {
  type RmwMsg = super::msg::rmw::HoleTraversalState;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        session_id: msg.session_id.as_str().into(),
        goal_id: msg.goal_id.as_str().into(),
        plan_id: msg.plan_id,
        state: msg.state,
        decision: msg.decision,
        s_progress: msg.s_progress,
        speed_limit: msg.speed_limit,
        reason: msg.reason.as_str().into(),
        traversal_uids: msg.traversal_uids
          .into_iter()
          .map(|elem| elem.as_str().into())
          .collect(),
        phases: msg.phases.as_slice().into(),
        preparing_required: msg.preparing_required.as_slice().into(),
        attempt: msg.attempt,
        recovery_phase: msg.recovery_phase,
        hold_gimbal_heading: msg.hold_gimbal_heading,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        session_id: msg.session_id.as_str().into(),
        goal_id: msg.goal_id.as_str().into(),
      plan_id: msg.plan_id,
      state: msg.state,
      decision: msg.decision,
      s_progress: msg.s_progress,
      speed_limit: msg.speed_limit,
        reason: msg.reason.as_str().into(),
        traversal_uids: msg.traversal_uids
          .iter()
          .map(|elem| elem.as_str().into())
          .collect(),
        phases: msg.phases.as_slice().into(),
        preparing_required: msg.preparing_required.as_slice().into(),
      attempt: msg.attempt,
      recovery_phase: msg.recovery_phase,
      hold_gimbal_heading: msg.hold_gimbal_heading,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      session_id: msg.session_id.to_string(),
      goal_id: msg.goal_id.to_string(),
      plan_id: msg.plan_id,
      state: msg.state,
      decision: msg.decision,
      s_progress: msg.s_progress,
      speed_limit: msg.speed_limit,
      reason: msg.reason.to_string(),
      traversal_uids: msg.traversal_uids
          .into_iter()
          .map(|elem| elem.to_string())
          .collect(),
      phases: msg.phases.into(),
      preparing_required: msg.preparing_required.into(),
      attempt: msg.attempt,
      recovery_phase: msg.recovery_phase,
      hold_gimbal_heading: msg.hold_gimbal_heading,
    }
  }
}


// Corresponds to nav_interfaces__msg__HoleTraversalEvent
/// 导航侧发布 hole_traversal_event：某个路径事件已被执行调度器触发的通知。
/// 对应交接文档5.4、7.3；区别于仅描述计划位置的HoleEvent。
/// 接收方仍须按会话/任务/通行/事件类型记录去重，不能假设外部动作恰好执行一次。

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct HoleTraversalEvent {
    /// 公共消息头：stamp为发送方填写的ROS时间；frame_id标注坐标系。不会自动填时间或转换坐标。
    pub header: std_msgs::msg::Header,

    /// 导航本次运行的身份，程序自动生成；重启时更换，同次运行的重规划不更换。用于拒绝旧会话消息。
    pub session_id: std::string::String,

    /// 本次最终导航任务的身份；同一个最终目标的重规划保持不变，不是路径点编号。
    pub goal_id: std::string::String,

    /// 当前计划版本；同一会话内接纳新版本/失效等会更新。不能单凭换版重复执行已完成动作。
    pub plan_id: u64,

    /// 本次触发事件属于哪一次具体通行，与计划中的对应记录匹配。
    pub traversal_uid: std::string::String,

    /// 当前控制器实例内递增的执行事件序号，便于排查顺序；不单独作为动作去重键。
    pub sequence: u64,

    /// 已触发的事件类型：0 A，1 S，2 E，3 X，4 T，5 D。通知本身不替代真实机构反馈。
    pub type_: u8,

    /// 该事件在触发时计划路径上的弧长位置，单位m。
    pub event_arc: f64,

    /// 处理该事件时参考点的可靠路径进度，单位m，可略大于event_arc。
    pub progress: f64,

    /// 所属尝试编号；历史事件不因倒退删除。
    pub attempt: u32,

}



impl Default for HoleTraversalEvent {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::HoleTraversalEvent::default())
  }
}

impl rosidl_runtime_rs::Message for HoleTraversalEvent {
  type RmwMsg = super::msg::rmw::HoleTraversalEvent;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        session_id: msg.session_id.as_str().into(),
        goal_id: msg.goal_id.as_str().into(),
        plan_id: msg.plan_id,
        traversal_uid: msg.traversal_uid.as_str().into(),
        sequence: msg.sequence,
        type_: msg.type_,
        event_arc: msg.event_arc,
        progress: msg.progress,
        attempt: msg.attempt,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        session_id: msg.session_id.as_str().into(),
        goal_id: msg.goal_id.as_str().into(),
      plan_id: msg.plan_id,
        traversal_uid: msg.traversal_uid.as_str().into(),
      sequence: msg.sequence,
      type_: msg.type_,
      event_arc: msg.event_arc,
      progress: msg.progress,
      attempt: msg.attempt,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      session_id: msg.session_id.to_string(),
      goal_id: msg.goal_id.to_string(),
      plan_id: msg.plan_id,
      traversal_uid: msg.traversal_uid.to_string(),
      sequence: msg.sequence,
      type_: msg.type_,
      event_arc: msg.event_arc,
      progress: msg.progress,
      attempt: msg.attempt,
    }
  }
}


