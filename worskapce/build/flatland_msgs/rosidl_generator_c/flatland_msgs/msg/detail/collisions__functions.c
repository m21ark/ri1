// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from flatland_msgs:msg/Collisions.idl
// generated code does not contain a copyright notice
#include "flatland_msgs/msg/detail/collisions__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `collisions`
#include "flatland_msgs/msg/detail/collision__functions.h"

bool
flatland_msgs__msg__Collisions__init(flatland_msgs__msg__Collisions * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    flatland_msgs__msg__Collisions__fini(msg);
    return false;
  }
  // collisions
  if (!flatland_msgs__msg__Collision__Sequence__init(&msg->collisions, 0)) {
    flatland_msgs__msg__Collisions__fini(msg);
    return false;
  }
  return true;
}

void
flatland_msgs__msg__Collisions__fini(flatland_msgs__msg__Collisions * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // collisions
  flatland_msgs__msg__Collision__Sequence__fini(&msg->collisions);
}

bool
flatland_msgs__msg__Collisions__are_equal(const flatland_msgs__msg__Collisions * lhs, const flatland_msgs__msg__Collisions * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // collisions
  if (!flatland_msgs__msg__Collision__Sequence__are_equal(
      &(lhs->collisions), &(rhs->collisions)))
  {
    return false;
  }
  return true;
}

bool
flatland_msgs__msg__Collisions__copy(
  const flatland_msgs__msg__Collisions * input,
  flatland_msgs__msg__Collisions * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // collisions
  if (!flatland_msgs__msg__Collision__Sequence__copy(
      &(input->collisions), &(output->collisions)))
  {
    return false;
  }
  return true;
}

flatland_msgs__msg__Collisions *
flatland_msgs__msg__Collisions__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  flatland_msgs__msg__Collisions * msg = (flatland_msgs__msg__Collisions *)allocator.allocate(sizeof(flatland_msgs__msg__Collisions), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(flatland_msgs__msg__Collisions));
  bool success = flatland_msgs__msg__Collisions__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
flatland_msgs__msg__Collisions__destroy(flatland_msgs__msg__Collisions * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    flatland_msgs__msg__Collisions__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
flatland_msgs__msg__Collisions__Sequence__init(flatland_msgs__msg__Collisions__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  flatland_msgs__msg__Collisions * data = NULL;

  if (size) {
    data = (flatland_msgs__msg__Collisions *)allocator.zero_allocate(size, sizeof(flatland_msgs__msg__Collisions), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = flatland_msgs__msg__Collisions__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        flatland_msgs__msg__Collisions__fini(&data[i - 1]);
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
flatland_msgs__msg__Collisions__Sequence__fini(flatland_msgs__msg__Collisions__Sequence * array)
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
      flatland_msgs__msg__Collisions__fini(&array->data[i]);
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

flatland_msgs__msg__Collisions__Sequence *
flatland_msgs__msg__Collisions__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  flatland_msgs__msg__Collisions__Sequence * array = (flatland_msgs__msg__Collisions__Sequence *)allocator.allocate(sizeof(flatland_msgs__msg__Collisions__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = flatland_msgs__msg__Collisions__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
flatland_msgs__msg__Collisions__Sequence__destroy(flatland_msgs__msg__Collisions__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    flatland_msgs__msg__Collisions__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
flatland_msgs__msg__Collisions__Sequence__are_equal(const flatland_msgs__msg__Collisions__Sequence * lhs, const flatland_msgs__msg__Collisions__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!flatland_msgs__msg__Collisions__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
flatland_msgs__msg__Collisions__Sequence__copy(
  const flatland_msgs__msg__Collisions__Sequence * input,
  flatland_msgs__msg__Collisions__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(flatland_msgs__msg__Collisions);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    flatland_msgs__msg__Collisions * data =
      (flatland_msgs__msg__Collisions *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!flatland_msgs__msg__Collisions__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          flatland_msgs__msg__Collisions__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!flatland_msgs__msg__Collisions__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
