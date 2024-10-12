// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from flatland_msgs:msg/Collision.idl
// generated code does not contain a copyright notice

#ifndef FLATLAND_MSGS__MSG__DETAIL__COLLISION__BUILDER_HPP_
#define FLATLAND_MSGS__MSG__DETAIL__COLLISION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "flatland_msgs/msg/detail/collision__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace flatland_msgs
{

namespace msg
{

namespace builder
{

class Init_Collision_contact_normals
{
public:
  explicit Init_Collision_contact_normals(::flatland_msgs::msg::Collision & msg)
  : msg_(msg)
  {}
  ::flatland_msgs::msg::Collision contact_normals(::flatland_msgs::msg::Collision::_contact_normals_type arg)
  {
    msg_.contact_normals = std::move(arg);
    return std::move(msg_);
  }

private:
  ::flatland_msgs::msg::Collision msg_;
};

class Init_Collision_contact_positions
{
public:
  explicit Init_Collision_contact_positions(::flatland_msgs::msg::Collision & msg)
  : msg_(msg)
  {}
  Init_Collision_contact_normals contact_positions(::flatland_msgs::msg::Collision::_contact_positions_type arg)
  {
    msg_.contact_positions = std::move(arg);
    return Init_Collision_contact_normals(msg_);
  }

private:
  ::flatland_msgs::msg::Collision msg_;
};

class Init_Collision_magnitude_forces
{
public:
  explicit Init_Collision_magnitude_forces(::flatland_msgs::msg::Collision & msg)
  : msg_(msg)
  {}
  Init_Collision_contact_positions magnitude_forces(::flatland_msgs::msg::Collision::_magnitude_forces_type arg)
  {
    msg_.magnitude_forces = std::move(arg);
    return Init_Collision_contact_positions(msg_);
  }

private:
  ::flatland_msgs::msg::Collision msg_;
};

class Init_Collision_body_b
{
public:
  explicit Init_Collision_body_b(::flatland_msgs::msg::Collision & msg)
  : msg_(msg)
  {}
  Init_Collision_magnitude_forces body_b(::flatland_msgs::msg::Collision::_body_b_type arg)
  {
    msg_.body_b = std::move(arg);
    return Init_Collision_magnitude_forces(msg_);
  }

private:
  ::flatland_msgs::msg::Collision msg_;
};

class Init_Collision_entity_b
{
public:
  explicit Init_Collision_entity_b(::flatland_msgs::msg::Collision & msg)
  : msg_(msg)
  {}
  Init_Collision_body_b entity_b(::flatland_msgs::msg::Collision::_entity_b_type arg)
  {
    msg_.entity_b = std::move(arg);
    return Init_Collision_body_b(msg_);
  }

private:
  ::flatland_msgs::msg::Collision msg_;
};

class Init_Collision_body_a
{
public:
  explicit Init_Collision_body_a(::flatland_msgs::msg::Collision & msg)
  : msg_(msg)
  {}
  Init_Collision_entity_b body_a(::flatland_msgs::msg::Collision::_body_a_type arg)
  {
    msg_.body_a = std::move(arg);
    return Init_Collision_entity_b(msg_);
  }

private:
  ::flatland_msgs::msg::Collision msg_;
};

class Init_Collision_entity_a
{
public:
  Init_Collision_entity_a()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Collision_body_a entity_a(::flatland_msgs::msg::Collision::_entity_a_type arg)
  {
    msg_.entity_a = std::move(arg);
    return Init_Collision_body_a(msg_);
  }

private:
  ::flatland_msgs::msg::Collision msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::flatland_msgs::msg::Collision>()
{
  return flatland_msgs::msg::builder::Init_Collision_entity_a();
}

}  // namespace flatland_msgs

#endif  // FLATLAND_MSGS__MSG__DETAIL__COLLISION__BUILDER_HPP_
