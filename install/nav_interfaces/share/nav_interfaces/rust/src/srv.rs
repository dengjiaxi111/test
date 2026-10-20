#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to nav_interfaces__srv__ReloadTerrain_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ReloadTerrain_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub expected_path: std::string::String,

}



impl Default for ReloadTerrain_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::ReloadTerrain_Request::default())
  }
}

impl rosidl_runtime_rs::Message for ReloadTerrain_Request {
  type RmwMsg = super::srv::rmw::ReloadTerrain_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        expected_path: msg.expected_path.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        expected_path: msg.expected_path.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      expected_path: msg.expected_path.to_string(),
    }
  }
}


// Corresponds to nav_interfaces__srv__ReloadTerrain_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ReloadTerrain_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub reason: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub terrain_path: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub terrain_revision: u64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub replanning_triggered: bool,

}



impl Default for ReloadTerrain_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::ReloadTerrain_Response::default())
  }
}

impl rosidl_runtime_rs::Message for ReloadTerrain_Response {
  type RmwMsg = super::srv::rmw::ReloadTerrain_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        reason: msg.reason.as_str().into(),
        terrain_path: msg.terrain_path.as_str().into(),
        terrain_revision: msg.terrain_revision,
        replanning_triggered: msg.replanning_triggered,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        reason: msg.reason.as_str().into(),
        terrain_path: msg.terrain_path.as_str().into(),
      terrain_revision: msg.terrain_revision,
      replanning_triggered: msg.replanning_triggered,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      reason: msg.reason.to_string(),
      terrain_path: msg.terrain_path.to_string(),
      terrain_revision: msg.terrain_revision,
      replanning_triggered: msg.replanning_triggered,
    }
  }
}


// Corresponds to nav_interfaces__srv__GetTemporaryMap_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetTemporaryMap_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for GetTemporaryMap_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetTemporaryMap_Request::default())
  }
}

impl rosidl_runtime_rs::Message for GetTemporaryMap_Request {
  type RmwMsg = super::srv::rmw::GetTemporaryMap_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
    }
  }
}


// Corresponds to nav_interfaces__srv__GetTemporaryMap_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetTemporaryMap_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub reason: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub map_path: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub session_id: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub source_id: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub map_revision: u64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub source_map: nav_msgs::msg::OccupancyGrid,


    // This member is not documented.
    #[allow(missing_docs)]
    pub indices: Vec<u32>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub values: Vec<i8>,

}



impl Default for GetTemporaryMap_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetTemporaryMap_Response::default())
  }
}

impl rosidl_runtime_rs::Message for GetTemporaryMap_Response {
  type RmwMsg = super::srv::rmw::GetTemporaryMap_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        reason: msg.reason.as_str().into(),
        map_path: msg.map_path.as_str().into(),
        session_id: msg.session_id.as_str().into(),
        source_id: msg.source_id.as_str().into(),
        map_revision: msg.map_revision,
        source_map: nav_msgs::msg::OccupancyGrid::into_rmw_message(std::borrow::Cow::Owned(msg.source_map)).into_owned(),
        indices: msg.indices.as_slice().into(),
        values: msg.values.as_slice().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        reason: msg.reason.as_str().into(),
        map_path: msg.map_path.as_str().into(),
        session_id: msg.session_id.as_str().into(),
        source_id: msg.source_id.as_str().into(),
      map_revision: msg.map_revision,
        source_map: nav_msgs::msg::OccupancyGrid::into_rmw_message(std::borrow::Cow::Borrowed(&msg.source_map)).into_owned(),
        indices: msg.indices.as_slice().into(),
        values: msg.values.as_slice().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      reason: msg.reason.to_string(),
      map_path: msg.map_path.to_string(),
      session_id: msg.session_id.to_string(),
      source_id: msg.source_id.to_string(),
      map_revision: msg.map_revision,
      source_map: nav_msgs::msg::OccupancyGrid::from_rmw_message(msg.source_map),
      indices: msg.indices.into(),
      values: msg.values.into(),
    }
  }
}


// Corresponds to nav_interfaces__srv__ApplyTemporaryMap_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ApplyTemporaryMap_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub expected_session_id: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub expected_source_id: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub expected_map_revision: u64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub indices: Vec<u32>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub values: Vec<i8>,

}



impl Default for ApplyTemporaryMap_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::ApplyTemporaryMap_Request::default())
  }
}

impl rosidl_runtime_rs::Message for ApplyTemporaryMap_Request {
  type RmwMsg = super::srv::rmw::ApplyTemporaryMap_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        expected_session_id: msg.expected_session_id.as_str().into(),
        expected_source_id: msg.expected_source_id.as_str().into(),
        expected_map_revision: msg.expected_map_revision,
        indices: msg.indices.as_slice().into(),
        values: msg.values.as_slice().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        expected_session_id: msg.expected_session_id.as_str().into(),
        expected_source_id: msg.expected_source_id.as_str().into(),
      expected_map_revision: msg.expected_map_revision,
        indices: msg.indices.as_slice().into(),
        values: msg.values.as_slice().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      expected_session_id: msg.expected_session_id.to_string(),
      expected_source_id: msg.expected_source_id.to_string(),
      expected_map_revision: msg.expected_map_revision,
      indices: msg.indices.into(),
      values: msg.values.into(),
    }
  }
}


