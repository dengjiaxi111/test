// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from nav_interfaces:msg/HoleTraversal.idl
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
#include "nav_interfaces/msg/detail/hole_traversal__struct.h"
#include "nav_interfaces/msg/detail/hole_traversal__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

// Nested array functions includes
#include "nav_interfaces/msg/detail/hole_event__functions.h"
#include "nav_interfaces/msg/detail/hole_straight__functions.h"
// end nested array functions include
bool nav_interfaces__msg__hole_event__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * nav_interfaces__msg__hole_event__convert_to_py(void * raw_ros_message);
bool nav_interfaces__msg__hole_straight__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * nav_interfaces__msg__hole_straight__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool nav_interfaces__msg__hole_traversal__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[49];
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
    assert(strncmp("nav_interfaces.msg._hole_traversal.HoleTraversal", full_classname_dest, 48) == 0);
  }
  nav_interfaces__msg__HoleTraversal * ros_message = _ros_message;
  {  // traversal_uid
    PyObject * field = PyObject_GetAttrString(_pymsg, "traversal_uid");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->traversal_uid, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // hole_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "hole_id");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->hole_id, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // entry_edge_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "entry_edge_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->entry_edge_id = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // exit_edge_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "exit_edge_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->exit_edge_id = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // centerline
    PyObject * field = PyObject_GetAttrString(_pymsg, "centerline");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->centerline = (Py_True == field);
    Py_DECREF(field);
  }
  {  // validated
    PyObject * field = PyObject_GetAttrString(_pymsg, "validated");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->validated = (Py_True == field);
    Py_DECREF(field);
  }
  {  // requirement_revision
    PyObject * field = PyObject_GetAttrString(_pymsg, "requirement_revision");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->requirement_revision = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }
  {  // events
    PyObject * field = PyObject_GetAttrString(_pymsg, "events");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'events'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = 6;
    nav_interfaces__msg__HoleEvent * dest = ros_message->events;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!nav_interfaces__msg__hole_event__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // straight_segments
    PyObject * field = PyObject_GetAttrString(_pymsg, "straight_segments");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'straight_segments'");
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
    if (!nav_interfaces__msg__HoleStraight__Sequence__init(&(ros_message->straight_segments), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create nav_interfaces__msg__HoleStraight__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    nav_interfaces__msg__HoleStraight * dest = ros_message->straight_segments.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!nav_interfaces__msg__hole_straight__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // uphill_entry
    PyObject * field = PyObject_GetAttrString(_pymsg, "uphill_entry");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->uphill_entry = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * nav_interfaces__msg__hole_traversal__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of HoleTraversal */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("nav_interfaces.msg._hole_traversal");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "HoleTraversal");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  nav_interfaces__msg__HoleTraversal * ros_message = (nav_interfaces__msg__HoleTraversal *)raw_ros_message;
  {  // traversal_uid
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->traversal_uid.data,
      strlen(ros_message->traversal_uid.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "traversal_uid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // hole_id
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->hole_id.data,
      strlen(ros_message->hole_id.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "hole_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // entry_edge_id
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->entry_edge_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "entry_edge_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // exit_edge_id
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->exit_edge_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "exit_edge_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // centerline
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->centerline ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "centerline", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // validated
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->validated ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "validated", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // requirement_revision
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->requirement_revision);
    {
      int rc = PyObject_SetAttrString(_pymessage, "requirement_revision", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // events
    PyObject * field = NULL;
    size_t size = 6;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    nav_interfaces__msg__HoleEvent * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->events[i]);
      PyObject * pyitem = nav_interfaces__msg__hole_event__convert_to_py(item);
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
      int rc = PyObject_SetAttrString(_pymessage, "events", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // straight_segments
    PyObject * field = NULL;
    size_t size = ros_message->straight_segments.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    nav_interfaces__msg__HoleStraight * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->straight_segments.data[i]);
      PyObject * pyitem = nav_interfaces__msg__hole_straight__convert_to_py(item);
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
      int rc = PyObject_SetAttrString(_pymessage, "straight_segments", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // uphill_entry
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->uphill_entry ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "uphill_entry", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
