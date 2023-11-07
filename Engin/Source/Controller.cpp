#include "Controller.h"
#include "Engine.h"
#include <iostream>
#include "Sprite.h"

project::Controller::Controller(Entity* entity) : Component(entity)
{
	m_posX = entity->GetPosX();
	m_posY = entity->GetPosY();
}

void project::Controller::Update(float dt)
{
	//normal movement

	if (Input()->IsKeyDown((static_cast<int>(EKey::EKEY_RIGHT)))) {
		m_posX += m_speed * dt;
		m_Entity->SetPosition(m_posX, m_posY);

		Flip flip;
		flip.v = false;
		flip.h = true;
		m_Entity->GetComponent<Sprite>()->SetSpriteFlip(flip);
	}
	if (Input()->IsKeyDown((static_cast<int>(EKey::EKEY_LEFT)))) {
		m_posX -= m_speed * dt;
		m_Entity->SetPosition(m_posX, m_posY);

		Flip flip;
		flip.v = false;
		flip.h = false;
		m_Entity->GetComponent<Sprite>()->SetSpriteFlip(flip);
	}
	if (Input()->IsKeyDown((static_cast<int>(EKey::EKEY_UP)))) {
		m_posY -= m_speed * dt;
		m_Entity->SetPosition(m_posX, m_posY);
	}
	if (Input()->IsKeyDown((static_cast<int>(EKey::EKEY_DOWN)))) {
		m_posY += m_speed * dt;
		m_Entity->SetPosition(m_posX, m_posY);
	}
}

void project::Controller::Start()
{
}

void project::Controller::Destroy()
{
}

void project::Controller::SetSpeedValue(float speed)
{
	m_speed = speed;
}
