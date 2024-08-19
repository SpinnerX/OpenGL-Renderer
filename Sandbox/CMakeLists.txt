cmake_minimum_required(VERSION 3.15)
project(Sandbox CXX)

include_directories(
    ../
)


add_executable(${PROJECT_NAME} Application.cpp)

# target_link_libraries(${PROJECT_NAME} engine3d)
target_link_libraries(
    ${PROJECT_NAME}
    Renderer
    glfw
    glm::glm
    fmt::fmt
    spdlog::spdlog
    yaml-cpp::yaml-cpp
)