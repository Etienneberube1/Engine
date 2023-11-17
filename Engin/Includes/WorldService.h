#pragma once

#include <vector>
#include <string>
#include <map>
#include <BaseScene.h>
#include <IWorld.h>

namespace project
{
    class Entity;

    class WorldService : public IWorld
    {
    public:
        virtual ~WorldService() = default;

        virtual Entity* Create(const std::string& name) override;
        virtual void Update(float dt) override;
        virtual void Draw() override;
        virtual void Shutdown() override;
        virtual Entity* Find(const std::string& name) override;
        virtual void Remove(const std::string& name) override;
        virtual void Remove(Entity* entity) override;
        virtual void Load(const std::string& sceneName) override;
        virtual void Unload() override;
        virtual void Register(const std::string& sceneName, BaseScene* scene) override;

    private:
        void CleanEntities();
        void StartEntities();
        void UpdateLoadScene();

        std::string m_SceneToLoad;
        std::vector<Entity*> m_EntityInWorld;
        std::vector<Entity*> m_EntityToRemove;
        std::vector<Entity*> m_EntityToStart;
        std::map<std::string, Entity*> m_EntityMap;
        std::map<std::string, BaseScene*> m_SceneRegistry;
    };
}
