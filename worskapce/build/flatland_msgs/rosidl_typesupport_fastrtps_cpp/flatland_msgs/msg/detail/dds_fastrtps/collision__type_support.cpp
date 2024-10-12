// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from flatland_msgs:msg/Collision.idl
// generated code does not contain a copyright notice
#include "flatland_msgs/msg/detail/collision__rosidl_typesupport_fastrtps_cpp.hpp"
#include "flatland_msgs/msg/detail/collision__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace flatland_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const flatland_msgs::msg::Vector2 &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  flatland_msgs::msg::Vector2 &);
size_t get_serialized_size(
  const flatland_msgs::msg::Vector2 &,
  size_t current_alignment);
size_t
max_serialized_size_Vector2(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace flatland_msgs

// functions for flatland_msgs::msg::Vector2 already declared above


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
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: entity_a
  cdr << ros_message.entity_a;
  // Member: body_a
  cdr << ros_message.body_a;
  // Member: entity_b
  cdr << ros_message.entity_b;
  // Member: body_b
  cdr << ros_message.body_b;
  // Member: magnitude_forces
  {
    cdr << ros_message.magnitude_forces;
  }
  // Member: contact_positions
  {
    size_t size = ros_message.contact_positions.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      flatland_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.contact_positions[i],
        cdr);
    }
  }
  // Member: contact_normals
  {
    size_t size = ros_message.contact_normals.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      flatland_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.contact_normals[i],
        cdr);
    }
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_flatland_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  flatland_msgs::msg::Collision & ros_message)
{
  // Member: entity_a
  cdr >> ros_message.entity_a;

  // Member: body_a
  cdr >> ros_message.body_a;

  // Member: entity_b
  cdr >> ros_message.entity_b;

  // Member: body_b
  cdr >> ros_message.body_b;

  // Member: magnitude_forces
  {
    cdr >> ros_message.magnitude_forces;
  }

  // Member: contact_positions
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    ros_message.contact_positions.resize(size);
    for (size_t i = 0; i < size; i++) {
      flatland_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr, ros_message.contact_positions[i]);
    }
  }

  // Member: contact_normals
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    ros_message.contact_normals.resize(size);
    for (size_t i = 0; i < size; i++) {
      flatland_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr, ros_message.contact_normals[i]);
    }
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_flatland_msgs
get_serialized_size(
  const flatland_msgs::msg::Collision & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: entity_a
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.entity_a.size() + 1);
  // Member: body_a
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.body_a.size() + 1);
  // Member: entity_b
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.entity_b.size() + 1);
  // Member: body_b
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.body_b.size() + 1);
  // Member: magnitude_forces
  {
    size_t array_size = ros_message.magnitude_forces.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.magnitude_forces[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: contact_positions
  {
    size_t array_size = ros_message.contact_positions.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        flatland_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.contact_positions[index], current_alignment);
    }
  }
  // Member: contact_normals
  {
    size_t array_size = ros_message.contact_normals.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        flatland_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.contact_normals[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_flatland_msgs
max_serialized_size_Collision(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: entity_a
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: body_a
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: entity_b
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: body_b
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: magnitude_forces
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: contact_positions
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        flatland_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Vector2(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: contact_normals
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        flatland_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Vector2(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = flatland_msgs::msg::Collision;
    is_plain =
      (
      offsetof(DataType, contact_normals) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _Collision__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const flatland_msgs::msg::Collision *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Collision__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<flatland_msgs::msg::Collision *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Collision__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const flatland_msgs::msg::Collision *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Collision__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Collision(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Collision__callbacks = {
  "flatland_msgs::msg",
  "Collision",
  _Collision__cdr_serialize,
  _Collision__cdr_deserialize,
  _Collision__get_serialized_size,
  _Collision__max_serialized_size
};

static rosidl_message_type_support_t _Collision__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Collision__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace flatland_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_flatland_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<flatland_msgs::msg::Collision>()
{
  return &flatland_msgs::msg::typesupport_fastrtps_cpp::_Collision__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, flatland_msgs, msg, Collision)() {
  return &flatland_msgs::msg::typesupport_fastrtps_cpp::_Collision__handle;
}

#ifdef __cplusplus
}
#endif
