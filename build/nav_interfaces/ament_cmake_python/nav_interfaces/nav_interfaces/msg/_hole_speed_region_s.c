// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from nav_interfaces:msg/HoleSpeedRegion.idl
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
#include "nav_interfaces/msg/detail/hole_speed_region__struct.h"
#include "nav_interfaces/msg/detail/hole_speed_region__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool nav_interfaces__msg__hole_speed_region__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[54];
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
    assert(strncmp("nav_interfaces.msg._hole_speed_region.HoleSpeedRegion", full_classname_dest, 53) == 0);
  }
  nav_interfaces__msg__HoleSpeedRegion * ros_message = _ros_message;
  {  // s_begin
    PyObject * field = PyObject_GetAttrString(_pymsg, "s_begin");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->s_begin = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // s_end
    PyObject * field = PyObject_GetAttrString(_pymsg, "s_end");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->s_end = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // speed_limit
    PyObject * field = PyObject_GetAttrString(_pymsg, "speed_limit");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->speed_limit = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // kind
    PyObject * field = PyObject_GetAttrString(_pymsg, "kind");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->kind = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * nav_interfaces__msg__hole_speed_region__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of HoleSpeedRegion */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("nav_interfaces.msg._hole_speed_region");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "HoleSpeedRegion");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  nav_interfaces__msg__HoleSpeedRegion * ros_message = (nav_interfaces__msg__HoleSpeedRegion *)raw_ros_message;
  {  // s_begin
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->s_begin);
    {
      int rc = PyObject_SetAttrString(_pymessage, "s_begin", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // s_end
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->s_end);
    {
      int rc = PyObject_SetAttrString(_pymessage, "s_end", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // speed_limit
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->speed_limit);
    {
      int rc = PyObject_SetAttrString(_pymessage, "speed_limit", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // kind
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->kind);
    {
      int rc = PyObject_SetAttrString(_pymessage, "kind", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
