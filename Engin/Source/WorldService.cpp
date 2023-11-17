#include <WorldService.h>
#include <Entity.h>
#include <BaseScene.h>
#include <Engine.h>

project::Entity* project::WorldService::Create(const std::string& name)
{
    Entity* _newEntity = new Entity(name);

    if (m_EntityMap.count(name) == 0)
    {
        m_EntityToStart.emplace_back(_newEntity);
        return _newEntity;
    }

    return nullptr;
}

void project::WorldService::Update(float dt)
{
    for (auto entity : m_EntityInWorld)
    {
        entity->Update(dt);
    }

    UpdateLoadScene();

    StartEntities();
    CleanEntities();
}

void project::WorldService::Draw()
{
    for (auto entity : m_EntityInWorld)
    {
        entity->Draw();
    }
}

void project::WorldService::Remove(Entity* entity)
{
    if (entity != nullptr)
    {
        Remove(entity->GetName());
    }
}

void project::WorldService::Remove(const std::string& name)
{
    if (m_EntityMap.count(name) > 0)
    {
        for (size_t i = 0; i < m_EntityInWorld.size(); i++)
        {
            Entity* entity = m_EntityInWorld[i];
            if (entity->GetName() == name)
            {
                m_EntityToRemove.emplace_back(entity);
                break;
            }
        }
    }
}

project::Entity* project::WorldService::Find(const std::string& name)
{
    if (m_EntityMap.count(name) > 0)
    {
        return m_EntityMap[name];
    }

    return nullptr;
}

void project::WorldService::Load(const std::string& scene)
{
    if (m_SceneRegistry.count(scene) > 0)
    {
        m_SceneToLoad = scene;
    }
}

void project::WorldService::Register(const std::string& name, BaseScene* scene)
{
    if (m_SceneRegistry.count(name) == 0)
    {
        m_SceneRegistry[name] = scene;
    }
}

void project::WorldService::Unload()
{
    for (auto entity : m_EntityInWorld)
    {
        entity->Destroy();
        delete entity;
    }

    for (auto entity : m_EntityToStart)
    {
        delete entity;
    }

    for (auto entity : m_EntityToRemove)
    {
        entity->Destroy();
        delete entity;
    }

    m_EntityInWorld.clear();
    m_EntityMap.clear();
    m_EntityToStart.clear();
    m_EntityToRemove.clear();
}

void project::WorldService::Shutdown()
{
    Unload();

    for (auto scene : m_SceneRegistry)
    {
        delete scene.second;
    }

    m_SceneRegistry.clear();
}

void project::WorldService::CleanEntities()
{
    if (m_EntityToRemove.size() > 0)
    {
        std::vector<Entity*> _trash = m_EntityToRemove;
        m_EntityToRemove.clear();

        for (auto entity : _trash)
        {
            m_EntityMap.erase(entity->GetName());
            entity->Destroy();

            for (auto it = m_EntityInWorld.begin(); it != m_EntityInWorld.end(); ++it)
            {
                if (entity == *it)
                {
                    m_EntityInWorld.erase(it);
                    delete entity;
                    break;
                }
            }
        }

        _trash.clear();
    }
}

void project::WorldService::StartEntities()
{
    if (m_EntityToStart.size() > 0)
    {
        std::vector<Entity*> _starting = m_EntityToStart;
        m_EntityToStart.clear();

        for (auto entity : _starting)
        {
            if (m_EntityMap.count(entity->GetName()) > 0)
            {
                Engine::Get().Logger().LogWarning("Not adding entity with same name");
                continue;
            }

            m_EntityInWorld.emplace_back(entity);
            m_EntityMap.emplace(entity->GetName(), entity);
        }

        for (auto entity : _starting)
        {
            entity->Start();
        }

        _starting.clear();
    }
}

void project::WorldService::UpdateLoadScene()
{
    if (!m_SceneToLoad.empty())
    {
        Unload();
        m_SceneRegistry[m_SceneToLoad]->Load();
        m_SceneToLoad.clear();
    }
}