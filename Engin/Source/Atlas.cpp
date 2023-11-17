#include <Atlas.h>
#include <Engine.h>

project::Atlas::Atlas() : Atlas(nullptr)
{
}

project::Atlas::Atlas(Entity* parent) : Sprite(parent)
{
}

void project::Atlas::AddFrame(const std::string& name, int x, int y, int w, int h)
{
    m_Frames.emplace(name, RectI{ x, y, w, h });

    if (m_Frames.size() == 1)
    {
        SetFrame(name);
    }
}

void project::Atlas::SetFrame(const std::string& name)
{
    RectI _src = m_Frames[name];
    m_Source.x = _src.x;
    m_Source.y = _src.y;
    m_Source.w = _src.w;
    m_Source.h = _src.h;
}