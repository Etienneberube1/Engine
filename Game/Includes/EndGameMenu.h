#pragma once
#include "BaseScene.h"

namespace project {
    class Entity;

    // Class representing the end game menu scene.
    class EndGameMenu : public BaseScene
    {
    public:
        // Destructor.
        ~EndGameMenu() = default;

        // Overridden Load method from BaseScene to set up the end game menu.
        virtual void Load() override;

    private:
        // Creates and configures the menu entity.
        Entity* CreateMenu();

        // Pointer to the UI entity.
        Entity* m_UI;

        // ID for the font used in the menu.
        size_t m_fontId;

        // ID for the menu background music.
        size_t m_menuMusic;
    };
}
