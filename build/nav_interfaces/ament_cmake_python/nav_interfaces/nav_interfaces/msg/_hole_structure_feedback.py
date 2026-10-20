# generated from rosidl_generator_py/resource/_idl.py.em
# with input from nav_interfaces:msg/HoleStructureFeedback.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_HoleStructureFeedback(type):
    """Metaclass of message 'HoleStructureFeedback'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'EXECUTING': 0,
        'COMPLETED': 1,
        'FAILED': 2,
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
                'nav_interfaces.msg.HoleStructureFeedback')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__hole_structure_feedback
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__hole_structure_feedback
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__hole_structure_feedback
            cls._TYPE_SUPPORT = module.type_support_msg__msg__hole_structure_feedback
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__hole_structure_feedback

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'EXECUTING': cls.__constants['EXECUTING'],
            'COMPLETED': cls.__constants['COMPLETED'],
            'FAILED': cls.__constants['FAILED'],
        }

    @property
    def EXECUTING(self):
        """Message constant 'EXECUTING'."""
        return Metaclass_HoleStructureFeedback.__constants['EXECUTING']

    @property
    def COMPLETED(self):
        """Message constant 'COMPLETED'."""
        return Metaclass_HoleStructureFeedback.__constants['COMPLETED']

    @property
    def FAILED(self):
        """Message constant 'FAILED'."""
        return Metaclass_HoleStructureFeedback.__constants['FAILED']


class HoleStructureFeedback(metaclass=Metaclass_HoleStructureFeedback):
    """
    Message class 'HoleStructureFeedback'.

    Constants:
      EXECUTING
      COMPLETED
      FAILED
    """

    __slots__ = [
        '_header',
        '_session_id',
        '_goal_id',
        '_request_id',
        '_requirement_revision',
        '_target',
        '_status',
        '_whole_vehicle_clear',
        '_normal_clearance',
        '_moving_transition_supported',
        '_cleared_traversal_uids',
        '_simulated',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'session_id': 'string',
        'goal_id': 'string',
        'request_id': 'uint64',
        'requirement_revision': 'uint64',
        'target': 'uint8',
        'status': 'uint8',
        'whole_vehicle_clear': 'boolean',
        'normal_clearance': 'boolean',
        'moving_transition_supported': 'boolean',
        'cleared_traversal_uids': 'sequence<string>',
        'simulated': 'boolean',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.UnboundedString()),  # noqa: E501
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
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.session_id = kwargs.get('session_id', str())
        self.goal_id = kwargs.get('goal_id', str())
        self.request_id = kwargs.get('request_id', int())
        self.requirement_revision = kwargs.get('requirement_revision', int())
        self.target = kwargs.get('target', int())
        self.status = kwargs.get('status', int())
        self.whole_vehicle_clear = kwargs.get('whole_vehicle_clear', bool())
        self.normal_clearance = kwargs.get('normal_clearance', bool())
        self.moving_transition_supported = kwargs.get('moving_transition_supported', bool())
        self.cleared_traversal_uids = kwargs.get('cleared_traversal_uids', [])
        self.simulated = kwargs.get('simulated', bool())

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
        if self.request_id != other.request_id:
            return False
        if self.requirement_revision != other.requirement_revision:
            return False
        if self.target != other.target:
            return False
        if self.status != other.status:
            return False
        if self.whole_vehicle_clear != other.whole_vehicle_clear:
            return False
        if self.normal_clearance != other.normal_clearance:
            return False
        if self.moving_transition_supported != other.moving_transition_supported:
            return False
        if self.cleared_traversal_uids != other.cleared_traversal_uids:
            return False
        if self.simulated != other.simulated:
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
    def request_id(self):
        """Message field 'request_id'."""
        return self._request_id

    @request_id.setter
    def request_id(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'request_id' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'request_id' field must be an unsigned integer in [0, 18446744073709551615]"
        self._request_id = value

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
    def target(self):
        """Message field 'target'."""
        return self._target

    @target.setter
    def target(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'target' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'target' field must be an unsigned integer in [0, 255]"
        self._target = value

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
    def whole_vehicle_clear(self):
        """Message field 'whole_vehicle_clear'."""
        return self._whole_vehicle_clear

    @whole_vehicle_clear.setter
    def whole_vehicle_clear(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'whole_vehicle_clear' field must be of type 'bool'"
        self._whole_vehicle_clear = value

    @builtins.property
    def normal_clearance(self):
        """Message field 'normal_clearance'."""
        return self._normal_clearance

    @normal_clearance.setter
    def normal_clearance(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'normal_clearance' field must be of type 'bool'"
        self._normal_clearance = value

    @builtins.property
    def moving_transition_supported(self):
        """Message field 'moving_transition_supported'."""
        return self._moving_transition_supported

    @moving_transition_supported.setter
    def moving_transition_supported(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'moving_transition_supported' field must be of type 'bool'"
        self._moving_transition_supported = value

    @builtins.property
    def cleared_traversal_uids(self):
        """Message field 'cleared_traversal_uids'."""
        return self._cleared_traversal_uids

    @cleared_traversal_uids.setter
    def cleared_traversal_uids(self, value):
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
                "The 'cleared_traversal_uids' field must be a set or sequence and each value of type 'str'"
        self._cleared_traversal_uids = value

    @builtins.property
    def simulated(self):
        """Message field 'simulated'."""
        return self._simulated

    @simulated.setter
    def simulated(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'simulated' field must be of type 'bool'"
        self._simulated = value
