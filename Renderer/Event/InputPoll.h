#pragma once
#include <Renderer/Core/core.h>
#include <Renderer/Event/KeyCodes.h>
#include <Renderer/Event/MouseCodes.h>
#include "glm/glm.hpp"

namespace engine3d{
    class ENGINE_API InputPoll{
    public:

        //! @note Key/Mouse event pressed!
        static bool IsKeyPressed(KeyCode keycode);

        static bool IsMousePressed(MouseCode mouseCode);

        //! @note Mouse Position
        static glm::vec2 GetMousePos();

        static float GetMouseX();

        static float GetMouseY();
    };
};