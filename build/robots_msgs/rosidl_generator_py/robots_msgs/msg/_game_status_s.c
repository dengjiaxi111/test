// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from robots_msgs:msg/GameStatus.idl
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
#include "robots_msgs/msg/detail/game_status__struct.h"
#include "robots_msgs/msg/detail/game_status__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool robots_msgs__msg__game_status__convert_from_py(PyObject * _pymsg, void * _ros_message)
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
    assert(strncmp("robots_msgs.msg._game_status.GameStatus", full_classname_dest, 39) == 0);
  }
  robots_msgs__msg__GameStatus * ros_message = _ros_message;
  {  // game_type
    PyObject * field = PyObject_GetAttrString(_pymsg, "game_type");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->game_type = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // game_progress
    PyObject * field = PyObject_GetAttrString(_pymsg, "game_progress");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->game_progress = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // stage_remain_time
    PyObject * field = PyObject_GetAttrString(_pymsg, "stage_remain_time");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->stage_remain_time = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // my_hp
    PyObject * field = PyObject_GetAttrString(_pymsg, "my_hp");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->my_hp = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // my_outpost_hp
    PyObject * field = PyObject_GetAttrString(_pymsg, "my_outpost_hp");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->my_outpost_hp = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // my_base_hp
    PyObject * field = PyObject_GetAttrString(_pymsg, "my_base_hp");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->my_base_hp = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // our_hero_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "our_hero_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->our_hero_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // our_hero_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "our_hero_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->our_hero_y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // enemy_1_robot_hp
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_1_robot_hp");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->enemy_1_robot_hp = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // enemy_2_robot_hp
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_2_robot_hp");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->enemy_2_robot_hp = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // enemy_3_robot_hp
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_3_robot_hp");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->enemy_3_robot_hp = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // enemy_4_robot_hp
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_4_robot_hp");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->enemy_4_robot_hp = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // enemy_5_robot_hp
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_5_robot_hp");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->enemy_5_robot_hp = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // enemy_7_robot_hp
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_7_robot_hp");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->enemy_7_robot_hp = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // enemy_outpost_hp
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_outpost_hp");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->enemy_outpost_hp = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // enemy_base_hp
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_base_hp");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->enemy_base_hp = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // external_supply_area_occupied
    PyObject * field = PyObject_GetAttrString(_pymsg, "external_supply_area_occupied");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->external_supply_area_occupied = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // inner_supply_area_occupied
    PyObject * field = PyObject_GetAttrString(_pymsg, "inner_supply_area_occupied");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->inner_supply_area_occupied = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // supply_area_occupied
    PyObject * field = PyObject_GetAttrString(_pymsg, "supply_area_occupied");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->supply_area_occupied = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // our_small_buff_activated
    PyObject * field = PyObject_GetAttrString(_pymsg, "our_small_buff_activated");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->our_small_buff_activated = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // our_big_buff_activated
    PyObject * field = PyObject_GetAttrString(_pymsg, "our_big_buff_activated");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->our_big_buff_activated = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // our_fortress_status
    PyObject * field = PyObject_GetAttrString(_pymsg, "our_fortress_status");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->our_fortress_status = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // remaining_gold_coin
    PyObject * field = PyObject_GetAttrString(_pymsg, "remaining_gold_coin");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->remaining_gold_coin = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * robots_msgs__msg__game_status__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of GameStatus */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("robots_msgs.msg._game_status");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "GameStatus");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  robots_msgs__msg__GameStatus * ros_message = (robots_msgs__msg__GameStatus *)raw_ros_message;
  {  // game_type
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->game_type);
    {
      int rc = PyObject_SetAttrString(_pymessage, "game_type", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // game_progress
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->game_progress);
    {
      int rc = PyObject_SetAttrString(_pymessage, "game_progress", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // stage_remain_time
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->stage_remain_time);
    {
      int rc = PyObject_SetAttrString(_pymessage, "stage_remain_time", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // my_hp
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->my_hp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "my_hp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // my_outpost_hp
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->my_outpost_hp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "my_outpost_hp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // my_base_hp
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->my_base_hp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "my_base_hp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // our_hero_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->our_hero_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "our_hero_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // our_hero_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->our_hero_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "our_hero_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_1_robot_hp
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->enemy_1_robot_hp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_1_robot_hp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_2_robot_hp
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->enemy_2_robot_hp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_2_robot_hp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_3_robot_hp
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->enemy_3_robot_hp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_3_robot_hp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_4_robot_hp
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->enemy_4_robot_hp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_4_robot_hp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_5_robot_hp
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->enemy_5_robot_hp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_5_robot_hp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_7_robot_hp
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->enemy_7_robot_hp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_7_robot_hp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_outpost_hp
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->enemy_outpost_hp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_outpost_hp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_base_hp
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->enemy_base_hp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_base_hp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // external_supply_area_occupied
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->external_supply_area_occupied);
    {
      int rc = PyObject_SetAttrString(_pymessage, "external_supply_area_occupied", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // inner_supply_area_occupied
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->inner_supply_area_occupied);
    {
      int rc = PyObject_SetAttrString(_pymessage, "inner_supply_area_occupied", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // supply_area_occupied
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->supply_area_occupied);
    {
      int rc = PyObject_SetAttrString(_pymessage, "supply_area_occupied", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // our_small_buff_activated
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->our_small_buff_activated);
    {
      int rc = PyObject_SetAttrString(_pymessage, "our_small_buff_activated", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // our_big_buff_activated
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->our_big_buff_activated);
    {
      int rc = PyObject_SetAttrString(_pymessage, "our_big_buff_activated", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // our_fortress_status
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->our_fortress_status);
    {
      int rc = PyObject_SetAttrString(_pymessage, "our_fortress_status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // remaining_gold_coin
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->remaining_gold_coin);
    {
      int rc = PyObject_SetAttrString(_pymessage, "remaining_gold_coin", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
