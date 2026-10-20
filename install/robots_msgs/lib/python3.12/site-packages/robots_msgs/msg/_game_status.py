# generated from rosidl_generator_py/resource/_idl.py.em
# with input from robots_msgs:msg/GameStatus.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GameStatus(type):
    """Metaclass of message 'GameStatus'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('robots_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'robots_msgs.msg.GameStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__game_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__game_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__game_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__game_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__game_status

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GameStatus(metaclass=Metaclass_GameStatus):
    """Message class 'GameStatus'."""

    __slots__ = [
        '_game_type',
        '_game_progress',
        '_stage_remain_time',
        '_my_hp',
        '_my_outpost_hp',
        '_my_base_hp',
        '_our_hero_x',
        '_our_hero_y',
        '_enemy_1_robot_hp',
        '_enemy_2_robot_hp',
        '_enemy_3_robot_hp',
        '_enemy_4_robot_hp',
        '_enemy_5_robot_hp',
        '_enemy_7_robot_hp',
        '_enemy_outpost_hp',
        '_enemy_base_hp',
        '_external_supply_area_occupied',
        '_inner_supply_area_occupied',
        '_supply_area_occupied',
        '_our_small_buff_activated',
        '_our_big_buff_activated',
        '_our_fortress_status',
        '_remaining_gold_coin',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'game_type': 'uint8',
        'game_progress': 'uint8',
        'stage_remain_time': 'uint16',
        'my_hp': 'uint16',
        'my_outpost_hp': 'uint16',
        'my_base_hp': 'uint16',
        'our_hero_x': 'float',
        'our_hero_y': 'float',
        'enemy_1_robot_hp': 'uint16',
        'enemy_2_robot_hp': 'uint16',
        'enemy_3_robot_hp': 'uint16',
        'enemy_4_robot_hp': 'uint16',
        'enemy_5_robot_hp': 'uint16',
        'enemy_7_robot_hp': 'uint16',
        'enemy_outpost_hp': 'uint16',
        'enemy_base_hp': 'uint16',
        'external_supply_area_occupied': 'uint8',
        'inner_supply_area_occupied': 'uint8',
        'supply_area_occupied': 'uint8',
        'our_small_buff_activated': 'uint8',
        'our_big_buff_activated': 'uint8',
        'our_fortress_status': 'uint8',
        'remaining_gold_coin': 'uint16',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.game_type = kwargs.get('game_type', int())
        self.game_progress = kwargs.get('game_progress', int())
        self.stage_remain_time = kwargs.get('stage_remain_time', int())
        self.my_hp = kwargs.get('my_hp', int())
        self.my_outpost_hp = kwargs.get('my_outpost_hp', int())
        self.my_base_hp = kwargs.get('my_base_hp', int())
        self.our_hero_x = kwargs.get('our_hero_x', float())
        self.our_hero_y = kwargs.get('our_hero_y', float())
        self.enemy_1_robot_hp = kwargs.get('enemy_1_robot_hp', int())
        self.enemy_2_robot_hp = kwargs.get('enemy_2_robot_hp', int())
        self.enemy_3_robot_hp = kwargs.get('enemy_3_robot_hp', int())
        self.enemy_4_robot_hp = kwargs.get('enemy_4_robot_hp', int())
        self.enemy_5_robot_hp = kwargs.get('enemy_5_robot_hp', int())
        self.enemy_7_robot_hp = kwargs.get('enemy_7_robot_hp', int())
        self.enemy_outpost_hp = kwargs.get('enemy_outpost_hp', int())
        self.enemy_base_hp = kwargs.get('enemy_base_hp', int())
        self.external_supply_area_occupied = kwargs.get('external_supply_area_occupied', int())
        self.inner_supply_area_occupied = kwargs.get('inner_supply_area_occupied', int())
        self.supply_area_occupied = kwargs.get('supply_area_occupied', int())
        self.our_small_buff_activated = kwargs.get('our_small_buff_activated', int())
        self.our_big_buff_activated = kwargs.get('our_big_buff_activated', int())
        self.our_fortress_status = kwargs.get('our_fortress_status', int())
        self.remaining_gold_coin = kwargs.get('remaining_gold_coin', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.game_type != other.game_type:
            return False
        if self.game_progress != other.game_progress:
            return False
        if self.stage_remain_time != other.stage_remain_time:
            return False
        if self.my_hp != other.my_hp:
            return False
        if self.my_outpost_hp != other.my_outpost_hp:
            return False
        if self.my_base_hp != other.my_base_hp:
            return False
        if self.our_hero_x != other.our_hero_x:
            return False
        if self.our_hero_y != other.our_hero_y:
            return False
        if self.enemy_1_robot_hp != other.enemy_1_robot_hp:
            return False
        if self.enemy_2_robot_hp != other.enemy_2_robot_hp:
            return False
        if self.enemy_3_robot_hp != other.enemy_3_robot_hp:
            return False
        if self.enemy_4_robot_hp != other.enemy_4_robot_hp:
            return False
        if self.enemy_5_robot_hp != other.enemy_5_robot_hp:
            return False
        if self.enemy_7_robot_hp != other.enemy_7_robot_hp:
            return False
        if self.enemy_outpost_hp != other.enemy_outpost_hp:
            return False
        if self.enemy_base_hp != other.enemy_base_hp:
            return False
        if self.external_supply_area_occupied != other.external_supply_area_occupied:
            return False
        if self.inner_supply_area_occupied != other.inner_supply_area_occupied:
            return False
        if self.supply_area_occupied != other.supply_area_occupied:
            return False
        if self.our_small_buff_activated != other.our_small_buff_activated:
            return False
        if self.our_big_buff_activated != other.our_big_buff_activated:
            return False
        if self.our_fortress_status != other.our_fortress_status:
            return False
        if self.remaining_gold_coin != other.remaining_gold_coin:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def game_type(self):
        """Message field 'game_type'."""
        return self._game_type

    @game_type.setter
    def game_type(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'game_type' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'game_type' field must be an unsigned integer in [0, 255]"
        self._game_type = value

    @builtins.property
    def game_progress(self):
        """Message field 'game_progress'."""
        return self._game_progress

    @game_progress.setter
    def game_progress(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'game_progress' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'game_progress' field must be an unsigned integer in [0, 255]"
        self._game_progress = value

    @builtins.property
    def stage_remain_time(self):
        """Message field 'stage_remain_time'."""
        return self._stage_remain_time

    @stage_remain_time.setter
    def stage_remain_time(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'stage_remain_time' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'stage_remain_time' field must be an unsigned integer in [0, 65535]"
        self._stage_remain_time = value

    @builtins.property
    def my_hp(self):
        """Message field 'my_hp'."""
        return self._my_hp

    @my_hp.setter
    def my_hp(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'my_hp' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'my_hp' field must be an unsigned integer in [0, 65535]"
        self._my_hp = value

    @builtins.property
    def my_outpost_hp(self):
        """Message field 'my_outpost_hp'."""
        return self._my_outpost_hp

    @my_outpost_hp.setter
    def my_outpost_hp(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'my_outpost_hp' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'my_outpost_hp' field must be an unsigned integer in [0, 65535]"
        self._my_outpost_hp = value

    @builtins.property
    def my_base_hp(self):
        """Message field 'my_base_hp'."""
        return self._my_base_hp

    @my_base_hp.setter
    def my_base_hp(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'my_base_hp' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'my_base_hp' field must be an unsigned integer in [0, 65535]"
        self._my_base_hp = value

    @builtins.property
    def our_hero_x(self):
        """Message field 'our_hero_x'."""
        return self._our_hero_x

    @our_hero_x.setter
    def our_hero_x(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'our_hero_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'our_hero_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._our_hero_x = value

    @builtins.property
    def our_hero_y(self):
        """Message field 'our_hero_y'."""
        return self._our_hero_y

    @our_hero_y.setter
    def our_hero_y(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'our_hero_y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'our_hero_y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._our_hero_y = value

    @builtins.property
    def enemy_1_robot_hp(self):
        """Message field 'enemy_1_robot_hp'."""
        return self._enemy_1_robot_hp

    @enemy_1_robot_hp.setter
    def enemy_1_robot_hp(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'enemy_1_robot_hp' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'enemy_1_robot_hp' field must be an unsigned integer in [0, 65535]"
        self._enemy_1_robot_hp = value

    @builtins.property
    def enemy_2_robot_hp(self):
        """Message field 'enemy_2_robot_hp'."""
        return self._enemy_2_robot_hp

    @enemy_2_robot_hp.setter
    def enemy_2_robot_hp(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'enemy_2_robot_hp' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'enemy_2_robot_hp' field must be an unsigned integer in [0, 65535]"
        self._enemy_2_robot_hp = value

    @builtins.property
    def enemy_3_robot_hp(self):
        """Message field 'enemy_3_robot_hp'."""
        return self._enemy_3_robot_hp

    @enemy_3_robot_hp.setter
    def enemy_3_robot_hp(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'enemy_3_robot_hp' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'enemy_3_robot_hp' field must be an unsigned integer in [0, 65535]"
        self._enemy_3_robot_hp = value

    @builtins.property
    def enemy_4_robot_hp(self):
        """Message field 'enemy_4_robot_hp'."""
        return self._enemy_4_robot_hp

    @enemy_4_robot_hp.setter
    def enemy_4_robot_hp(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'enemy_4_robot_hp' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'enemy_4_robot_hp' field must be an unsigned integer in [0, 65535]"
        self._enemy_4_robot_hp = value

    @builtins.property
    def enemy_5_robot_hp(self):
        """Message field 'enemy_5_robot_hp'."""
        return self._enemy_5_robot_hp

    @enemy_5_robot_hp.setter
    def enemy_5_robot_hp(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'enemy_5_robot_hp' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'enemy_5_robot_hp' field must be an unsigned integer in [0, 65535]"
        self._enemy_5_robot_hp = value

    @builtins.property
    def enemy_7_robot_hp(self):
        """Message field 'enemy_7_robot_hp'."""
        return self._enemy_7_robot_hp

    @enemy_7_robot_hp.setter
    def enemy_7_robot_hp(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'enemy_7_robot_hp' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'enemy_7_robot_hp' field must be an unsigned integer in [0, 65535]"
        self._enemy_7_robot_hp = value

    @builtins.property
    def enemy_outpost_hp(self):
        """Message field 'enemy_outpost_hp'."""
        return self._enemy_outpost_hp

    @enemy_outpost_hp.setter
    def enemy_outpost_hp(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'enemy_outpost_hp' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'enemy_outpost_hp' field must be an unsigned integer in [0, 65535]"
        self._enemy_outpost_hp = value

    @builtins.property
    def enemy_base_hp(self):
        """Message field 'enemy_base_hp'."""
        return self._enemy_base_hp

    @enemy_base_hp.setter
    def enemy_base_hp(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'enemy_base_hp' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'enemy_base_hp' field must be an unsigned integer in [0, 65535]"
        self._enemy_base_hp = value

    @builtins.property
    def external_supply_area_occupied(self):
        """Message field 'external_supply_area_occupied'."""
        return self._external_supply_area_occupied

    @external_supply_area_occupied.setter
    def external_supply_area_occupied(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'external_supply_area_occupied' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'external_supply_area_occupied' field must be an unsigned integer in [0, 255]"
        self._external_supply_area_occupied = value

    @builtins.property
    def inner_supply_area_occupied(self):
        """Message field 'inner_supply_area_occupied'."""
        return self._inner_supply_area_occupied

    @inner_supply_area_occupied.setter
    def inner_supply_area_occupied(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'inner_supply_area_occupied' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'inner_supply_area_occupied' field must be an unsigned integer in [0, 255]"
        self._inner_supply_area_occupied = value

    @builtins.property
    def supply_area_occupied(self):
        """Message field 'supply_area_occupied'."""
        return self._supply_area_occupied

    @supply_area_occupied.setter
    def supply_area_occupied(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'supply_area_occupied' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'supply_area_occupied' field must be an unsigned integer in [0, 255]"
        self._supply_area_occupied = value

    @builtins.property
    def our_small_buff_activated(self):
        """Message field 'our_small_buff_activated'."""
        return self._our_small_buff_activated

    @our_small_buff_activated.setter
    def our_small_buff_activated(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'our_small_buff_activated' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'our_small_buff_activated' field must be an unsigned integer in [0, 255]"
        self._our_small_buff_activated = value

    @builtins.property
    def our_big_buff_activated(self):
        """Message field 'our_big_buff_activated'."""
        return self._our_big_buff_activated

    @our_big_buff_activated.setter
    def our_big_buff_activated(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'our_big_buff_activated' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'our_big_buff_activated' field must be an unsigned integer in [0, 255]"
        self._our_big_buff_activated = value

    @builtins.property
    def our_fortress_status(self):
        """Message field 'our_fortress_status'."""
        return self._our_fortress_status

    @our_fortress_status.setter
    def our_fortress_status(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'our_fortress_status' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'our_fortress_status' field must be an unsigned integer in [0, 255]"
        self._our_fortress_status = value

    @builtins.property
    def remaining_gold_coin(self):
        """Message field 'remaining_gold_coin'."""
        return self._remaining_gold_coin

    @remaining_gold_coin.setter
    def remaining_gold_coin(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'remaining_gold_coin' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'remaining_gold_coin' field must be an unsigned integer in [0, 65535]"
        self._remaining_gold_coin = value
