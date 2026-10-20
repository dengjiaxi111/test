#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "nav_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__nav_interfaces__srv__ReloadTerrain_Request() -> *const std::ffi::c_void;
}

#[link(name = "nav_interfaces__rosidl_generator_c")]
extern "C" {
    fn nav_interfaces__srv__ReloadTerrain_Request__init(msg: *mut ReloadTerrain_Request) -> bool;
    fn nav_interfaces__srv__ReloadTerrain_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ReloadTerrain_Request>, size: usize) -> bool;
    fn nav_interfaces__srv__ReloadTerrain_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ReloadTerrain_Request>);
    fn nav_interfaces__srv__ReloadTerrain_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ReloadTerrain_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<ReloadTerrain_Request>) -> bool;
}

// Corresponds to nav_interfaces__srv__ReloadTerrain_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ReloadTerrain_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub expected_path: rosidl_runtime_rs::String,

}



impl Default for ReloadTerrain_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !nav_interfaces__srv__ReloadTerrain_Request__init(&mut msg as *mut _) {
        panic!("Call to nav_interfaces__srv__ReloadTerrain_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ReloadTerrain_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_interfaces__srv__ReloadTerrain_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_interfaces__srv__ReloadTerrain_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_interfaces__srv__ReloadTerrain_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ReloadTerrain_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ReloadTerrain_Request where Self: Sized {
  const TYPE_NAME: &'static str = "nav_interfaces/srv/ReloadTerrain_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__nav_interfaces__srv__ReloadTerrain_Request() }
  }
}


#[link(name = "nav_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__nav_interfaces__srv__ReloadTerrain_Response() -> *const std::ffi::c_void;
}

#[link(name = "nav_interfaces__rosidl_generator_c")]
extern "C" {
    fn nav_interfaces__srv__ReloadTerrain_Response__init(msg: *mut ReloadTerrain_Response) -> bool;
    fn nav_interfaces__srv__ReloadTerrain_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ReloadTerrain_Response>, size: usize) -> bool;
    fn nav_interfaces__srv__ReloadTerrain_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ReloadTerrain_Response>);
    fn nav_interfaces__srv__ReloadTerrain_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ReloadTerrain_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<ReloadTerrain_Response>) -> bool;
}

// Corresponds to nav_interfaces__srv__ReloadTerrain_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ReloadTerrain_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub reason: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub terrain_path: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub terrain_revision: u64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub replanning_triggered: bool,

}



impl Default for ReloadTerrain_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !nav_interfaces__srv__ReloadTerrain_Response__init(&mut msg as *mut _) {
        panic!("Call to nav_interfaces__srv__ReloadTerrain_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ReloadTerrain_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_interfaces__srv__ReloadTerrain_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_interfaces__srv__ReloadTerrain_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_interfaces__srv__ReloadTerrain_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ReloadTerrain_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ReloadTerrain_Response where Self: Sized {
  const TYPE_NAME: &'static str = "nav_interfaces/srv/ReloadTerrain_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__nav_interfaces__srv__ReloadTerrain_Response() }
  }
}


#[link(name = "nav_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__nav_interfaces__srv__GetTemporaryMap_Request() -> *const std::ffi::c_void;
}

#[link(name = "nav_interfaces__rosidl_generator_c")]
extern "C" {
    fn nav_interfaces__srv__GetTemporaryMap_Request__init(msg: *mut GetTemporaryMap_Request) -> bool;
    fn nav_interfaces__srv__GetTemporaryMap_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetTemporaryMap_Request>, size: usize) -> bool;
    fn nav_interfaces__srv__GetTemporaryMap_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetTemporaryMap_Request>);
    fn nav_interfaces__srv__GetTemporaryMap_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetTemporaryMap_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<GetTemporaryMap_Request>) -> bool;
}

