// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from flatland_msgs:msg/Collisions.idl
// generated code does not contain a copyright notice

#ifndef FLATLAND_MSGS__MSG__DETAIL__COLLISIONS__STRUCT_HPP_
#define FLATLAND_MSGS__MSG__DETAIL__COLLISIONS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'collisions'
#include "flatland_msgs/msg/detail/collision__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__flatland_msgs__msg__Collisions __attribute__((deprecated))
#else
# define DEPRECATED__flatland_msgs__msg__Collisions __declspec(deprecated)
#endif

namespace flatland_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Collisions_
{
  using Type = Collisions_<ContainerAllocator>;

  explicit Collisions_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit Collisions_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _collisions_type =
    std::vector<flatland_msgs::msg::Collision_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<flatland_msgs::msg::Collision_<ContainerAllocator>>>;
  _collisions_type collisions;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__collisions(
    const std::vector<flatland_msgs::msg::Collision_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<flatland_msgs::msg::Collision_<ContainerAllocator>>> & _arg)
  {
    this->collisions = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    flatland_msgs::msg::Collisions_<ContainerAllocator> *;
  using ConstRawPtr =
    const flatland_msgs::msg::Collisions_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<flatland_msgs::msg::Collisions_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<flatland_msgs::msg::Collisions_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      flatland_msgs::msg::Collisions_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<flatland_msgs::msg::Collisions_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      flatland_msgs::msg::Collisions_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<flatland_msgs::msg::Collisions_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<flatland_msgs::msg::Collisions_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<flatland_msgs::msg::Collisions_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__flatland_msgs__msg__Collisions
    std::shared_ptr<flatland_msgs::msg::Collisions_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__flatland_msgs__msg__Collisions
    std::shared_ptr<flatland_msgs::msg::Collisions_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Collisions_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->collisions != other.collisions) {
      return false;
    }
    return true;
  }
  bool operator!=(const Collisions_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Collisions_

// alias to use template instance with default allocator
using Collisions =
  flatland_msgs::msg::Collisions_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace flatland_msgs

#endif  // FLATLAND_MSGS__MSG__DETAIL__COLLISIONS__STRUCT_HPP_
