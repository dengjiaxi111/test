# generated from rosidl_generator_py/resource/_idl.py.em
# with input from robots_msgs:msg/EnemyPose.idl
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


class Metaclass_EnemyPose(type):
    """Metaclass of message 'EnemyPose'."""

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
                'robots_msgs.msg.EnemyPose')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__enemy_pose
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__enemy_pose
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__enemy_pose
            cls._TYPE_SUPPORT = module.type_support_msg__msg__enemy_pose
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__enemy_pose

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class EnemyPose(metaclass=Metaclass_EnemyPose):
    """Message class 'EnemyPose'."""

    __slots__ = [
        '_enemy_dist',
        '_enemy_ori',
        '_enemy_num',
        '_enemy_x',
        '_enemy_y',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'enemy_dist': 'float',
        'enemy_ori': 'float',
        'enemy_num': 'int8',
        'enemy_x': 'float',
        'enemy_y': 'float',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
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
        self.enemy_dist = kwargs.get('enemy_dist', float())
        self.enemy_ori = kwargs.get('enemy_ori', float())
        self.enemy_num = kwargs.get('enemy_num', int())
        self.enemy_x = kwargs.get('enemy_x', float())
        self.enemy_y = kwargs.get('enemy_y', float())

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
        if self.enemy_dist != other.enemy_dist:
            return False
        if self.enemy_ori != other.enemy_ori:
            return False
        if self.enemy_num != other.enemy_num:
            return False
        if self.enemy_x != other.enemy_x:
            return False
        if self.enemy_y != other.enemy_y:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def enemy_dist(self):
        """Message field 'enemy_dist'."""
        return self._enemy_dist

    @enemy_dist.setter
    def enemy_dist(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'enemy_dist' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'enemy_dist' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._enemy_dist = value

    @builtins.property
    def enemy_ori(self):
        """Message field 'enemy_ori'."""
        return self._enemy_ori

    @enemy_ori.setter
    def enemy_ori(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'enemy_ori' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'enemy_ori' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._enemy_ori = value

    @builtins.property
    def enemy_num(self):
        """Message field 'enemy_num'."""
        return self._enemy_num

    @enemy_num.setter
    def enemy_num(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'enemy_num' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'enemy_num' field must be an integer in [-128, 127]"
        self._enemy_num = value

    @builtins.property
    def enemy_x(self):
        """Message field 'enemy_x'."""
        return self._enemy_x

    @enemy_x.setter
    def enemy_x(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'enemy_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'enemy_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._enemy_x = value

    @builtins.property
    def enemy_y(self):
        """Message field 'enemy_y'."""
        return self._enemy_y

    @enemy_y.setter
    def enemy_y(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'enemy_y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'enemy_y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._enemy_y = value
