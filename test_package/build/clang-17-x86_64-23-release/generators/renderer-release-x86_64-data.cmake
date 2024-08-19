########### AGGREGATED COMPONENTS AND DEPENDENCIES FOR THE MULTI CONFIG #####################
#############################################################################################

set(renderer_COMPONENT_NAMES "")
if(DEFINED renderer_FIND_DEPENDENCY_NAMES)
  list(APPEND renderer_FIND_DEPENDENCY_NAMES glfw3 spdlog fmt glm yaml-cpp)
  list(REMOVE_DUPLICATES renderer_FIND_DEPENDENCY_NAMES)
else()
  set(renderer_FIND_DEPENDENCY_NAMES glfw3 spdlog fmt glm yaml-cpp)
endif()
set(glfw3_FIND_MODE "NO_MODULE")
set(spdlog_FIND_MODE "NO_MODULE")
set(fmt_FIND_MODE "NO_MODULE")
set(glm_FIND_MODE "NO_MODULE")
set(yaml-cpp_FIND_MODE "NO_MODULE")

########### VARIABLES #######################################################################
#############################################################################################
set(renderer_PACKAGE_FOLDER_RELEASE "C:/Users/heraa/.conan2/p/b/rendedf130b340afc2/p")
set(renderer_BUILD_MODULES_PATHS_RELEASE )


set(renderer_INCLUDE_DIRS_RELEASE "${renderer_PACKAGE_FOLDER_RELEASE}/./"
			"${renderer_PACKAGE_FOLDER_RELEASE}/./Renderer")
set(renderer_RES_DIRS_RELEASE )
set(renderer_DEFINITIONS_RELEASE )
set(renderer_SHARED_LINK_FLAGS_RELEASE )
set(renderer_EXE_LINK_FLAGS_RELEASE )
set(renderer_OBJECTS_RELEASE )
set(renderer_COMPILE_DEFINITIONS_RELEASE )
set(renderer_COMPILE_OPTIONS_C_RELEASE )
set(renderer_COMPILE_OPTIONS_CXX_RELEASE )
set(renderer_LIB_DIRS_RELEASE "${renderer_PACKAGE_FOLDER_RELEASE}/lib")
set(renderer_BIN_DIRS_RELEASE )
set(renderer_LIBRARY_TYPE_RELEASE STATIC)
set(renderer_IS_HOST_WINDOWS_RELEASE 1)
set(renderer_LIBS_RELEASE Renderer)
set(renderer_SYSTEM_LIBS_RELEASE )
set(renderer_FRAMEWORK_DIRS_RELEASE )
set(renderer_FRAMEWORKS_RELEASE )
set(renderer_BUILD_DIRS_RELEASE )
set(renderer_NO_SONAME_MODE_RELEASE FALSE)


# COMPOUND VARIABLES
set(renderer_COMPILE_OPTIONS_RELEASE
    "$<$<COMPILE_LANGUAGE:CXX>:${renderer_COMPILE_OPTIONS_CXX_RELEASE}>"
    "$<$<COMPILE_LANGUAGE:C>:${renderer_COMPILE_OPTIONS_C_RELEASE}>")
set(renderer_LINKER_FLAGS_RELEASE
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:${renderer_SHARED_LINK_FLAGS_RELEASE}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:${renderer_SHARED_LINK_FLAGS_RELEASE}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:${renderer_EXE_LINK_FLAGS_RELEASE}>")


set(renderer_COMPONENTS_RELEASE )