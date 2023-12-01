#include "Sprite.h"
#include "Engine.h"
#include "Entity.h"

project::Sprite::Sprite() : Sprite(nullptr)
{
}

project::Sprite::Sprite(Entity* parent) : Component(parent)
{
    m_Flip.h = false;
    m_Flip.v = false;
}

void project::Sprite::Draw()
{
    double _rot = m_entity->GetRotation();
    RectF _dst;
    m_entity->GetRect(&_dst);

    Graphics().DrawTexture(m_TextureId, m_Source, _dst, _rot, m_Flip, m_Color);
}

void project::Sprite::Load(const std::string& filename)
{
    m_TextureId = Graphics().LoadTexture(filename);
    Graphics().GetTextureSize(m_TextureId, &m_Source.w, &m_Source.h);
}

void project::Sprite::SetColor(const Color& color)
{
    m_Color.Set(color);
}

void project::Sprite::SetFlip(bool h, bool v)
{
    m_Flip.h = h;
    m_Flip.v = v;
}