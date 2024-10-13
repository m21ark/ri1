// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from flatland_msgs:srv/ChangeRate.idl
// generated code does not contain a copyright notice

#ifndef FLATLAND_MSGS__SRV__DETAIL__CHANGE_RATE__STRUCT_H_
#define FLATLAND_MSGS__SRV__DETAIL__CHANGE_RATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/ChangeRate in the package flatland_msgs.
typedef struct flatland_msgs__srv__ChangeRate_Request
{
  double rate;
} flatland_msgs__srv__ChangeRate_Request;

// Struct for a sequence of flatland_msgs__srv__ChangeRate_Request.
typedef struct flatland_msgs__srv__ChangeRate_Request__Sequence
{
  flatland_msgs__srv__ChangeRate_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} flatland_msgs__srv__ChangeRate_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ChangeRate in the package flatland_msgs.
typedef struct flatland_msgs__srv__ChangeRate_Response
{
  bool success;
  rosidl_runtime_c__String message;
} flatland_msgs__srv__ChangeRate_Response;

// Struct for a sequence of flatland_msgs__srv__ChangeRate_Response.
typedef struct flatland_msgs__srv__ChangeRate_Response__Sequence
{
  flatland_msgs__srv__ChangeRate_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} flatland_msgs__srv__ChangeRate_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FLATLAND_MSGS__SRV__DETAIL__CHANGE_RATE__STRUCT_H_
