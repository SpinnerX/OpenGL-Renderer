#include <Renderer/Graphics/Skybox.h>
#include <Renderer/glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <Renderer/image/stb_image.h>
#include <Renderer/Graphics/Shader.h>
#include <glm/glm.hpp>

Skybox::Skybox(){
    glEnable(GL_DEPTH_TEST);

    float vertices[] = {
        //   Coordinates
        -1.0f, -1.0f,  1.0f,//        7--------6
        1.0f, -1.0f,  1.0f,//       /|       /|
        1.0f, -1.0f, -1.0f,//      4--------5 |
        -1.0f, -1.0f, -1.0f,//      | |      | |
        -1.0f,  1.0f,  1.0f,//      | 3------|-2
        1.0f,  1.0f,  1.0f,//      |/       |/
        1.0f,  1.0f, -1.0f,//      0--------1
        -1.0f,  1.0f, -1.0f
    };

    uint32_t indices[] ={
        // Right
        1, 2, 6,
        6, 5, 1,
        // Left
        0, 4, 7,
        7, 3, 0,
        // Top
        4, 5, 6,
        6, 7, 4,
        // Bottom
        0, 3, 2,
        2, 1, 0,
        // Back
        0, 1, 5,
        5, 4, 0,
        // Front
        3, 7, 6,
        6, 2, 3
    };

    // uint32_t skyboxVao, vbo, ibo;

    glGenVertexArrays(1, &skyboxVao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ibo);

    glBindVertexArray(skyboxVao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    std::string parentPath = "basics/figures/skybox-daylight/";
    std::string singleFile = "whiteClouds.jpg";

    std::string faces[] = {
        parentPath + "right.bmp",
        parentPath + "left.bmp",
        parentPath + "top.bmp",
        parentPath + "bottom.bmp",
        parentPath + "front.bmp",
        parentPath + "back.bmp"
    };


    // uint32_t cubeTextureID;
    glGenTextures(1, &cubeTextureID);
    glBindTexture(GL_TEXTURE_CUBE_MAP, cubeTextureID);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
    glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);

    for(uint32_t i = 0; i < 6; i++){
        int w, h, channels;
        unsigned char* data = stbi_load(faces[i].c_str(), &w, &h, &channels, 0);

        if(data){
            stbi_set_flip_vertically_on_load(false);
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

            stbi_image_free(data);
        }
        else{
            printf("Tried to load texture filepath at ===> %s\n", faces[i].c_str());
            printf("Could not load textures!\n");
        }
    }
    glm::vec4 lightColor = {1.0f, 1.0f, 1.0f, 1.0f};
    glm::vec3 lightPos = {0.5f, 0.5f, 0.5f};

    shader->Bind();
    shader->Set("skybox", 0);
}