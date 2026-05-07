// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cuadriga_interfaces:msg/GPXPoint.idl
// generated code does not contain a copyright notice

#ifndef CUADRIGA_INTERFACES__MSG__DETAIL__GPX_POINT__BUILDER_HPP_
#define CUADRIGA_INTERFACES__MSG__DETAIL__GPX_POINT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cuadriga_interfaces/msg/detail/gpx_point__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cuadriga_interfaces
{

namespace msg
{

namespace builder
{

class Init_GPXPoint_altitude
{
public:
  explicit Init_GPXPoint_altitude(::cuadriga_interfaces::msg::GPXPoint & msg)
  : msg_(msg)
  {}
  ::cuadriga_interfaces::msg::GPXPoint altitude(::cuadriga_interfaces::msg::GPXPoint::_altitude_type arg)
  {
    msg_.altitude = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cuadriga_interfaces::msg::GPXPoint msg_;
};

class Init_GPXPoint_longitude
{
public:
  explicit Init_GPXPoint_longitude(::cuadriga_interfaces::msg::GPXPoint & msg)
  : msg_(msg)
  {}
  Init_GPXPoint_altitude longitude(::cuadriga_interfaces::msg::GPXPoint::_longitude_type arg)
  {
    msg_.longitude = std::move(arg);
    return Init_GPXPoint_altitude(msg_);
  }

private:
  ::cuadriga_interfaces::msg::GPXPoint msg_;
};

class Init_GPXPoint_latitude
{
public:
  Init_GPXPoint_latitude()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GPXPoint_longitude latitude(::cuadriga_interfaces::msg::GPXPoint::_latitude_type arg)
  {
    msg_.latitude = std::move(arg);
    return Init_GPXPoint_longitude(msg_);
  }

private:
  ::cuadriga_interfaces::msg::GPXPoint msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cuadriga_interfaces::msg::GPXPoint>()
{
  return cuadriga_interfaces::msg::builder::Init_GPXPoint_latitude();
}

}  // namespace cuadriga_interfaces

#endif  // CUADRIGA_INTERFACES__MSG__DETAIL__GPX_POINT__BUILDER_HPP_
