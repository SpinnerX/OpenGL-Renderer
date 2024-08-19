# Avoid multiple calls to find_package to append duplicated properties to the targets
include_guard()########### VARIABLES #######################################################################
#############################################################################################
set(renderer_FRAMEWORKS_FOUND_RELEASE "") # Will be filled later
conan_find_apple_frameworks(renderer_FRAMEWORKS_FOUND_RELEASE "${renderer_FRAMEWORKS_RELEASE}" "${renderer_FRAMEWORK_DIRS_RELEASE}")

set(renderer_LIBRARIES_TARGETS "") # Will be filled later


######## Create an interface target to contain all the dependencies (frameworks, system and conan deps)
if(NOT TARGET renderer_DEPS_TARGET)
    add_library(renderer_DEPS_TARGET INTERFACE IMPORTED)
endif()

set_property(TARGET renderer_DEPS_TARGET
             APPEND PROPERTY INTERFACE_LINK_LIBRARIES
             $<$<CONFIG:Release>:${renderer_FRAMEWORKS_FOUND_RELEASE}>
             $<$<CONFIG:Release>:${renderer_SYSTEM_LIBS_RELEASE}>
             $<$<CONFIG:Release>:glfw;spdlog::spdlog;fmt::fmt;glm::glm;yaml-cpp::yaml-cpp>)

####### Find the libraries declared in cpp_info.libs, create an IMPORTED target for each one and link the
####### renderer_DEPS_TARGET to all of them
conan_package_library_targets("${renderer_LIBS_RELEASE}"    # libraries
                              "${renderer_LIB_DIRS_RELEASE}" # package_libdir
                              "${renderer_BIN_DIRS_RELEASE}" # package_bindir
                              "${renderer_LIBRARY_TYPE_RELEASE}"
                              "${renderer_IS_HOST_WINDOWS_RELEASE}"
                              renderer_DEPS_TARGET
                              renderer_LIBRARIES_TARGETS  # out_libraries_targets
                              "_RELEASE"
                              "renderer"    # package_name
                              "${renderer_NO_SONAME_MODE_RELEASE}")  # soname

# FIXME: What is the result of this for multi-config? All configs adding themselves to path?
set(CMAKE_MODULE_PATH ${renderer_BUILD_DIRS_RELEASE} ${CMAKE_MODULE_PATH})

########## GLOBAL TARGET PROPERTIES Release ########################################
    set_property(TARGET Renderer::Renderer
                 APPEND PROPERTY INTERFACE_LINK_LIBRARIES
                 $<$<CONFIG:Release>:${renderer_OBJECTS_RELEASE}>
                 $<$<CONFIG:Release>:${renderer_LIBRARIES_TARGETS}>
                 )

    if("${renderer_LIBS_RELEASE}" STREQUAL "")
        # If the package is not declaring any "cpp_info.libs" the package deps, system libs,
        # frameworks etc are not linked to the imported targets and we need to do it to the
        # global target
        set_property(TARGET Renderer::Renderer
                     APPEND PROPERTY INTERFACE_LINK_LIBRARIES
                     renderer_DEPS_TARGET)
    endif()

    set_property(TARGET Renderer::Renderer
                 APPEND PROPERTY INTERFACE_LINK_OPTIONS
                 $<$<CONFIG:Release>:${renderer_LINKER_FLAGS_RELEASE}>)
    set_property(TARGET Renderer::Renderer
                 APPEND PROPERTY INTERFACE_INCLUDE_DIRECTORIES
                 $<$<CONFIG:Release>:${renderer_INCLUDE_DIRS_RELEASE}>)
    # Necessary to find LINK shared libraries in Linux
    set_property(TARGET Renderer::Renderer
                 APPEND PROPERTY INTERFACE_LINK_DIRECTORIES
                 $<$<CONFIG:Release>:${renderer_LIB_DIRS_RELEASE}>)
    set_property(TARGET Renderer::Renderer
                 APPEND PROPERTY INTERFACE_COMPILE_DEFINITIONS
                 $<$<CONFIG:Release>:${renderer_COMPILE_DEFINITIONS_RELEASE}>)
    set_property(TARGET Renderer::Renderer
                 APPEND PROPERTY INTERFACE_COMPILE_OPTIONS
                 $<$<CONFIG:Release>:${renderer_COMPILE_OPTIONS_RELEASE}>)

########## For the modules (FindXXX)
set(renderer_LIBRARIES_RELEASE Renderer::Renderer)