// Corresponds to nav_interfaces__srv__GetTemporaryMap_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetTemporaryMap_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for GetTemporaryMap_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !nav_interfaces__srv__GetTemporaryMap_Request__init(&mut msg as *mut _) {
        panic!("Call to nav_interfaces__srv__GetTemporaryMap_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetTemporaryMap_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_interfaces__srv__GetTemporaryMap_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_interfaces__srv__GetTemporaryMap_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_interfaces__srv__GetTemporaryMap_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetTemporaryMap_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetTemporaryMap_Request where Self: Sized {
  const TYPE_NAME: &'static str = "nav_interfaces/srv/GetTemporaryMap_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__nav_interfaces__srv__GetTemporaryMap_Request() }
  }
}


#[link(name = "nav_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__nav_interfaces__srv__GetTemporaryMap_Response() -> *const std::ffi::c_void;
}

#[link(name = "nav_interfaces__rosidl_generator_c")]
extern "C" {
    fn nav_interfaces__srv__GetTemporaryMap_Response__init(msg: *mut GetTemporaryMap_Response) -> bool;
    fn nav_interfaces__srv__GetTemporaryMap_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetTemporaryMap_Response>, size: usize) -> bool;
    fn nav_interfaces__srv__GetTemporaryMap_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetTemporaryMap_Response>);
    fn nav_interfaces__srv__GetTemporaryMap_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetTemporaryMap_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<GetTemporaryMap_Response>) -> bool;
}

// Corresponds to nav_interfaces__srv__GetTemporaryMap_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetTemporaryMap_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub reason: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub map_path: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub session_id: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub source_id: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub map_revision: u64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub source_map: nav_msgs::msg::rmw::OccupancyGrid,


    // This member is not documented.
    #[allow(missing_docs)]
    pub indices: rosidl_runtime_rs::Sequence<u32>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub values: rosidl_runtime_rs::Sequence<i8>,

}



impl Default for GetTemporaryMap_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !nav_interfaces__srv__GetTemporaryMap_Response__init(&mut msg as *mut _) {
        panic!("Call to nav_interfaces__srv__GetTemporaryMap_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetTemporaryMap_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_interfaces__srv__GetTemporaryMap_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_interfaces__srv__GetTemporaryMap_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_interfaces__srv__GetTemporaryMap_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetTemporaryMap_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetTemporaryMap_Response where Self: Sized {
  const TYPE_NAME: &'static str = "nav_interfaces/srv/GetTemporaryMap_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__nav_interfaces__srv__GetTemporaryMap_Response() }
  }
}


#[link(name = "nav_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__nav_interfaces__srv__ApplyTemporaryMap_Request() -> *const std::ffi::c_void;
}

#[link(name = "nav_interfaces__rosidl_generator_c")]
extern "C" {
    fn nav_interfaces__srv__ApplyTemporaryMap_Request__init(msg: *mut ApplyTemporaryMap_Request) -> bool;
    fn nav_interfaces__srv__ApplyTemporaryMap_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ApplyTemporaryMap_Request>, size: usize) -> bool;
    fn nav_interfaces__srv__ApplyTemporaryMap_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ApplyTemporaryMap_Request>);
    fn nav_interfaces__srv__ApplyTemporaryMap_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ApplyTemporaryMap_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<ApplyTemporaryMap_Request>) -> bool;
}

// Corresponds to nav_interfaces__srv__ApplyTemporaryMap_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ApplyTemporaryMap_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub expected_session_id: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub expected_source_id: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub expected_map_revision: u64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub indices: rosidl_runtime_rs::Sequence<u32>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub values: rosidl_runtime_rs::Sequence<i8>,

}



impl Default for ApplyTemporaryMap_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !nav_interfaces__srv__ApplyTemporaryMap_Request__init(&mut msg as *mut _) {
        panic!("Call to nav_interfaces__srv__ApplyTemporaryMap_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ApplyTemporaryMap_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_interfaces__srv__ApplyTemporaryMap_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_interfaces__srv__ApplyTemporaryMap_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_interfaces__srv__ApplyTemporaryMap_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ApplyTemporaryMap_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ApplyTemporaryMap_Request where Self: Sized {
  const TYPE_NAME: &'static str = "nav_interfaces/srv/ApplyTemporaryMap_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__nav_interfaces__srv__ApplyTemporaryMap_Request() }
  }
}


