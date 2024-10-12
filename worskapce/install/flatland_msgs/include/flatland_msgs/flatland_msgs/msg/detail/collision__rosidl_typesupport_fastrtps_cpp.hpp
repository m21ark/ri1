// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from flatland_msgs:msg/Collision.idl
// generated code does not contain a copyright notice

#ifndef FLATLAND_MSGS__MSG__DETAIL__COLLISION__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define FLATLAND_MSGS__MSG__DETAIL__COLLISION__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "flatland_msgs/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "flatland_msgs/msg/detail/collision__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace flatland_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_flatland_msgs
cdr_serialize(
  const flatland_msgs::msg::Collision & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_flatland_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  flatland_msgs::msg::Collision & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_flatland_msgs
get_serialized_size(
  const flatland_msgs::msg::Collision & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_flatland_msgs
max_serialized_size_Collision(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace flatland_msgs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_flatland_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, flatland_msgs, msg, Collision)();

#ifdef __cplusplus
}
#endif

#endif  // FLATLAND_MSGS__MSG__DETAIL__COLLISION__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
