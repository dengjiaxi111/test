// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from robots_msgs:msg/EnemyPose.idl
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
#include "robots_msgs/msg/detail/enemy_pose__struct.h"
#include "robots_msgs/msg/detail/enemy_pose__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool robots_msgs__msg__enemy_pose__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[38];
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
    assert(strncmp("robots_msgs.msg._enemy_pose.EnemyPose", full_classname_dest, 37) == 0);
  }
  robots_msgs__msg__EnemyPose * ros_message = _ros_message;
  {  // enemy_dist
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_dist");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->enemy_dist = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // enemy_ori
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_ori");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->enemy_ori = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // enemy_num
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_num");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->enemy_num = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // enemy_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->enemy_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // enemy_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->enemy_y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * robots_msgs__msg__enemy_pose__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of EnemyPose */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("robots_msgs.msg._enemy_pose");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "EnemyPose");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  robots_msgs__msg__EnemyPose * ros_message = (robots_msgs__msg__EnemyPose *)raw_ros_message;
  {  // enemy_dist
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->enemy_dist);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_dist", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_ori
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->enemy_ori);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_ori", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_num
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->enemy_num);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_num", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->enemy_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->enemy_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
