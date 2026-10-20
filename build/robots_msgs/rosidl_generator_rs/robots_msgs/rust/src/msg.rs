#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to robots_msgs__msg__EnemyPose
/// enemy pose

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::EnemyPose::default())
  }
}

impl rosidl_runtime_rs::Message for EnemyPose {
  type RmwMsg = super::msg::rmw::EnemyPose;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        enemy_dist: msg.enemy_dist,
        enemy_ori: msg.enemy_ori,
        enemy_num: msg.enemy_num,
        enemy_x: msg.enemy_x,
        enemy_y: msg.enemy_y,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      enemy_dist: msg.enemy_dist,
      enemy_ori: msg.enemy_ori,
      enemy_num: msg.enemy_num,
      enemy_x: msg.enemy_x,
      enemy_y: msg.enemy_y,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      enemy_dist: msg.enemy_dist,
      enemy_ori: msg.enemy_ori,
      enemy_num: msg.enemy_num,
      enemy_x: msg.enemy_x,
      enemy_y: msg.enemy_y,
    }
  }
}


// Corresponds to robots_msgs__msg__GameStatus
/// game status

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::GameStatus::default())
  }
}

impl rosidl_runtime_rs::Message for GameStatus {
  type RmwMsg = super::msg::rmw::GameStatus;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        game_type: msg.game_type,
        game_progress: msg.game_progress,
        stage_remain_time: msg.stage_remain_time,
        my_hp: msg.my_hp,
        my_outpost_hp: msg.my_outpost_hp,
        my_base_hp: msg.my_base_hp,
        our_hero_x: msg.our_hero_x,
        our_hero_y: msg.our_hero_y,
        enemy_1_robot_hp: msg.enemy_1_robot_hp,
        enemy_2_robot_hp: msg.enemy_2_robot_hp,
        enemy_3_robot_hp: msg.enemy_3_robot_hp,
        enemy_4_robot_hp: msg.enemy_4_robot_hp,
        enemy_5_robot_hp: msg.enemy_5_robot_hp,
        enemy_7_robot_hp: msg.enemy_7_robot_hp,
        enemy_outpost_hp: msg.enemy_outpost_hp,
        enemy_base_hp: msg.enemy_base_hp,
        external_supply_area_occupied: msg.external_supply_area_occupied,
        inner_supply_area_occupied: msg.inner_supply_area_occupied,
        supply_area_occupied: msg.supply_area_occupied,
        our_small_buff_activated: msg.our_small_buff_activated,
        our_big_buff_activated: msg.our_big_buff_activated,
        our_fortress_status: msg.our_fortress_status,
        remaining_gold_coin: msg.remaining_gold_coin,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      game_type: msg.game_type,
      game_progress: msg.game_progress,
      stage_remain_time: msg.stage_remain_time,
      my_hp: msg.my_hp,
      my_outpost_hp: msg.my_outpost_hp,
      my_base_hp: msg.my_base_hp,
      our_hero_x: msg.our_hero_x,
      our_hero_y: msg.our_hero_y,
      enemy_1_robot_hp: msg.enemy_1_robot_hp,
      enemy_2_robot_hp: msg.enemy_2_robot_hp,
      enemy_3_robot_hp: msg.enemy_3_robot_hp,
      enemy_4_robot_hp: msg.enemy_4_robot_hp,
      enemy_5_robot_hp: msg.enemy_5_robot_hp,
      enemy_7_robot_hp: msg.enemy_7_robot_hp,
      enemy_outpost_hp: msg.enemy_outpost_hp,
      enemy_base_hp: msg.enemy_base_hp,
      external_supply_area_occupied: msg.external_supply_area_occupied,
      inner_supply_area_occupied: msg.inner_supply_area_occupied,
      supply_area_occupied: msg.supply_area_occupied,
      our_small_buff_activated: msg.our_small_buff_activated,
      our_big_buff_activated: msg.our_big_buff_activated,
      our_fortress_status: msg.our_fortress_status,
      remaining_gold_coin: msg.remaining_gold_coin,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      game_type: msg.game_type,
      game_progress: msg.game_progress,
      stage_remain_time: msg.stage_remain_time,
      my_hp: msg.my_hp,
      my_outpost_hp: msg.my_outpost_hp,
      my_base_hp: msg.my_base_hp,
      our_hero_x: msg.our_hero_x,
      our_hero_y: msg.our_hero_y,
      enemy_1_robot_hp: msg.enemy_1_robot_hp,
      enemy_2_robot_hp: msg.enemy_2_robot_hp,
      enemy_3_robot_hp: msg.enemy_3_robot_hp,
      enemy_4_robot_hp: msg.enemy_4_robot_hp,
      enemy_5_robot_hp: msg.enemy_5_robot_hp,
      enemy_7_robot_hp: msg.enemy_7_robot_hp,
      enemy_outpost_hp: msg.enemy_outpost_hp,
      enemy_base_hp: msg.enemy_base_hp,
      external_supply_area_occupied: msg.external_supply_area_occupied,
      inner_supply_area_occupied: msg.inner_supply_area_occupied,
      supply_area_occupied: msg.supply_area_occupied,
      our_small_buff_activated: msg.our_small_buff_activated,
      our_big_buff_activated: msg.our_big_buff_activated,
      our_fortress_status: msg.our_fortress_status,
      remaining_gold_coin: msg.remaining_gold_coin,
    }
  }
}


