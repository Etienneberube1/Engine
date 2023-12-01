#include <Entity.h>

project::Entity::Entity(const std::string& name) : m_Name(name)
{
}

void project::Entity::Start()
{
	for (auto it = m_ComponentByType.begin(); it != m_ComponentByType.end(); ++it)
	{
		it->second->Start();
	}
}

void project::Entity::Update(float dt)
{

	for (auto component : m_UpdatableComponents)
	{
		if (m_UpdatableComponents.size() != 0)
		{
			component->Update(dt);
		}


	}


}

void project::Entity::Draw()
{
	for (auto component : m_DrawableComponents)
	{
		component->Draw();
	}
}

void project::Entity::Destroy()
{
	for (auto it = m_ComponentByType.begin(); it != m_ComponentByType.end(); ++it)
	{
		it->second->Destroy();
		delete it->second;
	}

	m_ComponentByType.clear();
	m_DrawableComponents.clear();
	m_UpdatableComponents.clear();
}