#[link(name = "nav_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__nav_interfaces__srv__ApplyTemporaryMap_Response() -> *const std::ffi::c_void;
}

#[link(name = "nav_interfaces__rosidl_generator_c")]
extern "C" {
    fn nav_interfaces__srv__ApplyTemporaryMap_Response__init(msg: *mut ApplyTemporaryMap_Response) -> bool;
    fn nav_interfaces__srv__ApplyTemporaryMap_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ApplyTemporaryMap_Response>, size: usize) -> bool;
    fn nav_interfaces__srv__ApplyTemporaryMap_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ApplyTemporaryMap_Response>);
    fn nav_interfaces__srv__ApplyTemporaryMap_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ApplyTemporaryMap_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<ApplyTemporaryMap_Response>) -> bool;
}

// Corresponds to nav_interfaces__srv__ApplyTemporaryMap_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ApplyTemporaryMap_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub reason: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub map_revision: u64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub replanning_triggered: bool,

}



impl Default for ApplyTemporaryMap_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !nav_interfaces__srv__ApplyTemporaryMap_Response__init(&mut msg as *mut _) {
        panic!("Call to nav_interfaces__srv__ApplyTemporaryMap_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ApplyTemporaryMap_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_interfaces__srv__ApplyTemporaryMap_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_interfaces__srv__ApplyTemporaryMap_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_interfaces__srv__ApplyTemporaryMap_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ApplyTemporaryMap_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ApplyTemporaryMap_Response where Self: Sized {
  const TYPE_NAME: &'static str = "nav_interfaces/srv/ApplyTemporaryMap_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__nav_interfaces__srv__ApplyTemporaryMap_Response() }
  }
}


#[link(name = "nav_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__nav_interfaces__srv__GetHolePassageConfig_Request() -> *const std::ffi::c_void;
}

#[link(name = "nav_interfaces__rosidl_generator_c")]
extern "C" {
    fn nav_interfaces__srv__GetHolePassageConfig_Request__init(msg: *mut GetHolePassageConfig_Request) -> bool;
    fn nav_interfaces__srv__GetHolePassageConfig_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetHolePassageConfig_Request>, size: usize) -> bool;
    fn nav_interfaces__srv__GetHolePassageConfig_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetHolePassageConfig_Request>);
    fn nav_interfaces__srv__GetHolePassageConfig_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetHolePassageConfig_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<GetHolePassageConfig_Request>) -> bool;
}

// Corresponds to nav_interfaces__srv__GetHolePassageConfig_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetHolePassageConfig_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for GetHolePassageConfig_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !nav_interfaces__srv__GetHolePassageConfig_Request__init(&mut msg as *mut _) {
        panic!("Call to nav_interfaces__srv__GetHolePassageConfig_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetHolePassageConfig_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_interfaces__srv__GetHolePassageConfig_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_interfaces__srv__GetHolePassageConfig_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_interfaces__srv__GetHolePassageConfig_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetHolePassageConfig_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetHolePassageConfig_Request where Self: Sized {
  const TYPE_NAME: &'static str = "nav_interfaces/srv/GetHolePassageConfig_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__nav_interfaces__srv__GetHolePassageConfig_Request() }
  }
}


#[link(name = "nav_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__nav_interfaces__srv__GetHolePassageConfig_Response() -> *const std::ffi::c_void;
}

