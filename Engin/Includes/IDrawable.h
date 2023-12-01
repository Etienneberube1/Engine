#pragma once

namespace project {
    // Interface for drawable objects in the game engine.
    class IDrawable
    {
    public:
        // Virtual method to draw or render the object.
        virtual void Draw() = 0;
    };
}
