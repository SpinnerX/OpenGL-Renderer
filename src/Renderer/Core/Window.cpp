#include <Renderer/Core/Window.h>
#include <cassert>
#include <Renderer/glad/glad.h>
#include <GLFW/glfw3.h>

struct WindowData{
    std::string name;
    uint32_t width, height;
};

static WindowData g_WindowData;

Window::Window(const std::string& name, uint32_t w, uint32_t h){
    g_WindowData.name = name;
    g_WindowData.width = w;
    g_WindowData.height = h;
    //! @note Hinting to OpenGL by specifying what OpenGL Version to enable
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, true);

    m_Window = glfwCreateWindow((int)w, (int)h, name.c_str(), nullptr, nullptr);

    glfwMakeContextCurrent(m_Window);
    int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    if(!status){
        assert(false);
    }

    glfwSetWindowUserPointer(m_Window, &g_WindowData);
}

void Window::Clear(float r, float g, float b, float a){
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::UpdateWindow(){
    glfwSwapBuffers(m_Window);
    glfwPollEvents();
}

bool Window::IsWindowClosed() const{
    return !glfwWindowShouldClose(m_Window);
}