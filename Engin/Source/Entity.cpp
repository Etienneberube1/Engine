#pragma once 
#include "Entity.h"
#include "Engine.h"
#include <string>
#include "SDLGraphics.h"
#include "Component.h"

namespace project {


	Entity::Entity(std::string name, float posX, float posY, float widht, float height,float speed, const Color& color)
		:m_posX(posX), m_posY(posY), m_entityName(name), m_heigth(height), m_width(widht), 
		m_color(color), m_speed(speed)
	{
	}

	Entity::~Entity() {

	}


	void Entity::Start() {
		project::IGraphics* Gfx = Engine::Get().Graphics();
		Gfx->LoadTexture("assets/player.png");

	}


	void Entity::Update(float dt) {

		//if (input->IsKeyDown((static_cast<int>(EKey::EKEY_SPACE)))) {
		//	project::IAudio* audio = Engine::Get().Audio();
		//	audio->PlaySFX(audio->LoadSound("assets/audio/clicksound.wav"), 0);
		//}
		for (auto cmp : m_Updatables) {
			cmp->Update(dt);
		}
	}

	void Entity::Draw() {

		//project::IGraphics* GFX = Engine::Get().Graphics();
		//GFX->DrawRect(m_posX, m_posY, m_width, m_heigth, m_color);

		//GFX->DrawTexture(GFX->LoadTexture("assets/player.png"), { 300, 300, 500, 500 }, Color::White);
	
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