#include <Renderer/Graphics/Object.h>
#include <Renderer/glad/glad.h>

//! @note Automating checking what type we want to load into our object
//! @note Laying out how we want to handle our data (especially from our shaders)
static size_t TypeSize(VboType type){
    switch (type){
    case VboType::Float: return sizeof(float);
    case VboType::Float2: return sizeof(float) * 2;
    case VboType::Float3: return sizeof(float) * 3;
    case VboType::Float4: return sizeof(float) * 4;
    case VboType::Mat3: return sizeof(float) * 3 * 3;
    case VboType::Mat4: return sizeof(float) * 4 * 4;
    case VboType::Int: return sizeof(int);
    case VboType::Bool: return sizeof(bool);
    default: return 0;
    }
}

Object::Object(float* vertices, uint32_t* indices, uint32_t count) : m_Count(count){
    glCreateVertexArrays(1, &m_Vao);
    glCreateBuffers(1, &m_Vbo);
    glCreateBuffers(1, &m_Ibo);
    glBindVertexArray(m_Vao);

    glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Ibo);
    glBufferData(GL_ARRAY_BUFFER, count, indices, GL_STATIC_DRAW);
    indices = indices;
}

void Object::SetData(float* vertices, uint32_t* indices){
    glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    //! @note This assumes that we do not want to set our indices to new values and keep our previous indices values
    if(indices != nullptr){
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Ibo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    }
}

void Object::SetBufferLayout(const ObjectLayout& layout){
    glBindVertexArray(m_Vao);

    uint32_t index = 0; // glEnableAttrib(index++);
    for(const auto& element : layout){
        switch (element.type){
        case VboType::Float:
        case VboType::Float2:
        case VboType::Float3:
        case VboType::Float4:
            glVertexAttribPointer(index, GL_BGRA, GL_FLOAT, element.isNormalized, TypeSize(element.type), (const char*)0);
            glEnableVertexAttribArray(index++);
            break;
        default: break;
        }
    }
}

