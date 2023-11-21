#include "Controller.h"
#include "Engine.h"
#include "Sprite.h"
#include "EKey.h"
#include "Entity.h"


#include <iostream>

project::Controller::Controller(Entity* entity) : Component(entity)
{
	m_posX = m_Entity->GetX();
	m_posY = m_Entity->GetY();
}

void project::Controller::Update(float dt)
{
	if (Input().IsKeyDown(EKey::EKEY_D)) {
		m_posX += m_speed * dt;


		m_Entity->GetComponent<Sprite>()->SetFlip(true, false);

		m_Entity->SetPosition(m_posX, m_posY);
	}
	if (Input().IsKeyDown(EKey::EKEY_A)) {
		m_posX -= m_speed * dt;


		m_Entity->GetComponent<Sprite>()->SetFlip(false, false);

		m_Entity->SetPosition(m_posX, m_posY);
	}
	if (Input().IsKeyDown(EKey::EKEY_W)) {
		m_posY -= m_speed * dt;

		m_Entity->SetPosition(m_posX, m_posY);

	}
	if (Input().IsKeyDown(EKey::EKEY_S)) {
		m_posY += m_speed * dt;

		m_Entity->SetPosition(m_posX, m_posY);
	}

	 std::cout << "posX: " << m_posX << "  " << "posY: " << m_posY << std::endl;
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