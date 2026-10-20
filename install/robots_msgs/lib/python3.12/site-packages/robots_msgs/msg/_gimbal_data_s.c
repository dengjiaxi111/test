// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from robots_msgs:msg/GimbalData.idl
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
#include "robots_msgs/msg/detail/gimbal_data__struct.h"
#include "robots_msgs/msg/detail/gimbal_data__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool robots_msgs__msg__gimbal_data__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[40];
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
    assert(strncmp("robots_msgs.msg._gimbal_data.GimbalData", full_classname_dest, 39) == 0);
  }
  robots_msgs__msg__GimbalData * ros_message = _ros_message;
  {  // gimbal_yaw
    PyObject * field = PyObject_GetAttrString(_pymsg, "gimbal_yaw");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->gimbal_yaw = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // gimbal_pitch
    PyObject * field = PyObject_GetAttrString(_pymsg, "gimbal_pitch");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->gimbal_pitch = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // yaw_va
    PyObject * field = PyObject_GetAttrString(_pymsg, "yaw_va");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->yaw_va = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // base_yaw
    PyObject * field = PyObject_GetAttrString(_pymsg, "base_yaw");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->base_yaw = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // self_team
    PyObject * field = PyObject_GetAttrString(_pymsg, "self_team");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->self_team = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * robots_msgs__msg__gimbal_data__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of GimbalData */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("robots_msgs.msg._gimbal_data");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "GimbalData");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  robots_msgs__msg__GimbalData * ros_message = (robots_msgs__msg__GimbalData *)raw_ros_message;
  {  // gimbal_yaw
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->gimbal_yaw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gimbal_yaw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gimbal_pitch
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->gimbal_pitch);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gimbal_pitch", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // yaw_va
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->yaw_va);
    {
      int rc = PyObject_SetAttrString(_pymessage, "yaw_va", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // base_yaw
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->base_yaw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "base_yaw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // self_team
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->self_team);
    {
      int rc = PyObject_SetAttrString(_pymessage, "self_team", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
