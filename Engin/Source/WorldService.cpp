#pragma once
#include "WorldService.h"
#include <iostream>

namespace project {
	Entity* WorldService::Create(const std::string& name, float posX, float posY, float widht, float height, const Color& color)
	{
		Entity* entity = new Entity(name, posX, posY, widht, height, color);
		Add(entity);
		return entity;
	}

	void WorldService::Start() {
		for (auto entity : m_entityLists) {
			entity.second->Start();
		}
	}

	void WorldService::Update(float dt) {
		for (auto entity : m_entityLists) {
			entity.second->Update(dt);
		}
	}

	void WorldService::Draw() {
		for (auto entity : m_entityLists) {
			entity.second->Draw();
		}
	}

	void WorldService::Add(Entity* entity) {

		m_entityLists[entity->GetName()] = entity;
	}

	Entity* WorldService::GetEntity(std::string name) 
	{
		return m_entityLists.find(name)->second;
	}


	void WorldService::Destroy() {
		for (auto entity : m_entityLists) {
			entity.second->Destroy();
		}
	}


	void WorldService::Load(const std::string& scene)
	{
		if (m_Scenes.count(scene) > 0) {
			Unload();
			m_CurrentScene = m_Scenes[scene];
			m_CurrentScene->Load();
		}
	}

	void WorldService::Register(const std::string& name, IScene* scene)
	{
		std::cout << m_Scenes.size();
		if (m_Scenes.count(name) == 0) {
			m_Scenes[name] = scene;
		}
	}

	void WorldService::Unload()
	{
		if (m_CurrentScene != nullptr) {
			for (auto entity : m_entityLists) {
				entity.second->Destroy();
				delete entity.second;
			}
			m_entityLists.clear();
		}
	}

}