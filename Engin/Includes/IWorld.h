#pragma once
#include <string>

namespace project {

    class Entity;
    class BaseScene;

    // Interface for the game world and scene management.
    class IWorld
    {
    public:
        // Virtual destructor.
        virtual ~IWorld() = default;

        // Creates an entity with a given name.
        virtual Entity* Create(const std::string& name) = 0;

        // Updates the world and its entities.
        virtual void Update(float dt) = 0;

        // Draws the world and its entities.
        virtual void Draw() = 0;

        // Shuts down the world and releases resources.
        virtual void Shutdown() = 0;

        // Finds an entity by name.
        virtual Entity* Find(const std::string& name) = 0;

        // Removes an entity by name.
        virtual void Remove(const std::string& name) = 0;

        // Removes an entity by pointer.
        virtual void Remove(Entity* entity) = 0;

        // Loads a scene by name.
        virtual void Load(const std::string& sceneName) = 0;

        // Unloads the current scene.
        virtual void Unload() = 0;

        // Registers a scene with the world.
        virtual void Register(const std::string& sceneName, BaseScene* scene) = 0;
    };
}
