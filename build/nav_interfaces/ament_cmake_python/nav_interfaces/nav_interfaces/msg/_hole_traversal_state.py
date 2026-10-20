# generated from rosidl_generator_py/resource/_idl.py.em
# with input from nav_interfaces:msg/HoleTraversalState.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

# Member 'phases'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_HoleTraversalState(type):
    """Metaclass of message 'HoleTraversalState'."""

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
                'nav_interfaces.msg.HoleTraversalState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__hole_traversal_state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__hole_traversal_state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__hole_traversal_state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__hole_traversal_state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__hole_traversal_state

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


class HoleTraversalState(metaclass=Metaclass_HoleTraversalState):
    """Message class 'HoleTraversalState'."""

    __slots__ = [
        '_header',
        '_session_id',
        '_goal_id',
        '_plan_id',
        '_state',
        '_decision',
        '_s_progress',
        '_speed_limit',
        '_reason',
        '_traversal_uids',
        '_phases',
        '_preparing_required',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'session_id': 'string',
        'goal_id': 'string',
        'plan_id': 'uint64',
        'state': 'uint8',
        'decision': 'uint8',
        's_progress': 'double',
        'speed_limit': 'double',
        'reason': 'string',
        'traversal_uids': 'sequence<string>',
        'phases': 'sequence<uint8>',
        'preparing_required': 'sequence<boolean>',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.UnboundedString()),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('uint8')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('boolean')),  # noqa: E501
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
        self.state = kwargs.get('state', int())
        self.decision = kwargs.get('decision', int())
        self.s_progress = kwargs.get('s_progress', float())
        self.speed_limit = kwargs.get('speed_limit', float())
        self.reason = kwargs.get('reason', str())
        self.traversal_uids = kwargs.get('traversal_uids', [])
        self.phases = array.array('B', kwargs.get('phases', []))
        self.preparing_required = kwargs.get('preparing_required', [])

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
        if self.state != other.state:
            return False
        if self.decision != other.decision:
            return False
        if self.s_progress != other.s_progress:
            return False
        if self.speed_limit != other.speed_limit:
            return False
        if self.reason != other.reason:
            return False
        if self.traversal_uids != other.traversal_uids:
            return False
        if self.phases != other.phases:
            return False
        if self.preparing_required != other.preparing_required:
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
    def state(self):
        """Message field 'state'."""
        return self._state

    @state.setter
    def state(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'state' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'state' field must be an unsigned integer in [0, 255]"
        self._state = value

    @builtins.property
    def decision(self):
        """Message field 'decision'."""
        return self._decision

    @decision.setter
    def decision(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'decision' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'decision' field must be an unsigned integer in [0, 255]"
        self._decision = value

    @builtins.property
    def s_progress(self):
        """Message field 's_progress'."""
        return self._s_progress

    @s_progress.setter
    def s_progress(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 's_progress' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 's_progress' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._s_progress = value

    @builtins.property
    def speed_limit(self):
        """Message field 'speed_limit'."""
        return self._speed_limit

    @speed_limit.setter
    def speed_limit(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'speed_limit' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'speed_limit' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._speed_limit = value

    @builtins.property
    def reason(self):
        """Message field 'reason'."""
        return self._reason

    @reason.setter
    def reason(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'reason' field must be of type 'str'"
        self._reason = value

    @builtins.property
    def traversal_uids(self):
        """Message field 'traversal_uids'."""
        return self._traversal_uids

    @traversal_uids.setter
    def traversal_uids(self, value):
        if self._check_fields:
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
                 all(isinstance(v, str) for v in value) and
                 True), \
                "The 'traversal_uids' field must be a set or sequence and each value of type 'str'"
        self._traversal_uids = value

    @builtins.property
    def phases(self):
        """Message field 'phases'."""
        return self._phases

    @phases.setter
    def phases(self, value):
        if self._check_fields:
            if isinstance(value, array.array):
                assert value.typecode == 'B', \
                    "The 'phases' array.array() must have the type code of 'B'"
                self._phases = value
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
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'phases' field must be a set or sequence and each value of type 'int' and each unsigned integer in [0, 255]"
        self._phases = array.array('B', value)

    @builtins.property
    def preparing_required(self):
        """Message field 'preparing_required'."""
        return self._preparing_required

    @preparing_required.setter
    def preparing_required(self, value):
        if self._check_fields:
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
                 all(isinstance(v, bool) for v in value) and
                 True), \
                "The 'preparing_required' field must be a set or sequence and each value of type 'bool'"
        self._preparing_required = value
