// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from flatland_msgs:msg/Collision.idl
// generated code does not contain a copyright notice

#ifndef FLATLAND_MSGS__MSG__DETAIL__COLLISION__TRAITS_HPP_
#define FLATLAND_MSGS__MSG__DETAIL__COLLISION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "flatland_msgs/msg/detail/collision__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'contact_positions'
// Member 'contact_normals'
#include "flatland_msgs/msg/detail/vector2__traits.hpp"

namespace flatland_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Collision & msg,
  std::ostream & out)
{
  out << "{";
  // member: entity_a
  {
    out << "entity_a: ";
    rosidl_generator_traits::value_to_yaml(msg.entity_a, out);
    out << ", ";
  }

  // member: body_a
  {
    out << "body_a: ";
    rosidl_generator_traits::value_to_yaml(msg.body_a, out);
    out << ", ";
  }

  // member: entity_b
  {
    out << "entity_b: ";
    rosidl_generator_traits::value_to_yaml(msg.entity_b, out);
    out << ", ";
  }

  // member: body_b
  {
    out << "body_b: ";
    rosidl_generator_traits::value_to_yaml(msg.body_b, out);
    out << ", ";
  }

  // member: magnitude_forces
  {
    if (msg.magnitude_forces.size() == 0) {
      out << "magnitude_forces: []";
    } else {
      out << "magnitude_forces: [";
      size_t pending_items = msg.magnitude_forces.size();
      for (auto item : msg.magnitude_forces) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: contact_positions
  {
    if (msg.contact_positions.size() == 0) {
      out << "contact_positions: []";
    } else {
      out << "contact_positions: [";
      size_t pending_items = msg.contact_positions.size();
      for (auto item : msg.contact_positions) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: contact_normals
  {
    if (msg.contact_normals.size() == 0) {
      out << "contact_normals: []";
    } else {
      out << "contact_normals: [";
      size_t pending_items = msg.contact_normals.size();
      for (auto item : msg.contact_normals) {
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
  const Collision & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: entity_a
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "entity_a: ";
    rosidl_generator_traits::value_to_yaml(msg.entity_a, out);
    out << "\n";
  }

  // member: body_a
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "body_a: ";
    rosidl_generator_traits::value_to_yaml(msg.body_a, out);
    out << "\n";
  }

  // member: entity_b
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "entity_b: ";
    rosidl_generator_traits::value_to_yaml(msg.entity_b, out);
    out << "\n";
  }

  // member: body_b
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "body_b: ";
    rosidl_generator_traits::value_to_yaml(msg.body_b, out);
    out << "\n";
  }

  // member: magnitude_forces
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.magnitude_forces.size() == 0) {
      out << "magnitude_forces: []\n";
    } else {
      out << "magnitude_forces:\n";
      for (auto item : msg.magnitude_forces) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: contact_positions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.contact_positions.size() == 0) {
      out << "contact_positions: []\n";
    } else {
      out << "contact_positions:\n";
      for (auto item : msg.contact_positions) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: contact_normals
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.contact_normals.size() == 0) {
      out << "contact_normals: []\n";
    } else {
      out << "contact_normals:\n";
      for (auto item : msg.contact_normals) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Collision & msg, bool use_flow_style = false)
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
  const flatland_msgs::msg::Collision & msg,
  std::ostream & out, size_t indentation = 0)
{
  flatland_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use flatland_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const flatland_msgs::msg::Collision & msg)
{
  return flatland_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<flatland_msgs::msg::Collision>()
{
  return "flatland_msgs::msg::Collision";
}

template<>
inline const char * name<flatland_msgs::msg::Collision>()
{
  return "flatland_msgs/msg/Collision";
}

template<>
struct has_fixed_size<flatland_msgs::msg::Collision>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<flatland_msgs::msg::Collision>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<flatland_msgs::msg::Collision>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FLATLAND_MSGS__MSG__DETAIL__COLLISION__TRAITS_HPP_
