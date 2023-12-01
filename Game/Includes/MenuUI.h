#pragma once
#include "Component.h"
#include "IDrawable.h"
#include "IUpdatable.h"
#include "Entity.h"

namespace project {

    // Class representing the user interface (UI) for the main menu.
    class MenuUI : public Component, public IDrawable, public IUpdatable
    {
    public:
        // Default constructor.
        MenuUI();

        // Constructor that associates the UI with a parent entity.
        MenuUI(Entity* parent);

        // Destructor.
        ~MenuUI();

        // Update method for handling UI interactions and animations.
        virtual void Update(float DeltaTime) override;

        // Draw method for rendering UI elements.
        virtual void Draw() override;

    private:
        // ID for the font used in the menu UI.
        size_t m_fontId;
    };
}
