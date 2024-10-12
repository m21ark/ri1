// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from flatland_msgs:srv/MoveModel.idl
// generated code does not contain a copyright notice
#include "flatland_msgs/srv/detail/move_model__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `name`
#include "rosidl_runtime_c/string_functions.h"
// Member `pose`
#include "geometry_msgs/msg/detail/pose2_d__functions.h"

bool
flatland_msgs__srv__MoveModel_Request__init(flatland_msgs__srv__MoveModel_Request * msg)
{
  if (!msg) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    flatland_msgs__srv__MoveModel_Request__fini(msg);
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose2D__init(&msg->pose)) {
    flatland_msgs__srv__MoveModel_Request__fini(msg);
    return false;
  }
  return true;
}

void
flatland_msgs__srv__MoveModel_Request__fini(flatland_msgs__srv__MoveModel_Request * msg)
{
  if (!msg) {
    return;
  }
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // pose
  geometry_msgs__msg__Pose2D__fini(&msg->pose);
}

bool
flatland_msgs__srv__MoveModel_Request__are_equal(const flatland_msgs__srv__MoveModel_Request * lhs, const flatland_msgs__srv__MoveModel_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name), &(rhs->name)))
  {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose2D__are_equal(
      &(lhs->pose), &(rhs->pose)))
  {
    return false;
  }
  return true;
}

bool
flatland_msgs__srv__MoveModel_Request__copy(
  const flatland_msgs__srv__MoveModel_Request * input,
  flatland_msgs__srv__MoveModel_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__copy(
      &(input->name), &(output->name)))
  {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose2D__copy(
      &(input->pose), &(output->pose)))
  {
    return false;
  }
  return true;
}

flatland_msgs__srv__MoveModel_Request *
flatland_msgs__srv__MoveModel_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  flatland_msgs__srv__MoveModel_Request * msg = (flatland_msgs__srv__MoveModel_Request *)allocator.allocate(sizeof(flatland_msgs__srv__MoveModel_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(flatland_msgs__srv__MoveModel_Request));
  bool success = flatland_msgs__srv__MoveModel_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
flatland_msgs__srv__MoveModel_Request__destroy(flatland_msgs__srv__MoveModel_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    flatland_msgs__srv__MoveModel_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
flatland_msgs__srv__MoveModel_Request__Sequence__init(flatland_msgs__srv__MoveModel_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  flatland_msgs__srv__MoveModel_Request * data = NULL;

  if (size) {
    data = (flatland_msgs__srv__MoveModel_Request *)allocator.zero_allocate(size, sizeof(flatland_msgs__srv__MoveModel_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = flatland_msgs__srv__MoveModel_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        flatland_msgs__srv__MoveModel_Request__fini(&data[i - 1]);
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
flatland_msgs__srv__MoveModel_Request__Sequence__fini(flatland_msgs__srv__MoveModel_Request__Sequence * array)
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
      flatland_msgs__srv__MoveModel_Request__fini(&array->data[i]);
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

flatland_msgs__srv__MoveModel_Request__Sequence *
flatland_msgs__srv__MoveModel_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  flatland_msgs__srv__MoveModel_Request__Sequence * array = (flatland_msgs__srv__MoveModel_Request__Sequence *)allocator.allocate(sizeof(flatland_msgs__srv__MoveModel_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = flatland_msgs__srv__MoveModel_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
flatland_msgs__srv__MoveModel_Request__Sequence__destroy(flatland_msgs__srv__MoveModel_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    flatland_msgs__srv__MoveModel_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
flatland_msgs__srv__MoveModel_Request__Sequence__are_equal(const flatland_msgs__srv__MoveModel_Request__Sequence * lhs, const flatland_msgs__srv__MoveModel_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!flatland_msgs__srv__MoveModel_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
flatland_msgs__srv__MoveModel_Request__Sequence__copy(
  const flatland_msgs__srv__MoveModel_Request__Sequence * input,
  flatland_msgs__srv__MoveModel_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(flatland_msgs__srv__MoveModel_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    flatland_msgs__srv__MoveModel_Request * data =
      (flatland_msgs__srv__MoveModel_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!flatland_msgs__srv__MoveModel_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          flatland_msgs__srv__MoveModel_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!flatland_msgs__srv__MoveModel_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
flatland_msgs__srv__MoveModel_Response__init(flatland_msgs__srv__MoveModel_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    flatland_msgs__srv__MoveModel_Response__fini(msg);
    return false;
  }
  return true;
}

void
flatland_msgs__srv__MoveModel_Response__fini(flatland_msgs__srv__MoveModel_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
flatland_msgs__srv__MoveModel_Response__are_equal(const flatland_msgs__srv__MoveModel_Response * lhs, const flatland_msgs__srv__MoveModel_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
flatland_msgs__srv__MoveModel_Response__copy(
  const flatland_msgs__srv__MoveModel_Response * input,
  flatland_msgs__srv__MoveModel_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

flatland_msgs__srv__MoveModel_Response *
flatland_msgs__srv__MoveModel_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  flatland_msgs__srv__MoveModel_Response * msg = (flatland_msgs__srv__MoveModel_Response *)allocator.allocate(sizeof(flatland_msgs__srv__MoveModel_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(flatland_msgs__srv__MoveModel_Response));
  bool success = flatland_msgs__srv__MoveModel_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
flatland_msgs__srv__MoveModel_Response__destroy(flatland_msgs__srv__MoveModel_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    flatland_msgs__srv__MoveModel_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
flatland_msgs__srv__MoveModel_Response__Sequence__init(flatland_msgs__srv__MoveModel_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  flatland_msgs__srv__MoveModel_Response * data = NULL;

  if (size) {
    data = (flatland_msgs__srv__MoveModel_Response *)allocator.zero_allocate(size, sizeof(flatland_msgs__srv__MoveModel_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = flatland_msgs__srv__MoveModel_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        flatland_msgs__srv__MoveModel_Response__fini(&data[i - 1]);
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
flatland_msgs__srv__MoveModel_Response__Sequence__fini(flatland_msgs__srv__MoveModel_Response__Sequence * array)
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
      flatland_msgs__srv__MoveModel_Response__fini(&array->data[i]);
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

flatland_msgs__srv__MoveModel_Response__Sequence *
flatland_msgs__srv__MoveModel_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  flatland_msgs__srv__MoveModel_Response__Sequence * array = (flatland_msgs__srv__MoveModel_Response__Sequence *)allocator.allocate(sizeof(flatland_msgs__srv__MoveModel_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = flatland_msgs__srv__MoveModel_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
flatland_msgs__srv__MoveModel_Response__Sequence__destroy(flatland_msgs__srv__MoveModel_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    flatland_msgs__srv__MoveModel_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
flatland_msgs__srv__MoveModel_Response__Sequence__are_equal(const flatland_msgs__srv__MoveModel_Response__Sequence * lhs, const flatland_msgs__srv__MoveModel_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!flatland_msgs__srv__MoveModel_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
flatland_msgs__srv__MoveModel_Response__Sequence__copy(
  const flatland_msgs__srv__MoveModel_Response__Sequence * input,
  flatland_msgs__srv__MoveModel_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(flatland_msgs__srv__MoveModel_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    flatland_msgs__srv__MoveModel_Response * data =
      (flatland_msgs__srv__MoveModel_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!flatland_msgs__srv__MoveModel_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          flatland_msgs__srv__MoveModel_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!flatland_msgs__srv__MoveModel_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
