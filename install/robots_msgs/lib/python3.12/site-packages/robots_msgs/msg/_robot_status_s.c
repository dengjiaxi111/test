// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from robots_msgs:msg/RobotStatus.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "robots_msgs/msg/detail/robot_status__struct.h"
#include "robots_msgs/msg/detail/robot_status__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool robots_msgs__msg__robot_status__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[42];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("robots_msgs.msg._robot_status.RobotStatus", full_classname_dest, 41) == 0);
  }
  robots_msgs__msg__RobotStatus * ros_message = _ros_message;
  {  // robot_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "robot_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->robot_id = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // x
    PyObject * field = PyObject_GetAttrString(_pymsg, "x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // y
    PyObject * field = PyObject_GetAttrString(_pymsg, "y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // angle
    PyObject * field = PyObject_GetAttrString(_pymsg, "angle");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->angle = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // recovery_buff
    PyObject * field = PyObject_GetAttrString(_pymsg, "recovery_buff");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->recovery_buff = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // defence_buff
    PyObject * field = PyObject_GetAttrString(_pymsg, "defence_buff");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->defence_buff = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // vulnerability_buff
    PyObject * field = PyObject_GetAttrString(_pymsg, "vulnerability_buff");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->vulnerability_buff = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // attack_buff
    PyObject * field = PyObject_GetAttrString(_pymsg, "attack_buff");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->attack_buff = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // remaining_energy
    PyObject * field = PyObject_GetAttrString(_pymsg, "remaining_energy");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->remaining_energy = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // projectile_allowance_17mm
    PyObject * field = PyObject_GetAttrString(_pymsg, "projectile_allowance_17mm");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->projectile_allowance_17mm = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // fort_area
    PyObject * field = PyObject_GetAttrString(_pymsg, "fort_area");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->fort_area = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // supply_blood_area
    PyObject * field = PyObject_GetAttrString(_pymsg, "supply_blood_area");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->supply_blood_area = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // local_exchange_projectile_allowance_17mm
    PyObject * field = PyObject_GetAttrString(_pymsg, "local_exchange_projectile_allowance_17mm");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->local_exchange_projectile_allowance_17mm = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // remote_exchange_projectile_times
    PyObject * field = PyObject_GetAttrString(_pymsg, "remote_exchange_projectile_times");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->remote_exchange_projectile_times = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // remote_exchange_health_times
    PyObject * field = PyObject_GetAttrString(_pymsg, "remote_exchange_health_times");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->remote_exchange_health_times = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // can_free_rebirth
    PyObject * field = PyObject_GetAttrString(_pymsg, "can_free_rebirth");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->can_free_rebirth = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // can_instant_rebirth
    PyObject * field = PyObject_GetAttrString(_pymsg, "can_instant_rebirth");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->can_instant_rebirth = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // rebirth_need_coin
    PyObject * field = PyObject_GetAttrString(_pymsg, "rebirth_need_coin");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->rebirth_need_coin = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // ttk_status
    PyObject * field = PyObject_GetAttrString(_pymsg, "ttk_status");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->ttk_status = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // projectile_allowance_17mm_remain
    PyObject * field = PyObject_GetAttrString(_pymsg, "projectile_allowance_17mm_remain");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->projectile_allowance_17mm_remain = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // target_position_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "target_position_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->target_position_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // target_position_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "target_position_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->target_position_y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * robots_msgs__msg__robot_status__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of RobotStatus */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("robots_msgs.msg._robot_status");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "RobotStatus");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  robots_msgs__msg__RobotStatus * ros_message = (robots_msgs__msg__RobotStatus *)raw_ros_message;
  {  // robot_id
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->robot_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "robot_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // angle
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->angle);
    {
      int rc = PyObject_SetAttrString(_pymessage, "angle", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // recovery_buff
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->recovery_buff);
    {
      int rc = PyObject_SetAttrString(_pymessage, "recovery_buff", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // defence_buff
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->defence_buff);
    {
      int rc = PyObject_SetAttrString(_pymessage, "defence_buff", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // vulnerability_buff
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->vulnerability_buff);
    {
      int rc = PyObject_SetAttrString(_pymessage, "vulnerability_buff", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // attack_buff
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->attack_buff);
    {
      int rc = PyObject_SetAttrString(_pymessage, "attack_buff", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // remaining_energy
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->remaining_energy);
    {
      int rc = PyObject_SetAttrString(_pymessage, "remaining_energy", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // projectile_allowance_17mm
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->projectile_allowance_17mm);
    {
      int rc = PyObject_SetAttrString(_pymessage, "projectile_allowance_17mm", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // fort_area
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->fort_area);
    {
      int rc = PyObject_SetAttrString(_pymessage, "fort_area", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // supply_blood_area
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->supply_blood_area);
    {
      int rc = PyObject_SetAttrString(_pymessage, "supply_blood_area", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // local_exchange_projectile_allowance_17mm
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->local_exchange_projectile_allowance_17mm);
    {
      int rc = PyObject_SetAttrString(_pymessage, "local_exchange_projectile_allowance_17mm", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // remote_exchange_projectile_times
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->remote_exchange_projectile_times);
    {
      int rc = PyObject_SetAttrString(_pymessage, "remote_exchange_projectile_times", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // remote_exchange_health_times
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->remote_exchange_health_times);
    {
      int rc = PyObject_SetAttrString(_pymessage, "remote_exchange_health_times", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // can_free_rebirth
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->can_free_rebirth);
    {
      int rc = PyObject_SetAttrString(_pymessage, "can_free_rebirth", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // can_instant_rebirth
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->can_instant_rebirth);
    {
      int rc = PyObject_SetAttrString(_pymessage, "can_instant_rebirth", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rebirth_need_coin
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->rebirth_need_coin);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rebirth_need_coin", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ttk_status
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->ttk_status);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ttk_status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // projectile_allowance_17mm_remain
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->projectile_allowance_17mm_remain);
    {
      int rc = PyObject_SetAttrString(_pymessage, "projectile_allowance_17mm_remain", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // target_position_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->target_position_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "target_position_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // target_position_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->target_position_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "target_position_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
