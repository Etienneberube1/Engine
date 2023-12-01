#pragma once
#include "BaseScene.h"

namespace project {

    class Entity;

    // Class representing the main menu scene.
    class MenuScene : public BaseScene
    {
    public:
        // Destructor.
        ~MenuScene() = default;

        // Overridden Load method from BaseScene to set up the main menu.
        virtual void Load() override;

    private:
        // Creates and configures the menu entity.
        Entity* CreateMenu();

        // Pointer to the UI entity for the menu.
        Entity* m_menuUI;

        // ID for the font used in the menu.
        size_t m_fontId;

        // ID for the menu background music.
        size_t m_menuMusic;
    };
}
