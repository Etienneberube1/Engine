#include <Entity.h>

project::Entity::Entity(const std::string& name) : m_name(name)
{
}

void project::Entity::Start()
{
    for (auto it = m_componentByType.begin(); it != m_componentByType.end(); ++it)
    {
        it->second->Start();
    }
}

void project::Entity::Update(float dt)
{
    for (auto component : m_updatableComponents)
    {
        if (!m_updatableComponents.empty())
        {
            component->Update(dt);
        }
    }
}

void project::Entity::Draw()
{
    for (auto component : m_drawableComponents)
    {
        component->Draw();
    }
}

void project::Entity::Destroy()
{
    for (auto it = m_componentByType.begin(); it != m_componentByType.end(); ++it)
    {
        it->second->Destroy();
        delete it->second;
    }

    m_componentByType.clear();
    m_drawableComponents.clear();
    m_updatableComponents.clear();
}

