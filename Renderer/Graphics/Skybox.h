#pragma once
#include <cstdint>

class Shader;
class Skybox{
public:
    Skybox();

private:
    uint32_t skyboxVao, vbo, ibo;
    uint32_t cubeTextureID;
    Shader* shader;
};