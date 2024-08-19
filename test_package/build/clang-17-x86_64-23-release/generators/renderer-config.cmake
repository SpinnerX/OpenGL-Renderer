########## MACROS ###########################################################################
#############################################################################################

# Requires CMake > 3.15
if(${CMAKE_VERSION} VERSION_LESS "3.15")
    message(FATAL_ERROR "The 'CMakeDeps' generator only works with CMake >= 3.15")
endif()

if(renderer_FIND_QUIETLY)
    set(renderer_MESSAGE_MODE VERBOSE)
else()
    set(renderer_MESSAGE_MODE STATUS)
endif()

include(${CMAKE_CURRENT_LIST_DIR}/cmakedeps_macros.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/rendererTargets.cmake)
include(CMakeFindDependencyMacro)

check_build_type_defined()

foreach(_DEPENDENCY ${renderer_FIND_DEPENDENCY_NAMES} )
    # Check that we have not already called a find_package with the transitive dependency
    if(NOT ${_DEPENDENCY}_FOUND)
        find_dependency(${_DEPENDENCY} REQUIRED ${${_DEPENDENCY}_FIND_MODE})
    endif()
endforeach()

set(renderer_VERSION_STRING "1.0")
set(renderer_INCLUDE_DIRS ${renderer_INCLUDE_DIRS_RELEASE} )
set(renderer_INCLUDE_DIR ${renderer_INCLUDE_DIRS_RELEASE} )
set(renderer_LIBRARIES ${renderer_LIBRARIES_RELEASE} )
set(renderer_DEFINITIONS ${renderer_DEFINITIONS_RELEASE} )

# Only the first installed configuration is included to avoid the collision
foreach(_BUILD_MODULE ${renderer_BUILD_MODULES_PATHS_RELEASE} )
    message(${renderer_MESSAGE_MODE} "Conan: Including build module from '${_BUILD_MODULE}'")
    include(${_BUILD_MODULE})
endforeach()