// Corresponds to robots_msgs__msg__RobotStatus
/// robot status

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::RobotStatus::default())
  }
}

impl rosidl_runtime_rs::Message for RobotStatus {
  type RmwMsg = super::msg::rmw::RobotStatus;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        robot_id: msg.robot_id,
        x: msg.x,
        y: msg.y,
        angle: msg.angle,
        recovery_buff: msg.recovery_buff,
        defence_buff: msg.defence_buff,
        vulnerability_buff: msg.vulnerability_buff,
        attack_buff: msg.attack_buff,
        remaining_energy: msg.remaining_energy,
        projectile_allowance_17mm: msg.projectile_allowance_17mm,
        fort_area: msg.fort_area,
        supply_blood_area: msg.supply_blood_area,
        local_exchange_projectile_allowance_17mm: msg.local_exchange_projectile_allowance_17mm,
        remote_exchange_projectile_times: msg.remote_exchange_projectile_times,
        remote_exchange_health_times: msg.remote_exchange_health_times,
        can_free_rebirth: msg.can_free_rebirth,
        can_instant_rebirth: msg.can_instant_rebirth,
        rebirth_need_coin: msg.rebirth_need_coin,
        ttk_status: msg.ttk_status,
        projectile_allowance_17mm_remain: msg.projectile_allowance_17mm_remain,
        target_position_x: msg.target_position_x,
        target_position_y: msg.target_position_y,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      robot_id: msg.robot_id,
      x: msg.x,
      y: msg.y,
      angle: msg.angle,
      recovery_buff: msg.recovery_buff,
      defence_buff: msg.defence_buff,
      vulnerability_buff: msg.vulnerability_buff,
      attack_buff: msg.attack_buff,
      remaining_energy: msg.remaining_energy,
      projectile_allowance_17mm: msg.projectile_allowance_17mm,
      fort_area: msg.fort_area,
      supply_blood_area: msg.supply_blood_area,
      local_exchange_projectile_allowance_17mm: msg.local_exchange_projectile_allowance_17mm,
      remote_exchange_projectile_times: msg.remote_exchange_projectile_times,
      remote_exchange_health_times: msg.remote_exchange_health_times,
      can_free_rebirth: msg.can_free_rebirth,
      can_instant_rebirth: msg.can_instant_rebirth,
      rebirth_need_coin: msg.rebirth_need_coin,
      ttk_status: msg.ttk_status,
      projectile_allowance_17mm_remain: msg.projectile_allowance_17mm_remain,
      target_position_x: msg.target_position_x,
      target_position_y: msg.target_position_y,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      robot_id: msg.robot_id,
      x: msg.x,
      y: msg.y,
      angle: msg.angle,
      recovery_buff: msg.recovery_buff,
      defence_buff: msg.defence_buff,
      vulnerability_buff: msg.vulnerability_buff,
      attack_buff: msg.attack_buff,
      remaining_energy: msg.remaining_energy,
      projectile_allowance_17mm: msg.projectile_allowance_17mm,
      fort_area: msg.fort_area,
      supply_blood_area: msg.supply_blood_area,
      local_exchange_projectile_allowance_17mm: msg.local_exchange_projectile_allowance_17mm,
      remote_exchange_projectile_times: msg.remote_exchange_projectile_times,
      remote_exchange_health_times: msg.remote_exchange_health_times,
      can_free_rebirth: msg.can_free_rebirth,
      can_instant_rebirth: msg.can_instant_rebirth,
      rebirth_need_coin: msg.rebirth_need_coin,
      ttk_status: msg.ttk_status,
      projectile_allowance_17mm_remain: msg.projectile_allowance_17mm_remain,
      target_position_x: msg.target_position_x,
      target_position_y: msg.target_position_y,
    }
  }
}


// Corresponds to robots_msgs__msg__GimbCmdFram

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::GimbCmdFram::default())
  }
}

