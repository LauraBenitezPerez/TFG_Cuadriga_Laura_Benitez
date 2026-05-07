// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from cuadriga_interfaces:msg/GPXPoint.idl
// generated code does not contain a copyright notice

#ifndef CUADRIGA_INTERFACES__MSG__DETAIL__GPX_POINT__FUNCTIONS_H_
#define CUADRIGA_INTERFACES__MSG__DETAIL__GPX_POINT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "cuadriga_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "cuadriga_interfaces/msg/detail/gpx_point__struct.h"

/// Initialize msg/GPXPoint message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * cuadriga_interfaces__msg__GPXPoint
 * )) before or use
 * cuadriga_interfaces__msg__GPXPoint__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_cuadriga_interfaces
bool
cuadriga_interfaces__msg__GPXPoint__init(cuadriga_interfaces__msg__GPXPoint * msg);

/// Finalize msg/GPXPoint message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cuadriga_interfaces
void
cuadriga_interfaces__msg__GPXPoint__fini(cuadriga_interfaces__msg__GPXPoint * msg);

/// Create msg/GPXPoint message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * cuadriga_interfaces__msg__GPXPoint__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cuadriga_interfaces
cuadriga_interfaces__msg__GPXPoint *
cuadriga_interfaces__msg__GPXPoint__create();

/// Destroy msg/GPXPoint message.
/**
 * It calls
 * cuadriga_interfaces__msg__GPXPoint__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cuadriga_interfaces
void
cuadriga_interfaces__msg__GPXPoint__destroy(cuadriga_interfaces__msg__GPXPoint * msg);

/// Check for msg/GPXPoint message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cuadriga_interfaces
bool
cuadriga_interfaces__msg__GPXPoint__are_equal(const cuadriga_interfaces__msg__GPXPoint * lhs, const cuadriga_interfaces__msg__GPXPoint * rhs);

/// Copy a msg/GPXPoint message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_cuadriga_interfaces
bool
cuadriga_interfaces__msg__GPXPoint__copy(
  const cuadriga_interfaces__msg__GPXPoint * input,
  cuadriga_interfaces__msg__GPXPoint * output);

/// Initialize array of msg/GPXPoint messages.
/**
 * It allocates the memory for the number of elements and calls
 * cuadriga_interfaces__msg__GPXPoint__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_cuadriga_interfaces
bool
cuadriga_interfaces__msg__GPXPoint__Sequence__init(cuadriga_interfaces__msg__GPXPoint__Sequence * array, size_t size);

/// Finalize array of msg/GPXPoint messages.
/**
 * It calls
 * cuadriga_interfaces__msg__GPXPoint__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cuadriga_interfaces
void
cuadriga_interfaces__msg__GPXPoint__Sequence__fini(cuadriga_interfaces__msg__GPXPoint__Sequence * array);

/// Create array of msg/GPXPoint messages.
/**
 * It allocates the memory for the array and calls
 * cuadriga_interfaces__msg__GPXPoint__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cuadriga_interfaces
cuadriga_interfaces__msg__GPXPoint__Sequence *
cuadriga_interfaces__msg__GPXPoint__Sequence__create(size_t size);

/// Destroy array of msg/GPXPoint messages.
/**
 * It calls
 * cuadriga_interfaces__msg__GPXPoint__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cuadriga_interfaces
void
cuadriga_interfaces__msg__GPXPoint__Sequence__destroy(cuadriga_interfaces__msg__GPXPoint__Sequence * array);

/// Check for msg/GPXPoint message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cuadriga_interfaces
bool
cuadriga_interfaces__msg__GPXPoint__Sequence__are_equal(const cuadriga_interfaces__msg__GPXPoint__Sequence * lhs, const cuadriga_interfaces__msg__GPXPoint__Sequence * rhs);

/// Copy an array of msg/GPXPoint messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_cuadriga_interfaces
bool
cuadriga_interfaces__msg__GPXPoint__Sequence__copy(
  const cuadriga_interfaces__msg__GPXPoint__Sequence * input,
  cuadriga_interfaces__msg__GPXPoint__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // CUADRIGA_INTERFACES__MSG__DETAIL__GPX_POINT__FUNCTIONS_H_
