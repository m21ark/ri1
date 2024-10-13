// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from flatland_msgs:msg/Collision.idl
// generated code does not contain a copyright notice

#ifndef FLATLAND_MSGS__MSG__DETAIL__COLLISION__STRUCT_H_
#define FLATLAND_MSGS__MSG__DETAIL__COLLISION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'entity_a'
// Member 'body_a'
// Member 'entity_b'
// Member 'body_b'
#include "rosidl_runtime_c/string.h"
// Member 'magnitude_forces'
#include "rosidl_runtime_c/primitives_sequence.h"
// Member 'contact_positions'
// Member 'contact_normals'
#include "flatland_msgs/msg/detail/vector2__struct.h"

/// Struct defined in msg/Collision in the package flatland_msgs.
typedef struct flatland_msgs__msg__Collision
{
  rosidl_runtime_c__String entity_a;
  rosidl_runtime_c__String body_a;
  rosidl_runtime_c__String entity_b;
  rosidl_runtime_c__String body_b;
  rosidl_runtime_c__double__Sequence magnitude_forces;
  flatland_msgs__msg__Vector2__Sequence contact_positions;
  flatland_msgs__msg__Vector2__Sequence contact_normals;
} flatland_msgs__msg__Collision;

// Struct for a sequence of flatland_msgs__msg__Collision.
typedef struct flatland_msgs__msg__Collision__Sequence
{
  flatland_msgs__msg__Collision * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} flatland_msgs__msg__Collision__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FLATLAND_MSGS__MSG__DETAIL__COLLISION__STRUCT_H_
