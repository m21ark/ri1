// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from flatland_msgs:msg/DebugTopicList.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "flatland_msgs/msg/detail/debug_topic_list__rosidl_typesupport_introspection_c.h"
#include "flatland_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "flatland_msgs/msg/detail/debug_topic_list__functions.h"
#include "flatland_msgs/msg/detail/debug_topic_list__struct.h"


// Include directives for member types
// Member `topics`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void flatland_msgs__msg__DebugTopicList__rosidl_typesupport_introspection_c__DebugTopicList_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  flatland_msgs__msg__DebugTopicList__init(message_memory);
}

void flatland_msgs__msg__DebugTopicList__rosidl_typesupport_introspection_c__DebugTopicList_fini_function(void * message_memory)
{
  flatland_msgs__msg__DebugTopicList__fini(message_memory);
}

size_t flatland_msgs__msg__DebugTopicList__rosidl_typesupport_introspection_c__size_function__DebugTopicList__topics(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * flatland_msgs__msg__DebugTopicList__rosidl_typesupport_introspection_c__get_const_function__DebugTopicList__topics(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * flatland_msgs__msg__DebugTopicList__rosidl_typesupport_introspection_c__get_function__DebugTopicList__topics(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void flatland_msgs__msg__DebugTopicList__rosidl_typesupport_introspection_c__fetch_function__DebugTopicList__topics(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    flatland_msgs__msg__DebugTopicList__rosidl_typesupport_introspection_c__get_const_function__DebugTopicList__topics(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void flatland_msgs__msg__DebugTopicList__rosidl_typesupport_introspection_c__assign_function__DebugTopicList__topics(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    flatland_msgs__msg__DebugTopicList__rosidl_typesupport_introspection_c__get_function__DebugTopicList__topics(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool flatland_msgs__msg__DebugTopicList__rosidl_typesupport_introspection_c__resize_function__DebugTopicList__topics(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember flatland_msgs__msg__DebugTopicList__rosidl_typesupport_introspection_c__DebugTopicList_message_member_array[1] = {
  {
    "topics",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(flatland_msgs__msg__DebugTopicList, topics),  // bytes offset in struct
    NULL,  // default value
    flatland_msgs__msg__DebugTopicList__rosidl_typesupport_introspection_c__size_function__DebugTopicList__topics,  // size() function pointer
    flatland_msgs__msg__DebugTopicList__rosidl_typesupport_introspection_c__get_const_function__DebugTopicList__topics,  // get_const(index) function pointer
    flatland_msgs__msg__DebugTopicList__rosidl_typesupport_introspection_c__get_function__DebugTopicList__topics,  // get(index) function pointer
    flatland_msgs__msg__DebugTopicList__rosidl_typesupport_introspection_c__fetch_function__DebugTopicList__topics,  // fetch(index, &value) function pointer
    flatland_msgs__msg__DebugTopicList__rosidl_typesupport_introspection_c__assign_function__DebugTopicList__topics,  // assign(index, value) function pointer
    flatland_msgs__msg__DebugTopicList__rosidl_typesupport_introspection_c__resize_function__DebugTopicList__topics  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers flatland_msgs__msg__DebugTopicList__rosidl_typesupport_introspection_c__DebugTopicList_message_members = {
  "flatland_msgs__msg",  // message namespace
  "DebugTopicList",  // message name
  1,  // number of fields
  sizeof(flatland_msgs__msg__DebugTopicList),
  flatland_msgs__msg__DebugTopicList__rosidl_typesupport_introspection_c__DebugTopicList_message_member_array,  // message members
  flatland_msgs__msg__DebugTopicList__rosidl_typesupport_introspection_c__DebugTopicList_init_function,  // function to initialize message memory (memory has to be allocated)
  flatland_msgs__msg__DebugTopicList__rosidl_typesupport_introspection_c__DebugTopicList_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t flatland_msgs__msg__DebugTopicList__rosidl_typesupport_introspection_c__DebugTopicList_message_type_support_handle = {
  0,
  &flatland_msgs__msg__DebugTopicList__rosidl_typesupport_introspection_c__DebugTopicList_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_flatland_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, flatland_msgs, msg, DebugTopicList)() {
  if (!flatland_msgs__msg__DebugTopicList__rosidl_typesupport_introspection_c__DebugTopicList_message_type_support_handle.typesupport_identifier) {
    flatland_msgs__msg__DebugTopicList__rosidl_typesupport_introspection_c__DebugTopicList_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &flatland_msgs__msg__DebugTopicList__rosidl_typesupport_introspection_c__DebugTopicList_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
