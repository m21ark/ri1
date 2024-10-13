// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from flatland_msgs:srv/SpawnModel.idl
// generated code does not contain a copyright notice

#ifndef FLATLAND_MSGS__SRV__DETAIL__SPAWN_MODEL__STRUCT_H_
#define FLATLAND_MSGS__SRV__DETAIL__SPAWN_MODEL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'yaml_path'
// Member 'name'
// Member 'ns'
#include "rosidl_runtime_c/string.h"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose2_d__struct.h"

/// Struct defined in srv/SpawnModel in the package flatland_msgs.
typedef struct flatland_msgs__srv__SpawnModel_Request
{
  rosidl_runtime_c__String yaml_path;
  rosidl_runtime_c__String name;
  rosidl_runtime_c__String ns;
  geometry_msgs__msg__Pose2D pose;
} flatland_msgs__srv__SpawnModel_Request;

// Struct for a sequence of flatland_msgs__srv__SpawnModel_Request.
typedef struct flatland_msgs__srv__SpawnModel_Request__Sequence
{
  flatland_msgs__srv__SpawnModel_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} flatland_msgs__srv__SpawnModel_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SpawnModel in the package flatland_msgs.
typedef struct flatland_msgs__srv__SpawnModel_Response
{
  bool success;
  rosidl_runtime_c__String message;
} flatland_msgs__srv__SpawnModel_Response;

// Struct for a sequence of flatland_msgs__srv__SpawnModel_Response.
typedef struct flatland_msgs__srv__SpawnModel_Response__Sequence
{
  flatland_msgs__srv__SpawnModel_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} flatland_msgs__srv__SpawnModel_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FLATLAND_MSGS__SRV__DETAIL__SPAWN_MODEL__STRUCT_H_
