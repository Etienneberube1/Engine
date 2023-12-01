#pragma once
#include <EKey.h>

namespace project {

    // Interface for input handling functionalities.
    class IInput
    {
    public:
        // Virtual destructor.
        virtual ~IInput() = default;

        // Checks if a specific key is currently pressed down.
        virtual bool IsKeyDown(EKey key) = 0;

        // Checks if a specific mouse button is currently pressed down.
        virtual bool IsButtonDown(int button) = 0;

        // Retrieves the current position of the mouse cursor.
        virtual void GetMousePosition(int* x, int* y) = 0;

    protected:
        // Friend class declaration for Engine, granting Engine special access to protected members.
        friend class Engine;

        // Updates the current state of input devices.
        virtual void Update() = 0;
    };
}
