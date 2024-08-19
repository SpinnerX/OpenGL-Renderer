message(STATUS "Conan: Using CMakeDeps conandeps_legacy.cmake aggregator via include()")
message(STATUS "Conan: It is recommended to use explicit find_package() per dependency instead")

find_package(glfw3)
find_package(spdlog)
find_package(fmt)
find_package(glm)
find_package(yaml-cpp)

set(CONANDEPS_LEGACY  glfw  spdlog::spdlog  fmt::fmt  glm::glm  yaml-cpp::yaml-cpp )