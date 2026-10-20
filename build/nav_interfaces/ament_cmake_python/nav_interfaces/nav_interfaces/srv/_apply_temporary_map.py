# generated from rosidl_generator_py/resource/_idl.py.em
# with input from nav_interfaces:srv/ApplyTemporaryMap.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

# Member 'indices'
# Member 'values'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ApplyTemporaryMap_Request(type):
    """Metaclass of message 'ApplyTemporaryMap_Request'."""

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
                'nav_interfaces.srv.ApplyTemporaryMap_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__apply_temporary_map__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__apply_temporary_map__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__apply_temporary_map__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__apply_temporary_map__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__apply_temporary_map__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ApplyTemporaryMap_Request(metaclass=Metaclass_ApplyTemporaryMap_Request):
    """Message class 'ApplyTemporaryMap_Request'."""

    __slots__ = [
        '_expected_session_id',
        '_expected_source_id',
        '_expected_map_revision',
        '_indices',
        '_values',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'expected_session_id': 'string',
        'expected_source_id': 'string',
        'expected_map_revision': 'uint64',
        'indices': 'sequence<uint32>',
        'values': 'sequence<int8>',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('uint32')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('int8')),  # noqa: E501
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
        self.expected_session_id = kwargs.get('expected_session_id', str())
        self.expected_source_id = kwargs.get('expected_source_id', str())
        self.expected_map_revision = kwargs.get('expected_map_revision', int())
        self.indices = array.array('I', kwargs.get('indices', []))
        self.values = array.array('b', kwargs.get('values', []))

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
        if self.expected_session_id != other.expected_session_id:
            return False
        if self.expected_source_id != other.expected_source_id:
            return False
        if self.expected_map_revision != other.expected_map_revision:
            return False
        if self.indices != other.indices:
            return False
        if self.values != other.values:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def expected_session_id(self):
        """Message field 'expected_session_id'."""
        return self._expected_session_id

    @expected_session_id.setter
    def expected_session_id(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'expected_session_id' field must be of type 'str'"
        self._expected_session_id = value

    @builtins.property
    def expected_source_id(self):
        """Message field 'expected_source_id'."""
        return self._expected_source_id

    @expected_source_id.setter
    def expected_source_id(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'expected_source_id' field must be of type 'str'"
        self._expected_source_id = value

    @builtins.property
    def expected_map_revision(self):
        """Message field 'expected_map_revision'."""
        return self._expected_map_revision

    @expected_map_revision.setter
    def expected_map_revision(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'expected_map_revision' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'expected_map_revision' field must be an unsigned integer in [0, 18446744073709551615]"
        self._expected_map_revision = value

    @builtins.property
    def indices(self):
        """Message field 'indices'."""
        return self._indices

    @indices.setter
    def indices(self, value):
        if self._check_fields:
            if isinstance(value, array.array):
                assert value.typecode == 'I', \
                    "The 'indices' array.array() must have the type code of 'I'"
                self._indices = value
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
                 all(val >= 0 and val < 4294967296 for val in value)), \
                "The 'indices' field must be a set or sequence and each value of type 'int' and each unsigned integer in [0, 4294967295]"
        self._indices = array.array('I', value)

    @builtins.property
    def values(self):
        """Message field 'values'."""
        return self._values

    @values.setter
    def values(self, value):
        if self._check_fields:
            if isinstance(value, array.array):
                assert value.typecode == 'b', \
                    "The 'values' array.array() must have the type code of 'b'"
                self._values = value
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
                "The 'values' field must be a set or sequence and each value of type 'int' and each integer in [-128, 127]"
        self._values = array.array('b', value)


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_ApplyTemporaryMap_Response(type):
    """Metaclass of message 'ApplyTemporaryMap_Response'."""

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
                'nav_interfaces.srv.ApplyTemporaryMap_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__apply_temporary_map__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__apply_temporary_map__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__apply_temporary_map__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__apply_temporary_map__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__apply_temporary_map__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ApplyTemporaryMap_Response(metaclass=Metaclass_ApplyTemporaryMap_Response):
    """Message class 'ApplyTemporaryMap_Response'."""

    __slots__ = [
        '_success',
        '_reason',
        '_map_revision',
        '_replanning_triggered',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'reason': 'string',
        'map_revision': 'uint64',
        'replanning_triggered': 'boolean',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
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
        self.success = kwargs.get('success', bool())
        self.reason = kwargs.get('reason', str())
        self.map_revision = kwargs.get('map_revision', int())
        self.replanning_triggered = kwargs.get('replanning_triggered', bool())

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
        if self.success != other.success:
            return False
        if self.reason != other.reason:
            return False
        if self.map_revision != other.map_revision:
            return False
        if self.replanning_triggered != other.replanning_triggered:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value

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
    def replanning_triggered(self):
        """Message field 'replanning_triggered'."""
        return self._replanning_triggered

    @replanning_triggered.setter
    def replanning_triggered(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'replanning_triggered' field must be of type 'bool'"
        self._replanning_triggered = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_ApplyTemporaryMap_Event(type):
    """Metaclass of message 'ApplyTemporaryMap_Event'."""

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
                'nav_interfaces.srv.ApplyTemporaryMap_Event')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__apply_temporary_map__event
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__apply_temporary_map__event
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__apply_temporary_map__event
            cls._TYPE_SUPPORT = module.type_support_msg__srv__apply_temporary_map__event
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__apply_temporary_map__event

            from service_msgs.msg import ServiceEventInfo
            if ServiceEventInfo.__class__._TYPE_SUPPORT is None:
                ServiceEventInfo.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ApplyTemporaryMap_Event(metaclass=Metaclass_ApplyTemporaryMap_Event):
    """Message class 'ApplyTemporaryMap_Event'."""

    __slots__ = [
        '_info',
        '_request',
        '_response',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'info': 'service_msgs/ServiceEventInfo',
        'request': 'sequence<nav_interfaces/ApplyTemporaryMap_Request, 1>',
        'response': 'sequence<nav_interfaces/ApplyTemporaryMap_Response, 1>',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['service_msgs', 'msg'], 'ServiceEventInfo'),  # noqa: E501
        rosidl_parser.definition.BoundedSequence(rosidl_parser.definition.NamespacedType(['nav_interfaces', 'srv'], 'ApplyTemporaryMap_Request'), 1),  # noqa: E501
        rosidl_parser.definition.BoundedSequence(rosidl_parser.definition.NamespacedType(['nav_interfaces', 'srv'], 'ApplyTemporaryMap_Response'), 1),  # noqa: E501
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
        from service_msgs.msg import ServiceEventInfo
        self.info = kwargs.get('info', ServiceEventInfo())
        self.request = kwargs.get('request', [])
        self.response = kwargs.get('response', [])

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
        if self.info != other.info:
            return False
        if self.request != other.request:
            return False
        if self.response != other.response:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def info(self):
        """Message field 'info'."""
        return self._info

    @info.setter
    def info(self, value):
        if self._check_fields:
            from service_msgs.msg import ServiceEventInfo
            assert \
                isinstance(value, ServiceEventInfo), \
                "The 'info' field must be a sub message of type 'ServiceEventInfo'"
        self._info = value

    @builtins.property
    def request(self):
        """Message field 'request'."""
        return self._request

    @request.setter
    def request(self, value):
        if self._check_fields:
            from nav_interfaces.srv import ApplyTemporaryMap_Request
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
                 len(value) <= 1 and
                 all(isinstance(v, ApplyTemporaryMap_Request) for v in value) and
                 True), \
                "The 'request' field must be a set or sequence with length <= 1 and each value of type 'ApplyTemporaryMap_Request'"
        self._request = value

    @builtins.property
    def response(self):
        """Message field 'response'."""
        return self._response

    @response.setter
    def response(self, value):
        if self._check_fields:
            from nav_interfaces.srv import ApplyTemporaryMap_Response
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
                 len(value) <= 1 and
                 all(isinstance(v, ApplyTemporaryMap_Response) for v in value) and
                 True), \
                "The 'response' field must be a set or sequence with length <= 1 and each value of type 'ApplyTemporaryMap_Response'"
        self._response = value


class Metaclass_ApplyTemporaryMap(type):
    """Metaclass of service 'ApplyTemporaryMap'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('nav_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'nav_interfaces.srv.ApplyTemporaryMap')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__apply_temporary_map

            from nav_interfaces.srv import _apply_temporary_map
            if _apply_temporary_map.Metaclass_ApplyTemporaryMap_Request._TYPE_SUPPORT is None:
                _apply_temporary_map.Metaclass_ApplyTemporaryMap_Request.__import_type_support__()
            if _apply_temporary_map.Metaclass_ApplyTemporaryMap_Response._TYPE_SUPPORT is None:
                _apply_temporary_map.Metaclass_ApplyTemporaryMap_Response.__import_type_support__()
            if _apply_temporary_map.Metaclass_ApplyTemporaryMap_Event._TYPE_SUPPORT is None:
                _apply_temporary_map.Metaclass_ApplyTemporaryMap_Event.__import_type_support__()


class ApplyTemporaryMap(metaclass=Metaclass_ApplyTemporaryMap):
    from nav_interfaces.srv._apply_temporary_map import ApplyTemporaryMap_Request as Request
    from nav_interfaces.srv._apply_temporary_map import ApplyTemporaryMap_Response as Response
    from nav_interfaces.srv._apply_temporary_map import ApplyTemporaryMap_Event as Event

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
