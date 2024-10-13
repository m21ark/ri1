// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from flatland_msgs:msg/Collision.idl
// generated code does not contain a copyright notice
#include "flatland_msgs/msg/detail/collision__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "flatland_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "flatland_msgs/msg/detail/collision__struct.h"
#include "flatland_msgs/msg/detail/collision__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "flatland_msgs/msg/detail/vector2__functions.h"  // contact_normals, contact_positions
#include "rosidl_runtime_c/primitives_sequence.h"  // magnitude_forces
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // magnitude_forces
#include "rosidl_runtime_c/string.h"  // body_a, body_b, entity_a, entity_b
#include "rosidl_runtime_c/string_functions.h"  // body_a, body_b, entity_a, entity_b

// forward declare type support functions
size_t get_serialized_size_flatland_msgs__msg__Vector2(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_flatland_msgs__msg__Vector2(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, flatland_msgs, msg, Vector2)();


using _Collision__ros_msg_type = flatland_msgs__msg__Collision;

static bool _Collision__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Collision__ros_msg_type * ros_message = static_cast<const _Collision__ros_msg_type *>(untyped_ros_message);
  // Field name: entity_a
  {
    const rosidl_runtime_c__String * str = &ros_message->entity_a;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: body_a
  {
    const rosidl_runtime_c__String * str = &ros_message->body_a;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: entity_b
  {
    const rosidl_runtime_c__String * str = &ros_message->entity_b;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: body_b
  {
    const rosidl_runtime_c__String * str = &ros_message->body_b;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: magnitude_forces
  {
    size_t size = ros_message->magnitude_forces.size;
    auto array_ptr = ros_message->magnitude_forces.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: contact_positions
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, flatland_msgs, msg, Vector2
      )()->data);
    size_t size = ros_message->contact_positions.size;
    auto array_ptr = ros_message->contact_positions.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  // Field name: contact_normals
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, flatland_msgs, msg, Vector2
      )()->data);
    size_t size = ros_message->contact_normals.size;
    auto array_ptr = ros_message->contact_normals.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  return true;
}

static bool _Collision__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Collision__ros_msg_type * ros_message = static_cast<_Collision__ros_msg_type *>(untyped_ros_message);
  // Field name: entity_a
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->entity_a.data) {
      rosidl_runtime_c__String__init(&ros_message->entity_a);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->entity_a,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'entity_a'\n");
      return false;
    }
  }

  // Field name: body_a
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->body_a.data) {
      rosidl_runtime_c__String__init(&ros_message->body_a);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->body_a,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'body_a'\n");
      return false;
    }
  }

  // Field name: entity_b
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->entity_b.data) {
      rosidl_runtime_c__String__init(&ros_message->entity_b);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->entity_b,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'entity_b'\n");
      return false;
    }
  }

  // Field name: body_b
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->body_b.data) {
      rosidl_runtime_c__String__init(&ros_message->body_b);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->body_b,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'body_b'\n");
      return false;
    }
  }

  // Field name: magnitude_forces
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->magnitude_forces.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->magnitude_forces);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->magnitude_forces, size)) {
      fprintf(stderr, "failed to create array for field 'magnitude_forces'");
      return false;
    }
    auto array_ptr = ros_message->magnitude_forces.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: contact_positions
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, flatland_msgs, msg, Vector2
      )()->data);
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->contact_positions.data) {
      flatland_msgs__msg__Vector2__Sequence__fini(&ros_message->contact_positions);
    }
    if (!flatland_msgs__msg__Vector2__Sequence__init(&ros_message->contact_positions, size)) {
      fprintf(stderr, "failed to create array for field 'contact_positions'");
      return false;
    }
    auto array_ptr = ros_message->contact_positions.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  // Field name: contact_normals
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, flatland_msgs, msg, Vector2
      )()->data);
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->contact_normals.data) {
      flatland_msgs__msg__Vector2__Sequence__fini(&ros_message->contact_normals);
    }
    if (!flatland_msgs__msg__Vector2__Sequence__init(&ros_message->contact_normals, size)) {
      fprintf(stderr, "failed to create array for field 'contact_normals'");
      return false;
    }
    auto array_ptr = ros_message->contact_normals.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_flatland_msgs
size_t get_serialized_size_flatland_msgs__msg__Collision(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Collision__ros_msg_type * ros_message = static_cast<const _Collision__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name entity_a
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->entity_a.size + 1);
  // field.name body_a
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->body_a.size + 1);
  // field.name entity_b
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->entity_b.size + 1);
  // field.name body_b
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->body_b.size + 1);
  // field.name magnitude_forces
  {
    size_t array_size = ros_message->magnitude_forces.size;
    auto array_ptr = ros_message->magnitude_forces.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name contact_positions
  {
    size_t array_size = ros_message->contact_positions.size;
    auto array_ptr = ros_message->contact_positions.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_flatland_msgs__msg__Vector2(
        &array_ptr[index], current_alignment);
    }
  }
  // field.name contact_normals
  {
    size_t array_size = ros_message->contact_normals.size;
    auto array_ptr = ros_message->contact_normals.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_flatland_msgs__msg__Vector2(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Collision__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_flatland_msgs__msg__Collision(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_flatland_msgs
size_t max_serialized_size_flatland_msgs__msg__Collision(
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

  // member: entity_a
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
  // member: body_a
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
  // member: entity_b
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
  // member: body_b
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
  // member: magnitude_forces
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
  // member: contact_positions
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
      size_t inner_size;
      inner_size =
        max_serialized_size_flatland_msgs__msg__Vector2(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: contact_normals
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
      size_t inner_size;
      inner_size =
        max_serialized_size_flatland_msgs__msg__Vector2(
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
    using DataType = flatland_msgs__msg__Collision;
    is_plain =
      (
      offsetof(DataType, contact_normals) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _Collision__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_flatland_msgs__msg__Collision(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Collision = {
  "flatland_msgs::msg",
  "Collision",
  _Collision__cdr_serialize,
  _Collision__cdr_deserialize,
  _Collision__get_serialized_size,
  _Collision__max_serialized_size
};

static rosidl_message_type_support_t _Collision__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Collision,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, flatland_msgs, msg, Collision)() {
  return &_Collision__type_support;
}

#if defined(__cplusplus)
}
#endif
