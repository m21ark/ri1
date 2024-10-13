// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from flatland_msgs:msg/Collisions.idl
// generated code does not contain a copyright notice

#ifndef FLATLAND_MSGS__MSG__DETAIL__COLLISIONS__STRUCT_H_
#define FLATLAND_MSGS__MSG__DETAIL__COLLISIONS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'collisions'
#include "flatland_msgs/msg/detail/collision__struct.h"

/// Struct defined in msg/Collisions in the package flatland_msgs.
typedef struct flatland_msgs__msg__Collisions
{
  std_msgs__msg__Header header;
  flatland_msgs__msg__Collision__Sequence collisions;
} flatland_msgs__msg__Collisions;

// Struct for a sequence of flatland_msgs__msg__Collisions.
typedef struct flatland_msgs__msg__Collisions__Sequence
{
  flatland_msgs__msg__Collisions * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} flatland_msgs__msg__Collisions__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FLATLAND_MSGS__MSG__DETAIL__COLLISIONS__STRUCT_H_
