#include <Renderer/Application.h>
#include <Renderer/image/stb_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Application::Application(GLFWwindow* window, uint32_t w, uint32_t h) : m_Window(window), m_Width(w), m_Height(h) {
    glCreateBuffers(1, &squareVao);
    glCreateBuffers(1, &squareVbo);
    glCreateBuffers(1, &squareIbo);

    glBindVertexArray(squareVao);

    //{x, y}, {color}, {texCoords}
    // float vertices[] = {
    //     -0.5f, -0.5f, 0.0f, // right
    //     0.5f, -0.5f, 0.0f,// up
    //     0.0f, 0.5f,  0.0f// left
    // };
    // float vertices[] = {
    //     -0.5f, -0.5f, 0.0f,
    //     0.5f, -0.5f, 0.0f,
    //     0.0f,  0.5f, 0.0f
    // };

    float vertices[] = {
        -0.5f, 0.0f, 0.0f,
        0.5f, 0.0f, 0.0f,
        0.0f, 0.5f, 0.0f
    };

    // float vertices[] = {
    //     -0.5f, 0.0f,
    //     0.0f, 0.5f,
    //     0.0f, -0.5f,
    //     0.0f, 0.5f
    // };

    uint32_t indices[] = {0, 1, 2};

    // m_Triangle = Object(vertices, indices, sizeof(indices));
    m_Triangle = ObjectDrawer();
    m_Triangle.CreateObject(vertices, indices, 3);

    // glBindBuffer(GL_ARRAY_BUFFER, squareVbo);
    // glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, squareIbo);
    // glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // glEnableVertexAttribArray(0);
    // glVertexAttribPointer(0, 3, GL_FLOAT, false, 3 * sizeof(float), (void *)0);
}

void Application::UpdateApplication(){
    // glDrawArrays(GL_TRIANGLES, 0, 3);
    m_Triangle.RenderObject();
    // glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, m_Triangle.GetIndexCount());
    // glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, m_Triangle.GetIndices());
}