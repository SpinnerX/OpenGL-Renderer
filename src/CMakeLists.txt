include_directories(
    ../
    ../Renderer
)

set(
    all_headers
    ../Renderer/glad/glad.h
    ../Renderer/KHR/khrplatform.h

    ../Renderer/Application.h

    # ../Renderer/Event/
    ../Renderer/Graphics/Object.h
    ../Renderer/Graphics/Shader.h

    # ../Renderer/Event/ApplicationEvent.h
    # ../Renderer/Event/Event.h
    # ../Renderer/Event/KeyEvent.h
    # ../Renderer/Event/MouseEvent.h
    # ../Renderer/Event/InputPoll.h
)

set(
    all_src
    Renderer/glad/glad.c

    Renderer/Application.cpp
    Renderer/Graphics/Camera.cpp
    Renderer/image/stb_image.cpp
    Renderer/Graphics/ObjectPrimitive.cpp
    # Renderer/Core/Window.cpp
    Renderer/Graphics/Object.cpp
    Renderer/Graphics/Shader.cpp
    # Renderer/Event/InputPoll.cpp
)

add_library(${PROJECT_NAME} ${all_headers} ${all_src})