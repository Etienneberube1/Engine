#pragma once
#include "BaseScene.h"

namespace project {

    class Entity;

    // Class representing the main game scene.
    class GameScene : public BaseScene
    {
    public:
        // Destructor.
        ~GameScene() = default;

        // Overridden Load method from BaseScene to set up the game environment.
        virtual void Load() override;

    private:
        // Creates the player entity.
        Entity* CreatePlayer();

        // Creates the tile map for the game.
        Entity* CreateTileMap();

        // Creates enemies in the game.
        void CreateEnemy();

        // Pointer to the UI entity for the game.
        Entity* m_gameUI;

        // ID for the font used in the game UI.
        size_t m_fontId;
    };
}
