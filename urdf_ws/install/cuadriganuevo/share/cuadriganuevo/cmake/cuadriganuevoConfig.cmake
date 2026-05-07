# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_cuadriganuevo_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED cuadriganuevo_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(cuadriganuevo_FOUND FALSE)
  elseif(NOT cuadriganuevo_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(cuadriganuevo_FOUND FALSE)
  endif()
  return()
endif()
set(_cuadriganuevo_CONFIG_INCLUDED TRUE)

# output package information
if(NOT cuadriganuevo_FIND_QUIETLY)
  message(STATUS "Found cuadriganuevo: 0.0.0 (${cuadriganuevo_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'cuadriganuevo' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${cuadriganuevo_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(cuadriganuevo_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${cuadriganuevo_DIR}/${_extra}")
endforeach()
