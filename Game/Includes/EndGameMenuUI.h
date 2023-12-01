#pragma once
#include "Component.h"
#include "IDrawable.h"
#include "IUpdatable.h"
#include "Entity.h"

namespace project {

    // Class representing the UI for the end game menu.
    class EndGameMenuUI : public Component, public IDrawable, public IUpdatable
    {
    public:
        // Constructors.
        EndGameMenuUI();
        EndGameMenuUI(Entity* parent);

        // Destructor.
        ~EndGameMenuUI();

        // Update method for handling UI logic.
        virtual void Update(float DeltaTime) override;

        // Draw method for rendering the UI elements.
        virtual void Draw() override;

    private:
        // Font identifier for UI text elements.
        size_t m_fontId;
    };
}
