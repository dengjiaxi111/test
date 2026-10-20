# generated from rosidl_generator_py/resource/_idl.py.em
# with input from nav_interfaces:msg/NavigationPlan.idl
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


class Metaclass_NavigationPlan(type):
    """Metaclass of message 'NavigationPlan'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'ACTIVE': 0,
        'INVALIDATED': 1,
        'CANCELLED': 2,
        'COMPLETED': 3,
        'FAILED': 4,
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
                'nav_interfaces.msg.NavigationPlan')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__navigation_plan
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__navigation_plan
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__navigation_plan
            cls._TYPE_SUPPORT = module.type_support_msg__msg__navigation_plan
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__navigation_plan

            from nav_interfaces.msg import HoleSpeedRegion
            if HoleSpeedRegion.__class__._TYPE_SUPPORT is None:
                HoleSpeedRegion.__class__.__import_type_support__()

            from nav_interfaces.msg import HoleTraversal
            if HoleTraversal.__class__._TYPE_SUPPORT is None:
                HoleTraversal.__class__.__import_type_support__()

            from nav_msgs.msg import Path
            if Path.__class__._TYPE_SUPPORT is None:
                Path.__class__.__import_type_support__()

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'ACTIVE': cls.__constants['ACTIVE'],
            'INVALIDATED': cls.__constants['INVALIDATED'],
            'CANCELLED': cls.__constants['CANCELLED'],
            'COMPLETED': cls.__constants['COMPLETED'],
            'FAILED': cls.__constants['FAILED'],
        }

    @property
    def ACTIVE(self):
        """Message constant 'ACTIVE'."""
        return Metaclass_NavigationPlan.__constants['ACTIVE']

    @property
    def INVALIDATED(self):
        """Message constant 'INVALIDATED'."""
        return Metaclass_NavigationPlan.__constants['INVALIDATED']

    @property
    def CANCELLED(self):
        """Message constant 'CANCELLED'."""
        return Metaclass_NavigationPlan.__constants['CANCELLED']

    @property
    def COMPLETED(self):
        """Message constant 'COMPLETED'."""
        return Metaclass_NavigationPlan.__constants['COMPLETED']

    @property
    def FAILED(self):
        """Message constant 'FAILED'."""
        return Metaclass_NavigationPlan.__constants['FAILED']


class NavigationPlan(metaclass=Metaclass_NavigationPlan):
    """
    Message class 'NavigationPlan'.

    Constants:
      ACTIVE
      INVALIDATED
      CANCELLED
      COMPLETED
      FAILED
    """

    __slots__ = [
        '_header',
        '_session_id',
        '_goal_id',
        '_plan_id',
        '_status',
        '_reason',
        '_constraints_enabled',
        '_terrain_revision',
        '_parameter_revision',
        '_map_revision',
        '_path',
        '_path_length',
        '_passages',
        '_speed_regions',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'session_id': 'string',
        'goal_id': 'string',
        'plan_id': 'uint64',
        'status': 'uint8',
        'reason': 'string',
        'constraints_enabled': 'boolean',
        'terrain_revision': 'uint64',
        'parameter_revision': 'uint64',
        'map_revision': 'uint64',
        'path': 'nav_msgs/Path',
        'path_length': 'double',
        'passages': 'sequence<nav_interfaces/HoleTraversal>',
        'speed_regions': 'sequence<nav_interfaces/HoleSpeedRegion>',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['nav_msgs', 'msg'], 'Path'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['nav_interfaces', 'msg'], 'HoleTraversal')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['nav_interfaces', 'msg'], 'HoleSpeedRegion')),  # noqa: E501
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
        self.status = kwargs.get('status', int())
        self.reason = kwargs.get('reason', str())
        self.constraints_enabled = kwargs.get('constraints_enabled', bool())
        self.terrain_revision = kwargs.get('terrain_revision', int())
        self.parameter_revision = kwargs.get('parameter_revision', int())
        self.map_revision = kwargs.get('map_revision', int())
        from nav_msgs.msg import Path
        self.path = kwargs.get('path', Path())
        self.path_length = kwargs.get('path_length', float())
        self.passages = kwargs.get('passages', [])
        self.speed_regions = kwargs.get('speed_regions', [])

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
        if self.status != other.status:
            return False
        if self.reason != other.reason:
            return False
        if self.constraints_enabled != other.constraints_enabled:
            return False
        if self.terrain_revision != other.terrain_revision:
            return False
        if self.parameter_revision != other.parameter_revision:
            return False
        if self.map_revision != other.map_revision:
            return False
        if self.path != other.path:
            return False
        if self.path_length != other.path_length:
            return False
        if self.passages != other.passages:
            return False
        if self.speed_regions != other.speed_regions:
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
    def status(self):
        """Message field 'status'."""
        return self._status

    @status.setter
    def status(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'status' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'status' field must be an unsigned integer in [0, 255]"
        self._status = value

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
    def constraints_enabled(self):
        """Message field 'constraints_enabled'."""
        return self._constraints_enabled

    @constraints_enabled.setter
    def constraints_enabled(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'constraints_enabled' field must be of type 'bool'"
        self._constraints_enabled = value

    @builtins.property
    def terrain_revision(self):
        """Message field 'terrain_revision'."""
        return self._terrain_revision

    @terrain_revision.setter
    def terrain_revision(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'terrain_revision' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'terrain_revision' field must be an unsigned integer in [0, 18446744073709551615]"
        self._terrain_revision = value

    @builtins.property
    def parameter_revision(self):
        """Message field 'parameter_revision'."""
        return self._parameter_revision

    @parameter_revision.setter
    def parameter_revision(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'parameter_revision' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'parameter_revision' field must be an unsigned integer in [0, 18446744073709551615]"
        self._parameter_revision = value

    @builtins.property
    def map_revision(self):
        """Message field 'map_revision'."""
        return self._map_revision

    @map_revision.setter
    def map_revision(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'map_revision' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'map_revision' field must be an unsigned integer in [0, 18446744073709551615]"
        self._map_revision = value

    @builtins.property
    def path(self):
        """Message field 'path'."""
        return self._path

    @path.setter
    def path(self, value):
        if self._check_fields:
            from nav_msgs.msg import Path
            assert \
                isinstance(value, Path), \
                "The 'path' field must be a sub message of type 'Path'"
        self._path = value

    @builtins.property
    def path_length(self):
        """Message field 'path_length'."""
        return self._path_length

    @path_length.setter
    def path_length(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'path_length' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'path_length' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._path_length = value

    @builtins.property
    def passages(self):
        """Message field 'passages'."""
        return self._passages

    @passages.setter
    def passages(self, value):
        if self._check_fields:
            from nav_interfaces.msg import HoleTraversal
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
                 all(isinstance(v, HoleTraversal) for v in value) and
                 True), \
                "The 'passages' field must be a set or sequence and each value of type 'HoleTraversal'"
        self._passages = value

    @builtins.property
    def speed_regions(self):
        """Message field 'speed_regions'."""
        return self._speed_regions

    @speed_regions.setter
    def speed_regions(self, value):
        if self._check_fields:
            from nav_interfaces.msg import HoleSpeedRegion
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
                 all(isinstance(v, HoleSpeedRegion) for v in value) and
                 True), \
                "The 'speed_regions' field must be a set or sequence and each value of type 'HoleSpeedRegion'"
        self._speed_regions = value
