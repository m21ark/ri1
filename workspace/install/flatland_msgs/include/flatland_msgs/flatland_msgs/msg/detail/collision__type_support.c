// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from flatland_msgs:msg/Collision.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "flatland_msgs/msg/detail/collision__rosidl_typesupport_introspection_c.h"
#include "flatland_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "flatland_msgs/msg/detail/collision__functions.h"
#include "flatland_msgs/msg/detail/collision__struct.h"


// Include directives for member types
// Member `entity_a`
// Member `body_a`
// Member `entity_b`
// Member `body_b`
#include "rosidl_runtime_c/string_functions.h"
// Member `magnitude_forces`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `contact_positions`
// Member `contact_normals`
#include "flatland_msgs/msg/vector2.h"
// Member `contact_positions`
// Member `contact_normals`
#include "flatland_msgs/msg/detail/vector2__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__Collision_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  flatland_msgs__msg__Collision__init(message_memory);
}

void flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__Collision_fini_function(void * message_memory)
{
  flatland_msgs__msg__Collision__fini(message_memory);
}

size_t flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__size_function__Collision__magnitude_forces(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__get_const_function__Collision__magnitude_forces(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__get_function__Collision__magnitude_forces(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__fetch_function__Collision__magnitude_forces(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__get_const_function__Collision__magnitude_forces(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__assign_function__Collision__magnitude_forces(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__get_function__Collision__magnitude_forces(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__resize_function__Collision__magnitude_forces(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__size_function__Collision__contact_positions(
  const void * untyped_member)
{
  const flatland_msgs__msg__Vector2__Sequence * member =
    (const flatland_msgs__msg__Vector2__Sequence *)(untyped_member);
  return member->size;
}

const void * flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__get_const_function__Collision__contact_positions(
  const void * untyped_member, size_t index)
{
  const flatland_msgs__msg__Vector2__Sequence * member =
    (const flatland_msgs__msg__Vector2__Sequence *)(untyped_member);
  return &member->data[index];
}

void * flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__get_function__Collision__contact_positions(
  void * untyped_member, size_t index)
{
  flatland_msgs__msg__Vector2__Sequence * member =
    (flatland_msgs__msg__Vector2__Sequence *)(untyped_member);
  return &member->data[index];
}

void flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__fetch_function__Collision__contact_positions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const flatland_msgs__msg__Vector2 * item =
    ((const flatland_msgs__msg__Vector2 *)
    flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__get_const_function__Collision__contact_positions(untyped_member, index));
  flatland_msgs__msg__Vector2 * value =
    (flatland_msgs__msg__Vector2 *)(untyped_value);
  *value = *item;
}

void flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__assign_function__Collision__contact_positions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  flatland_msgs__msg__Vector2 * item =
    ((flatland_msgs__msg__Vector2 *)
    flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__get_function__Collision__contact_positions(untyped_member, index));
  const flatland_msgs__msg__Vector2 * value =
    (const flatland_msgs__msg__Vector2 *)(untyped_value);
  *item = *value;
}

bool flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__resize_function__Collision__contact_positions(
  void * untyped_member, size_t size)
{
  flatland_msgs__msg__Vector2__Sequence * member =
    (flatland_msgs__msg__Vector2__Sequence *)(untyped_member);
  flatland_msgs__msg__Vector2__Sequence__fini(member);
  return flatland_msgs__msg__Vector2__Sequence__init(member, size);
}

size_t flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__size_function__Collision__contact_normals(
  const void * untyped_member)
{
  const flatland_msgs__msg__Vector2__Sequence * member =
    (const flatland_msgs__msg__Vector2__Sequence *)(untyped_member);
  return member->size;
}

const void * flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__get_const_function__Collision__contact_normals(
  const void * untyped_member, size_t index)
{
  const flatland_msgs__msg__Vector2__Sequence * member =
    (const flatland_msgs__msg__Vector2__Sequence *)(untyped_member);
  return &member->data[index];
}

void * flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__get_function__Collision__contact_normals(
  void * untyped_member, size_t index)
{
  flatland_msgs__msg__Vector2__Sequence * member =
    (flatland_msgs__msg__Vector2__Sequence *)(untyped_member);
  return &member->data[index];
}

void flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__fetch_function__Collision__contact_normals(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const flatland_msgs__msg__Vector2 * item =
    ((const flatland_msgs__msg__Vector2 *)
    flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__get_const_function__Collision__contact_normals(untyped_member, index));
  flatland_msgs__msg__Vector2 * value =
    (flatland_msgs__msg__Vector2 *)(untyped_value);
  *value = *item;
}

void flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__assign_function__Collision__contact_normals(
  void * untyped_member, size_t index, const void * untyped_value)
{
  flatland_msgs__msg__Vector2 * item =
    ((flatland_msgs__msg__Vector2 *)
    flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__get_function__Collision__contact_normals(untyped_member, index));
  const flatland_msgs__msg__Vector2 * value =
    (const flatland_msgs__msg__Vector2 *)(untyped_value);
  *item = *value;
}

bool flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__resize_function__Collision__contact_normals(
  void * untyped_member, size_t size)
{
  flatland_msgs__msg__Vector2__Sequence * member =
    (flatland_msgs__msg__Vector2__Sequence *)(untyped_member);
  flatland_msgs__msg__Vector2__Sequence__fini(member);
  return flatland_msgs__msg__Vector2__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__Collision_message_member_array[7] = {
  {
    "entity_a",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(flatland_msgs__msg__Collision, entity_a),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "body_a",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(flatland_msgs__msg__Collision, body_a),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "entity_b",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(flatland_msgs__msg__Collision, entity_b),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "body_b",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(flatland_msgs__msg__Collision, body_b),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "magnitude_forces",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(flatland_msgs__msg__Collision, magnitude_forces),  // bytes offset in struct
    NULL,  // default value
    flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__size_function__Collision__magnitude_forces,  // size() function pointer
    flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__get_const_function__Collision__magnitude_forces,  // get_const(index) function pointer
    flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__get_function__Collision__magnitude_forces,  // get(index) function pointer
    flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__fetch_function__Collision__magnitude_forces,  // fetch(index, &value) function pointer
    flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__assign_function__Collision__magnitude_forces,  // assign(index, value) function pointer
    flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__resize_function__Collision__magnitude_forces  // resize(index) function pointer
  },
  {
    "contact_positions",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(flatland_msgs__msg__Collision, contact_positions),  // bytes offset in struct
    NULL,  // default value
    flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__size_function__Collision__contact_positions,  // size() function pointer
    flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__get_const_function__Collision__contact_positions,  // get_const(index) function pointer
    flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__get_function__Collision__contact_positions,  // get(index) function pointer
    flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__fetch_function__Collision__contact_positions,  // fetch(index, &value) function pointer
    flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__assign_function__Collision__contact_positions,  // assign(index, value) function pointer
    flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__resize_function__Collision__contact_positions  // resize(index) function pointer
  },
  {
    "contact_normals",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(flatland_msgs__msg__Collision, contact_normals),  // bytes offset in struct
    NULL,  // default value
    flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__size_function__Collision__contact_normals,  // size() function pointer
    flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__get_const_function__Collision__contact_normals,  // get_const(index) function pointer
    flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__get_function__Collision__contact_normals,  // get(index) function pointer
    flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__fetch_function__Collision__contact_normals,  // fetch(index, &value) function pointer
    flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__assign_function__Collision__contact_normals,  // assign(index, value) function pointer
    flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__resize_function__Collision__contact_normals  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__Collision_message_members = {
  "flatland_msgs__msg",  // message namespace
  "Collision",  // message name
  7,  // number of fields
  sizeof(flatland_msgs__msg__Collision),
  flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__Collision_message_member_array,  // message members
  flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__Collision_init_function,  // function to initialize message memory (memory has to be allocated)
  flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__Collision_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__Collision_message_type_support_handle = {
  0,
  &flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__Collision_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_flatland_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, flatland_msgs, msg, Collision)() {
  flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__Collision_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, flatland_msgs, msg, Vector2)();
  flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__Collision_message_member_array[6].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, flatland_msgs, msg, Vector2)();
  if (!flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__Collision_message_type_support_handle.typesupport_identifier) {
    flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__Collision_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &flatland_msgs__msg__Collision__rosidl_typesupport_introspection_c__Collision_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
