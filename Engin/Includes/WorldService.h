#pragma once

#include <vector>
#include <string>
#include <map>
#include <BaseScene.h>
#include <IWorld.h>

namespace project
{
    class Entity;

    // Class managing entities and scenes within the game world.
    class WorldService : public IWorld
    {
    public:
        // Destructor.
        virtual ~WorldService() = default;

        // Creates a new entity with a given name.
        virtual Entity* Create(const std::string& name) override;

        // Updates all entities within the world.
        virtual void Update(float dt) override;

        // Draws all entities within the world.
        virtual void Draw() override;

        // Shuts down the world, releasing all entities and resources.
        virtual void Shutdown() override;

        // Finds an entity by name.
        virtual Entity* Find(const std::string& name) override;

        // Removes an entity by name.
        virtual void Remove(const std::string& name) override;

        // Removes an entity by reference.
        virtual void Remove(Entity* entity) override;

        // Loads a scene by name.
        virtual void Load(const std::string& sceneName) override;

        // Unloads the current scene.
        virtual void Unload() override;

        // Registers a scene with the world.
        virtual void Register(const std::string& sceneName, BaseScene* scene) override;

    private:
        // Helper functions for managing entities.
        void CleanEntities();      // Cleans up removed entities.
        void StartEntities();      // Initializes new entities.
        void UpdateLoadScene();    // Handles scene transitions.

        // Member variables for managing entities and scenes.
        std::string m_SceneToLoad;                    // Name of the scene to be loaded.
        std::vector<Entity*> m_EntityInWorld;         // Entities currently in the world.
        std::vector<Entity*> m_EntityToRemove;        // Entities to be removed.
        std::vector<Entity*> m_EntityToStart;         // Entities to be initialized.
        std::map<std::string, Entity*> m_EntityMap;   // Map of entities by name.
        std::map<std::string, BaseScene*> m_SceneRegistry; // Registered scenes.
    };
}
