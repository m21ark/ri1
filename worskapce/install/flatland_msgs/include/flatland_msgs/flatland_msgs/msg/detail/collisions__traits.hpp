// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from flatland_msgs:msg/Collisions.idl
// generated code does not contain a copyright notice

#ifndef FLATLAND_MSGS__MSG__DETAIL__COLLISIONS__TRAITS_HPP_
#define FLATLAND_MSGS__MSG__DETAIL__COLLISIONS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "flatland_msgs/msg/detail/collisions__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'collisions'
#include "flatland_msgs/msg/detail/collision__traits.hpp"

namespace flatland_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Collisions & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: collisions
  {
    if (msg.collisions.size() == 0) {
      out << "collisions: []";
    } else {
      out << "collisions: [";
      size_t pending_items = msg.collisions.size();
      for (auto item : msg.collisions) {
        to_flow_style_yaml(item, out);
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
  const Collisions & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: collisions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.collisions.size() == 0) {
      out << "collisions: []\n";
    } else {
      out << "collisions:\n";
      for (auto item : msg.collisions) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Collisions & msg, bool use_flow_style = false)
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
  const flatland_msgs::msg::Collisions & msg,
  std::ostream & out, size_t indentation = 0)
{
  flatland_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use flatland_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const flatland_msgs::msg::Collisions & msg)
{
  return flatland_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<flatland_msgs::msg::Collisions>()
{
  return "flatland_msgs::msg::Collisions";
}

template<>
inline const char * name<flatland_msgs::msg::Collisions>()
{
  return "flatland_msgs/msg/Collisions";
}

template<>
struct has_fixed_size<flatland_msgs::msg::Collisions>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<flatland_msgs::msg::Collisions>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<flatland_msgs::msg::Collisions>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FLATLAND_MSGS__MSG__DETAIL__COLLISIONS__TRAITS_HPP_
