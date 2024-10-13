// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from flatland_msgs:msg/Collision.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "flatland_msgs/msg/detail/collision__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace flatland_msgs
{

namespace msg
{

namespace rosidl_typesupport_cpp
{

typedef struct _Collision_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Collision_type_support_ids_t;

static const _Collision_type_support_ids_t _Collision_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Collision_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Collision_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Collision_type_support_symbol_names_t _Collision_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, flatland_msgs, msg, Collision)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, flatland_msgs, msg, Collision)),
  }
};

typedef struct _Collision_type_support_data_t
{
  void * data[2];
} _Collision_type_support_data_t;

static _Collision_type_support_data_t _Collision_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Collision_message_typesupport_map = {
  2,
  "flatland_msgs",
  &_Collision_message_typesupport_ids.typesupport_identifier[0],
  &_Collision_message_typesupport_symbol_names.symbol_name[0],
  &_Collision_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Collision_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Collision_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace msg

}  // namespace flatland_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<flatland_msgs::msg::Collision>()
{
  return &::flatland_msgs::msg::rosidl_typesupport_cpp::Collision_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, flatland_msgs, msg, Collision)() {
  return get_message_type_support_handle<flatland_msgs::msg::Collision>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp
