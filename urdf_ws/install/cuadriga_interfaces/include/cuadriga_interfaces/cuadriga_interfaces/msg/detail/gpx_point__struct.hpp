// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cuadriga_interfaces:msg/GPXPoint.idl
// generated code does not contain a copyright notice

#ifndef CUADRIGA_INTERFACES__MSG__DETAIL__GPX_POINT__STRUCT_HPP_
#define CUADRIGA_INTERFACES__MSG__DETAIL__GPX_POINT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__cuadriga_interfaces__msg__GPXPoint __attribute__((deprecated))
#else
# define DEPRECATED__cuadriga_interfaces__msg__GPXPoint __declspec(deprecated)
#endif

namespace cuadriga_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GPXPoint_
{
  using Type = GPXPoint_<ContainerAllocator>;

  explicit GPXPoint_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->latitude = 0.0;
      this->longitude = 0.0;
      this->altitude = 0.0;
    }
  }

  explicit GPXPoint_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->latitude = 0.0;
      this->longitude = 0.0;
      this->altitude = 0.0;
    }
  }

  // field types and members
  using _latitude_type =
    double;
  _latitude_type latitude;
  using _longitude_type =
    double;
  _longitude_type longitude;
  using _altitude_type =
    double;
  _altitude_type altitude;

  // setters for named parameter idiom
  Type & set__latitude(
    const double & _arg)
  {
    this->latitude = _arg;
    return *this;
  }
  Type & set__longitude(
    const double & _arg)
  {
    this->longitude = _arg;
    return *this;
  }
  Type & set__altitude(
    const double & _arg)
  {
    this->altitude = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cuadriga_interfaces::msg::GPXPoint_<ContainerAllocator> *;
  using ConstRawPtr =
    const cuadriga_interfaces::msg::GPXPoint_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cuadriga_interfaces::msg::GPXPoint_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cuadriga_interfaces::msg::GPXPoint_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cuadriga_interfaces::msg::GPXPoint_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cuadriga_interfaces::msg::GPXPoint_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cuadriga_interfaces::msg::GPXPoint_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cuadriga_interfaces::msg::GPXPoint_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cuadriga_interfaces::msg::GPXPoint_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cuadriga_interfaces::msg::GPXPoint_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cuadriga_interfaces__msg__GPXPoint
    std::shared_ptr<cuadriga_interfaces::msg::GPXPoint_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cuadriga_interfaces__msg__GPXPoint
    std::shared_ptr<cuadriga_interfaces::msg::GPXPoint_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GPXPoint_ & other) const
  {
    if (this->latitude != other.latitude) {
      return false;
    }
    if (this->longitude != other.longitude) {
      return false;
    }
    if (this->altitude != other.altitude) {
      return false;
    }
    return true;
  }
  bool operator!=(const GPXPoint_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GPXPoint_

// alias to use template instance with default allocator
using GPXPoint =
  cuadriga_interfaces::msg::GPXPoint_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace cuadriga_interfaces

#endif  // CUADRIGA_INTERFACES__MSG__DETAIL__GPX_POINT__STRUCT_HPP_
