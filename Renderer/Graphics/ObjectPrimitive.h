#pragma once
#include <cstdint>

class ObjectDrawer{
public:
    ObjectDrawer();
    ~ObjectDrawer();

    void CreateObject(float* vertices, uint32_t* indices, uint32_t count);

    void RenderObject();

private:
    uint32_t m_Vbo, m_Ibo, m_Vao, m_Count;
};