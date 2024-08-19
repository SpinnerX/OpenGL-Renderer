#pragma once
#include <cstdint>
#include <string>
#include <glm/glm.hpp>
#include <vector>

enum class VboType : uint8_t{
    Float, Float2, Float3, Float4,
    Mat3, Mat4,
    Int, Bool
};

struct ObjectElement{
    ObjectElement(VboType t, const std::string& n, bool normalized=false) : type(t), name(n), isNormalized(normalized) {}

    VboType type;
    std::string name;
    bool isNormalized;
};

struct ObjectLayout{
    using iterator = std::vector<ObjectElement>::iterator;
    using const_iterator = std::vector<ObjectElement>::const_iterator;

    ObjectLayout(const std::initializer_list<ObjectElement>&& list) : m_Elements(list){}

    iterator begin() { return m_Elements.begin(); }
    iterator end() { return m_Elements.end(); }

    const_iterator begin() const { return m_Elements.begin(); }
    const_iterator end() const { return m_Elements.end(); }
    std::vector<ObjectElement> m_Elements;
};

//! @note Object - it is our primitive object inside our presentation screen.
class Object{
public:
    Object() = default;
    Object(float* vertices, uint32_t* indices, uint32_t count);

    //! @note Setting our graphics object
    void SetData(float* vertices, uint32_t* indices);

    uint32_t GetIndexCount() const { return m_Count; }
    uint32_t GetVao() const { return m_Vao; }

    void SetBufferLayout(const ObjectLayout& layout);

    void* GetIndices() const { return indices; }
private:
    uint32_t m_Vbo, m_Ibo;
    uint32_t m_Vao;
    uint32_t m_Count;
    glm::vec3 m_Position; //! @note TODO -- Contain a position to place this object in our screen.
    void* indices;
};