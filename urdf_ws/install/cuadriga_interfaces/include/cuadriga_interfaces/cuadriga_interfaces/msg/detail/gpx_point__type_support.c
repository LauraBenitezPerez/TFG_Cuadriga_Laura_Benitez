// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from cuadriga_interfaces:msg/GPXPoint.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "cuadriga_interfaces/msg/detail/gpx_point__rosidl_typesupport_introspection_c.h"
#include "cuadriga_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "cuadriga_interfaces/msg/detail/gpx_point__functions.h"
#include "cuadriga_interfaces/msg/detail/gpx_point__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void cuadriga_interfaces__msg__GPXPoint__rosidl_typesupport_introspection_c__GPXPoint_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  cuadriga_interfaces__msg__GPXPoint__init(message_memory);
}

void cuadriga_interfaces__msg__GPXPoint__rosidl_typesupport_introspection_c__GPXPoint_fini_function(void * message_memory)
{
  cuadriga_interfaces__msg__GPXPoint__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember cuadriga_interfaces__msg__GPXPoint__rosidl_typesupport_introspection_c__GPXPoint_message_member_array[3] = {
  {
    "latitude",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cuadriga_interfaces__msg__GPXPoint, latitude),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "longitude",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cuadriga_interfaces__msg__GPXPoint, longitude),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "altitude",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cuadriga_interfaces__msg__GPXPoint, altitude),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers cuadriga_interfaces__msg__GPXPoint__rosidl_typesupport_introspection_c__GPXPoint_message_members = {
  "cuadriga_interfaces__msg",  // message namespace
  "GPXPoint",  // message name
  3,  // number of fields
  sizeof(cuadriga_interfaces__msg__GPXPoint),
  cuadriga_interfaces__msg__GPXPoint__rosidl_typesupport_introspection_c__GPXPoint_message_member_array,  // message members
  cuadriga_interfaces__msg__GPXPoint__rosidl_typesupport_introspection_c__GPXPoint_init_function,  // function to initialize message memory (memory has to be allocated)
  cuadriga_interfaces__msg__GPXPoint__rosidl_typesupport_introspection_c__GPXPoint_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t cuadriga_interfaces__msg__GPXPoint__rosidl_typesupport_introspection_c__GPXPoint_message_type_support_handle = {
  0,
  &cuadriga_interfaces__msg__GPXPoint__rosidl_typesupport_introspection_c__GPXPoint_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_cuadriga_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cuadriga_interfaces, msg, GPXPoint)() {
  if (!cuadriga_interfaces__msg__GPXPoint__rosidl_typesupport_introspection_c__GPXPoint_message_type_support_handle.typesupport_identifier) {
    cuadriga_interfaces__msg__GPXPoint__rosidl_typesupport_introspection_c__GPXPoint_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &cuadriga_interfaces__msg__GPXPoint__rosidl_typesupport_introspection_c__GPXPoint_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
