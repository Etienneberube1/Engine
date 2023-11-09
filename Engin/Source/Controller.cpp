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

		m_Entity->GetComponent<Animation>()->SetFlip(false, true);
		//m_Entity->GetComponent<Animation>()->Play("fly", true);
	}
	if (Input()->IsKeyDown((static_cast<int>(EKey::EKEY_LEFT)))) {
		m_posX -= m_speed * dt;
		m_Entity->SetPosition(m_posX, m_posY);


		m_Entity->GetComponent<Animation>()->SetFlip(false, false);
		//m_Entity->GetComponent<Animation>()->Play("fly", true);


	}
	if (Input()->IsKeyDown((static_cast<int>(EKey::EKEY_UP)))) {
		m_posY -= m_speed * dt;
		m_Entity->SetPosition(m_posX, m_posY);

		//m_Entity->GetComponent<Animation>()->Play("fly", true);


	}
	if (Input()->IsKeyDown((static_cast<int>(EKey::EKEY_DOWN)))) {
		m_posY += m_speed * dt;
		m_Entity->SetPosition(m_posX, m_posY);

		//m_Entity->GetComponent<Animation>()->Play("fly", true);
	}

	//m_Entity->GetComponent<Animation>()->Play("idle", true);
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
