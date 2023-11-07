#include "BoxCollider.h"



project::BoxCollider::BoxCollider(Entity* entity) : Component(entity)
{

}

void project::BoxCollider::Draw()
{
	Graphics()->DrawRect(m_posX, m_posY, m_widht, m_height, Color::Green);
}

void project::BoxCollider::Update(float dt)
{
	m_posX = m_Entity->GetPosX();
	m_posY = m_Entity->GetPosY();
	m_widht = m_Entity->GetWidth();
	m_height = m_Entity->GetHeight();


}

void project::BoxCollider::Start()
{
}

void project::BoxCollider::Destroy()
{
}

void project::BoxCollider::CheckRectCollision(float x, float y, float w, float h)
{
	if (m_Entity->GetPosX() <= (x + w) ||
		(m_Entity->GetPosX() + m_Entity->GetWidth()) >= x ||
		m_Entity->GetPosX() <= (y + h) ||
		(m_Entity->GetPosY() + m_Entity->GetHeight()) >= y) 
	{
		std::cout << "Collsion\n";
	}
}
