// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from flatland_msgs:msg/DebugTopicList.idl
// generated code does not contain a copyright notice

#ifndef FLATLAND_MSGS__MSG__DETAIL__DEBUG_TOPIC_LIST__TRAITS_HPP_
#define FLATLAND_MSGS__MSG__DETAIL__DEBUG_TOPIC_LIST__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "flatland_msgs/msg/detail/debug_topic_list__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace flatland_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const DebugTopicList & msg,
  std::ostream & out)
{
  out << "{";
  // member: topics
  {
    if (msg.topics.size() == 0) {
      out << "topics: []";
    } else {
      out << "topics: [";
      size_t pending_items = msg.topics.size();
      for (auto item : msg.topics) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DebugTopicList & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: topics
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.topics.size() == 0) {
      out << "topics: []\n";
    } else {
      out << "topics:\n";
      for (auto item : msg.topics) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DebugTopicList & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace flatland_msgs

namespace rosidl_generator_traits
{

[[deprecated("use flatland_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const flatland_msgs::msg::DebugTopicList & msg,
  std::ostream & out, size_t indentation = 0)
{
  flatland_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use flatland_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const flatland_msgs::msg::DebugTopicList & msg)
{
  return flatland_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<flatland_msgs::msg::DebugTopicList>()
{
  return "flatland_msgs::msg::DebugTopicList";
}

template<>
inline const char * name<flatland_msgs::msg::DebugTopicList>()
{
  return "flatland_msgs/msg/DebugTopicList";
}

template<>
struct has_fixed_size<flatland_msgs::msg::DebugTopicList>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<flatland_msgs::msg::DebugTopicList>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<flatland_msgs::msg::DebugTopicList>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FLATLAND_MSGS__MSG__DETAIL__DEBUG_TOPIC_LIST__TRAITS_HPP_
