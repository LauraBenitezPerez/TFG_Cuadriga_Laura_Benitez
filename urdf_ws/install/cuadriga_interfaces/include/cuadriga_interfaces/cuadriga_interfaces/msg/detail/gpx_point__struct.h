// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cuadriga_interfaces:msg/GPXPoint.idl
// generated code does not contain a copyright notice

#ifndef CUADRIGA_INTERFACES__MSG__DETAIL__GPX_POINT__STRUCT_H_
#define CUADRIGA_INTERFACES__MSG__DETAIL__GPX_POINT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/GPXPoint in the package cuadriga_interfaces.
typedef struct cuadriga_interfaces__msg__GPXPoint
{
  double latitude;
  double longitude;
  double altitude;
} cuadriga_interfaces__msg__GPXPoint;

// Struct for a sequence of cuadriga_interfaces__msg__GPXPoint.
typedef struct cuadriga_interfaces__msg__GPXPoint__Sequence
{
  cuadriga_interfaces__msg__GPXPoint * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cuadriga_interfaces__msg__GPXPoint__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUADRIGA_INTERFACES__MSG__DETAIL__GPX_POINT__STRUCT_H_
