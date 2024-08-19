#pragma once
#include <string>
// #include <GLFW/glfw3.h>

class GLFWwindow;
class Window{
public:
    Window(const std::string& name, uint32_t w, uint32_t h);

    void* GetNativeWindow() const { return m_Window; }

    void UpdateWindow();

    bool IsWindowClosed() const;

    void Clear(float r, float g, float b, float a=1.0f);

private:
    GLFWwindow* m_Window;  
};