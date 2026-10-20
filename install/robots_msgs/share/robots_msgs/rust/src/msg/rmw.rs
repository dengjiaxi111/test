#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "robots_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__robots_msgs__msg__EnemyPose() -> *const std::ffi::c_void;
}

#[link(name = "robots_msgs__rosidl_generator_c")]
extern "C" {
    fn robots_msgs__msg__EnemyPose__init(msg: *mut EnemyPose) -> bool;
    fn robots_msgs__msg__EnemyPose__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<EnemyPose>, size: usize) -> bool;
    fn robots_msgs__msg__EnemyPose__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<EnemyPose>);
    fn robots_msgs__msg__EnemyPose__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<EnemyPose>, out_seq: *mut rosidl_runtime_rs::Sequence<EnemyPose>) -> bool;
}

// Corresponds to robots_msgs__msg__EnemyPose
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// enemy pose

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct EnemyPose {

    // This member is not documented.
    #[allow(missing_docs)]
    pub enemy_dist: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub enemy_ori: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub enemy_num: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub enemy_x: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub enemy_y: f32,

}



impl Default for EnemyPose {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !robots_msgs__msg__EnemyPose__init(&mut msg as *mut _) {
        panic!("Call to robots_msgs__msg__EnemyPose__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for EnemyPose {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robots_msgs__msg__EnemyPose__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robots_msgs__msg__EnemyPose__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robots_msgs__msg__EnemyPose__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for EnemyPose {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for EnemyPose where Self: Sized {
  const TYPE_NAME: &'static str = "robots_msgs/msg/EnemyPose";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__robots_msgs__msg__EnemyPose() }
  }
}


#[link(name = "robots_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__robots_msgs__msg__GameStatus() -> *const std::ffi::c_void;
}

#[link(name = "robots_msgs__rosidl_generator_c")]
extern "C" {
    fn robots_msgs__msg__GameStatus__init(msg: *mut GameStatus) -> bool;
    fn robots_msgs__msg__GameStatus__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GameStatus>, size: usize) -> bool;
    fn robots_msgs__msg__GameStatus__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GameStatus>);
    fn robots_msgs__msg__GameStatus__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GameStatus>, out_seq: *mut rosidl_runtime_rs::Sequence<GameStatus>) -> bool;
}

// Corresponds to robots_msgs__msg__GameStatus
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// game status

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GameStatus {

    // This member is not documented.
    #[allow(missing_docs)]
    pub game_type: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub game_progress: u8,

    /// 当前阶段剩余时间
    pub stage_remain_time: u16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub my_hp: u16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub my_outpost_hp: u16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub my_base_hp: u16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub our_hero_x: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub our_hero_y: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub enemy_1_robot_hp: u16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub enemy_2_robot_hp: u16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub enemy_3_robot_hp: u16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub enemy_4_robot_hp: u16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub enemy_5_robot_hp: u16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub enemy_7_robot_hp: u16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub enemy_outpost_hp: u16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub enemy_base_hp: u16,

    /// 己方补给站前补血点的占领状态
    pub external_supply_area_occupied: u8,

    /// 己方补给站内部补血点的占领状态
    pub inner_supply_area_occupied: u8,

    /// 己方补给区的占领状态
    pub supply_area_occupied: u8,

    /// 己方小符激活状态
    pub our_small_buff_activated: u8,

    /// 己方大符激活状态
    pub our_big_buff_activated: u8,

    /// 己方堡垒占领状态
    pub our_fortress_status: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub remaining_gold_coin: u16,

}



impl Default for GameStatus {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !robots_msgs__msg__GameStatus__init(&mut msg as *mut _) {
        panic!("Call to robots_msgs__msg__GameStatus__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GameStatus {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robots_msgs__msg__GameStatus__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robots_msgs__msg__GameStatus__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robots_msgs__msg__GameStatus__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GameStatus {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GameStatus where Self: Sized {
  const TYPE_NAME: &'static str = "robots_msgs/msg/GameStatus";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__robots_msgs__msg__GameStatus() }
  }
}


#[link(name = "robots_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__robots_msgs__msg__RobotStatus() -> *const std::ffi::c_void;
}

#[link(name = "robots_msgs__rosidl_generator_c")]
extern "C" {
    fn robots_msgs__msg__RobotStatus__init(msg: *mut RobotStatus) -> bool;
    fn robots_msgs__msg__RobotStatus__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<RobotStatus>, size: usize) -> bool;
    fn robots_msgs__msg__RobotStatus__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<RobotStatus>);
    fn robots_msgs__msg__RobotStatus__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<RobotStatus>, out_seq: *mut rosidl_runtime_rs::Sequence<RobotStatus>) -> bool;
}

