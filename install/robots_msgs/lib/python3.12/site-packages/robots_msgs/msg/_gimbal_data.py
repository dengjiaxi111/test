# generated from rosidl_generator_py/resource/_idl.py.em
# with input from robots_msgs:msg/GimbalData.idl
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


class Metaclass_GimbalData(type):
    """Metaclass of message 'GimbalData'."""

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
                'robots_msgs.msg.GimbalData')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__gimbal_data
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__gimbal_data
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__gimbal_data
            cls._TYPE_SUPPORT = module.type_support_msg__msg__gimbal_data
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__gimbal_data

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GimbalData(metaclass=Metaclass_GimbalData):
    """Message class 'GimbalData'."""

    __slots__ = [
        '_gimbal_yaw',
        '_gimbal_pitch',
        '_yaw_va',
        '_base_yaw',
        '_self_team',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'gimbal_yaw': 'float',
        'gimbal_pitch': 'float',
        'yaw_va': 'float',
        'base_yaw': 'float',
        'self_team': 'uint8',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
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
        self.gimbal_yaw = kwargs.get('gimbal_yaw', float())
        self.gimbal_pitch = kwargs.get('gimbal_pitch', float())
        self.yaw_va = kwargs.get('yaw_va', float())
        self.base_yaw = kwargs.get('base_yaw', float())
        self.self_team = kwargs.get('self_team', int())

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
        if self.gimbal_yaw != other.gimbal_yaw:
            return False
        if self.gimbal_pitch != other.gimbal_pitch:
            return False
        if self.yaw_va != other.yaw_va:
            return False
        if self.base_yaw != other.base_yaw:
            return False
        if self.self_team != other.self_team:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def gimbal_yaw(self):
        """Message field 'gimbal_yaw'."""
        return self._gimbal_yaw

    @gimbal_yaw.setter
    def gimbal_yaw(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'gimbal_yaw' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'gimbal_yaw' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._gimbal_yaw = value

    @builtins.property
    def gimbal_pitch(self):
        """Message field 'gimbal_pitch'."""
        return self._gimbal_pitch

    @gimbal_pitch.setter
    def gimbal_pitch(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'gimbal_pitch' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'gimbal_pitch' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._gimbal_pitch = value

    @builtins.property
    def yaw_va(self):
        """Message field 'yaw_va'."""
        return self._yaw_va

    @yaw_va.setter
    def yaw_va(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'yaw_va' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'yaw_va' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._yaw_va = value

    @builtins.property
    def base_yaw(self):
        """Message field 'base_yaw'."""
        return self._base_yaw

    @base_yaw.setter
    def base_yaw(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'base_yaw' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'base_yaw' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._base_yaw = value

    @builtins.property
    def self_team(self):
        """Message field 'self_team'."""
        return self._self_team

    @self_team.setter
    def self_team(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'self_team' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'self_team' field must be an unsigned integer in [0, 255]"
        self._self_team = value
