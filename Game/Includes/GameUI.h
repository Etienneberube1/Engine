#pragma once
#include "Observer.h"
#include "IDrawable.h"
#include "Engine.h"
#include "Component.h"

namespace project {

    // Class representing the game's user interface.
    class GameUI : public IDrawable, public Component, public Observer<int>
    {
    public:
        // Constructors.
        GameUI();
        GameUI(Entity* parent);

        // Observer method to receive notifications about score changes.
        virtual void OnNotify(const int& value) override
        {
            m_playerScore += value; // Updates the player's score.
        }

        // Draws the UI elements on the screen.
        virtual void Draw() override;

    private:
        // Player's score to be displayed on the UI.
        float m_playerScore;

        // Font identifier for rendering text in the UI.
        size_t m_fontId;
    };

}
