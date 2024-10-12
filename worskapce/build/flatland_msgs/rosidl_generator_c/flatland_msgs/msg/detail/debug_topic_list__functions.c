// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from flatland_msgs:msg/DebugTopicList.idl
// generated code does not contain a copyright notice
#include "flatland_msgs/msg/detail/debug_topic_list__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `topics`
#include "rosidl_runtime_c/string_functions.h"

bool
flatland_msgs__msg__DebugTopicList__init(flatland_msgs__msg__DebugTopicList * msg)
{
  if (!msg) {
    return false;
  }
  // topics
  if (!rosidl_runtime_c__String__Sequence__init(&msg->topics, 0)) {
    flatland_msgs__msg__DebugTopicList__fini(msg);
    return false;
  }
  return true;
}

void
flatland_msgs__msg__DebugTopicList__fini(flatland_msgs__msg__DebugTopicList * msg)
{
  if (!msg) {
    return;
  }
  // topics
  rosidl_runtime_c__String__Sequence__fini(&msg->topics);
}

bool
flatland_msgs__msg__DebugTopicList__are_equal(const flatland_msgs__msg__DebugTopicList * lhs, const flatland_msgs__msg__DebugTopicList * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // topics
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->topics), &(rhs->topics)))
  {
    return false;
  }
  return true;
}

bool
flatland_msgs__msg__DebugTopicList__copy(
  const flatland_msgs__msg__DebugTopicList * input,
  flatland_msgs__msg__DebugTopicList * output)
{
  if (!input || !output) {
    return false;
  }
  // topics
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->topics), &(output->topics)))
  {
    return false;
  }
  return true;
}

flatland_msgs__msg__DebugTopicList *
flatland_msgs__msg__DebugTopicList__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  flatland_msgs__msg__DebugTopicList * msg = (flatland_msgs__msg__DebugTopicList *)allocator.allocate(sizeof(flatland_msgs__msg__DebugTopicList), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(flatland_msgs__msg__DebugTopicList));
  bool success = flatland_msgs__msg__DebugTopicList__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
flatland_msgs__msg__DebugTopicList__destroy(flatland_msgs__msg__DebugTopicList * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    flatland_msgs__msg__DebugTopicList__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
flatland_msgs__msg__DebugTopicList__Sequence__init(flatland_msgs__msg__DebugTopicList__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  flatland_msgs__msg__DebugTopicList * data = NULL;

  if (size) {
    data = (flatland_msgs__msg__DebugTopicList *)allocator.zero_allocate(size, sizeof(flatland_msgs__msg__DebugTopicList), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = flatland_msgs__msg__DebugTopicList__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        flatland_msgs__msg__DebugTopicList__fini(&data[i - 1]);
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
flatland_msgs__msg__DebugTopicList__Sequence__fini(flatland_msgs__msg__DebugTopicList__Sequence * array)
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
      flatland_msgs__msg__DebugTopicList__fini(&array->data[i]);
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

flatland_msgs__msg__DebugTopicList__Sequence *
flatland_msgs__msg__DebugTopicList__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  flatland_msgs__msg__DebugTopicList__Sequence * array = (flatland_msgs__msg__DebugTopicList__Sequence *)allocator.allocate(sizeof(flatland_msgs__msg__DebugTopicList__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = flatland_msgs__msg__DebugTopicList__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
flatland_msgs__msg__DebugTopicList__Sequence__destroy(flatland_msgs__msg__DebugTopicList__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    flatland_msgs__msg__DebugTopicList__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
flatland_msgs__msg__DebugTopicList__Sequence__are_equal(const flatland_msgs__msg__DebugTopicList__Sequence * lhs, const flatland_msgs__msg__DebugTopicList__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!flatland_msgs__msg__DebugTopicList__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
flatland_msgs__msg__DebugTopicList__Sequence__copy(
  const flatland_msgs__msg__DebugTopicList__Sequence * input,
  flatland_msgs__msg__DebugTopicList__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(flatland_msgs__msg__DebugTopicList);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    flatland_msgs__msg__DebugTopicList * data =
      (flatland_msgs__msg__DebugTopicList *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!flatland_msgs__msg__DebugTopicList__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          flatland_msgs__msg__DebugTopicList__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!flatland_msgs__msg__DebugTopicList__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
