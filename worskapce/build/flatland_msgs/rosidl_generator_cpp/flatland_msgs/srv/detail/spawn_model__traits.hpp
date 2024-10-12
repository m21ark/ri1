// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from flatland_msgs:srv/SpawnModel.idl
// generated code does not contain a copyright notice

#ifndef FLATLAND_MSGS__SRV__DETAIL__SPAWN_MODEL__TRAITS_HPP_
#define FLATLAND_MSGS__SRV__DETAIL__SPAWN_MODEL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "flatland_msgs/srv/detail/spawn_model__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose2_d__traits.hpp"

namespace flatland_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const SpawnModel_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: yaml_path
  {
    out << "yaml_path: ";
    rosidl_generator_traits::value_to_yaml(msg.yaml_path, out);
    out << ", ";
  }

  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << ", ";
  }

  // member: ns
  {
    out << "ns: ";
    rosidl_generator_traits::value_to_yaml(msg.ns, out);
    out << ", ";
  }

  // member: pose
  {
    out << "pose: ";
    to_flow_style_yaml(msg.pose, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SpawnModel_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: yaml_path
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaml_path: ";
    rosidl_generator_traits::value_to_yaml(msg.yaml_path, out);
    out << "\n";
  }

  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << "\n";
  }

  // member: ns
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ns: ";
    rosidl_generator_traits::value_to_yaml(msg.ns, out);
    out << "\n";
  }

  // member: pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose:\n";
    to_block_style_yaml(msg.pose, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SpawnModel_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace flatland_msgs

namespace rosidl_generator_traits
{

[[deprecated("use flatland_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const flatland_msgs::srv::SpawnModel_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  flatland_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use flatland_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const flatland_msgs::srv::SpawnModel_Request & msg)
{
  return flatland_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<flatland_msgs::srv::SpawnModel_Request>()
{
  return "flatland_msgs::srv::SpawnModel_Request";
}

template<>
inline const char * name<flatland_msgs::srv::SpawnModel_Request>()
{
  return "flatland_msgs/srv/SpawnModel_Request";
}

template<>
struct has_fixed_size<flatland_msgs::srv::SpawnModel_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<flatland_msgs::srv::SpawnModel_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<flatland_msgs::srv::SpawnModel_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace flatland_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const SpawnModel_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SpawnModel_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SpawnModel_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace flatland_msgs

namespace rosidl_generator_traits
{

[[deprecated("use flatland_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const flatland_msgs::srv::SpawnModel_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  flatland_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use flatland_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const flatland_msgs::srv::SpawnModel_Response & msg)
{
  return flatland_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<flatland_msgs::srv::SpawnModel_Response>()
{
  return "flatland_msgs::srv::SpawnModel_Response";
}

template<>
inline const char * name<flatland_msgs::srv::SpawnModel_Response>()
{
  return "flatland_msgs/srv/SpawnModel_Response";
}

template<>
struct has_fixed_size<flatland_msgs::srv::SpawnModel_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<flatland_msgs::srv::SpawnModel_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<flatland_msgs::srv::SpawnModel_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<flatland_msgs::srv::SpawnModel>()
{
  return "flatland_msgs::srv::SpawnModel";
}

template<>
inline const char * name<flatland_msgs::srv::SpawnModel>()
{
  return "flatland_msgs/srv/SpawnModel";
}

template<>
struct has_fixed_size<flatland_msgs::srv::SpawnModel>
  : std::integral_constant<
    bool,
    has_fixed_size<flatland_msgs::srv::SpawnModel_Request>::value &&
    has_fixed_size<flatland_msgs::srv::SpawnModel_Response>::value
  >
{
};

template<>
struct has_bounded_size<flatland_msgs::srv::SpawnModel>
  : std::integral_constant<
    bool,
    has_bounded_size<flatland_msgs::srv::SpawnModel_Request>::value &&
    has_bounded_size<flatland_msgs::srv::SpawnModel_Response>::value
  >
{
};

template<>
struct is_service<flatland_msgs::srv::SpawnModel>
  : std::true_type
{
};

template<>
struct is_service_request<flatland_msgs::srv::SpawnModel_Request>
  : std::true_type
{
};

template<>
struct is_service_response<flatland_msgs::srv::SpawnModel_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // FLATLAND_MSGS__SRV__DETAIL__SPAWN_MODEL__TRAITS_HPP_
