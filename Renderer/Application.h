#include <Renderer/Graphics/Shader.h>
#include <Renderer/Graphics/Camera.h>
// #include <Renderer/Graphics/Object.h>
#include <Renderer/Graphics/ObjectPrimitive.h>
class Application{
public:
    Application(GLFWwindow* window, uint32_t w, uint32_t h);

    void UpdateApplication();

private:
    GLFWwindow* m_Window;
    uint32_t m_Width, m_Height;

    // Square
    uint32_t squareVbo, squareIbo;
    uint32_t squareVao;

    ObjectDrawer m_Triangle;

};