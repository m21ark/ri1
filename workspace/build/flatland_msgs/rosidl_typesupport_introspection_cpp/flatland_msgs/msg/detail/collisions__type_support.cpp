// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from flatland_msgs:msg/Collisions.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "flatland_msgs/msg/detail/collisions__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace flatland_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Collisions_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) flatland_msgs::msg::Collisions(_init);
}

void Collisions_fini_function(void * message_memory)
{
  auto typed_message = static_cast<flatland_msgs::msg::Collisions *>(message_memory);
  typed_message->~Collisions();
}

size_t size_function__Collisions__collisions(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<flatland_msgs::msg::Collision> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Collisions__collisions(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<flatland_msgs::msg::Collision> *>(untyped_member);
  return &member[index];
}

void * get_function__Collisions__collisions(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<flatland_msgs::msg::Collision> *>(untyped_member);
  return &member[index];
}

void fetch_function__Collisions__collisions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const flatland_msgs::msg::Collision *>(
    get_const_function__Collisions__collisions(untyped_member, index));
  auto & value = *reinterpret_cast<flatland_msgs::msg::Collision *>(untyped_value);
  value = item;
}

void assign_function__Collisions__collisions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<flatland_msgs::msg::Collision *>(
    get_function__Collisions__collisions(untyped_member, index));
  const auto & value = *reinterpret_cast<const flatland_msgs::msg::Collision *>(untyped_value);
  item = value;
}

void resize_function__Collisions__collisions(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<flatland_msgs::msg::Collision> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Collisions_message_member_array[2] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(flatland_msgs::msg::Collisions, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "collisions",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<flatland_msgs::msg::Collision>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(flatland_msgs::msg::Collisions, collisions),  // bytes offset in struct
    nullptr,  // default value
    size_function__Collisions__collisions,  // size() function pointer
    get_const_function__Collisions__collisions,  // get_const(index) function pointer
    get_function__Collisions__collisions,  // get(index) function pointer
    fetch_function__Collisions__collisions,  // fetch(index, &value) function pointer
    assign_function__Collisions__collisions,  // assign(index, value) function pointer
    resize_function__Collisions__collisions  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Collisions_message_members = {
  "flatland_msgs::msg",  // message namespace
  "Collisions",  // message name
  2,  // number of fields
  sizeof(flatland_msgs::msg::Collisions),
  Collisions_message_member_array,  // message members
  Collisions_init_function,  // function to initialize message memory (memory has to be allocated)
  Collisions_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Collisions_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Collisions_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace flatland_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<flatland_msgs::msg::Collisions>()
{
  return &::flatland_msgs::msg::rosidl_typesupport_introspection_cpp::Collisions_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, flatland_msgs, msg, Collisions)() {
  return &::flatland_msgs::msg::rosidl_typesupport_introspection_cpp::Collisions_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
