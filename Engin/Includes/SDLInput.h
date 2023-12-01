#pragma once

#include <IInput.h>

namespace project
{
    // Class implementing SDL-based input handling.
    class SdlInput final : public IInput
    {
    public:
        // Destructor.
        virtual ~SdlInput() = default;

        // Checks if a specific key is currently pressed down.
        virtual bool IsKeyDown(EKey keycode) override;

        // Checks if a specific mouse button is currently pressed down.
        virtual bool IsButtonDown(int button) override;

        // Retrieves the current position of the mouse cursor.
        virtual void GetMousePosition(int* x, int* y) override;

    protected:
        // Updates the current state of input devices.
        virtual void Update() override;

    private:
        // Current state of the keyboard keys.
        const unsigned char* m_KeyStates = nullptr;

        // Current mouse position.
        int m_MouseX = 0;
        int m_MouseY = 0;

        // Current state of the mouse buttons.
        bool m_MouseStates[3]{ false, false, false }; // Assuming left, middle, right buttons.
    };
}
