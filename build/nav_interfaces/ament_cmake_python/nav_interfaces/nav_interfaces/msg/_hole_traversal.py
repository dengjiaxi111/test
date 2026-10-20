# generated from rosidl_generator_py/resource/_idl.py.em
# with input from nav_interfaces:msg/HoleTraversal.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_HoleTraversal(type):
    """Metaclass of message 'HoleTraversal'."""

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
                'nav_interfaces.msg.HoleTraversal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__hole_traversal
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__hole_traversal
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__hole_traversal
            cls._TYPE_SUPPORT = module.type_support_msg__msg__hole_traversal
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__hole_traversal

            from nav_interfaces.msg import HoleEvent
            if HoleEvent.__class__._TYPE_SUPPORT is None:
                HoleEvent.__class__.__import_type_support__()

            from nav_interfaces.msg import HoleStraight
            if HoleStraight.__class__._TYPE_SUPPORT is None:
                HoleStraight.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class HoleTraversal(metaclass=Metaclass_HoleTraversal):
    """Message class 'HoleTraversal'."""

    __slots__ = [
        '_traversal_uid',
        '_hole_id',
        '_entry_edge_id',
        '_exit_edge_id',
        '_centerline',
        '_validated',
        '_requirement_revision',
        '_events',
        '_straight_segments',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'traversal_uid': 'string',
        'hole_id': 'string',
        'entry_edge_id': 'int32',
        'exit_edge_id': 'int32',
        'centerline': 'boolean',
        'validated': 'boolean',
        'requirement_revision': 'uint64',
        'events': 'nav_interfaces/HoleEvent[6]',
        'straight_segments': 'sequence<nav_interfaces/HoleStraight>',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.NamespacedType(['nav_interfaces', 'msg'], 'HoleEvent'), 6),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['nav_interfaces', 'msg'], 'HoleStraight')),  # noqa: E501
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
        self.traversal_uid = kwargs.get('traversal_uid', str())
        self.hole_id = kwargs.get('hole_id', str())
        self.entry_edge_id = kwargs.get('entry_edge_id', int())
        self.exit_edge_id = kwargs.get('exit_edge_id', int())
        self.centerline = kwargs.get('centerline', bool())
        self.validated = kwargs.get('validated', bool())
        self.requirement_revision = kwargs.get('requirement_revision', int())
        from nav_interfaces.msg import HoleEvent
        self.events = kwargs.get(
            'events',
            [HoleEvent() for x in range(6)]
        )
        self.straight_segments = kwargs.get('straight_segments', [])

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
        if self.traversal_uid != other.traversal_uid:
            return False
        if self.hole_id != other.hole_id:
            return False
        if self.entry_edge_id != other.entry_edge_id:
            return False
        if self.exit_edge_id != other.exit_edge_id:
            return False
        if self.centerline != other.centerline:
            return False
        if self.validated != other.validated:
            return False
        if self.requirement_revision != other.requirement_revision:
            return False
        if self.events != other.events:
            return False
        if self.straight_segments != other.straight_segments:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

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
    def hole_id(self):
        """Message field 'hole_id'."""
        return self._hole_id

    @hole_id.setter
    def hole_id(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'hole_id' field must be of type 'str'"
        self._hole_id = value

    @builtins.property
    def entry_edge_id(self):
        """Message field 'entry_edge_id'."""
        return self._entry_edge_id

    @entry_edge_id.setter
    def entry_edge_id(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'entry_edge_id' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'entry_edge_id' field must be an integer in [-2147483648, 2147483647]"
        self._entry_edge_id = value

    @builtins.property
    def exit_edge_id(self):
        """Message field 'exit_edge_id'."""
        return self._exit_edge_id

    @exit_edge_id.setter
    def exit_edge_id(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'exit_edge_id' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'exit_edge_id' field must be an integer in [-2147483648, 2147483647]"
        self._exit_edge_id = value

    @builtins.property
    def centerline(self):
        """Message field 'centerline'."""
        return self._centerline

    @centerline.setter
    def centerline(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'centerline' field must be of type 'bool'"
        self._centerline = value

    @builtins.property
    def validated(self):
        """Message field 'validated'."""
        return self._validated

    @validated.setter
    def validated(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'validated' field must be of type 'bool'"
        self._validated = value

    @builtins.property
    def requirement_revision(self):
        """Message field 'requirement_revision'."""
        return self._requirement_revision

    @requirement_revision.setter
    def requirement_revision(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'requirement_revision' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'requirement_revision' field must be an unsigned integer in [0, 18446744073709551615]"
        self._requirement_revision = value

    @builtins.property
    def events(self):
        """Message field 'events'."""
        return self._events

    @events.setter
    def events(self, value):
        if self._check_fields:
            from nav_interfaces.msg import HoleEvent
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
                 len(value) == 6 and
                 all(isinstance(v, HoleEvent) for v in value) and
                 True), \
                "The 'events' field must be a set or sequence with length 6 and each value of type 'HoleEvent'"
        self._events = value

    @builtins.property
    def straight_segments(self):
        """Message field 'straight_segments'."""
        return self._straight_segments

    @straight_segments.setter
    def straight_segments(self, value):
        if self._check_fields:
            from nav_interfaces.msg import HoleStraight
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
                 all(isinstance(v, HoleStraight) for v in value) and
                 True), \
                "The 'straight_segments' field must be a set or sequence and each value of type 'HoleStraight'"
        self._straight_segments = value
