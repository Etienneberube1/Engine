#include <Animation.h>
#include <Engine.h>

project::Animation::Animation() : Animation(nullptr)
{
}

project::Animation::Animation(Entity* parent) : Atlas(parent)
{
}

void project::Animation::Update(float dt)
{
    if (m_Playing)
    {
        m_Elapsed += dt;
        if (m_Elapsed >= m_Delay)
        {
            m_Elapsed = 0.0f;
            m_CurrentFrame++;
            if (m_CurrentFrame > m_EndFrame)
            {
                m_CurrentFrame = m_StartFrame;
                if (!m_Loop)
                {
                    m_Playing = false;
                }
            }

            UpdateFrame();
        }
    }
}

void project::Animation::Init(int frameInRows, int frameWidth, int frameHeight)
{
    m_FrameInRowCount = frameInRows;
    m_FrameWidth = frameWidth;
    m_FrameHeight = frameHeight;

    m_Source.x = 0;
    m_Source.y = 0;
    m_Source.w = m_FrameWidth;
    m_Source.h = m_FrameHeight;

    m_CurrentClip.clear();
}

void project::Animation::AddClip(const std::string& name, int start, int count, float delay)
{
    m_Clips.emplace(name, AnimationClip{ start, count, delay });
}

void project::Animation::Stop()
{
    m_Playing = false;
    m_CurrentFrame = 0;
    m_StartFrame = 0;
    m_LastFrame = 0;
    m_Delay = 0.0f;
    m_Loop = false;
    m_CurrentClip.clear();
}

void project::Animation::Play(const std::string& name, bool loop)
{
    if (name != m_CurrentClip)
    {
        const AnimationClip _clip = m_Clips[name];
        m_CurrentFrame = _clip.start;
        m_StartFrame = _clip.start;
        m_EndFrame = _clip.start + _clip.count - 1;
        m_Delay = _clip.delay;
        m_Loop = loop;

        m_Elapsed = _clip.delay;
        m_LastFrame = -1;

        UpdateFrame();
        m_Playing = true;
        m_CurrentClip = name;
    }
}

void project::Animation::UpdateFrame()
{
    char temp[128] = { 0 };
    snprintf(temp, 128, "%s%d", m_CurrentClip.c_str(), m_CurrentFrame);
    SetFrame(std::string(temp));
}