// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from flatland_msgs:msg/Collisions.idl
// generated code does not contain a copyright notice

#ifndef FLATLAND_MSGS__MSG__DETAIL__COLLISIONS__BUILDER_HPP_
#define FLATLAND_MSGS__MSG__DETAIL__COLLISIONS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "flatland_msgs/msg/detail/collisions__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace flatland_msgs
{

namespace msg
{

namespace builder
{

class Init_Collisions_collisions
{
public:
  explicit Init_Collisions_collisions(::flatland_msgs::msg::Collisions & msg)
  : msg_(msg)
  {}
  ::flatland_msgs::msg::Collisions collisions(::flatland_msgs::msg::Collisions::_collisions_type arg)
  {
    msg_.collisions = std::move(arg);
    return std::move(msg_);
  }

private:
  ::flatland_msgs::msg::Collisions msg_;
};

class Init_Collisions_header
{
public:
  Init_Collisions_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Collisions_collisions header(::flatland_msgs::msg::Collisions::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Collisions_collisions(msg_);
  }

private:
  ::flatland_msgs::msg::Collisions msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::flatland_msgs::msg::Collisions>()
{
  return flatland_msgs::msg::builder::Init_Collisions_header();
}

}  // namespace flatland_msgs

#endif  // FLATLAND_MSGS__MSG__DETAIL__COLLISIONS__BUILDER_HPP_
