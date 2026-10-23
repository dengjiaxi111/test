# generated from rosidl_generator_py/resource/_idl.py.em
# with input from nav_interfaces:msg/HoleTraversalEvent.idl
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


class Metaclass_HoleTraversalEvent(type):
    """Metaclass of message 'HoleTraversalEvent'."""

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
            module = import_type_support('nav_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'nav_interfaces.msg.HoleTraversalEvent')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__hole_traversal_event
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__hole_traversal_event
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__hole_traversal_event
            cls._TYPE_SUPPORT = module.type_support_msg__msg__hole_traversal_event
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__hole_traversal_event

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class HoleTraversalEvent(metaclass=Metaclass_HoleTraversalEvent):
    """Message class 'HoleTraversalEvent'."""

    __slots__ = [
        '_header',
        '_session_id',
        '_goal_id',
        '_plan_id',
        '_traversal_uid',
        '_sequence',
        '_type',
        '_event_arc',
        '_progress',
        '_attempt',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'session_id': 'string',
        'goal_id': 'string',
        'plan_id': 'uint64',
        'traversal_uid': 'string',
        'sequence': 'uint64',
        'type': 'uint8',
        'event_arc': 'double',
        'progress': 'double',
        'attempt': 'uint32',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
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
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.session_id = kwargs.get('session_id', str())
        self.goal_id = kwargs.get('goal_id', str())
        self.plan_id = kwargs.get('plan_id', int())
        self.traversal_uid = kwargs.get('traversal_uid', str())
        self.sequence = kwargs.get('sequence', int())
        self.type = kwargs.get('type', int())
        self.event_arc = kwargs.get('event_arc', float())
        self.progress = kwargs.get('progress', float())
        self.attempt = kwargs.get('attempt', int())

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
        if self.header != other.header:
            return False
        if self.session_id != other.session_id:
            return False
        if self.goal_id != other.goal_id:
            return False
        if self.plan_id != other.plan_id:
            return False
        if self.traversal_uid != other.traversal_uid:
            return False
        if self.sequence != other.sequence:
            return False
        if self.type != other.type:
            return False
        if self.event_arc != other.event_arc:
            return False
        if self.progress != other.progress:
            return False
        if self.attempt != other.attempt:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if self._check_fields:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def session_id(self):
        """Message field 'session_id'."""
        return self._session_id

    @session_id.setter
    def session_id(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'session_id' field must be of type 'str'"
        self._session_id = value

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'goal_id' field must be of type 'str'"
        self._goal_id = value

    @builtins.property
    def plan_id(self):
        """Message field 'plan_id'."""
        return self._plan_id

    @plan_id.setter
    def plan_id(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'plan_id' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'plan_id' field must be an unsigned integer in [0, 18446744073709551615]"
        self._plan_id = value

    @builtins.property
    def traversal_uid(self):
        """Message field 'traversal_uid'."""
        return self._traversal_uid

    @traversal_uid.setter
    def traversal_uid(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'traversal_uid' field must be of type 'str'"
        self._traversal_uid = value

    @builtins.property
    def sequence(self):
        """Message field 'sequence'."""
        return self._sequence

    @sequence.setter
    def sequence(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'sequence' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'sequence' field must be an unsigned integer in [0, 18446744073709551615]"
        self._sequence = value

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
    def event_arc(self):
        """Message field 'event_arc'."""
        return self._event_arc

    @event_arc.setter
    def event_arc(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'event_arc' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'event_arc' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._event_arc = value

    @builtins.property
    def progress(self):
        """Message field 'progress'."""
        return self._progress

    @progress.setter
    def progress(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'progress' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'progress' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._progress = value

    @builtins.property
    def attempt(self):
        """Message field 'attempt'."""
        return self._attempt

    @attempt.setter
    def attempt(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'attempt' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'attempt' field must be an unsigned integer in [0, 4294967295]"
        self._attempt = value