// Corresponds to robots_msgs__msg__RobotStatus
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// robot status

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RobotStatus {

    // This member is not documented.
    #[allow(missing_docs)]
    pub robot_id: u8,

    /// 本机器人位置 x 坐标，单位：m
    pub x: f32,

    /// 本机器人位置 y 坐标，单位：m
    pub y: f32,

    /// 本机器人测速模块的朝向，单位：度。正北为 0 度
    pub angle: f32,

    /// 机器人回血增益（百分比，值为 10 表示每秒恢复血量上限的 10%
    pub recovery_buff: u8,

    /// 机器人防御增益（百分比，值为 50 表示 50%防御增益
    pub defence_buff: u8,

    /// 机器人负防御增益（百分比，值为 30 表示-30%防御增益）
    pub vulnerability_buff: u8,

    /// 机器人攻击增益（百分比，值为 50 表示 50%攻击增益
    pub attack_buff: u16,

    /// 机器人剩余能量值反馈，以 16 进制标识机器人剩余能量值比例
    pub remaining_energy: u8,

    /// 17mm 弹丸允许发弹量
    pub projectile_allowance_17mm: u16,

    /// 己方堡垒
    pub fort_area: u8,

    /// 己方补血点
    pub supply_blood_area: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub local_exchange_projectile_allowance_17mm: u16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub remote_exchange_projectile_times: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub remote_exchange_health_times: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub can_free_rebirth: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub can_instant_rebirth: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub rebirth_need_coin: u16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub ttk_status: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub projectile_allowance_17mm_remain: u16,

    /// 云台手发的控制目标位置x坐标
    pub target_position_x: f32,

    /// 云台手发的控制目标位置y坐标
    pub target_position_y: f32,

}



impl Default for RobotStatus {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !robots_msgs__msg__RobotStatus__init(&mut msg as *mut _) {
        panic!("Call to robots_msgs__msg__RobotStatus__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for RobotStatus {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robots_msgs__msg__RobotStatus__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robots_msgs__msg__RobotStatus__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robots_msgs__msg__RobotStatus__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for RobotStatus {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for RobotStatus where Self: Sized {
  const TYPE_NAME: &'static str = "robots_msgs/msg/RobotStatus";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__robots_msgs__msg__RobotStatus() }
  }
}


#[link(name = "robots_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__robots_msgs__msg__GimbCmdFram() -> *const std::ffi::c_void;
}

#[link(name = "robots_msgs__rosidl_generator_c")]
extern "C" {
    fn robots_msgs__msg__GimbCmdFram__init(msg: *mut GimbCmdFram) -> bool;
    fn robots_msgs__msg__GimbCmdFram__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GimbCmdFram>, size: usize) -> bool;
    fn robots_msgs__msg__GimbCmdFram__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GimbCmdFram>);
    fn robots_msgs__msg__GimbCmdFram__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GimbCmdFram>, out_seq: *mut rosidl_runtime_rs::Sequence<GimbCmdFram>) -> bool;
}

// Corresponds to robots_msgs__msg__GimbCmdFram
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GimbCmdFram {

    // This member is not documented.
    #[allow(missing_docs)]
    pub center_yaw: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub armor_pitch: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub armor_yaw: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub spin_flag: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub shot_mode: u8,

}



impl Default for GimbCmdFram {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !robots_msgs__msg__GimbCmdFram__init(&mut msg as *mut _) {
        panic!("Call to robots_msgs__msg__GimbCmdFram__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GimbCmdFram {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robots_msgs__msg__GimbCmdFram__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robots_msgs__msg__GimbCmdFram__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robots_msgs__msg__GimbCmdFram__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GimbCmdFram {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GimbCmdFram where Self: Sized {
  const TYPE_NAME: &'static str = "robots_msgs/msg/GimbCmdFram";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__robots_msgs__msg__GimbCmdFram() }
  }
}


#[link(name = "robots_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__robots_msgs__msg__GimbalData() -> *const std::ffi::c_void;
}

#[link(name = "robots_msgs__rosidl_generator_c")]
extern "C" {
    fn robots_msgs__msg__GimbalData__init(msg: *mut GimbalData) -> bool;
    fn robots_msgs__msg__GimbalData__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GimbalData>, size: usize) -> bool;
    fn robots_msgs__msg__GimbalData__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GimbalData>);
    fn robots_msgs__msg__GimbalData__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GimbalData>, out_seq: *mut rosidl_runtime_rs::Sequence<GimbalData>) -> bool;
}

// Corresponds to robots_msgs__msg__GimbalData
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// gimbal data

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GimbalData {

    // This member is not documented.
    #[allow(missing_docs)]
    pub gimbal_yaw: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub gimbal_pitch: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub yaw_va: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub base_yaw: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub self_team: u8,

}



