#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "flatland_rviz_plugins::flatland_rviz_plugins" for configuration ""
set_property(TARGET flatland_rviz_plugins::flatland_rviz_plugins APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(flatland_rviz_plugins::flatland_rviz_plugins PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libflatland_rviz_plugins.so"
  IMPORTED_SONAME_NOCONFIG "libflatland_rviz_plugins.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS flatland_rviz_plugins::flatland_rviz_plugins )
list(APPEND _IMPORT_CHECK_FILES_FOR_flatland_rviz_plugins::flatland_rviz_plugins "${_IMPORT_PREFIX}/lib/libflatland_rviz_plugins.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
