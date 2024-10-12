// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from flatland_msgs:msg/Collision.idl
// generated code does not contain a copyright notice

#ifndef FLATLAND_MSGS__MSG__DETAIL__COLLISION__STRUCT_HPP_
#define FLATLAND_MSGS__MSG__DETAIL__COLLISION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'contact_positions'
// Member 'contact_normals'
#include "flatland_msgs/msg/detail/vector2__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__flatland_msgs__msg__Collision __attribute__((deprecated))
#else
# define DEPRECATED__flatland_msgs__msg__Collision __declspec(deprecated)
#endif

namespace flatland_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Collision_
{
  using Type = Collision_<ContainerAllocator>;

  explicit Collision_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->entity_a = "";
      this->body_a = "";
      this->entity_b = "";
      this->body_b = "";
    }
  }

  explicit Collision_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : entity_a(_alloc),
    body_a(_alloc),
    entity_b(_alloc),
    body_b(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->entity_a = "";
      this->body_a = "";
      this->entity_b = "";
      this->body_b = "";
    }
  }

  // field types and members
  using _entity_a_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _entity_a_type entity_a;
  using _body_a_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _body_a_type body_a;
  using _entity_b_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _entity_b_type entity_b;
  using _body_b_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _body_b_type body_b;
  using _magnitude_forces_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _magnitude_forces_type magnitude_forces;
  using _contact_positions_type =
    std::vector<flatland_msgs::msg::Vector2_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<flatland_msgs::msg::Vector2_<ContainerAllocator>>>;
  _contact_positions_type contact_positions;
  using _contact_normals_type =
    std::vector<flatland_msgs::msg::Vector2_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<flatland_msgs::msg::Vector2_<ContainerAllocator>>>;
  _contact_normals_type contact_normals;

  // setters for named parameter idiom
  Type & set__entity_a(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->entity_a = _arg;
    return *this;
  }
  Type & set__body_a(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->body_a = _arg;
    return *this;
  }
  Type & set__entity_b(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->entity_b = _arg;
    return *this;
  }
  Type & set__body_b(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->body_b = _arg;
    return *this;
  }
  Type & set__magnitude_forces(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->magnitude_forces = _arg;
    return *this;
  }
  Type & set__contact_positions(
    const std::vector<flatland_msgs::msg::Vector2_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<flatland_msgs::msg::Vector2_<ContainerAllocator>>> & _arg)
  {
    this->contact_positions = _arg;
    return *this;
  }
  Type & set__contact_normals(
    const std::vector<flatland_msgs::msg::Vector2_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<flatland_msgs::msg::Vector2_<ContainerAllocator>>> & _arg)
  {
    this->contact_normals = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    flatland_msgs::msg::Collision_<ContainerAllocator> *;
  using ConstRawPtr =
    const flatland_msgs::msg::Collision_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<flatland_msgs::msg::Collision_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<flatland_msgs::msg::Collision_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      flatland_msgs::msg::Collision_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<flatland_msgs::msg::Collision_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      flatland_msgs::msg::Collision_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<flatland_msgs::msg::Collision_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<flatland_msgs::msg::Collision_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<flatland_msgs::msg::Collision_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__flatland_msgs__msg__Collision
    std::shared_ptr<flatland_msgs::msg::Collision_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__flatland_msgs__msg__Collision
    std::shared_ptr<flatland_msgs::msg::Collision_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Collision_ & other) const
  {
    if (this->entity_a != other.entity_a) {
      return false;
    }
    if (this->body_a != other.body_a) {
      return false;
    }
    if (this->entity_b != other.entity_b) {
      return false;
    }
    if (this->body_b != other.body_b) {
      return false;
    }
    if (this->magnitude_forces != other.magnitude_forces) {
      return false;
    }
    if (this->contact_positions != other.contact_positions) {
      return false;
    }
    if (this->contact_normals != other.contact_normals) {
      return false;
    }
    return true;
  }
  bool operator!=(const Collision_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Collision_

// alias to use template instance with default allocator
using Collision =
  flatland_msgs::msg::Collision_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace flatland_msgs

#endif  // FLATLAND_MSGS__MSG__DETAIL__COLLISION__STRUCT_HPP_
