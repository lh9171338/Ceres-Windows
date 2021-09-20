#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Ceres::ceres" for configuration "Release"
set_property(TARGET Ceres::ceres APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Ceres::ceres PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/ceres.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/ceres.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Ceres::ceres )
list(APPEND _IMPORT_CHECK_FILES_FOR_Ceres::ceres "${_IMPORT_PREFIX}/lib/ceres.lib" "${_IMPORT_PREFIX}/bin/ceres.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
