// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from flatland_msgs:msg/Collisions.idl
// generated code does not contain a copyright notice

#ifndef FLATLAND_MSGS__MSG__DETAIL__COLLISIONS__FUNCTIONS_H_
#define FLATLAND_MSGS__MSG__DETAIL__COLLISIONS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "flatland_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "flatland_msgs/msg/detail/collisions__struct.h"

/// Initialize msg/Collisions message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * flatland_msgs__msg__Collisions
 * )) before or use
 * flatland_msgs__msg__Collisions__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_flatland_msgs
bool
flatland_msgs__msg__Collisions__init(flatland_msgs__msg__Collisions * msg);

/// Finalize msg/Collisions message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_flatland_msgs
void
flatland_msgs__msg__Collisions__fini(flatland_msgs__msg__Collisions * msg);

/// Create msg/Collisions message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * flatland_msgs__msg__Collisions__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_flatland_msgs
flatland_msgs__msg__Collisions *
flatland_msgs__msg__Collisions__create();

/// Destroy msg/Collisions message.
/**
 * It calls
 * flatland_msgs__msg__Collisions__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_flatland_msgs
void
flatland_msgs__msg__Collisions__destroy(flatland_msgs__msg__Collisions * msg);

/// Check for msg/Collisions message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_flatland_msgs
bool
flatland_msgs__msg__Collisions__are_equal(const flatland_msgs__msg__Collisions * lhs, const flatland_msgs__msg__Collisions * rhs);

/// Copy a msg/Collisions message.
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
ROSIDL_GENERATOR_C_PUBLIC_flatland_msgs
bool
flatland_msgs__msg__Collisions__copy(
  const flatland_msgs__msg__Collisions * input,
  flatland_msgs__msg__Collisions * output);

/// Initialize array of msg/Collisions messages.
/**
 * It allocates the memory for the number of elements and calls
 * flatland_msgs__msg__Collisions__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_flatland_msgs
bool
flatland_msgs__msg__Collisions__Sequence__init(flatland_msgs__msg__Collisions__Sequence * array, size_t size);

/// Finalize array of msg/Collisions messages.
/**
 * It calls
 * flatland_msgs__msg__Collisions__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_flatland_msgs
void
flatland_msgs__msg__Collisions__Sequence__fini(flatland_msgs__msg__Collisions__Sequence * array);

/// Create array of msg/Collisions messages.
/**
 * It allocates the memory for the array and calls
 * flatland_msgs__msg__Collisions__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_flatland_msgs
flatland_msgs__msg__Collisions__Sequence *
flatland_msgs__msg__Collisions__Sequence__create(size_t size);

/// Destroy array of msg/Collisions messages.
/**
 * It calls
 * flatland_msgs__msg__Collisions__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_flatland_msgs
void
flatland_msgs__msg__Collisions__Sequence__destroy(flatland_msgs__msg__Collisions__Sequence * array);

/// Check for msg/Collisions message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_flatland_msgs
bool
flatland_msgs__msg__Collisions__Sequence__are_equal(const flatland_msgs__msg__Collisions__Sequence * lhs, const flatland_msgs__msg__Collisions__Sequence * rhs);

/// Copy an array of msg/Collisions messages.
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
ROSIDL_GENERATOR_C_PUBLIC_flatland_msgs
bool
flatland_msgs__msg__Collisions__Sequence__copy(
  const flatland_msgs__msg__Collisions__Sequence * input,
  flatland_msgs__msg__Collisions__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // FLATLAND_MSGS__MSG__DETAIL__COLLISIONS__FUNCTIONS_H_
