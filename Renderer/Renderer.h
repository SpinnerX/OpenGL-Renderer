#pragma once

#include <vector>
#include <string>


#ifdef _WIN32
  #define RENDERER_EXPORT __declspec(dllexport)
#else
  #define RENDERER_EXPORT
#endif

RENDERER_EXPORT void Renderer();
RENDERER_EXPORT void Renderer_print_vector(const std::vector<std::string> &strings);
