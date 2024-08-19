#include <Renderer/Graphics/ObjectPrimitive.h>
#include <Renderer/glad/glad.h>
#include <Renderer/image/stb_image.h>

ObjectDrawer::ObjectDrawer(){}

ObjectDrawer::~ObjectDrawer(){
    if(!m_Vao){
        glDeleteVertexArrays(1, &m_Vao);
    }

    if(!m_Vbo){
        glDeleteBuffers(GL_ARRAY_BUFFER, 0);
    }

    if(!m_Ibo){
        glDeleteBuffers(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
}

void ObjectDrawer::CreateObject(float* vertices, uint32_t* indices, uint32_t count){
    m_Count = count;
    glCreateVertexArrays(1, &m_Vao);
    glCreateBuffers(1, &m_Vbo);
    glCreateBuffers(1, &m_Ibo);

    glBindVertexArray(m_Vao);

    glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);

    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 9, vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices) * m_Count, indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void ObjectDrawer::RenderObject(){
    glBindVertexArray(m_Vao);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Ibo);
    glDrawElements(GL_TRIANGLES, m_Count, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}