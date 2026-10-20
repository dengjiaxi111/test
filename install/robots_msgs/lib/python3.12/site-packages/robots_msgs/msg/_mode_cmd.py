# generated from rosidl_generator_py/resource/_idl.py.em
# with input from robots_msgs:msg/ModeCmd.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ModeCmd(type):
    """Metaclass of message 'ModeCmd'."""

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
                'robots_msgs.msg.ModeCmd')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__mode_cmd
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__mode_cmd
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__mode_cmd
            cls._TYPE_SUPPORT = module.type_support_msg__msg__mode_cmd
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__mode_cmd

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ModeCmd(metaclass=Metaclass_ModeCmd):
    """Message class 'ModeCmd'."""

    __slots__ = [
        '_should_chassis_spin',
        '_should_gimbal_patrol',
        '_buy_bullet',
        '_rebirth',
        '_use_capacity',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'should_chassis_spin': 'uint8',
        'should_gimbal_patrol': 'uint8',
        'buy_bullet': 'uint8',
        'rebirth': 'uint8',
        'use_capacity': 'uint8',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
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
        self.should_chassis_spin = kwargs.get('should_chassis_spin', int())
        self.should_gimbal_patrol = kwargs.get('should_gimbal_patrol', int())
        self.buy_bullet = kwargs.get('buy_bullet', int())
        self.rebirth = kwargs.get('rebirth', int())
        self.use_capacity = kwargs.get('use_capacity', int())

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
        if self.should_chassis_spin != other.should_chassis_spin:
            return False
        if self.should_gimbal_patrol != other.should_gimbal_patrol:
            return False
        if self.buy_bullet != other.buy_bullet:
            return False
        if self.rebirth != other.rebirth:
            return False
        if self.use_capacity != other.use_capacity:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def should_chassis_spin(self):
        """Message field 'should_chassis_spin'."""
        return self._should_chassis_spin

    @should_chassis_spin.setter
    def should_chassis_spin(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'should_chassis_spin' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'should_chassis_spin' field must be an unsigned integer in [0, 255]"
        self._should_chassis_spin = value

    @builtins.property
    def should_gimbal_patrol(self):
        """Message field 'should_gimbal_patrol'."""
        return self._should_gimbal_patrol

    @should_gimbal_patrol.setter
    def should_gimbal_patrol(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'should_gimbal_patrol' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'should_gimbal_patrol' field must be an unsigned integer in [0, 255]"
        self._should_gimbal_patrol = value

    @builtins.property
    def buy_bullet(self):
        """Message field 'buy_bullet'."""
        return self._buy_bullet

    @buy_bullet.setter
    def buy_bullet(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'buy_bullet' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'buy_bullet' field must be an unsigned integer in [0, 255]"
        self._buy_bullet = value

    @builtins.property
    def rebirth(self):
        """Message field 'rebirth'."""
        return self._rebirth

    @rebirth.setter
    def rebirth(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'rebirth' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'rebirth' field must be an unsigned integer in [0, 255]"
        self._rebirth = value

    @builtins.property
    def use_capacity(self):
        """Message field 'use_capacity'."""
        return self._use_capacity

    @use_capacity.setter
    def use_capacity(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'use_capacity' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'use_capacity' field must be an unsigned integer in [0, 255]"
        self._use_capacity = value
