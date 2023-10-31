#include "Sprite.h"


project::Sprite::Sprite(Entity* entity) : Component(entity),
	m_color(Color::White)
{

	
}

size_t project::Sprite::LoadTexture(const std::string& filename)
{
	return Graphics()->LoadTexture(filename);
}

void project::Sprite::Draw()
{
	m_dst.x = m_Entity->GetPosX();
	m_dst.y = m_Entity->GetPosY();
	m_dst.w = m_Entity->GetWidth();
	m_dst.h = m_Entity->GetHeight();

	Graphics()->DrawTexture(m_texture, m_dst, m_color);
}

void project::Sprite::SetSpriteValue(const std::string& filename, const RectF& dst, const Color color)
{
	m_texture = LoadTexture(filename);

	m_dst.x = dst.x;
	m_dst.y = dst.y;
	m_dst.w = dst.w;
	m_dst.h = dst.h;

	m_color = color;
}