// Corresponds to nav_interfaces__srv__ApplyTemporaryMap_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ApplyTemporaryMap_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub reason: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub map_revision: u64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub replanning_triggered: bool,

}



impl Default for ApplyTemporaryMap_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::ApplyTemporaryMap_Response::default())
  }
}

impl rosidl_runtime_rs::Message for ApplyTemporaryMap_Response {
  type RmwMsg = super::srv::rmw::ApplyTemporaryMap_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        reason: msg.reason.as_str().into(),
        map_revision: msg.map_revision,
        replanning_triggered: msg.replanning_triggered,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        reason: msg.reason.as_str().into(),
      map_revision: msg.map_revision,
      replanning_triggered: msg.replanning_triggered,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      reason: msg.reason.to_string(),
      map_revision: msg.map_revision,
      replanning_triggered: msg.replanning_triggered,
    }
  }
}


// Corresponds to nav_interfaces__srv__GetHolePassageConfig_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetHolePassageConfig_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for GetHolePassageConfig_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetHolePassageConfig_Request::default())
  }
}

impl rosidl_runtime_rs::Message for GetHolePassageConfig_Request {
  type RmwMsg = super::srv::rmw::GetHolePassageConfig_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
    }
  }
}


// Corresponds to nav_interfaces__srv__GetHolePassageConfig_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetHolePassageConfig_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub manual_config_active: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub reason: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub config_yaml: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub config_path: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub terrain_path: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub terrain_geometry: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub config_revision: u64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub terrain_revision: u64,

}



impl Default for GetHolePassageConfig_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetHolePassageConfig_Response::default())
  }
}

impl rosidl_runtime_rs::Message for GetHolePassageConfig_Response {
  type RmwMsg = super::srv::rmw::GetHolePassageConfig_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        manual_config_active: msg.manual_config_active,
        reason: msg.reason.as_str().into(),
        config_yaml: msg.config_yaml.as_str().into(),
        config_path: msg.config_path.as_str().into(),
        terrain_path: msg.terrain_path.as_str().into(),
        terrain_geometry: msg.terrain_geometry.as_str().into(),
        config_revision: msg.config_revision,
        terrain_revision: msg.terrain_revision,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
      manual_config_active: msg.manual_config_active,
        reason: msg.reason.as_str().into(),
        config_yaml: msg.config_yaml.as_str().into(),
        config_path: msg.config_path.as_str().into(),
        terrain_path: msg.terrain_path.as_str().into(),
        terrain_geometry: msg.terrain_geometry.as_str().into(),
      config_revision: msg.config_revision,
      terrain_revision: msg.terrain_revision,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      manual_config_active: msg.manual_config_active,
      reason: msg.reason.to_string(),
      config_yaml: msg.config_yaml.to_string(),
      config_path: msg.config_path.to_string(),
      terrain_path: msg.terrain_path.to_string(),
      terrain_geometry: msg.terrain_geometry.to_string(),
      config_revision: msg.config_revision,
      terrain_revision: msg.terrain_revision,
    }
  }
}


// Corresponds to nav_interfaces__srv__ApplyHolePassageConfig_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ApplyHolePassageConfig_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub config_yaml: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub expected_config_revision: u64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub expected_terrain_revision: u64,

}



impl Default for ApplyHolePassageConfig_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::ApplyHolePassageConfig_Request::default())
  }
}

impl rosidl_runtime_rs::Message for ApplyHolePassageConfig_Request {
  type RmwMsg = super::srv::rmw::ApplyHolePassageConfig_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        config_yaml: msg.config_yaml.as_str().into(),
        expected_config_revision: msg.expected_config_revision,
        expected_terrain_revision: msg.expected_terrain_revision,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        config_yaml: msg.config_yaml.as_str().into(),
      expected_config_revision: msg.expected_config_revision,
      expected_terrain_revision: msg.expected_terrain_revision,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      config_yaml: msg.config_yaml.to_string(),
      expected_config_revision: msg.expected_config_revision,
      expected_terrain_revision: msg.expected_terrain_revision,
    }
  }
}


// Corresponds to nav_interfaces__srv__ApplyHolePassageConfig_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ApplyHolePassageConfig_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub reason: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub config_revision: u64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub terrain_revision: u64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub replanning_triggered: bool,

}



impl Default for ApplyHolePassageConfig_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::ApplyHolePassageConfig_Response::default())
  }
}

impl rosidl_runtime_rs::Message for ApplyHolePassageConfig_Response {
  type RmwMsg = super::srv::rmw::ApplyHolePassageConfig_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        reason: msg.reason.as_str().into(),
        config_revision: msg.config_revision,
        terrain_revision: msg.terrain_revision,
        replanning_triggered: msg.replanning_triggered,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        reason: msg.reason.as_str().into(),
      config_revision: msg.config_revision,
      terrain_revision: msg.terrain_revision,
      replanning_triggered: msg.replanning_triggered,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      reason: msg.reason.to_string(),
      config_revision: msg.config_revision,
      terrain_revision: msg.terrain_revision,
      replanning_triggered: msg.replanning_triggered,
    }
  }
}