impl rosidl_runtime_rs::Message for GimbCmdFram {
  type RmwMsg = super::msg::rmw::GimbCmdFram;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        center_yaw: msg.center_yaw,
        armor_pitch: msg.armor_pitch,
        armor_yaw: msg.armor_yaw,
        spin_flag: msg.spin_flag,
        shot_mode: msg.shot_mode,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      center_yaw: msg.center_yaw,
      armor_pitch: msg.armor_pitch,
      armor_yaw: msg.armor_yaw,
      spin_flag: msg.spin_flag,
      shot_mode: msg.shot_mode,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      center_yaw: msg.center_yaw,
      armor_pitch: msg.armor_pitch,
      armor_yaw: msg.armor_yaw,
      spin_flag: msg.spin_flag,
      shot_mode: msg.shot_mode,
    }
  }
}


// Corresponds to robots_msgs__msg__GimbalData
/// gimbal data

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::GimbalData::default())
  }
}

impl rosidl_runtime_rs::Message for GimbalData {
  type RmwMsg = super::msg::rmw::GimbalData;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        gimbal_yaw: msg.gimbal_yaw,
        gimbal_pitch: msg.gimbal_pitch,
        yaw_va: msg.yaw_va,
        base_yaw: msg.base_yaw,
        self_team: msg.self_team,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      gimbal_yaw: msg.gimbal_yaw,
      gimbal_pitch: msg.gimbal_pitch,
      yaw_va: msg.yaw_va,
      base_yaw: msg.base_yaw,
      self_team: msg.self_team,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      gimbal_yaw: msg.gimbal_yaw,
      gimbal_pitch: msg.gimbal_pitch,
      yaw_va: msg.yaw_va,
      base_yaw: msg.base_yaw,
      self_team: msg.self_team,
    }
  }
}


// Corresponds to robots_msgs__msg__ModeCmd

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ModeCmd::default())
  }
}

impl rosidl_runtime_rs::Message for ModeCmd {
  type RmwMsg = super::msg::rmw::ModeCmd;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        should_chassis_spin: msg.should_chassis_spin,
        should_gimbal_patrol: msg.should_gimbal_patrol,
        buy_bullet: msg.buy_bullet,
        rebirth: msg.rebirth,
        use_capacity: msg.use_capacity,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      should_chassis_spin: msg.should_chassis_spin,
      should_gimbal_patrol: msg.should_gimbal_patrol,
      buy_bullet: msg.buy_bullet,
      rebirth: msg.rebirth,
      use_capacity: msg.use_capacity,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      should_chassis_spin: msg.should_chassis_spin,
      should_gimbal_patrol: msg.should_gimbal_patrol,
      buy_bullet: msg.buy_bullet,
      rebirth: msg.rebirth,
      use_capacity: msg.use_capacity,
    }
  }
}


// Corresponds to robots_msgs__msg__MyPath

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    pub delta_x: Vec<i8>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub delta_y: Vec<i8>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub sender_id: u16,

}



impl Default for MyPath {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::MyPath::default())
  }
}

impl rosidl_runtime_rs::Message for MyPath {
  type RmwMsg = super::msg::rmw::MyPath;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        intention: msg.intention,
        start_x: msg.start_x,
        start_y: msg.start_y,
        delta_x: msg.delta_x.as_slice().into(),
        delta_y: msg.delta_y.as_slice().into(),
        sender_id: msg.sender_id,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      intention: msg.intention,
      start_x: msg.start_x,
      start_y: msg.start_y,
        delta_x: msg.delta_x.as_slice().into(),
        delta_y: msg.delta_y.as_slice().into(),
      sender_id: msg.sender_id,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      intention: msg.intention,
      start_x: msg.start_x,
      start_y: msg.start_y,
      delta_x: msg.delta_x.into(),
      delta_y: msg.delta_y.into(),
      sender_id: msg.sender_id,
    }
  }
}


// Corresponds to robots_msgs__msg__ChassisOdom

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ChassisOdom::default())
  }
}

impl rosidl_runtime_rs::Message for ChassisOdom {
  type RmwMsg = super::msg::rmw::ChassisOdom;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        speed_x: msg.speed_x,
        speed_y: msg.speed_y,
        speed_w: msg.speed_w,
        gimbal_angle: msg.gimbal_angle,
        capacitor_voltage: msg.capacitor_voltage,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      speed_x: msg.speed_x,
      speed_y: msg.speed_y,
      speed_w: msg.speed_w,
      gimbal_angle: msg.gimbal_angle,
      capacitor_voltage: msg.capacitor_voltage,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      speed_x: msg.speed_x,
      speed_y: msg.speed_y,
      speed_w: msg.speed_w,
      gimbal_angle: msg.gimbal_angle,
      capacitor_voltage: msg.capacitor_voltage,
    }
  }
}


