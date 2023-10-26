#include "Controller.h"
#include "Engine.h"

project::Controller::Controller(Entity* entity) : Component(entity)
{
	m_posX = entity->GetPosX();
	m_posY = entity->GetPosY();
	m_speed = entity->GetSpeed();
}

void project::Controller::Update(float dt)
{
	project::IInput* input = project::Engine::Get().Input();

	//normal movement

	if (input->IsKeyDown((static_cast<int>(EKey::EKEY_RIGHT)))) {
		m_posX -= m_speed * dt;
		m_Entity->SetPosition(m_posX, m_posY);
	}
	else if (input->IsKeyDown((static_cast<int>(EKey::EKEY_LEFT)))) {
		m_posX += m_speed * dt;
		m_Entity->SetPosition(m_posX, m_posY);
	}
	else if (input->IsKeyDown((static_cast<int>(EKey::EKEY_UP)))) {
		m_posY += m_speed * dt;
		m_Entity->SetPosition(m_posX, m_posY);
	}
	else if (input->IsKeyDown((static_cast<int>(EKey::EKEY_DOWN)))) {
		m_posY -= m_speed * dt;
		m_Entity->SetPosition(m_posX, m_posY);
	}

	// diag movement
	if (input->IsKeyDown((static_cast<int>(EKey::EKEY_RIGHT))) && input->IsKeyDown((static_cast<int>(EKey::EKEY_UP)))) {
		m_posX -= m_speed * dt;
		m_posY += m_speed * dt;
		m_Entity->SetPosition(m_posX, m_posY);
	}
	else if (input->IsKeyDown((static_cast<int>(EKey::EKEY_UP))) && input->IsKeyDown((static_cast<int>(EKey::EKEY_LEFT)))) {
		m_posY += m_speed * dt;
		m_posX += m_speed * dt;
		m_Entity->SetPosition(m_posX, m_posY);
	}
	else if (input->IsKeyDown((static_cast<int>(EKey::EKEY_DOWN))) && input->IsKeyDown((static_cast<int>(EKey::EKEY_LEFT)))) {
		m_posY -= m_speed * dt;
		m_posX += m_speed * dt;
		m_Entity->SetPosition(m_posX, m_posY);
	}
	else if (input->IsKeyDown((static_cast<int>(EKey::EKEY_DOWN))) && input->IsKeyDown((static_cast<int>(EKey::EKEY_RIGHT)))) {
		m_posY -= m_speed * dt;
		m_posX -= m_speed * dt;
		m_Entity->SetPosition(m_posX, m_posY);
	}

}

void project::Controller::Start()
{
}

void project::Controller::Destroy()
{
}