// Corresponds to nav_interfaces__srv__SaveHolePassageConfig_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SaveHolePassageConfig_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub expected_config_revision: u64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub expected_terrain_revision: u64,

}



impl Default for SaveHolePassageConfig_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SaveHolePassageConfig_Request::default())
  }
}

impl rosidl_runtime_rs::Message for SaveHolePassageConfig_Request {
  type RmwMsg = super::srv::rmw::SaveHolePassageConfig_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        expected_config_revision: msg.expected_config_revision,
        expected_terrain_revision: msg.expected_terrain_revision,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      expected_config_revision: msg.expected_config_revision,
      expected_terrain_revision: msg.expected_terrain_revision,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      expected_config_revision: msg.expected_config_revision,
      expected_terrain_revision: msg.expected_terrain_revision,
    }
  }
}


// Corresponds to nav_interfaces__srv__SaveHolePassageConfig_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SaveHolePassageConfig_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub reason: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub config_path: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub config_revision: u64,

}



impl Default for SaveHolePassageConfig_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SaveHolePassageConfig_Response::default())
  }
}

impl rosidl_runtime_rs::Message for SaveHolePassageConfig_Response {
  type RmwMsg = super::srv::rmw::SaveHolePassageConfig_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        reason: msg.reason.as_str().into(),
        config_path: msg.config_path.as_str().into(),
        config_revision: msg.config_revision,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        reason: msg.reason.as_str().into(),
        config_path: msg.config_path.as_str().into(),
      config_revision: msg.config_revision,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      reason: msg.reason.to_string(),
      config_path: msg.config_path.to_string(),
      config_revision: msg.config_revision,
    }
  }
}






#[link(name = "nav_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__nav_interfaces__srv__ReloadTerrain() -> *const std::ffi::c_void;
}

// Corresponds to nav_interfaces__srv__ReloadTerrain
#[allow(missing_docs, non_camel_case_types)]
pub struct ReloadTerrain;

impl rosidl_runtime_rs::Service for ReloadTerrain {
    type Request = ReloadTerrain_Request;
    type Response = ReloadTerrain_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__nav_interfaces__srv__ReloadTerrain() }
    }
}




#[link(name = "nav_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__nav_interfaces__srv__GetTemporaryMap() -> *const std::ffi::c_void;
}

// Corresponds to nav_interfaces__srv__GetTemporaryMap
#[allow(missing_docs, non_camel_case_types)]
pub struct GetTemporaryMap;

impl rosidl_runtime_rs::Service for GetTemporaryMap {
    type Request = GetTemporaryMap_Request;
    type Response = GetTemporaryMap_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__nav_interfaces__srv__GetTemporaryMap() }
    }
}




#[link(name = "nav_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__nav_interfaces__srv__ApplyTemporaryMap() -> *const std::ffi::c_void;
}

// Corresponds to nav_interfaces__srv__ApplyTemporaryMap
#[allow(missing_docs, non_camel_case_types)]
pub struct ApplyTemporaryMap;

impl rosidl_runtime_rs::Service for ApplyTemporaryMap {
    type Request = ApplyTemporaryMap_Request;
    type Response = ApplyTemporaryMap_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__nav_interfaces__srv__ApplyTemporaryMap() }
    }
}




#[link(name = "nav_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__nav_interfaces__srv__GetHolePassageConfig() -> *const std::ffi::c_void;
}

// Corresponds to nav_interfaces__srv__GetHolePassageConfig
#[allow(missing_docs, non_camel_case_types)]
pub struct GetHolePassageConfig;

impl rosidl_runtime_rs::Service for GetHolePassageConfig {
    type Request = GetHolePassageConfig_Request;
    type Response = GetHolePassageConfig_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__nav_interfaces__srv__GetHolePassageConfig() }
    }
}




#[link(name = "nav_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__nav_interfaces__srv__ApplyHolePassageConfig() -> *const std::ffi::c_void;
}

// Corresponds to nav_interfaces__srv__ApplyHolePassageConfig
#[allow(missing_docs, non_camel_case_types)]
pub struct ApplyHolePassageConfig;

impl rosidl_runtime_rs::Service for ApplyHolePassageConfig {
    type Request = ApplyHolePassageConfig_Request;
    type Response = ApplyHolePassageConfig_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__nav_interfaces__srv__ApplyHolePassageConfig() }
    }
}




#[link(name = "nav_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__nav_interfaces__srv__SaveHolePassageConfig() -> *const std::ffi::c_void;
}

// Corresponds to nav_interfaces__srv__SaveHolePassageConfig
#[allow(missing_docs, non_camel_case_types)]
pub struct SaveHolePassageConfig;

impl rosidl_runtime_rs::Service for SaveHolePassageConfig {
    type Request = SaveHolePassageConfig_Request;
    type Response = SaveHolePassageConfig_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__nav_interfaces__srv__SaveHolePassageConfig() }
    }
}


