// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from flatland_msgs:msg/Collision.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "flatland_msgs/msg/detail/collision__struct.hpp"
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

void Collision_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) flatland_msgs::msg::Collision(_init);
}

void Collision_fini_function(void * message_memory)
{
  auto typed_message = static_cast<flatland_msgs::msg::Collision *>(message_memory);
  typed_message->~Collision();
}

size_t size_function__Collision__magnitude_forces(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Collision__magnitude_forces(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__Collision__magnitude_forces(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__Collision__magnitude_forces(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__Collision__magnitude_forces(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__Collision__magnitude_forces(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__Collision__magnitude_forces(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__Collision__magnitude_forces(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Collision__contact_positions(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<flatland_msgs::msg::Vector2> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Collision__contact_positions(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<flatland_msgs::msg::Vector2> *>(untyped_member);
  return &member[index];
}

void * get_function__Collision__contact_positions(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<flatland_msgs::msg::Vector2> *>(untyped_member);
  return &member[index];
}

void fetch_function__Collision__contact_positions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const flatland_msgs::msg::Vector2 *>(
    get_const_function__Collision__contact_positions(untyped_member, index));
  auto & value = *reinterpret_cast<flatland_msgs::msg::Vector2 *>(untyped_value);
  value = item;
}

void assign_function__Collision__contact_positions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<flatland_msgs::msg::Vector2 *>(
    get_function__Collision__contact_positions(untyped_member, index));
  const auto & value = *reinterpret_cast<const flatland_msgs::msg::Vector2 *>(untyped_value);
  item = value;
}

void resize_function__Collision__contact_positions(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<flatland_msgs::msg::Vector2> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Collision__contact_normals(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<flatland_msgs::msg::Vector2> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Collision__contact_normals(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<flatland_msgs::msg::Vector2> *>(untyped_member);
  return &member[index];
}

void * get_function__Collision__contact_normals(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<flatland_msgs::msg::Vector2> *>(untyped_member);
  return &member[index];
}

void fetch_function__Collision__contact_normals(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const flatland_msgs::msg::Vector2 *>(
    get_const_function__Collision__contact_normals(untyped_member, index));
  auto & value = *reinterpret_cast<flatland_msgs::msg::Vector2 *>(untyped_value);
  value = item;
}

void assign_function__Collision__contact_normals(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<flatland_msgs::msg::Vector2 *>(
    get_function__Collision__contact_normals(untyped_member, index));
  const auto & value = *reinterpret_cast<const flatland_msgs::msg::Vector2 *>(untyped_value);
  item = value;
}

void resize_function__Collision__contact_normals(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<flatland_msgs::msg::Vector2> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Collision_message_member_array[7] = {
  {
    "entity_a",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(flatland_msgs::msg::Collision, entity_a),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "body_a",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(flatland_msgs::msg::Collision, body_a),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "entity_b",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(flatland_msgs::msg::Collision, entity_b),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "body_b",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(flatland_msgs::msg::Collision, body_b),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "magnitude_forces",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(flatland_msgs::msg::Collision, magnitude_forces),  // bytes offset in struct
    nullptr,  // default value
    size_function__Collision__magnitude_forces,  // size() function pointer
    get_const_function__Collision__magnitude_forces,  // get_const(index) function pointer
    get_function__Collision__magnitude_forces,  // get(index) function pointer
    fetch_function__Collision__magnitude_forces,  // fetch(index, &value) function pointer
    assign_function__Collision__magnitude_forces,  // assign(index, value) function pointer
    resize_function__Collision__magnitude_forces  // resize(index) function pointer
  },
  {
    "contact_positions",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<flatland_msgs::msg::Vector2>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(flatland_msgs::msg::Collision, contact_positions),  // bytes offset in struct
    nullptr,  // default value
    size_function__Collision__contact_positions,  // size() function pointer
    get_const_function__Collision__contact_positions,  // get_const(index) function pointer
    get_function__Collision__contact_positions,  // get(index) function pointer
    fetch_function__Collision__contact_positions,  // fetch(index, &value) function pointer
    assign_function__Collision__contact_positions,  // assign(index, value) function pointer
    resize_function__Collision__contact_positions  // resize(index) function pointer
  },
  {
    "contact_normals",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<flatland_msgs::msg::Vector2>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(flatland_msgs::msg::Collision, contact_normals),  // bytes offset in struct
    nullptr,  // default value
    size_function__Collision__contact_normals,  // size() function pointer
    get_const_function__Collision__contact_normals,  // get_const(index) function pointer
    get_function__Collision__contact_normals,  // get(index) function pointer
    fetch_function__Collision__contact_normals,  // fetch(index, &value) function pointer
    assign_function__Collision__contact_normals,  // assign(index, value) function pointer
    resize_function__Collision__contact_normals  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Collision_message_members = {
  "flatland_msgs::msg",  // message namespace
  "Collision",  // message name
  7,  // number of fields
  sizeof(flatland_msgs::msg::Collision),
  Collision_message_member_array,  // message members
  Collision_init_function,  // function to initialize message memory (memory has to be allocated)
  Collision_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Collision_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Collision_message_members,
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
get_message_type_support_handle<flatland_msgs::msg::Collision>()
{
  return &::flatland_msgs::msg::rosidl_typesupport_introspection_cpp::Collision_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, flatland_msgs, msg, Collision)() {
  return &::flatland_msgs::msg::rosidl_typesupport_introspection_cpp::Collision_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
