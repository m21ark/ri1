#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "flatland_box2d::flatland_box2d_lib" for configuration ""
set_property(TARGET flatland_box2d::flatland_box2d_lib APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(flatland_box2d::flatland_box2d_lib PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libflatland_box2d_lib.so"
  IMPORTED_SONAME_NOCONFIG "libflatland_box2d_lib.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS flatland_box2d::flatland_box2d_lib )
list(APPEND _IMPORT_CHECK_FILES_FOR_flatland_box2d::flatland_box2d_lib "${_IMPORT_PREFIX}/lib/libflatland_box2d_lib.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
