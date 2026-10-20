// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from robots_msgs:msg/ModeCmd.idl
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
#include "robots_msgs/msg/detail/mode_cmd__struct.h"
#include "robots_msgs/msg/detail/mode_cmd__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool robots_msgs__msg__mode_cmd__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[34];
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
    assert(strncmp("robots_msgs.msg._mode_cmd.ModeCmd", full_classname_dest, 33) == 0);
  }
  robots_msgs__msg__ModeCmd * ros_message = _ros_message;
  {  // should_chassis_spin
    PyObject * field = PyObject_GetAttrString(_pymsg, "should_chassis_spin");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->should_chassis_spin = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // should_gimbal_patrol
    PyObject * field = PyObject_GetAttrString(_pymsg, "should_gimbal_patrol");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->should_gimbal_patrol = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // buy_bullet
    PyObject * field = PyObject_GetAttrString(_pymsg, "buy_bullet");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->buy_bullet = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // rebirth
    PyObject * field = PyObject_GetAttrString(_pymsg, "rebirth");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->rebirth = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // use_capacity
    PyObject * field = PyObject_GetAttrString(_pymsg, "use_capacity");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->use_capacity = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * robots_msgs__msg__mode_cmd__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ModeCmd */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("robots_msgs.msg._mode_cmd");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ModeCmd");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  robots_msgs__msg__ModeCmd * ros_message = (robots_msgs__msg__ModeCmd *)raw_ros_message;
  {  // should_chassis_spin
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->should_chassis_spin);
    {
      int rc = PyObject_SetAttrString(_pymessage, "should_chassis_spin", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // should_gimbal_patrol
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->should_gimbal_patrol);
    {
      int rc = PyObject_SetAttrString(_pymessage, "should_gimbal_patrol", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // buy_bullet
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->buy_bullet);
    {
      int rc = PyObject_SetAttrString(_pymessage, "buy_bullet", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rebirth
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->rebirth);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rebirth", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // use_capacity
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->use_capacity);
    {
      int rc = PyObject_SetAttrString(_pymessage, "use_capacity", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
