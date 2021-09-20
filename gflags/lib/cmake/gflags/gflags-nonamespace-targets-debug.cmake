#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "gflags_shared" for configuration "Debug"
set_property(TARGET gflags_shared APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(gflags_shared PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/gflags_debug.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/gflags_debug.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS gflags_shared )
list(APPEND _IMPORT_CHECK_FILES_FOR_gflags_shared "${_IMPORT_PREFIX}/lib/gflags_debug.lib" "${_IMPORT_PREFIX}/bin/gflags_debug.dll" )

# Import target "gflags_nothreads_shared" for configuration "Debug"
set_property(TARGET gflags_nothreads_shared APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(gflags_nothreads_shared PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/gflags_nothreads_debug.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/gflags_nothreads_debug.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS gflags_nothreads_shared )
list(APPEND _IMPORT_CHECK_FILES_FOR_gflags_nothreads_shared "${_IMPORT_PREFIX}/lib/gflags_nothreads_debug.lib" "${_IMPORT_PREFIX}/bin/gflags_nothreads_debug.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
