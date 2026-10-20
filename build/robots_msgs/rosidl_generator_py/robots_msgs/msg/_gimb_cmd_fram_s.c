// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from robots_msgs:msg/GimbCmdFram.idl
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
#include "robots_msgs/msg/detail/gimb_cmd_fram__struct.h"
#include "robots_msgs/msg/detail/gimb_cmd_fram__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool robots_msgs__msg__gimb_cmd_fram__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[43];
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
    assert(strncmp("robots_msgs.msg._gimb_cmd_fram.GimbCmdFram", full_classname_dest, 42) == 0);
  }
  robots_msgs__msg__GimbCmdFram * ros_message = _ros_message;
  {  // center_yaw
    PyObject * field = PyObject_GetAttrString(_pymsg, "center_yaw");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->center_yaw = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // armor_pitch
    PyObject * field = PyObject_GetAttrString(_pymsg, "armor_pitch");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->armor_pitch = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // armor_yaw
    PyObject * field = PyObject_GetAttrString(_pymsg, "armor_yaw");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->armor_yaw = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // spin_flag
    PyObject * field = PyObject_GetAttrString(_pymsg, "spin_flag");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->spin_flag = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // shot_mode
    PyObject * field = PyObject_GetAttrString(_pymsg, "shot_mode");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->shot_mode = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * robots_msgs__msg__gimb_cmd_fram__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of GimbCmdFram */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("robots_msgs.msg._gimb_cmd_fram");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "GimbCmdFram");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  robots_msgs__msg__GimbCmdFram * ros_message = (robots_msgs__msg__GimbCmdFram *)raw_ros_message;
  {  // center_yaw
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->center_yaw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "center_yaw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // armor_pitch
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->armor_pitch);
    {
      int rc = PyObject_SetAttrString(_pymessage, "armor_pitch", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // armor_yaw
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->armor_yaw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "armor_yaw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // spin_flag
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->spin_flag);
    {
      int rc = PyObject_SetAttrString(_pymessage, "spin_flag", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // shot_mode
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->shot_mode);
    {
      int rc = PyObject_SetAttrString(_pymessage, "shot_mode", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
