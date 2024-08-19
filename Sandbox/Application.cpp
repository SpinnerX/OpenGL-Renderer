#include <Renderer/Application.h>
#include <stdio.h>

int main(int argc, char** argv){
    if(!glfwInit()){
        printf("GLFWInit() was not able to work!\n");
        return -2;
    }

    uint32_t width = 800, height=600;

    GLFWwindow* window = glfwCreateWindow(width, height, "OpenGL Renderer", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    
    int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    
    if(!status){
        printf("GLad loader did not work!\n");
        return -2;
    }
    printf("OpenGL Vesion == %s\n", (const char *)glGetString(GL_VERSION));

    if(!window){
        printf("Window nullptr!\n");
        return -2;
    }

    //! @note Applicatoin to remove any window boilerplate from OpenGL.
    Application app = Application(window, width, height);

    // ExampleSkybox(window, 800.0f, 600.0f);
    while(!glfwWindowShouldClose(window)){
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glfwPollEvents();

        app.UpdateApplication();

        glfwSwapBuffers(window);
        glViewport(0, 0, width, height);
    }
}