#pragma once 
#include "Entity.h"
#include "Engine.h"
#include <string>
#include "SDLGraphics.h"
#include "Component.h"

namespace project {


	Entity::Entity(std::string name, float posX, float posY, float widht, float height, const Color& color)
		:m_posX(posX), m_posY(posY), m_entityName(name), m_heigth(height), m_width(widht), 
		m_color(color)
	{
	}

	Entity::~Entity() {

	}


	void Entity::Start() {


	}


	void Entity::Update(float dt) {

		for (auto cmp : m_Updatables) {
			cmp->Update(dt);
		}
	}

	void Entity::Draw() {
	
		for (auto cmp : m_Drawables) {
			cmp->Draw();
		}
	
	}

	void Entity::Destroy() {
	
	}

	void Entity::SetPosition(float posX, float posY)
	{
		m_posX = posX;
		m_posY = posY;
	}



}