#pragma once 
#include "Entity.h"
#include "Engine.h"
#include <string>

namespace project {


	Entity::Entity(std::string name, float posX, float posY, float widht, float height, const Color& color)
		:m_posX(posX), m_posY(posY), m_entityName(name), m_heigth(height), m_width(widht), m_color(color)
	{
	}

	Entity::~Entity() {

	}


	void Entity::Start() {
		project::IGraphics* Gfx = Engine::Get().Graphics();
		Gfx->LoadTexture("assets/player.png");

	}


	void Entity::Update(float dt) {

		project::IInput* input = Engine::Get().Input();
		if (input->IsKeyDown((static_cast<int>(EKey::EKEY_RIGHT)))) {
			m_posX += 100.0f * dt;
		}
		else if (input->IsKeyDown((static_cast<int>(EKey::EKEY_LEFT)))) {
			m_posX -= 100.0f * dt;
		}
		else if (input->IsKeyDown((static_cast<int>(EKey::EKEY_UP)))) {
			m_posY -= 100.0f * dt;
		}
		else if (input->IsKeyDown((static_cast<int>(EKey::EKEY_DOWN)))) {
			m_posY += 100.0f * dt;
		}
		

		if (input->IsKeyDown((static_cast<int>(EKey::EKEY_SPACE)))) {
			project::IAudio* audio = Engine::Get().Audio();
			audio->PlaySFX(audio->LoadSound("assets/audio/clicksound.wav"), 0);
		}
	}

	void Entity::Draw() {

		project::IGraphics* GFX = Engine::Get().Graphics();
		GFX->DrawRect(m_posX, m_posY, m_width, m_heigth, m_color);

		//GFX->DrawTexture(GFX->LoadTexture("assets/player.png"), { 300, 300, 500, 500 }, Color::White);
	}

	void Entity::Destroy() {
	
	}
}