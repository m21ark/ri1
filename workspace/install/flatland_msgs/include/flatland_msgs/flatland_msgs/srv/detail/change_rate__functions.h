// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from flatland_msgs:srv/ChangeRate.idl
// generated code does not contain a copyright notice

#ifndef FLATLAND_MSGS__SRV__DETAIL__CHANGE_RATE__FUNCTIONS_H_
#define FLATLAND_MSGS__SRV__DETAIL__CHANGE_RATE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "flatland_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "flatland_msgs/srv/detail/change_rate__struct.h"

/// Initialize srv/ChangeRate message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * flatland_msgs__srv__ChangeRate_Request
 * )) before or use
 * flatland_msgs__srv__ChangeRate_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_flatland_msgs
bool
flatland_msgs__srv__ChangeRate_Request__init(flatland_msgs__srv__ChangeRate_Request * msg);

/// Finalize srv/ChangeRate message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_flatland_msgs
void
flatland_msgs__srv__ChangeRate_Request__fini(flatland_msgs__srv__ChangeRate_Request * msg);

/// Create srv/ChangeRate message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * flatland_msgs__srv__ChangeRate_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_flatland_msgs
flatland_msgs__srv__ChangeRate_Request *
flatland_msgs__srv__ChangeRate_Request__create();

/// Destroy srv/ChangeRate message.
/**
 * It calls
 * flatland_msgs__srv__ChangeRate_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_flatland_msgs
void
flatland_msgs__srv__ChangeRate_Request__destroy(flatland_msgs__srv__ChangeRate_Request * msg);

/// Check for srv/ChangeRate message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_flatland_msgs
bool
flatland_msgs__srv__ChangeRate_Request__are_equal(const flatland_msgs__srv__ChangeRate_Request * lhs, const flatland_msgs__srv__ChangeRate_Request * rhs);

/// Copy a srv/ChangeRate message.
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
flatland_msgs__srv__ChangeRate_Request__copy(
  const flatland_msgs__srv__ChangeRate_Request * input,
  flatland_msgs__srv__ChangeRate_Request * output);

/// Initialize array of srv/ChangeRate messages.
/**
 * It allocates the memory for the number of elements and calls
 * flatland_msgs__srv__ChangeRate_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_flatland_msgs
bool
flatland_msgs__srv__ChangeRate_Request__Sequence__init(flatland_msgs__srv__ChangeRate_Request__Sequence * array, size_t size);

/// Finalize array of srv/ChangeRate messages.
/**
 * It calls
 * flatland_msgs__srv__ChangeRate_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_flatland_msgs
void
flatland_msgs__srv__ChangeRate_Request__Sequence__fini(flatland_msgs__srv__ChangeRate_Request__Sequence * array);

/// Create array of srv/ChangeRate messages.
/**
 * It allocates the memory for the array and calls
 * flatland_msgs__srv__ChangeRate_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_flatland_msgs
flatland_msgs__srv__ChangeRate_Request__Sequence *
flatland_msgs__srv__ChangeRate_Request__Sequence__create(size_t size);

/// Destroy array of srv/ChangeRate messages.
/**
 * It calls
 * flatland_msgs__srv__ChangeRate_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_flatland_msgs
void
flatland_msgs__srv__ChangeRate_Request__Sequence__destroy(flatland_msgs__srv__ChangeRate_Request__Sequence * array);

/// Check for srv/ChangeRate message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_flatland_msgs
bool
flatland_msgs__srv__ChangeRate_Request__Sequence__are_equal(const flatland_msgs__srv__ChangeRate_Request__Sequence * lhs, const flatland_msgs__srv__ChangeRate_Request__Sequence * rhs);

/// Copy an array of srv/ChangeRate messages.
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
flatland_msgs__srv__ChangeRate_Request__Sequence__copy(
  const flatland_msgs__srv__ChangeRate_Request__Sequence * input,
  flatland_msgs__srv__ChangeRate_Request__Sequence * output);

/// Initialize srv/ChangeRate message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * flatland_msgs__srv__ChangeRate_Response
 * )) before or use
 * flatland_msgs__srv__ChangeRate_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_flatland_msgs
bool
flatland_msgs__srv__ChangeRate_Response__init(flatland_msgs__srv__ChangeRate_Response * msg);

/// Finalize srv/ChangeRate message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_flatland_msgs
void
flatland_msgs__srv__ChangeRate_Response__fini(flatland_msgs__srv__ChangeRate_Response * msg);

/// Create srv/ChangeRate message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * flatland_msgs__srv__ChangeRate_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_flatland_msgs
flatland_msgs__srv__ChangeRate_Response *
flatland_msgs__srv__ChangeRate_Response__create();

/// Destroy srv/ChangeRate message.
/**
 * It calls
 * flatland_msgs__srv__ChangeRate_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_flatland_msgs
void
flatland_msgs__srv__ChangeRate_Response__destroy(flatland_msgs__srv__ChangeRate_Response * msg);

/// Check for srv/ChangeRate message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_flatland_msgs
bool
flatland_msgs__srv__ChangeRate_Response__are_equal(const flatland_msgs__srv__ChangeRate_Response * lhs, const flatland_msgs__srv__ChangeRate_Response * rhs);

/// Copy a srv/ChangeRate message.
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
flatland_msgs__srv__ChangeRate_Response__copy(
  const flatland_msgs__srv__ChangeRate_Response * input,
  flatland_msgs__srv__ChangeRate_Response * output);

/// Initialize array of srv/ChangeRate messages.
/**
 * It allocates the memory for the number of elements and calls
 * flatland_msgs__srv__ChangeRate_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_flatland_msgs
bool
flatland_msgs__srv__ChangeRate_Response__Sequence__init(flatland_msgs__srv__ChangeRate_Response__Sequence * array, size_t size);

/// Finalize array of srv/ChangeRate messages.
/**
 * It calls
 * flatland_msgs__srv__ChangeRate_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_flatland_msgs
void
flatland_msgs__srv__ChangeRate_Response__Sequence__fini(flatland_msgs__srv__ChangeRate_Response__Sequence * array);

/// Create array of srv/ChangeRate messages.
/**
 * It allocates the memory for the array and calls
 * flatland_msgs__srv__ChangeRate_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_flatland_msgs
flatland_msgs__srv__ChangeRate_Response__Sequence *
flatland_msgs__srv__ChangeRate_Response__Sequence__create(size_t size);

/// Destroy array of srv/ChangeRate messages.
/**
 * It calls
 * flatland_msgs__srv__ChangeRate_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_flatland_msgs
void
flatland_msgs__srv__ChangeRate_Response__Sequence__destroy(flatland_msgs__srv__ChangeRate_Response__Sequence * array);

/// Check for srv/ChangeRate message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_flatland_msgs
bool
flatland_msgs__srv__ChangeRate_Response__Sequence__are_equal(const flatland_msgs__srv__ChangeRate_Response__Sequence * lhs, const flatland_msgs__srv__ChangeRate_Response__Sequence * rhs);

/// Copy an array of srv/ChangeRate messages.
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
flatland_msgs__srv__ChangeRate_Response__Sequence__copy(
  const flatland_msgs__srv__ChangeRate_Response__Sequence * input,
  flatland_msgs__srv__ChangeRate_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // FLATLAND_MSGS__SRV__DETAIL__CHANGE_RATE__FUNCTIONS_H_
