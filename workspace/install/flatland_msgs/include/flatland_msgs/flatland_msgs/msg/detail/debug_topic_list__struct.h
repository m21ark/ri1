// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from flatland_msgs:msg/DebugTopicList.idl
// generated code does not contain a copyright notice

#ifndef FLATLAND_MSGS__MSG__DETAIL__DEBUG_TOPIC_LIST__STRUCT_H_
#define FLATLAND_MSGS__MSG__DETAIL__DEBUG_TOPIC_LIST__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'topics'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/DebugTopicList in the package flatland_msgs.
typedef struct flatland_msgs__msg__DebugTopicList
{
  rosidl_runtime_c__String__Sequence topics;
} flatland_msgs__msg__DebugTopicList;

// Struct for a sequence of flatland_msgs__msg__DebugTopicList.
typedef struct flatland_msgs__msg__DebugTopicList__Sequence
{
  flatland_msgs__msg__DebugTopicList * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} flatland_msgs__msg__DebugTopicList__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FLATLAND_MSGS__MSG__DETAIL__DEBUG_TOPIC_LIST__STRUCT_H_
