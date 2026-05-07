// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cuadriga_interfaces:msg/GPXPoint.idl
// generated code does not contain a copyright notice

#ifndef CUADRIGA_INTERFACES__MSG__DETAIL__GPX_POINT__TRAITS_HPP_
#define CUADRIGA_INTERFACES__MSG__DETAIL__GPX_POINT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cuadriga_interfaces/msg/detail/gpx_point__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace cuadriga_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const GPXPoint & msg,
  std::ostream & out)
{
  out << "{";
  // member: latitude
  {
    out << "latitude: ";
    rosidl_generator_traits::value_to_yaml(msg.latitude, out);
    out << ", ";
  }

  // member: longitude
  {
    out << "longitude: ";
    rosidl_generator_traits::value_to_yaml(msg.longitude, out);
    out << ", ";
  }

  // member: altitude
  {
    out << "altitude: ";
    rosidl_generator_traits::value_to_yaml(msg.altitude, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GPXPoint & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: latitude
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "latitude: ";
    rosidl_generator_traits::value_to_yaml(msg.latitude, out);
    out << "\n";
  }

  // member: longitude
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "longitude: ";
    rosidl_generator_traits::value_to_yaml(msg.longitude, out);
    out << "\n";
  }

  // member: altitude
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "altitude: ";
    rosidl_generator_traits::value_to_yaml(msg.altitude, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GPXPoint & msg, bool use_flow_style = false)
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

}  // namespace cuadriga_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use cuadriga_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cuadriga_interfaces::msg::GPXPoint & msg,
  std::ostream & out, size_t indentation = 0)
{
  cuadriga_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cuadriga_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const cuadriga_interfaces::msg::GPXPoint & msg)
{
  return cuadriga_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<cuadriga_interfaces::msg::GPXPoint>()
{
  return "cuadriga_interfaces::msg::GPXPoint";
}

template<>
inline const char * name<cuadriga_interfaces::msg::GPXPoint>()
{
  return "cuadriga_interfaces/msg/GPXPoint";
}

template<>
struct has_fixed_size<cuadriga_interfaces::msg::GPXPoint>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<cuadriga_interfaces::msg::GPXPoint>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<cuadriga_interfaces::msg::GPXPoint>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUADRIGA_INTERFACES__MSG__DETAIL__GPX_POINT__TRAITS_HPP_
