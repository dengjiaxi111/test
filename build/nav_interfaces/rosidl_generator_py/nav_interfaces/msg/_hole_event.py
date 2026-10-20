# generated from rosidl_generator_py/resource/_idl.py.em
# with input from nav_interfaces:msg/HoleEvent.idl
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


class Metaclass_HoleEvent(type):
    """Metaclass of message 'HoleEvent'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'A': 0,
        'S': 1,
        'E': 2,
        'X': 3,
        'T': 4,
        'D': 5,
        'ON_PATH': 0,
        'BEFORE_PATH': 1,
        'AFTER_PATH': 2,
        'UNKNOWN': 3,
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('nav_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'nav_interfaces.msg.HoleEvent')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__hole_event
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__hole_event
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__hole_event
            cls._TYPE_SUPPORT = module.type_support_msg__msg__hole_event
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__hole_event

            from geometry_msgs.msg import Point
            if Point.__class__._TYPE_SUPPORT is None:
                Point.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'A': cls.__constants['A'],
            'S': cls.__constants['S'],
            'E': cls.__constants['E'],
            'X': cls.__constants['X'],
            'T': cls.__constants['T'],
            'D': cls.__constants['D'],
            'ON_PATH': cls.__constants['ON_PATH'],
            'BEFORE_PATH': cls.__constants['BEFORE_PATH'],
            'AFTER_PATH': cls.__constants['AFTER_PATH'],
            'UNKNOWN': cls.__constants['UNKNOWN'],
        }

    @property
    def A(self):
        """Message constant 'A'."""
        return Metaclass_HoleEvent.__constants['A']

    @property
    def S(self):
        """Message constant 'S'."""
        return Metaclass_HoleEvent.__constants['S']

    @property
    def E(self):
        """Message constant 'E'."""
        return Metaclass_HoleEvent.__constants['E']

    @property
    def X(self):
        """Message constant 'X'."""
        return Metaclass_HoleEvent.__constants['X']

    @property
    def T(self):
        """Message constant 'T'."""
        return Metaclass_HoleEvent.__constants['T']

    @property
    def D(self):
        """Message constant 'D'."""
        return Metaclass_HoleEvent.__constants['D']

    @property
    def ON_PATH(self):
        """Message constant 'ON_PATH'."""
        return Metaclass_HoleEvent.__constants['ON_PATH']

    @property
    def BEFORE_PATH(self):
        """Message constant 'BEFORE_PATH'."""
        return Metaclass_HoleEvent.__constants['BEFORE_PATH']

    @property
    def AFTER_PATH(self):
        """Message constant 'AFTER_PATH'."""
        return Metaclass_HoleEvent.__constants['AFTER_PATH']

    @property
    def UNKNOWN(self):
        """Message constant 'UNKNOWN'."""
        return Metaclass_HoleEvent.__constants['UNKNOWN']


class HoleEvent(metaclass=Metaclass_HoleEvent):
    """
    Message class 'HoleEvent'.

    Constants:
      A
      S
      E
      X
      T
      D
      ON_PATH
      BEFORE_PATH
      AFTER_PATH
      UNKNOWN
    """

    __slots__ = [
        '_type',
        '_range_status',
        '_s_path',
        '_point',
        '_point_valid',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'type': 'uint8',
        'range_status': 'uint8',
        's_path': 'double',
        'point': 'geometry_msgs/Point',
        'point_valid': 'boolean',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
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
        self.type = kwargs.get('type', int())
        self.range_status = kwargs.get('range_status', int())
        self.s_path = kwargs.get('s_path', float())
        from geometry_msgs.msg import Point
        self.point = kwargs.get('point', Point())
        self.point_valid = kwargs.get('point_valid', bool())

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
        if self.type != other.type:
            return False
        if self.range_status != other.range_status:
            return False
        if self.s_path != other.s_path:
            return False
        if self.point != other.point:
            return False
        if self.point_valid != other.point_valid:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property  # noqa: A003
    def type(self):  # noqa: A003
        """Message field 'type'."""
        return self._type

    @type.setter  # noqa: A003
    def type(self, value):  # noqa: A003
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'type' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'type' field must be an unsigned integer in [0, 255]"
        self._type = value

    @builtins.property
    def range_status(self):
        """Message field 'range_status'."""
        return self._range_status

    @range_status.setter
    def range_status(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'range_status' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'range_status' field must be an unsigned integer in [0, 255]"
        self._range_status = value

    @builtins.property
    def s_path(self):
        """Message field 's_path'."""
        return self._s_path

    @s_path.setter
    def s_path(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 's_path' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 's_path' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._s_path = value

    @builtins.property
    def point(self):
        """Message field 'point'."""
        return self._point

    @point.setter
    def point(self, value):
        if self._check_fields:
            from geometry_msgs.msg import Point
            assert \
                isinstance(value, Point), \
                "The 'point' field must be a sub message of type 'Point'"
        self._point = value

    @builtins.property
    def point_valid(self):
        """Message field 'point_valid'."""
        return self._point_valid

    @point_valid.setter
    def point_valid(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'point_valid' field must be of type 'bool'"
        self._point_valid = value
