// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from nav_interfaces:msg/HoleEvent.idl
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
#include "nav_interfaces/msg/detail/hole_event__struct.h"
#include "nav_interfaces/msg/detail/hole_event__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool geometry_msgs__msg__point__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * geometry_msgs__msg__point__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool nav_interfaces__msg__hole_event__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[41];
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
    assert(strncmp("nav_interfaces.msg._hole_event.HoleEvent", full_classname_dest, 40) == 0);
  }
  nav_interfaces__msg__HoleEvent * ros_message = _ros_message;
  {  // type
    PyObject * field = PyObject_GetAttrString(_pymsg, "type");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->type = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // range_status
    PyObject * field = PyObject_GetAttrString(_pymsg, "range_status");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->range_status = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // s_path
    PyObject * field = PyObject_GetAttrString(_pymsg, "s_path");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->s_path = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // point
    PyObject * field = PyObject_GetAttrString(_pymsg, "point");
    if (!field) {
      return false;
    }
    if (!geometry_msgs__msg__point__convert_from_py(field, &ros_message->point)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // point_valid
    PyObject * field = PyObject_GetAttrString(_pymsg, "point_valid");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->point_valid = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * nav_interfaces__msg__hole_event__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of HoleEvent */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("nav_interfaces.msg._hole_event");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "HoleEvent");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  nav_interfaces__msg__HoleEvent * ros_message = (nav_interfaces__msg__HoleEvent *)raw_ros_message;
  {  // type
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->type);
    {
      int rc = PyObject_SetAttrString(_pymessage, "type", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // range_status
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->range_status);
    {
      int rc = PyObject_SetAttrString(_pymessage, "range_status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // s_path
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->s_path);
    {
      int rc = PyObject_SetAttrString(_pymessage, "s_path", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // point
    PyObject * field = NULL;
    field = geometry_msgs__msg__point__convert_to_py(&ros_message->point);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "point", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // point_valid
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->point_valid ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "point_valid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
