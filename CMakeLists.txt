cmake_minimum_required(VERSION 3.15)
project(Renderer C CXX)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "") # works (in creating the compile_commands.json file)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)
find_package(fmt REQUIRED)
find_package(spdlog REQUIRED)
find_package(yaml-cpp REQUIRED)


add_subdirectory(src)
add_subdirectory(Sandbox)

target_include_directories(${PROJECT_NAME} PUBLIC ${GLM_INCLUDE_DIR})



target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC
    glfw
    ${OPENGL_LIBRARIES}
    glm::glm
    fmt::fmt
    spdlog::spdlog
    yaml-cpp::yaml-cpp
    # joltphysics::joltphysics
)

install(TARGETS ${PROJECT_NAME})
