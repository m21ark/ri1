// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from flatland_msgs:srv/DeleteModel.idl
// generated code does not contain a copyright notice

#ifndef FLATLAND_MSGS__SRV__DETAIL__DELETE_MODEL__BUILDER_HPP_
#define FLATLAND_MSGS__SRV__DETAIL__DELETE_MODEL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "flatland_msgs/srv/detail/delete_model__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace flatland_msgs
{

namespace srv
{

namespace builder
{

class Init_DeleteModel_Request_name
{
public:
  Init_DeleteModel_Request_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::flatland_msgs::srv::DeleteModel_Request name(::flatland_msgs::srv::DeleteModel_Request::_name_type arg)
  {
    msg_.name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::flatland_msgs::srv::DeleteModel_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::flatland_msgs::srv::DeleteModel_Request>()
{
  return flatland_msgs::srv::builder::Init_DeleteModel_Request_name();
}

}  // namespace flatland_msgs


namespace flatland_msgs
{

namespace srv
{

namespace builder
{

class Init_DeleteModel_Response_message
{
public:
  explicit Init_DeleteModel_Response_message(::flatland_msgs::srv::DeleteModel_Response & msg)
  : msg_(msg)
  {}
  ::flatland_msgs::srv::DeleteModel_Response message(::flatland_msgs::srv::DeleteModel_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::flatland_msgs::srv::DeleteModel_Response msg_;
};

class Init_DeleteModel_Response_success
{
public:
  Init_DeleteModel_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DeleteModel_Response_message success(::flatland_msgs::srv::DeleteModel_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_DeleteModel_Response_message(msg_);
  }

private:
  ::flatland_msgs::srv::DeleteModel_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::flatland_msgs::srv::DeleteModel_Response>()
{
  return flatland_msgs::srv::builder::Init_DeleteModel_Response_success();
}

}  // namespace flatland_msgs

#endif  // FLATLAND_MSGS__SRV__DETAIL__DELETE_MODEL__BUILDER_HPP_
