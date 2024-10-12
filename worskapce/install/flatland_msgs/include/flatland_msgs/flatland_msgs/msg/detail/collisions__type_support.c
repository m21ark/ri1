// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from flatland_msgs:msg/Collisions.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "flatland_msgs/msg/detail/collisions__rosidl_typesupport_introspection_c.h"
#include "flatland_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "flatland_msgs/msg/detail/collisions__functions.h"
#include "flatland_msgs/msg/detail/collisions__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `collisions`
#include "flatland_msgs/msg/collision.h"
// Member `collisions`
#include "flatland_msgs/msg/detail/collision__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void flatland_msgs__msg__Collisions__rosidl_typesupport_introspection_c__Collisions_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  flatland_msgs__msg__Collisions__init(message_memory);
}

void flatland_msgs__msg__Collisions__rosidl_typesupport_introspection_c__Collisions_fini_function(void * message_memory)
{
  flatland_msgs__msg__Collisions__fini(message_memory);
}

size_t flatland_msgs__msg__Collisions__rosidl_typesupport_introspection_c__size_function__Collisions__collisions(
  const void * untyped_member)
{
  const flatland_msgs__msg__Collision__Sequence * member =
    (const flatland_msgs__msg__Collision__Sequence *)(untyped_member);
  return member->size;
}

const void * flatland_msgs__msg__Collisions__rosidl_typesupport_introspection_c__get_const_function__Collisions__collisions(
  const void * untyped_member, size_t index)
{
  const flatland_msgs__msg__Collision__Sequence * member =
    (const flatland_msgs__msg__Collision__Sequence *)(untyped_member);
  return &member->data[index];
}

void * flatland_msgs__msg__Collisions__rosidl_typesupport_introspection_c__get_function__Collisions__collisions(
  void * untyped_member, size_t index)
{
  flatland_msgs__msg__Collision__Sequence * member =
    (flatland_msgs__msg__Collision__Sequence *)(untyped_member);
  return &member->data[index];
}

void flatland_msgs__msg__Collisions__rosidl_typesupport_introspection_c__fetch_function__Collisions__collisions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const flatland_msgs__msg__Collision * item =
    ((const flatland_msgs__msg__Collision *)
    flatland_msgs__msg__Collisions__rosidl_typesupport_introspection_c__get_const_function__Collisions__collisions(untyped_member, index));
  flatland_msgs__msg__Collision * value =
    (flatland_msgs__msg__Collision *)(untyped_value);
  *value = *item;
}

void flatland_msgs__msg__Collisions__rosidl_typesupport_introspection_c__assign_function__Collisions__collisions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  flatland_msgs__msg__Collision * item =
    ((flatland_msgs__msg__Collision *)
    flatland_msgs__msg__Collisions__rosidl_typesupport_introspection_c__get_function__Collisions__collisions(untyped_member, index));
  const flatland_msgs__msg__Collision * value =
    (const flatland_msgs__msg__Collision *)(untyped_value);
  *item = *value;
}

bool flatland_msgs__msg__Collisions__rosidl_typesupport_introspection_c__resize_function__Collisions__collisions(
  void * untyped_member, size_t size)
{
  flatland_msgs__msg__Collision__Sequence * member =
    (flatland_msgs__msg__Collision__Sequence *)(untyped_member);
  flatland_msgs__msg__Collision__Sequence__fini(member);
  return flatland_msgs__msg__Collision__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember flatland_msgs__msg__Collisions__rosidl_typesupport_introspection_c__Collisions_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(flatland_msgs__msg__Collisions, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "collisions",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(flatland_msgs__msg__Collisions, collisions),  // bytes offset in struct
    NULL,  // default value
    flatland_msgs__msg__Collisions__rosidl_typesupport_introspection_c__size_function__Collisions__collisions,  // size() function pointer
    flatland_msgs__msg__Collisions__rosidl_typesupport_introspection_c__get_const_function__Collisions__collisions,  // get_const(index) function pointer
    flatland_msgs__msg__Collisions__rosidl_typesupport_introspection_c__get_function__Collisions__collisions,  // get(index) function pointer
    flatland_msgs__msg__Collisions__rosidl_typesupport_introspection_c__fetch_function__Collisions__collisions,  // fetch(index, &value) function pointer
    flatland_msgs__msg__Collisions__rosidl_typesupport_introspection_c__assign_function__Collisions__collisions,  // assign(index, value) function pointer
    flatland_msgs__msg__Collisions__rosidl_typesupport_introspection_c__resize_function__Collisions__collisions  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers flatland_msgs__msg__Collisions__rosidl_typesupport_introspection_c__Collisions_message_members = {
  "flatland_msgs__msg",  // message namespace
  "Collisions",  // message name
  2,  // number of fields
  sizeof(flatland_msgs__msg__Collisions),
  flatland_msgs__msg__Collisions__rosidl_typesupport_introspection_c__Collisions_message_member_array,  // message members
  flatland_msgs__msg__Collisions__rosidl_typesupport_introspection_c__Collisions_init_function,  // function to initialize message memory (memory has to be allocated)
  flatland_msgs__msg__Collisions__rosidl_typesupport_introspection_c__Collisions_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t flatland_msgs__msg__Collisions__rosidl_typesupport_introspection_c__Collisions_message_type_support_handle = {
  0,
  &flatland_msgs__msg__Collisions__rosidl_typesupport_introspection_c__Collisions_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_flatland_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, flatland_msgs, msg, Collisions)() {
  flatland_msgs__msg__Collisions__rosidl_typesupport_introspection_c__Collisions_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  flatland_msgs__msg__Collisions__rosidl_typesupport_introspection_c__Collisions_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, flatland_msgs, msg, Collision)();
  if (!flatland_msgs__msg__Collisions__rosidl_typesupport_introspection_c__Collisions_message_type_support_handle.typesupport_identifier) {
    flatland_msgs__msg__Collisions__rosidl_typesupport_introspection_c__Collisions_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &flatland_msgs__msg__Collisions__rosidl_typesupport_introspection_c__Collisions_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
