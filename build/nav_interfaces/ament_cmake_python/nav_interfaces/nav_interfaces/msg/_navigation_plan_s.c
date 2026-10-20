// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from nav_interfaces:msg/NavigationPlan.idl
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
#include "nav_interfaces/msg/detail/navigation_plan__struct.h"
#include "nav_interfaces/msg/detail/navigation_plan__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

// Nested array functions includes
#include "nav_interfaces/msg/detail/hole_speed_region__functions.h"
#include "nav_interfaces/msg/detail/hole_traversal__functions.h"
// end nested array functions include
ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool nav_msgs__msg__path__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * nav_msgs__msg__path__convert_to_py(void * raw_ros_message);
bool nav_interfaces__msg__hole_traversal__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * nav_interfaces__msg__hole_traversal__convert_to_py(void * raw_ros_message);
bool nav_interfaces__msg__hole_speed_region__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * nav_interfaces__msg__hole_speed_region__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool nav_interfaces__msg__navigation_plan__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[51];
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
    assert(strncmp("nav_interfaces.msg._navigation_plan.NavigationPlan", full_classname_dest, 50) == 0);
  }
  nav_interfaces__msg__NavigationPlan * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // session_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "session_id");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->session_id, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // goal_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "goal_id");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->goal_id, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // plan_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "plan_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->plan_id = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }
  {  // status
    PyObject * field = PyObject_GetAttrString(_pymsg, "status");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->status = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // reason
    PyObject * field = PyObject_GetAttrString(_pymsg, "reason");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->reason, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // constraints_enabled
    PyObject * field = PyObject_GetAttrString(_pymsg, "constraints_enabled");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->constraints_enabled = (Py_True == field);
    Py_DECREF(field);
  }
  {  // terrain_revision
    PyObject * field = PyObject_GetAttrString(_pymsg, "terrain_revision");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->terrain_revision = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }
  {  // parameter_revision
    PyObject * field = PyObject_GetAttrString(_pymsg, "parameter_revision");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->parameter_revision = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }
  {  // map_revision
    PyObject * field = PyObject_GetAttrString(_pymsg, "map_revision");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->map_revision = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }
  {  // path
    PyObject * field = PyObject_GetAttrString(_pymsg, "path");
    if (!field) {
      return false;
    }
    if (!nav_msgs__msg__path__convert_from_py(field, &ros_message->path)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // path_length
    PyObject * field = PyObject_GetAttrString(_pymsg, "path_length");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->path_length = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // passages
    PyObject * field = PyObject_GetAttrString(_pymsg, "passages");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'passages'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!nav_interfaces__msg__HoleTraversal__Sequence__init(&(ros_message->passages), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create nav_interfaces__msg__HoleTraversal__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    nav_interfaces__msg__HoleTraversal * dest = ros_message->passages.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!nav_interfaces__msg__hole_traversal__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // speed_regions
    PyObject * field = PyObject_GetAttrString(_pymsg, "speed_regions");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'speed_regions'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!nav_interfaces__msg__HoleSpeedRegion__Sequence__init(&(ros_message->speed_regions), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create nav_interfaces__msg__HoleSpeedRegion__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    nav_interfaces__msg__HoleSpeedRegion * dest = ros_message->speed_regions.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!nav_interfaces__msg__hole_speed_region__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * nav_interfaces__msg__navigation_plan__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of NavigationPlan */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("nav_interfaces.msg._navigation_plan");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "NavigationPlan");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  nav_interfaces__msg__NavigationPlan * ros_message = (nav_interfaces__msg__NavigationPlan *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // session_id
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->session_id.data,
      strlen(ros_message->session_id.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "session_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // goal_id
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->goal_id.data,
      strlen(ros_message->goal_id.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "goal_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // plan_id
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->plan_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "plan_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // status
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->status);
    {
      int rc = PyObject_SetAttrString(_pymessage, "status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // reason
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->reason.data,
      strlen(ros_message->reason.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "reason", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // constraints_enabled
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->constraints_enabled ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "constraints_enabled", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // terrain_revision
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->terrain_revision);
    {
      int rc = PyObject_SetAttrString(_pymessage, "terrain_revision", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // parameter_revision
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->parameter_revision);
    {
      int rc = PyObject_SetAttrString(_pymessage, "parameter_revision", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // map_revision
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->map_revision);
    {
      int rc = PyObject_SetAttrString(_pymessage, "map_revision", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // path
    PyObject * field = NULL;
    field = nav_msgs__msg__path__convert_to_py(&ros_message->path);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "path", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // path_length
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->path_length);
    {
      int rc = PyObject_SetAttrString(_pymessage, "path_length", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // passages
    PyObject * field = NULL;
    size_t size = ros_message->passages.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    nav_interfaces__msg__HoleTraversal * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->passages.data[i]);
      PyObject * pyitem = nav_interfaces__msg__hole_traversal__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "passages", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // speed_regions
    PyObject * field = NULL;
    size_t size = ros_message->speed_regions.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    nav_interfaces__msg__HoleSpeedRegion * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->speed_regions.data[i]);
      PyObject * pyitem = nav_interfaces__msg__hole_speed_region__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "speed_regions", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
