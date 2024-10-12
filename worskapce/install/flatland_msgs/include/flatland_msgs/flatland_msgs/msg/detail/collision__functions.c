// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from flatland_msgs:msg/Collision.idl
// generated code does not contain a copyright notice
#include "flatland_msgs/msg/detail/collision__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `entity_a`
// Member `body_a`
// Member `entity_b`
// Member `body_b`
#include "rosidl_runtime_c/string_functions.h"
// Member `magnitude_forces`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `contact_positions`
// Member `contact_normals`
#include "flatland_msgs/msg/detail/vector2__functions.h"

bool
flatland_msgs__msg__Collision__init(flatland_msgs__msg__Collision * msg)
{
  if (!msg) {
    return false;
  }
  // entity_a
  if (!rosidl_runtime_c__String__init(&msg->entity_a)) {
    flatland_msgs__msg__Collision__fini(msg);
    return false;
  }
  // body_a
  if (!rosidl_runtime_c__String__init(&msg->body_a)) {
    flatland_msgs__msg__Collision__fini(msg);
    return false;
  }
  // entity_b
  if (!rosidl_runtime_c__String__init(&msg->entity_b)) {
    flatland_msgs__msg__Collision__fini(msg);
    return false;
  }
  // body_b
  if (!rosidl_runtime_c__String__init(&msg->body_b)) {
    flatland_msgs__msg__Collision__fini(msg);
    return false;
  }
  // magnitude_forces
  if (!rosidl_runtime_c__double__Sequence__init(&msg->magnitude_forces, 0)) {
    flatland_msgs__msg__Collision__fini(msg);
    return false;
  }
  // contact_positions
  if (!flatland_msgs__msg__Vector2__Sequence__init(&msg->contact_positions, 0)) {
    flatland_msgs__msg__Collision__fini(msg);
    return false;
  }
  // contact_normals
  if (!flatland_msgs__msg__Vector2__Sequence__init(&msg->contact_normals, 0)) {
    flatland_msgs__msg__Collision__fini(msg);
    return false;
  }
  return true;
}

void
flatland_msgs__msg__Collision__fini(flatland_msgs__msg__Collision * msg)
{
  if (!msg) {
    return;
  }
  // entity_a
  rosidl_runtime_c__String__fini(&msg->entity_a);
  // body_a
  rosidl_runtime_c__String__fini(&msg->body_a);
  // entity_b
  rosidl_runtime_c__String__fini(&msg->entity_b);
  // body_b
  rosidl_runtime_c__String__fini(&msg->body_b);
  // magnitude_forces
  rosidl_runtime_c__double__Sequence__fini(&msg->magnitude_forces);
  // contact_positions
  flatland_msgs__msg__Vector2__Sequence__fini(&msg->contact_positions);
  // contact_normals
  flatland_msgs__msg__Vector2__Sequence__fini(&msg->contact_normals);
}

bool
flatland_msgs__msg__Collision__are_equal(const flatland_msgs__msg__Collision * lhs, const flatland_msgs__msg__Collision * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // entity_a
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->entity_a), &(rhs->entity_a)))
  {
    return false;
  }
  // body_a
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->body_a), &(rhs->body_a)))
  {
    return false;
  }
  // entity_b
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->entity_b), &(rhs->entity_b)))
  {
    return false;
  }
  // body_b
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->body_b), &(rhs->body_b)))
  {
    return false;
  }
  // magnitude_forces
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->magnitude_forces), &(rhs->magnitude_forces)))
  {
    return false;
  }
  // contact_positions
  if (!flatland_msgs__msg__Vector2__Sequence__are_equal(
      &(lhs->contact_positions), &(rhs->contact_positions)))
  {
    return false;
  }
  // contact_normals
  if (!flatland_msgs__msg__Vector2__Sequence__are_equal(
      &(lhs->contact_normals), &(rhs->contact_normals)))
  {
    return false;
  }
  return true;
}

bool
flatland_msgs__msg__Collision__copy(
  const flatland_msgs__msg__Collision * input,
  flatland_msgs__msg__Collision * output)
{
  if (!input || !output) {
    return false;
  }
  // entity_a
  if (!rosidl_runtime_c__String__copy(
      &(input->entity_a), &(output->entity_a)))
  {
    return false;
  }
  // body_a
  if (!rosidl_runtime_c__String__copy(
      &(input->body_a), &(output->body_a)))
  {
    return false;
  }
  // entity_b
  if (!rosidl_runtime_c__String__copy(
      &(input->entity_b), &(output->entity_b)))
  {
    return false;
  }
  // body_b
  if (!rosidl_runtime_c__String__copy(
      &(input->body_b), &(output->body_b)))
  {
    return false;
  }
  // magnitude_forces
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->magnitude_forces), &(output->magnitude_forces)))
  {
    return false;
  }
  // contact_positions
  if (!flatland_msgs__msg__Vector2__Sequence__copy(
      &(input->contact_positions), &(output->contact_positions)))
  {
    return false;
  }
  // contact_normals
  if (!flatland_msgs__msg__Vector2__Sequence__copy(
      &(input->contact_normals), &(output->contact_normals)))
  {
    return false;
  }
  return true;
}

flatland_msgs__msg__Collision *
flatland_msgs__msg__Collision__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  flatland_msgs__msg__Collision * msg = (flatland_msgs__msg__Collision *)allocator.allocate(sizeof(flatland_msgs__msg__Collision), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(flatland_msgs__msg__Collision));
  bool success = flatland_msgs__msg__Collision__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
flatland_msgs__msg__Collision__destroy(flatland_msgs__msg__Collision * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    flatland_msgs__msg__Collision__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
flatland_msgs__msg__Collision__Sequence__init(flatland_msgs__msg__Collision__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  flatland_msgs__msg__Collision * data = NULL;

  if (size) {
    data = (flatland_msgs__msg__Collision *)allocator.zero_allocate(size, sizeof(flatland_msgs__msg__Collision), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = flatland_msgs__msg__Collision__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        flatland_msgs__msg__Collision__fini(&data[i - 1]);
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
flatland_msgs__msg__Collision__Sequence__fini(flatland_msgs__msg__Collision__Sequence * array)
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
      flatland_msgs__msg__Collision__fini(&array->data[i]);
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

flatland_msgs__msg__Collision__Sequence *
flatland_msgs__msg__Collision__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  flatland_msgs__msg__Collision__Sequence * array = (flatland_msgs__msg__Collision__Sequence *)allocator.allocate(sizeof(flatland_msgs__msg__Collision__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = flatland_msgs__msg__Collision__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
flatland_msgs__msg__Collision__Sequence__destroy(flatland_msgs__msg__Collision__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    flatland_msgs__msg__Collision__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
flatland_msgs__msg__Collision__Sequence__are_equal(const flatland_msgs__msg__Collision__Sequence * lhs, const flatland_msgs__msg__Collision__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!flatland_msgs__msg__Collision__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
flatland_msgs__msg__Collision__Sequence__copy(
  const flatland_msgs__msg__Collision__Sequence * input,
  flatland_msgs__msg__Collision__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(flatland_msgs__msg__Collision);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    flatland_msgs__msg__Collision * data =
      (flatland_msgs__msg__Collision *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!flatland_msgs__msg__Collision__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          flatland_msgs__msg__Collision__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!flatland_msgs__msg__Collision__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
