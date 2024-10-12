// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from flatland_msgs:srv/SpawnModel.idl
// generated code does not contain a copyright notice

#ifndef FLATLAND_MSGS__SRV__DETAIL__SPAWN_MODEL__BUILDER_HPP_
#define FLATLAND_MSGS__SRV__DETAIL__SPAWN_MODEL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "flatland_msgs/srv/detail/spawn_model__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace flatland_msgs
{

namespace srv
{

namespace builder
{

class Init_SpawnModel_Request_pose
{
public:
  explicit Init_SpawnModel_Request_pose(::flatland_msgs::srv::SpawnModel_Request & msg)
  : msg_(msg)
  {}
  ::flatland_msgs::srv::SpawnModel_Request pose(::flatland_msgs::srv::SpawnModel_Request::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::flatland_msgs::srv::SpawnModel_Request msg_;
};

class Init_SpawnModel_Request_ns
{
public:
  explicit Init_SpawnModel_Request_ns(::flatland_msgs::srv::SpawnModel_Request & msg)
  : msg_(msg)
  {}
  Init_SpawnModel_Request_pose ns(::flatland_msgs::srv::SpawnModel_Request::_ns_type arg)
  {
    msg_.ns = std::move(arg);
    return Init_SpawnModel_Request_pose(msg_);
  }

private:
  ::flatland_msgs::srv::SpawnModel_Request msg_;
};

class Init_SpawnModel_Request_name
{
public:
  explicit Init_SpawnModel_Request_name(::flatland_msgs::srv::SpawnModel_Request & msg)
  : msg_(msg)
  {}
  Init_SpawnModel_Request_ns name(::flatland_msgs::srv::SpawnModel_Request::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_SpawnModel_Request_ns(msg_);
  }

private:
  ::flatland_msgs::srv::SpawnModel_Request msg_;
};

class Init_SpawnModel_Request_yaml_path
{
public:
  Init_SpawnModel_Request_yaml_path()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SpawnModel_Request_name yaml_path(::flatland_msgs::srv::SpawnModel_Request::_yaml_path_type arg)
  {
    msg_.yaml_path = std::move(arg);
    return Init_SpawnModel_Request_name(msg_);
  }

private:
  ::flatland_msgs::srv::SpawnModel_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::flatland_msgs::srv::SpawnModel_Request>()
{
  return flatland_msgs::srv::builder::Init_SpawnModel_Request_yaml_path();
}

}  // namespace flatland_msgs


namespace flatland_msgs
{

namespace srv
{

namespace builder
{

class Init_SpawnModel_Response_message
{
public:
  explicit Init_SpawnModel_Response_message(::flatland_msgs::srv::SpawnModel_Response & msg)
  : msg_(msg)
  {}
  ::flatland_msgs::srv::SpawnModel_Response message(::flatland_msgs::srv::SpawnModel_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::flatland_msgs::srv::SpawnModel_Response msg_;
};

class Init_SpawnModel_Response_success
{
public:
  Init_SpawnModel_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SpawnModel_Response_message success(::flatland_msgs::srv::SpawnModel_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_SpawnModel_Response_message(msg_);
  }

private:
  ::flatland_msgs::srv::SpawnModel_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::flatland_msgs::srv::SpawnModel_Response>()
{
  return flatland_msgs::srv::builder::Init_SpawnModel_Response_success();
}

}  // namespace flatland_msgs

#endif  // FLATLAND_MSGS__SRV__DETAIL__SPAWN_MODEL__BUILDER_HPP_
