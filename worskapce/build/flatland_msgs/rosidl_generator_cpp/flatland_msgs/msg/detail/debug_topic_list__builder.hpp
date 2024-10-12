// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from flatland_msgs:msg/DebugTopicList.idl
// generated code does not contain a copyright notice

#ifndef FLATLAND_MSGS__MSG__DETAIL__DEBUG_TOPIC_LIST__BUILDER_HPP_
#define FLATLAND_MSGS__MSG__DETAIL__DEBUG_TOPIC_LIST__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "flatland_msgs/msg/detail/debug_topic_list__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace flatland_msgs
{

namespace msg
{

namespace builder
{

class Init_DebugTopicList_topics
{
public:
  Init_DebugTopicList_topics()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::flatland_msgs::msg::DebugTopicList topics(::flatland_msgs::msg::DebugTopicList::_topics_type arg)
  {
    msg_.topics = std::move(arg);
    return std::move(msg_);
  }

private:
  ::flatland_msgs::msg::DebugTopicList msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::flatland_msgs::msg::DebugTopicList>()
{
  return flatland_msgs::msg::builder::Init_DebugTopicList_topics();
}

}  // namespace flatland_msgs

#endif  // FLATLAND_MSGS__MSG__DETAIL__DEBUG_TOPIC_LIST__BUILDER_HPP_
