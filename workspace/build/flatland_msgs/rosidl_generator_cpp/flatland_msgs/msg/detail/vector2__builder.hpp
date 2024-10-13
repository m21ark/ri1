// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from flatland_msgs:msg/Vector2.idl
// generated code does not contain a copyright notice

#ifndef FLATLAND_MSGS__MSG__DETAIL__VECTOR2__BUILDER_HPP_
#define FLATLAND_MSGS__MSG__DETAIL__VECTOR2__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "flatland_msgs/msg/detail/vector2__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace flatland_msgs
{

namespace msg
{

namespace builder
{

class Init_Vector2_y
{
public:
  explicit Init_Vector2_y(::flatland_msgs::msg::Vector2 & msg)
  : msg_(msg)
  {}
  ::flatland_msgs::msg::Vector2 y(::flatland_msgs::msg::Vector2::_y_type arg)
  {
    msg_.y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::flatland_msgs::msg::Vector2 msg_;
};

class Init_Vector2_x
{
public:
  Init_Vector2_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Vector2_y x(::flatland_msgs::msg::Vector2::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Vector2_y(msg_);
  }

private:
  ::flatland_msgs::msg::Vector2 msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::flatland_msgs::msg::Vector2>()
{
  return flatland_msgs::msg::builder::Init_Vector2_x();
}

}  // namespace flatland_msgs

#endif  // FLATLAND_MSGS__MSG__DETAIL__VECTOR2__BUILDER_HPP_
