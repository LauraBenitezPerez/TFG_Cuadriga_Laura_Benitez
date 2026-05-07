// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cuadriga_interfaces:msg/GPXPoint.idl
// generated code does not contain a copyright notice
#include "cuadriga_interfaces/msg/detail/gpx_point__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
cuadriga_interfaces__msg__GPXPoint__init(cuadriga_interfaces__msg__GPXPoint * msg)
{
  if (!msg) {
    return false;
  }
  // latitude
  // longitude
  // altitude
  return true;
}

void
cuadriga_interfaces__msg__GPXPoint__fini(cuadriga_interfaces__msg__GPXPoint * msg)
{
  if (!msg) {
    return;
  }
  // latitude
  // longitude
  // altitude
}

bool
cuadriga_interfaces__msg__GPXPoint__are_equal(const cuadriga_interfaces__msg__GPXPoint * lhs, const cuadriga_interfaces__msg__GPXPoint * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // latitude
  if (lhs->latitude != rhs->latitude) {
    return false;
  }
  // longitude
  if (lhs->longitude != rhs->longitude) {
    return false;
  }
  // altitude
  if (lhs->altitude != rhs->altitude) {
    return false;
  }
  return true;
}

bool
cuadriga_interfaces__msg__GPXPoint__copy(
  const cuadriga_interfaces__msg__GPXPoint * input,
  cuadriga_interfaces__msg__GPXPoint * output)
{
  if (!input || !output) {
    return false;
  }
  // latitude
  output->latitude = input->latitude;
  // longitude
  output->longitude = input->longitude;
  // altitude
  output->altitude = input->altitude;
  return true;
}

cuadriga_interfaces__msg__GPXPoint *
cuadriga_interfaces__msg__GPXPoint__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cuadriga_interfaces__msg__GPXPoint * msg = (cuadriga_interfaces__msg__GPXPoint *)allocator.allocate(sizeof(cuadriga_interfaces__msg__GPXPoint), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cuadriga_interfaces__msg__GPXPoint));
  bool success = cuadriga_interfaces__msg__GPXPoint__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cuadriga_interfaces__msg__GPXPoint__destroy(cuadriga_interfaces__msg__GPXPoint * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cuadriga_interfaces__msg__GPXPoint__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cuadriga_interfaces__msg__GPXPoint__Sequence__init(cuadriga_interfaces__msg__GPXPoint__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cuadriga_interfaces__msg__GPXPoint * data = NULL;

  if (size) {
    data = (cuadriga_interfaces__msg__GPXPoint *)allocator.zero_allocate(size, sizeof(cuadriga_interfaces__msg__GPXPoint), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cuadriga_interfaces__msg__GPXPoint__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cuadriga_interfaces__msg__GPXPoint__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
cuadriga_interfaces__msg__GPXPoint__Sequence__fini(cuadriga_interfaces__msg__GPXPoint__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      cuadriga_interfaces__msg__GPXPoint__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

cuadriga_interfaces__msg__GPXPoint__Sequence *
cuadriga_interfaces__msg__GPXPoint__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cuadriga_interfaces__msg__GPXPoint__Sequence * array = (cuadriga_interfaces__msg__GPXPoint__Sequence *)allocator.allocate(sizeof(cuadriga_interfaces__msg__GPXPoint__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cuadriga_interfaces__msg__GPXPoint__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cuadriga_interfaces__msg__GPXPoint__Sequence__destroy(cuadriga_interfaces__msg__GPXPoint__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cuadriga_interfaces__msg__GPXPoint__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cuadriga_interfaces__msg__GPXPoint__Sequence__are_equal(const cuadriga_interfaces__msg__GPXPoint__Sequence * lhs, const cuadriga_interfaces__msg__GPXPoint__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cuadriga_interfaces__msg__GPXPoint__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cuadriga_interfaces__msg__GPXPoint__Sequence__copy(
  const cuadriga_interfaces__msg__GPXPoint__Sequence * input,
  cuadriga_interfaces__msg__GPXPoint__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cuadriga_interfaces__msg__GPXPoint);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cuadriga_interfaces__msg__GPXPoint * data =
      (cuadriga_interfaces__msg__GPXPoint *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cuadriga_interfaces__msg__GPXPoint__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cuadriga_interfaces__msg__GPXPoint__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cuadriga_interfaces__msg__GPXPoint__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
