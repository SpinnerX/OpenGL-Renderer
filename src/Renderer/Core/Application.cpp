#include <Renderer/Core/Application.h>
#include <string>
#include <glm/glm.hpp>
#include <Renderer/Graphics/Shader.h>
#include <Renderer/image/stb_image.h>
#include <Renderer/Graphics/Camera.h>

#include <string>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

static Camera camera;
// static uint32_t vbo, ibo, vao;
static uint32_t skyboxVao, vbo, ibo;
static uint32_t cubeTextureID;
static Shader shader("basics/shaders/skybox/skybox.vert", "basics/shaders/skybox/skybox.frag");
static Shader cubeShader("basics/shaders/lightTutorial-02/cube.vert", "basics/shaders/lightTutorial-02/cube.frag");

Application::Application(float w, float h){
    // printf("Initiating Application!\n");
    // glEnable(GL_DEPTH_TEST);
    // m_Width = w;
    // m_Height = h;

    // float vertices[] = {
    //     //   Coordinates
    //     -1.0f, -1.0f,  1.0f,//        7--------6
    //     1.0f, -1.0f,  1.0f,//       /|       /|
    //     1.0f, -1.0f, -1.0f,//      4--------5 |
    //     -1.0f, -1.0f, -1.0f,//      | |      | |
    //     -1.0f,  1.0f,  1.0f,//      | 3------|-2
    //     1.0f,  1.0f,  1.0f,//      |/       |/
    //     1.0f,  1.0f, -1.0f,//      0--------1
    //     -1.0f,  1.0f, -1.0f
    // };

    // unsigned int indices[] ={
    //     // Right
    //     1, 2, 6,
    //     6, 5, 1,
    //     // Left
    //     0, 4, 7,
    //     7, 3, 0,
    //     // Top
    //     4, 5, 6,
    //     6, 7, 4,
    //     // Bottom
    //     0, 3, 2,
    //     2, 1, 0,
    //     // Back
    //     0, 1, 5,
    //     5, 4, 0,
    //     // Front
    //     3, 7, 6,
    //     6, 2, 3
    // };

    // glGenVertexArrays(1, &skyboxVao);
    // glGenBuffers(1, &vbo);
    // glGenBuffers(1, &ibo);

    // glBindVertexArray(skyboxVao);
    // glBindBuffer(GL_ARRAY_BUFFER, vbo);
    // glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);

    // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    // glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);

    // glEnableVertexAttribArray(0);
    // glBindBuffer(GL_ARRAY_BUFFER, 0);
    // glBindVertexArray(0);

    // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    // std::string parentPath = "basics/figures/skybox-daylight/";
    // std::string singleFile = "whiteClouds.jpg";

    // std::string faces[] = {
    //     parentPath + "right.bmp",
    //     parentPath + "left.bmp",
    //     parentPath + "top.bmp",
    //     parentPath + "bottom.bmp",
    //     parentPath + "front.bmp",
    //     parentPath + "back.bmp"
    // };


    // glGenTextures(1, &cubeTextureID);
    // glBindTexture(GL_TEXTURE_CUBE_MAP, cubeTextureID);
    // glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    // glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    // glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    // glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
    // glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);

    // for(uint32_t i = 0; i < 6; i++){
    //     int w, h, channels;
    //     unsigned char* data = stbi_load(faces[i].c_str(), &w, &h, &channels, 0);

    //     if(data){
    //         stbi_set_flip_vertically_on_load(false);
    //         glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

    //         stbi_image_free(data);
    //     }
    //     else{
    //         printf("Tried to load texture filepath at ===> %s\n", faces[i].c_str());
    //         printf("Could not load textures!\n");
    //     }
    // }
    // glm::vec4 lightColor = {1.0f, 1.0f, 1.0f, 1.0f};
    // glm::vec3 lightPos = {0.5f, 0.5f, 0.5f};

    // Shader shader("basics/shaders/skybox/skybox.vert", "basics/shaders/skybox/skybox.frag");
    // Shader cubeShader("basics/shaders/lightTutorial-02/cube.vert", "basics/shaders/lightTutorial-02/cube.frag");

    // shader.Bind();
    // shader.Set("skybox", 0);

    // glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    // glfwSetCursorPosCallback(window, [](GLFWwindow* window, double xPosIn, double yPosIn){
    //     camera.MouseOnUpdate(xPosIn, yPosIn);
    // });

    // glfwSetScrollCallback(window, [](GLFWwindow* window, double xOffset, double yOffset){
    //     camera.MouseOnScrollback(xOffset, yOffset);
    // });
}

void Application::UpdateApplication(){
    // glDrawArrays(GL_TRIANGLES, 3, 36);
    // Specify the color of the background
    // glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
    // // Clean the back buffer and depth buffer
    // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // glDepthFunc(GL_LEQUAL);

    // camera.OnUpdate(m_Window);

    // if(glfwGetKey(m_Window, GLFW_KEY_ESCAPE) == GLFW_PRESS) return;

    

    // shader.Bind();
    // // glm::mat4 view = glm::mat4(1.0f);
    // // glm::mat4 projection = glm::mat4(1.0f);
    // glm::mat4 view = glm::mat4(1.0f);
    // glm::mat4 projection = camera.GetProjectionMatrix();

    // view = glm::mat4(glm::mat3(glm::lookAt(camera.cameraPos, camera.cameraPos + camera.cameraFront, camera.cameraUp)));
    // projection = glm::perspective(glm::radians(45.0f), (float)m_Width / (float)m_Height, 0.1f, 100.0f);

    // shader.Set("view", view);
    // shader.Set("projection", projection);

    // glBindVertexArray(skyboxVao);
    // glActiveTexture(GL_TEXTURE0);
    // glBindTexture(GL_TEXTURE_CUBE_MAP, cubeTextureID);
    // glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    // glBindVertexArray(0);

    // glDepthFunc(GL_LESS);
    // Enables Cull Facing
    // glEnable(GL_CULL_FACE);
    // // Keeps front faces
    // glCullFace(GL_FRONT);
    // // Uses counter clock-wise standard
    // glFrontFace(GL_CCW);
}