#[link(name = "nav_interfaces__rosidl_generator_c")]
extern "C" {
    fn nav_interfaces__srv__GetHolePassageConfig_Response__init(msg: *mut GetHolePassageConfig_Response) -> bool;
    fn nav_interfaces__srv__GetHolePassageConfig_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetHolePassageConfig_Response>, size: usize) -> bool;
    fn nav_interfaces__srv__GetHolePassageConfig_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetHolePassageConfig_Response>);
    fn nav_interfaces__srv__GetHolePassageConfig_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetHolePassageConfig_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<GetHolePassageConfig_Response>) -> bool;
}

// Corresponds to nav_interfaces__srv__GetHolePassageConfig_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
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
    pub reason: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub config_yaml: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub config_path: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub terrain_path: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub terrain_geometry: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub config_revision: u64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub terrain_revision: u64,

}



impl Default for GetHolePassageConfig_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !nav_interfaces__srv__GetHolePassageConfig_Response__init(&mut msg as *mut _) {
        panic!("Call to nav_interfaces__srv__GetHolePassageConfig_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetHolePassageConfig_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_interfaces__srv__GetHolePassageConfig_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_interfaces__srv__GetHolePassageConfig_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_interfaces__srv__GetHolePassageConfig_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetHolePassageConfig_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetHolePassageConfig_Response where Self: Sized {
  const TYPE_NAME: &'static str = "nav_interfaces/srv/GetHolePassageConfig_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__nav_interfaces__srv__GetHolePassageConfig_Response() }
  }
}


#[link(name = "nav_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__nav_interfaces__srv__ApplyHolePassageConfig_Request() -> *const std::ffi::c_void;
}

#[link(name = "nav_interfaces__rosidl_generator_c")]
extern "C" {
    fn nav_interfaces__srv__ApplyHolePassageConfig_Request__init(msg: *mut ApplyHolePassageConfig_Request) -> bool;
    fn nav_interfaces__srv__ApplyHolePassageConfig_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ApplyHolePassageConfig_Request>, size: usize) -> bool;
    fn nav_interfaces__srv__ApplyHolePassageConfig_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ApplyHolePassageConfig_Request>);
    fn nav_interfaces__srv__ApplyHolePassageConfig_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ApplyHolePassageConfig_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<ApplyHolePassageConfig_Request>) -> bool;
}

// Corresponds to nav_interfaces__srv__ApplyHolePassageConfig_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ApplyHolePassageConfig_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub config_yaml: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub expected_config_revision: u64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub expected_terrain_revision: u64,

}



impl Default for ApplyHolePassageConfig_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !nav_interfaces__srv__ApplyHolePassageConfig_Request__init(&mut msg as *mut _) {
        panic!("Call to nav_interfaces__srv__ApplyHolePassageConfig_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ApplyHolePassageConfig_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_interfaces__srv__ApplyHolePassageConfig_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_interfaces__srv__ApplyHolePassageConfig_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_interfaces__srv__ApplyHolePassageConfig_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ApplyHolePassageConfig_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ApplyHolePassageConfig_Request where Self: Sized {
  const TYPE_NAME: &'static str = "nav_interfaces/srv/ApplyHolePassageConfig_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__nav_interfaces__srv__ApplyHolePassageConfig_Request() }
  }
}


#[link(name = "nav_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__nav_interfaces__srv__ApplyHolePassageConfig_Response() -> *const std::ffi::c_void;
}

#[link(name = "nav_interfaces__rosidl_generator_c")]
extern "C" {
    fn nav_interfaces__srv__ApplyHolePassageConfig_Response__init(msg: *mut ApplyHolePassageConfig_Response) -> bool;
    fn nav_interfaces__srv__ApplyHolePassageConfig_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ApplyHolePassageConfig_Response>, size: usize) -> bool;
    fn nav_interfaces__srv__ApplyHolePassageConfig_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ApplyHolePassageConfig_Response>);
    fn nav_interfaces__srv__ApplyHolePassageConfig_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ApplyHolePassageConfig_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<ApplyHolePassageConfig_Response>) -> bool;
}

