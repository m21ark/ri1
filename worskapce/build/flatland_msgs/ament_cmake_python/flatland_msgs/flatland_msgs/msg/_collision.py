# generated from rosidl_generator_py/resource/_idl.py.em
# with input from flatland_msgs:msg/Collision.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'magnitude_forces'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Collision(type):
    """Metaclass of message 'Collision'."""

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
            module = import_type_support('flatland_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'flatland_msgs.msg.Collision')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__collision
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__collision
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__collision
            cls._TYPE_SUPPORT = module.type_support_msg__msg__collision
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__collision

            from flatland_msgs.msg import Vector2
            if Vector2.__class__._TYPE_SUPPORT is None:
                Vector2.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Collision(metaclass=Metaclass_Collision):
    """Message class 'Collision'."""

    __slots__ = [
        '_entity_a',
        '_body_a',
        '_entity_b',
        '_body_b',
        '_magnitude_forces',
        '_contact_positions',
        '_contact_normals',
    ]

    _fields_and_field_types = {
        'entity_a': 'string',
        'body_a': 'string',
        'entity_b': 'string',
        'body_b': 'string',
        'magnitude_forces': 'sequence<double>',
        'contact_positions': 'sequence<flatland_msgs/Vector2>',
        'contact_normals': 'sequence<flatland_msgs/Vector2>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['flatland_msgs', 'msg'], 'Vector2')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['flatland_msgs', 'msg'], 'Vector2')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.entity_a = kwargs.get('entity_a', str())
        self.body_a = kwargs.get('body_a', str())
        self.entity_b = kwargs.get('entity_b', str())
        self.body_b = kwargs.get('body_b', str())
        self.magnitude_forces = array.array('d', kwargs.get('magnitude_forces', []))
        self.contact_positions = kwargs.get('contact_positions', [])
        self.contact_normals = kwargs.get('contact_normals', [])

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
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
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.entity_a != other.entity_a:
            return False
        if self.body_a != other.body_a:
            return False
        if self.entity_b != other.entity_b:
            return False
        if self.body_b != other.body_b:
            return False
        if self.magnitude_forces != other.magnitude_forces:
            return False
        if self.contact_positions != other.contact_positions:
            return False
        if self.contact_normals != other.contact_normals:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def entity_a(self):
        """Message field 'entity_a'."""
        return self._entity_a

    @entity_a.setter
    def entity_a(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'entity_a' field must be of type 'str'"
        self._entity_a = value

    @builtins.property
    def body_a(self):
        """Message field 'body_a'."""
        return self._body_a

    @body_a.setter
    def body_a(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'body_a' field must be of type 'str'"
        self._body_a = value

    @builtins.property
    def entity_b(self):
        """Message field 'entity_b'."""
        return self._entity_b

    @entity_b.setter
    def entity_b(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'entity_b' field must be of type 'str'"
        self._entity_b = value

    @builtins.property
    def body_b(self):
        """Message field 'body_b'."""
        return self._body_b

    @body_b.setter
    def body_b(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'body_b' field must be of type 'str'"
        self._body_b = value

    @builtins.property
    def magnitude_forces(self):
        """Message field 'magnitude_forces'."""
        return self._magnitude_forces

    @magnitude_forces.setter
    def magnitude_forces(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'magnitude_forces' array.array() must have the type code of 'd'"
            self._magnitude_forces = value
            return
        if __debug__:
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
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'magnitude_forces' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._magnitude_forces = array.array('d', value)

    @builtins.property
    def contact_positions(self):
        """Message field 'contact_positions'."""
        return self._contact_positions

    @contact_positions.setter
    def contact_positions(self, value):
        if __debug__:
            from flatland_msgs.msg import Vector2
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
                 all(isinstance(v, Vector2) for v in value) and
                 True), \
                "The 'contact_positions' field must be a set or sequence and each value of type 'Vector2'"
        self._contact_positions = value

    @builtins.property
    def contact_normals(self):
        """Message field 'contact_normals'."""
        return self._contact_normals

    @contact_normals.setter
    def contact_normals(self, value):
        if __debug__:
            from flatland_msgs.msg import Vector2
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
                 all(isinstance(v, Vector2) for v in value) and
                 True), \
                "The 'contact_normals' field must be a set or sequence and each value of type 'Vector2'"
        self._contact_normals = value
