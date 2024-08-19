#pragma once
#include <cstdint>
#include <Renderer/glad/glad.h>
#include <GLFW/glfw3.h>

class Application{
public:
    Application(float w, float h);

    void UpdateApplication();

private:
    GLFWwindow* m_Window;
    uint32_t m_Width, m_Height;
};