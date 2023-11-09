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

bool project::BoxCollider::CheckRectCollision(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2)
{
	if (x1 >= (x2 - w2 /2 ) && x1 < (x2 + w2) && y1 >= (y2 - h2 / 2 ) && y1 <= (y2 + h2)) 
	{
		return true;
	}

	return false;
}
