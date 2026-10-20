// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from robots_msgs:msg/ChassisOdom.idl
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
#include "robots_msgs/msg/detail/chassis_odom__struct.h"
#include "robots_msgs/msg/detail/chassis_odom__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool robots_msgs__msg__chassis_odom__convert_from_py(PyObject * _pymsg, void * _ros_message)
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
    assert(strncmp("robots_msgs.msg._chassis_odom.ChassisOdom", full_classname_dest, 41) == 0);
  }
  robots_msgs__msg__ChassisOdom * ros_message = _ros_message;
  {  // speed_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "speed_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->speed_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // speed_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "speed_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->speed_y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // speed_w
    PyObject * field = PyObject_GetAttrString(_pymsg, "speed_w");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->speed_w = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // gimbal_angle
    PyObject * field = PyObject_GetAttrString(_pymsg, "gimbal_angle");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->gimbal_angle = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // capacitor_voltage
    PyObject * field = PyObject_GetAttrString(_pymsg, "capacitor_voltage");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->capacitor_voltage = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * robots_msgs__msg__chassis_odom__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ChassisOdom */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("robots_msgs.msg._chassis_odom");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ChassisOdom");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  robots_msgs__msg__ChassisOdom * ros_message = (robots_msgs__msg__ChassisOdom *)raw_ros_message;
  {  // speed_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->speed_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "speed_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // speed_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->speed_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "speed_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // speed_w
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->speed_w);
    {
      int rc = PyObject_SetAttrString(_pymessage, "speed_w", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gimbal_angle
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->gimbal_angle);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gimbal_angle", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // capacitor_voltage
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->capacitor_voltage);
    {
      int rc = PyObject_SetAttrString(_pymessage, "capacitor_voltage", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
