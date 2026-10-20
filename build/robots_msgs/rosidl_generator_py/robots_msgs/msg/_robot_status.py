# generated from rosidl_generator_py/resource/_idl.py.em
# with input from robots_msgs:msg/RobotStatus.idl
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


class Metaclass_RobotStatus(type):
    """Metaclass of message 'RobotStatus'."""

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
                'robots_msgs.msg.RobotStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__robot_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__robot_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__robot_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__robot_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__robot_status

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RobotStatus(metaclass=Metaclass_RobotStatus):
    """Message class 'RobotStatus'."""

    __slots__ = [
        '_robot_id',
        '_x',
        '_y',
        '_angle',
        '_recovery_buff',
        '_defence_buff',
        '_vulnerability_buff',
        '_attack_buff',
        '_remaining_energy',
        '_projectile_allowance_17mm',
        '_fort_area',
        '_supply_blood_area',
        '_local_exchange_projectile_allowance_17mm',
        '_remote_exchange_projectile_times',
        '_remote_exchange_health_times',
        '_can_free_rebirth',
        '_can_instant_rebirth',
        '_rebirth_need_coin',
        '_ttk_status',
        '_projectile_allowance_17mm_remain',
        '_target_position_x',
        '_target_position_y',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'robot_id': 'uint8',
        'x': 'float',
        'y': 'float',
        'angle': 'float',
        'recovery_buff': 'uint8',
        'defence_buff': 'uint8',
        'vulnerability_buff': 'uint8',
        'attack_buff': 'uint16',
        'remaining_energy': 'uint8',
        'projectile_allowance_17mm': 'uint16',
        'fort_area': 'uint8',
        'supply_blood_area': 'uint8',
        'local_exchange_projectile_allowance_17mm': 'uint16',
        'remote_exchange_projectile_times': 'uint8',
        'remote_exchange_health_times': 'uint8',
        'can_free_rebirth': 'uint8',
        'can_instant_rebirth': 'uint8',
        'rebirth_need_coin': 'uint16',
        'ttk_status': 'uint8',
        'projectile_allowance_17mm_remain': 'uint16',
        'target_position_x': 'float',
        'target_position_y': 'float',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
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
        self.robot_id = kwargs.get('robot_id', int())
        self.x = kwargs.get('x', float())
        self.y = kwargs.get('y', float())
        self.angle = kwargs.get('angle', float())
        self.recovery_buff = kwargs.get('recovery_buff', int())
        self.defence_buff = kwargs.get('defence_buff', int())
        self.vulnerability_buff = kwargs.get('vulnerability_buff', int())
        self.attack_buff = kwargs.get('attack_buff', int())
        self.remaining_energy = kwargs.get('remaining_energy', int())
        self.projectile_allowance_17mm = kwargs.get('projectile_allowance_17mm', int())
        self.fort_area = kwargs.get('fort_area', int())
        self.supply_blood_area = kwargs.get('supply_blood_area', int())
        self.local_exchange_projectile_allowance_17mm = kwargs.get('local_exchange_projectile_allowance_17mm', int())
        self.remote_exchange_projectile_times = kwargs.get('remote_exchange_projectile_times', int())
        self.remote_exchange_health_times = kwargs.get('remote_exchange_health_times', int())
        self.can_free_rebirth = kwargs.get('can_free_rebirth', int())
        self.can_instant_rebirth = kwargs.get('can_instant_rebirth', int())
        self.rebirth_need_coin = kwargs.get('rebirth_need_coin', int())
        self.ttk_status = kwargs.get('ttk_status', int())
        self.projectile_allowance_17mm_remain = kwargs.get('projectile_allowance_17mm_remain', int())
        self.target_position_x = kwargs.get('target_position_x', float())
        self.target_position_y = kwargs.get('target_position_y', float())

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
        if self.robot_id != other.robot_id:
            return False
        if self.x != other.x:
            return False
        if self.y != other.y:
            return False
        if self.angle != other.angle:
            return False
        if self.recovery_buff != other.recovery_buff:
            return False
        if self.defence_buff != other.defence_buff:
            return False
        if self.vulnerability_buff != other.vulnerability_buff:
            return False
        if self.attack_buff != other.attack_buff:
            return False
        if self.remaining_energy != other.remaining_energy:
            return False
        if self.projectile_allowance_17mm != other.projectile_allowance_17mm:
            return False
        if self.fort_area != other.fort_area:
            return False
        if self.supply_blood_area != other.supply_blood_area:
            return False
        if self.local_exchange_projectile_allowance_17mm != other.local_exchange_projectile_allowance_17mm:
            return False
        if self.remote_exchange_projectile_times != other.remote_exchange_projectile_times:
            return False
        if self.remote_exchange_health_times != other.remote_exchange_health_times:
            return False
        if self.can_free_rebirth != other.can_free_rebirth:
            return False
        if self.can_instant_rebirth != other.can_instant_rebirth:
            return False
        if self.rebirth_need_coin != other.rebirth_need_coin:
            return False
        if self.ttk_status != other.ttk_status:
            return False
        if self.projectile_allowance_17mm_remain != other.projectile_allowance_17mm_remain:
            return False
        if self.target_position_x != other.target_position_x:
            return False
        if self.target_position_y != other.target_position_y:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def robot_id(self):
        """Message field 'robot_id'."""
        return self._robot_id

    @robot_id.setter
    def robot_id(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'robot_id' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'robot_id' field must be an unsigned integer in [0, 255]"
        self._robot_id = value

    @builtins.property
    def x(self):
        """Message field 'x'."""
        return self._x

    @x.setter
    def x(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._x = value

    @builtins.property
    def y(self):
        """Message field 'y'."""
        return self._y

    @y.setter
    def y(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._y = value

    @builtins.property
    def angle(self):
        """Message field 'angle'."""
        return self._angle

    @angle.setter
    def angle(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'angle' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'angle' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._angle = value

    @builtins.property
    def recovery_buff(self):
        """Message field 'recovery_buff'."""
        return self._recovery_buff

    @recovery_buff.setter
    def recovery_buff(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'recovery_buff' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'recovery_buff' field must be an unsigned integer in [0, 255]"
        self._recovery_buff = value

    @builtins.property
    def defence_buff(self):
        """Message field 'defence_buff'."""
        return self._defence_buff

    @defence_buff.setter
    def defence_buff(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'defence_buff' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'defence_buff' field must be an unsigned integer in [0, 255]"
        self._defence_buff = value

    @builtins.property
    def vulnerability_buff(self):
        """Message field 'vulnerability_buff'."""
        return self._vulnerability_buff

    @vulnerability_buff.setter
    def vulnerability_buff(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'vulnerability_buff' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'vulnerability_buff' field must be an unsigned integer in [0, 255]"
        self._vulnerability_buff = value

    @builtins.property
    def attack_buff(self):
        """Message field 'attack_buff'."""
        return self._attack_buff

    @attack_buff.setter
    def attack_buff(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'attack_buff' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'attack_buff' field must be an unsigned integer in [0, 65535]"
        self._attack_buff = value

    @builtins.property
    def remaining_energy(self):
        """Message field 'remaining_energy'."""
        return self._remaining_energy

    @remaining_energy.setter
    def remaining_energy(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'remaining_energy' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'remaining_energy' field must be an unsigned integer in [0, 255]"
        self._remaining_energy = value

    @builtins.property
    def projectile_allowance_17mm(self):
        """Message field 'projectile_allowance_17mm'."""
        return self._projectile_allowance_17mm

    @projectile_allowance_17mm.setter
    def projectile_allowance_17mm(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'projectile_allowance_17mm' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'projectile_allowance_17mm' field must be an unsigned integer in [0, 65535]"
        self._projectile_allowance_17mm = value

    @builtins.property
    def fort_area(self):
        """Message field 'fort_area'."""
        return self._fort_area

    @fort_area.setter
    def fort_area(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'fort_area' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'fort_area' field must be an unsigned integer in [0, 255]"
        self._fort_area = value

    @builtins.property
    def supply_blood_area(self):
        """Message field 'supply_blood_area'."""
        return self._supply_blood_area

    @supply_blood_area.setter
    def supply_blood_area(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'supply_blood_area' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'supply_blood_area' field must be an unsigned integer in [0, 255]"
        self._supply_blood_area = value

    @builtins.property
    def local_exchange_projectile_allowance_17mm(self):
        """Message field 'local_exchange_projectile_allowance_17mm'."""
        return self._local_exchange_projectile_allowance_17mm

    @local_exchange_projectile_allowance_17mm.setter
    def local_exchange_projectile_allowance_17mm(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'local_exchange_projectile_allowance_17mm' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'local_exchange_projectile_allowance_17mm' field must be an unsigned integer in [0, 65535]"
        self._local_exchange_projectile_allowance_17mm = value

    @builtins.property
    def remote_exchange_projectile_times(self):
        """Message field 'remote_exchange_projectile_times'."""
        return self._remote_exchange_projectile_times

    @remote_exchange_projectile_times.setter
    def remote_exchange_projectile_times(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'remote_exchange_projectile_times' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'remote_exchange_projectile_times' field must be an unsigned integer in [0, 255]"
        self._remote_exchange_projectile_times = value

    @builtins.property
    def remote_exchange_health_times(self):
        """Message field 'remote_exchange_health_times'."""
        return self._remote_exchange_health_times

    @remote_exchange_health_times.setter
    def remote_exchange_health_times(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'remote_exchange_health_times' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'remote_exchange_health_times' field must be an unsigned integer in [0, 255]"
        self._remote_exchange_health_times = value

    @builtins.property
    def can_free_rebirth(self):
        """Message field 'can_free_rebirth'."""
        return self._can_free_rebirth

    @can_free_rebirth.setter
    def can_free_rebirth(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'can_free_rebirth' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'can_free_rebirth' field must be an unsigned integer in [0, 255]"
        self._can_free_rebirth = value

    @builtins.property
    def can_instant_rebirth(self):
        """Message field 'can_instant_rebirth'."""
        return self._can_instant_rebirth

    @can_instant_rebirth.setter
    def can_instant_rebirth(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'can_instant_rebirth' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'can_instant_rebirth' field must be an unsigned integer in [0, 255]"
        self._can_instant_rebirth = value

    @builtins.property
    def rebirth_need_coin(self):
        """Message field 'rebirth_need_coin'."""
        return self._rebirth_need_coin

    @rebirth_need_coin.setter
    def rebirth_need_coin(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'rebirth_need_coin' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'rebirth_need_coin' field must be an unsigned integer in [0, 65535]"
        self._rebirth_need_coin = value

    @builtins.property
    def ttk_status(self):
        """Message field 'ttk_status'."""
        return self._ttk_status

    @ttk_status.setter
    def ttk_status(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'ttk_status' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'ttk_status' field must be an unsigned integer in [0, 255]"
        self._ttk_status = value

    @builtins.property
    def projectile_allowance_17mm_remain(self):
        """Message field 'projectile_allowance_17mm_remain'."""
        return self._projectile_allowance_17mm_remain

    @projectile_allowance_17mm_remain.setter
    def projectile_allowance_17mm_remain(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'projectile_allowance_17mm_remain' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'projectile_allowance_17mm_remain' field must be an unsigned integer in [0, 65535]"
        self._projectile_allowance_17mm_remain = value

    @builtins.property
    def target_position_x(self):
        """Message field 'target_position_x'."""
        return self._target_position_x

    @target_position_x.setter
    def target_position_x(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'target_position_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'target_position_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._target_position_x = value

    @builtins.property
    def target_position_y(self):
        """Message field 'target_position_y'."""
        return self._target_position_y

    @target_position_y.setter
    def target_position_y(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'target_position_y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'target_position_y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._target_position_y = value
