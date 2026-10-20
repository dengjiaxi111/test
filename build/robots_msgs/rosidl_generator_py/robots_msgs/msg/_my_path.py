# generated from rosidl_generator_py/resource/_idl.py.em
# with input from robots_msgs:msg/MyPath.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

# Member 'delta_x'
# Member 'delta_y'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_MyPath(type):
    """Metaclass of message 'MyPath'."""

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
                'robots_msgs.msg.MyPath')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__my_path
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__my_path
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__my_path
            cls._TYPE_SUPPORT = module.type_support_msg__msg__my_path
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__my_path

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MyPath(metaclass=Metaclass_MyPath):
    """Message class 'MyPath'."""

    __slots__ = [
        '_intention',
        '_start_x',
        '_start_y',
        '_delta_x',
        '_delta_y',
        '_sender_id',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'intention': 'uint8',
        'start_x': 'uint16',
        'start_y': 'uint16',
        'delta_x': 'sequence<int8>',
        'delta_y': 'sequence<int8>',
        'sender_id': 'uint16',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('int8')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('int8')),  # noqa: E501
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
        self.intention = kwargs.get('intention', int())
        self.start_x = kwargs.get('start_x', int())
        self.start_y = kwargs.get('start_y', int())
        self.delta_x = array.array('b', kwargs.get('delta_x', []))
        self.delta_y = array.array('b', kwargs.get('delta_y', []))
        self.sender_id = kwargs.get('sender_id', int())

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
        if self.intention != other.intention:
            return False
        if self.start_x != other.start_x:
            return False
        if self.start_y != other.start_y:
            return False
        if self.delta_x != other.delta_x:
            return False
        if self.delta_y != other.delta_y:
            return False
        if self.sender_id != other.sender_id:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def intention(self):
        """Message field 'intention'."""
        return self._intention

    @intention.setter
    def intention(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'intention' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'intention' field must be an unsigned integer in [0, 255]"
        self._intention = value

    @builtins.property
    def start_x(self):
        """Message field 'start_x'."""
        return self._start_x

    @start_x.setter
    def start_x(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'start_x' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'start_x' field must be an unsigned integer in [0, 65535]"
        self._start_x = value

    @builtins.property
    def start_y(self):
        """Message field 'start_y'."""
        return self._start_y

    @start_y.setter
    def start_y(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'start_y' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'start_y' field must be an unsigned integer in [0, 65535]"
        self._start_y = value

    @builtins.property
    def delta_x(self):
        """Message field 'delta_x'."""
        return self._delta_x

    @delta_x.setter
    def delta_x(self, value):
        if self._check_fields:
            if isinstance(value, array.array):
                assert value.typecode == 'b', \
                    "The 'delta_x' array.array() must have the type code of 'b'"
                self._delta_x = value
                return
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -128 and val < 128 for val in value)), \
                "The 'delta_x' field must be a set or sequence and each value of type 'int' and each integer in [-128, 127]"
        self._delta_x = array.array('b', value)

    @builtins.property
    def delta_y(self):
        """Message field 'delta_y'."""
        return self._delta_y

    @delta_y.setter
    def delta_y(self, value):
        if self._check_fields:
            if isinstance(value, array.array):
                assert value.typecode == 'b', \
                    "The 'delta_y' array.array() must have the type code of 'b'"
                self._delta_y = value
                return
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -128 and val < 128 for val in value)), \
                "The 'delta_y' field must be a set or sequence and each value of type 'int' and each integer in [-128, 127]"
        self._delta_y = array.array('b', value)

    @builtins.property
    def sender_id(self):
        """Message field 'sender_id'."""
        return self._sender_id

    @sender_id.setter
    def sender_id(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'sender_id' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'sender_id' field must be an unsigned integer in [0, 65535]"
        self._sender_id = value