// Corresponds to nav_interfaces__srv__ApplyHolePassageConfig_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ApplyHolePassageConfig_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub reason: rosidl_runtime_rs::String,


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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !nav_interfaces__srv__ApplyHolePassageConfig_Response__init(&mut msg as *mut _) {
        panic!("Call to nav_interfaces__srv__ApplyHolePassageConfig_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ApplyHolePassageConfig_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_interfaces__srv__ApplyHolePassageConfig_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_interfaces__srv__ApplyHolePassageConfig_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_interfaces__srv__ApplyHolePassageConfig_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ApplyHolePassageConfig_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ApplyHolePassageConfig_Response where Self: Sized {
  const TYPE_NAME: &'static str = "nav_interfaces/srv/ApplyHolePassageConfig_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__nav_interfaces__srv__ApplyHolePassageConfig_Response() }
  }
}


#[link(name = "nav_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__nav_interfaces__srv__SaveHolePassageConfig_Request() -> *const std::ffi::c_void;
}

#[link(name = "nav_interfaces__rosidl_generator_c")]
extern "C" {
    fn nav_interfaces__srv__SaveHolePassageConfig_Request__init(msg: *mut SaveHolePassageConfig_Request) -> bool;
    fn nav_interfaces__srv__SaveHolePassageConfig_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SaveHolePassageConfig_Request>, size: usize) -> bool;
    fn nav_interfaces__srv__SaveHolePassageConfig_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SaveHolePassageConfig_Request>);
    fn nav_interfaces__srv__SaveHolePassageConfig_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SaveHolePassageConfig_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<SaveHolePassageConfig_Request>) -> bool;
}

// Corresponds to nav_interfaces__srv__SaveHolePassageConfig_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !nav_interfaces__srv__SaveHolePassageConfig_Request__init(&mut msg as *mut _) {
        panic!("Call to nav_interfaces__srv__SaveHolePassageConfig_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SaveHolePassageConfig_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_interfaces__srv__SaveHolePassageConfig_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_interfaces__srv__SaveHolePassageConfig_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_interfaces__srv__SaveHolePassageConfig_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SaveHolePassageConfig_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SaveHolePassageConfig_Request where Self: Sized {
  const TYPE_NAME: &'static str = "nav_interfaces/srv/SaveHolePassageConfig_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__nav_interfaces__srv__SaveHolePassageConfig_Request() }
  }
}


#[link(name = "nav_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__nav_interfaces__srv__SaveHolePassageConfig_Response() -> *const std::ffi::c_void;
}

#[link(name = "nav_interfaces__rosidl_generator_c")]
extern "C" {
    fn nav_interfaces__srv__SaveHolePassageConfig_Response__init(msg: *mut SaveHolePassageConfig_Response) -> bool;
    fn nav_interfaces__srv__SaveHolePassageConfig_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SaveHolePassageConfig_Response>, size: usize) -> bool;
    fn nav_interfaces__srv__SaveHolePassageConfig_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SaveHolePassageConfig_Response>);
    fn nav_interfaces__srv__SaveHolePassageConfig_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SaveHolePassageConfig_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<SaveHolePassageConfig_Response>) -> bool;
}

// Corresponds to nav_interfaces__srv__SaveHolePassageConfig_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SaveHolePassageConfig_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub reason: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub config_path: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub config_revision: u64,

}



impl Default for SaveHolePassageConfig_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !nav_interfaces__srv__SaveHolePassageConfig_Response__init(&mut msg as *mut _) {
        panic!("Call to nav_interfaces__srv__SaveHolePassageConfig_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SaveHolePassageConfig_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_interfaces__srv__SaveHolePassageConfig_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_interfaces__srv__SaveHolePassageConfig_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nav_interfaces__srv__SaveHolePassageConfig_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SaveHolePassageConfig_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SaveHolePassageConfig_Response where Self: Sized {
  const TYPE_NAME: &'static str = "nav_interfaces/srv/SaveHolePassageConfig_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__nav_interfaces__srv__SaveHolePassageConfig_Response() }
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


