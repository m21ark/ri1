// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from flatland_msgs:srv/SpawnModel.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "flatland_msgs/srv/detail/spawn_model__rosidl_typesupport_introspection_c.h"
#include "flatland_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "flatland_msgs/srv/detail/spawn_model__functions.h"
#include "flatland_msgs/srv/detail/spawn_model__struct.h"


// Include directives for member types
// Member `yaml_path`
// Member `name`
// Member `ns`
#include "rosidl_runtime_c/string_functions.h"
// Member `pose`
#include "geometry_msgs/msg/pose2_d.h"
// Member `pose`
#include "geometry_msgs/msg/detail/pose2_d__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void flatland_msgs__srv__SpawnModel_Request__rosidl_typesupport_introspection_c__SpawnModel_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  flatland_msgs__srv__SpawnModel_Request__init(message_memory);
}

void flatland_msgs__srv__SpawnModel_Request__rosidl_typesupport_introspection_c__SpawnModel_Request_fini_function(void * message_memory)
{
  flatland_msgs__srv__SpawnModel_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember flatland_msgs__srv__SpawnModel_Request__rosidl_typesupport_introspection_c__SpawnModel_Request_message_member_array[4] = {
  {
    "yaml_path",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(flatland_msgs__srv__SpawnModel_Request, yaml_path),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(flatland_msgs__srv__SpawnModel_Request, name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ns",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(flatland_msgs__srv__SpawnModel_Request, ns),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(flatland_msgs__srv__SpawnModel_Request, pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers flatland_msgs__srv__SpawnModel_Request__rosidl_typesupport_introspection_c__SpawnModel_Request_message_members = {
  "flatland_msgs__srv",  // message namespace
  "SpawnModel_Request",  // message name
  4,  // number of fields
  sizeof(flatland_msgs__srv__SpawnModel_Request),
  flatland_msgs__srv__SpawnModel_Request__rosidl_typesupport_introspection_c__SpawnModel_Request_message_member_array,  // message members
  flatland_msgs__srv__SpawnModel_Request__rosidl_typesupport_introspection_c__SpawnModel_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  flatland_msgs__srv__SpawnModel_Request__rosidl_typesupport_introspection_c__SpawnModel_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t flatland_msgs__srv__SpawnModel_Request__rosidl_typesupport_introspection_c__SpawnModel_Request_message_type_support_handle = {
  0,
  &flatland_msgs__srv__SpawnModel_Request__rosidl_typesupport_introspection_c__SpawnModel_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_flatland_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, flatland_msgs, srv, SpawnModel_Request)() {
  flatland_msgs__srv__SpawnModel_Request__rosidl_typesupport_introspection_c__SpawnModel_Request_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose2D)();
  if (!flatland_msgs__srv__SpawnModel_Request__rosidl_typesupport_introspection_c__SpawnModel_Request_message_type_support_handle.typesupport_identifier) {
    flatland_msgs__srv__SpawnModel_Request__rosidl_typesupport_introspection_c__SpawnModel_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &flatland_msgs__srv__SpawnModel_Request__rosidl_typesupport_introspection_c__SpawnModel_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "flatland_msgs/srv/detail/spawn_model__rosidl_typesupport_introspection_c.h"
// already included above
// #include "flatland_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "flatland_msgs/srv/detail/spawn_model__functions.h"
// already included above
// #include "flatland_msgs/srv/detail/spawn_model__struct.h"


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void flatland_msgs__srv__SpawnModel_Response__rosidl_typesupport_introspection_c__SpawnModel_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  flatland_msgs__srv__SpawnModel_Response__init(message_memory);
}

void flatland_msgs__srv__SpawnModel_Response__rosidl_typesupport_introspection_c__SpawnModel_Response_fini_function(void * message_memory)
{
  flatland_msgs__srv__SpawnModel_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember flatland_msgs__srv__SpawnModel_Response__rosidl_typesupport_introspection_c__SpawnModel_Response_message_member_array[2] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(flatland_msgs__srv__SpawnModel_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(flatland_msgs__srv__SpawnModel_Response, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers flatland_msgs__srv__SpawnModel_Response__rosidl_typesupport_introspection_c__SpawnModel_Response_message_members = {
  "flatland_msgs__srv",  // message namespace
  "SpawnModel_Response",  // message name
  2,  // number of fields
  sizeof(flatland_msgs__srv__SpawnModel_Response),
  flatland_msgs__srv__SpawnModel_Response__rosidl_typesupport_introspection_c__SpawnModel_Response_message_member_array,  // message members
  flatland_msgs__srv__SpawnModel_Response__rosidl_typesupport_introspection_c__SpawnModel_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  flatland_msgs__srv__SpawnModel_Response__rosidl_typesupport_introspection_c__SpawnModel_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t flatland_msgs__srv__SpawnModel_Response__rosidl_typesupport_introspection_c__SpawnModel_Response_message_type_support_handle = {
  0,
  &flatland_msgs__srv__SpawnModel_Response__rosidl_typesupport_introspection_c__SpawnModel_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_flatland_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, flatland_msgs, srv, SpawnModel_Response)() {
  if (!flatland_msgs__srv__SpawnModel_Response__rosidl_typesupport_introspection_c__SpawnModel_Response_message_type_support_handle.typesupport_identifier) {
    flatland_msgs__srv__SpawnModel_Response__rosidl_typesupport_introspection_c__SpawnModel_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &flatland_msgs__srv__SpawnModel_Response__rosidl_typesupport_introspection_c__SpawnModel_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "flatland_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "flatland_msgs/srv/detail/spawn_model__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers flatland_msgs__srv__detail__spawn_model__rosidl_typesupport_introspection_c__SpawnModel_service_members = {
  "flatland_msgs__srv",  // service namespace
  "SpawnModel",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // flatland_msgs__srv__detail__spawn_model__rosidl_typesupport_introspection_c__SpawnModel_Request_message_type_support_handle,
  NULL  // response message
  // flatland_msgs__srv__detail__spawn_model__rosidl_typesupport_introspection_c__SpawnModel_Response_message_type_support_handle
};

static rosidl_service_type_support_t flatland_msgs__srv__detail__spawn_model__rosidl_typesupport_introspection_c__SpawnModel_service_type_support_handle = {
  0,
  &flatland_msgs__srv__detail__spawn_model__rosidl_typesupport_introspection_c__SpawnModel_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, flatland_msgs, srv, SpawnModel_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, flatland_msgs, srv, SpawnModel_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_flatland_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, flatland_msgs, srv, SpawnModel)() {
  if (!flatland_msgs__srv__detail__spawn_model__rosidl_typesupport_introspection_c__SpawnModel_service_type_support_handle.typesupport_identifier) {
    flatland_msgs__srv__detail__spawn_model__rosidl_typesupport_introspection_c__SpawnModel_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)flatland_msgs__srv__detail__spawn_model__rosidl_typesupport_introspection_c__SpawnModel_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, flatland_msgs, srv, SpawnModel_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, flatland_msgs, srv, SpawnModel_Response)()->data;
  }

  return &flatland_msgs__srv__detail__spawn_model__rosidl_typesupport_introspection_c__SpawnModel_service_type_support_handle;
}
