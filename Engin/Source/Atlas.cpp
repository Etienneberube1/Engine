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
    m_frames.emplace(name, RectI{ x, y, w, h });

    // Automatically set the first frame added as the current frame.
    if (m_frames.size() == 1)
    {
        SetFrame(name);
    }
}

void project::Atlas::SetFrame(const std::string& name)
{
    RectI src = m_frames[name];
    m_Source.x = src.x;
    m_Source.y = src.y;
    m_Source.w = src.w;
    m_Source.h = src.h;
}