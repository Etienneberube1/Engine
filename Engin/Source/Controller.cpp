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

		anim->Play("fly", true);
	}
	if (Input()->IsKeyDown((static_cast<int>(EKey::EKEY_LEFT)))) {
		m_posX -= m_speed * dt;
		m_Entity->SetPosition(m_posX, m_posY);

		Flip flip;
		flip.v = false;
		flip.h = false;
		m_Entity->GetComponent<Sprite>()->SetSpriteFlip(flip);

		anim->Play("fly", true);

	}
	if (Input()->IsKeyDown((static_cast<int>(EKey::EKEY_UP)))) {
		m_posY -= m_speed * dt;
		m_Entity->SetPosition(m_posX, m_posY);

		anim->Play("fly", true);

	}
	if (Input()->IsKeyDown((static_cast<int>(EKey::EKEY_DOWN)))) {
		m_posY += m_speed * dt;
		m_Entity->SetPosition(m_posX, m_posY);

		anim->Play("fly", true);
	}


	//anim->Stop();
}

void project::Controller::Start()
{
	anim = m_Entity->GetComponent<Animation>();
}

void project::Controller::Destroy()
{
}

void project::Controller::SetSpeedValue(float speed)
{
	m_speed = speed;
}
