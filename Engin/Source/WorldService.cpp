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
		for (auto entity : m_entityList) {
			entity->Start();
		}
	}

	void WorldService::Update(float dt) {
		for (auto entity : m_entityList) {
			entity->Update(dt);
		}
	}

	void WorldService::Draw() {
		for (auto entity : m_entityList) {
			entity->Draw();
		}
	}

	void WorldService::Add(Entity* entity) {
		m_entityList.emplace_back(entity);
	}


	void WorldService::Destroy() {
		for (auto entity : m_entityList) {
			entity->Destroy();
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
			for (auto entity : m_entityList) {
				entity->Destroy();
				delete entity;
			}
			m_entityList.clear();
		}
	}

}