impl Default for GimbalData {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !robots_msgs__msg__GimbalData__init(&mut msg as *mut _) {
        panic!("Call to robots_msgs__msg__GimbalData__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GimbalData {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robots_msgs__msg__GimbalData__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robots_msgs__msg__GimbalData__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robots_msgs__msg__GimbalData__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GimbalData {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GimbalData where Self: Sized {
  const TYPE_NAME: &'static str = "robots_msgs/msg/GimbalData";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__robots_msgs__msg__GimbalData() }
  }
}


#[link(name = "robots_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__robots_msgs__msg__ModeCmd() -> *const std::ffi::c_void;
}

#[link(name = "robots_msgs__rosidl_generator_c")]
extern "C" {
    fn robots_msgs__msg__ModeCmd__init(msg: *mut ModeCmd) -> bool;
    fn robots_msgs__msg__ModeCmd__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ModeCmd>, size: usize) -> bool;
    fn robots_msgs__msg__ModeCmd__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ModeCmd>);
    fn robots_msgs__msg__ModeCmd__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ModeCmd>, out_seq: *mut rosidl_runtime_rs::Sequence<ModeCmd>) -> bool;
}

// Corresponds to robots_msgs__msg__ModeCmd
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ModeCmd {

    // This member is not documented.
    #[allow(missing_docs)]
    pub should_chassis_spin: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub should_gimbal_patrol: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub buy_bullet: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub rebirth: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub use_capacity: u8,

}



impl Default for ModeCmd {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !robots_msgs__msg__ModeCmd__init(&mut msg as *mut _) {
        panic!("Call to robots_msgs__msg__ModeCmd__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ModeCmd {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robots_msgs__msg__ModeCmd__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robots_msgs__msg__ModeCmd__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robots_msgs__msg__ModeCmd__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ModeCmd {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ModeCmd where Self: Sized {
  const TYPE_NAME: &'static str = "robots_msgs/msg/ModeCmd";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__robots_msgs__msg__ModeCmd() }
  }
}


#[link(name = "robots_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__robots_msgs__msg__MyPath() -> *const std::ffi::c_void;
}

#[link(name = "robots_msgs__rosidl_generator_c")]
extern "C" {
    fn robots_msgs__msg__MyPath__init(msg: *mut MyPath) -> bool;
    fn robots_msgs__msg__MyPath__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MyPath>, size: usize) -> bool;
    fn robots_msgs__msg__MyPath__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MyPath>);
    fn robots_msgs__msg__MyPath__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MyPath>, out_seq: *mut rosidl_runtime_rs::Sequence<MyPath>) -> bool;
}

// Corresponds to robots_msgs__msg__MyPath
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MyPath {

    // This member is not documented.
    #[allow(missing_docs)]
    pub intention: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub start_x: u16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub start_y: u16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub delta_x: rosidl_runtime_rs::Sequence<i8>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub delta_y: rosidl_runtime_rs::Sequence<i8>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub sender_id: u16,

}



impl Default for MyPath {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !robots_msgs__msg__MyPath__init(&mut msg as *mut _) {
        panic!("Call to robots_msgs__msg__MyPath__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MyPath {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robots_msgs__msg__MyPath__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robots_msgs__msg__MyPath__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robots_msgs__msg__MyPath__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MyPath {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MyPath where Self: Sized {
  const TYPE_NAME: &'static str = "robots_msgs/msg/MyPath";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__robots_msgs__msg__MyPath() }
  }
}


#[link(name = "robots_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__robots_msgs__msg__ChassisOdom() -> *const std::ffi::c_void;
}

#[link(name = "robots_msgs__rosidl_generator_c")]
extern "C" {
    fn robots_msgs__msg__ChassisOdom__init(msg: *mut ChassisOdom) -> bool;
    fn robots_msgs__msg__ChassisOdom__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ChassisOdom>, size: usize) -> bool;
    fn robots_msgs__msg__ChassisOdom__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ChassisOdom>);
    fn robots_msgs__msg__ChassisOdom__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ChassisOdom>, out_seq: *mut rosidl_runtime_rs::Sequence<ChassisOdom>) -> bool;
}

// Corresponds to robots_msgs__msg__ChassisOdom
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ChassisOdom {

    // This member is not documented.
    #[allow(missing_docs)]
    pub speed_x: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub speed_y: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub speed_w: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub gimbal_angle: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub capacitor_voltage: f32,

}



impl Default for ChassisOdom {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !robots_msgs__msg__ChassisOdom__init(&mut msg as *mut _) {
        panic!("Call to robots_msgs__msg__ChassisOdom__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ChassisOdom {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robots_msgs__msg__ChassisOdom__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robots_msgs__msg__ChassisOdom__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robots_msgs__msg__ChassisOdom__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ChassisOdom {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ChassisOdom where Self: Sized {
  const TYPE_NAME: &'static str = "robots_msgs/msg/ChassisOdom";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__robots_msgs__msg__ChassisOdom() }
  }
}


