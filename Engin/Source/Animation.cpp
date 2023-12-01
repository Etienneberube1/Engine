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
    if (m_playing)
    {
        m_elapsed += dt;
        if (m_elapsed >= m_delay)
        {
            m_elapsed = 0.0f;
            m_currentFrame++;
            if (m_currentFrame > m_endFrame)
            {
                m_currentFrame = m_startFrame;
                if (!m_loop)
                {
                    m_playing = false;
                }
            }

            UpdateFrame();
        }
    }
}

void project::Animation::Init(int frameInRows, int frameWidth, int frameHeight)
{
    m_frameInRowCount = frameInRows;
    m_frameWidth = frameWidth;
    m_frameHeight = frameHeight;

    m_Source.x = 0;
    m_Source.y = 0;
    m_Source.w = m_frameWidth;
    m_Source.h = m_frameHeight;

    m_currentClip.clear();
}

void project::Animation::AddClip(const std::string& name, int start, int count, float delay)
{
    m_clips.emplace(name, AnimationClip{ start, count, delay });
}

void project::Animation::Stop()
{
    m_playing = false;
    m_currentFrame = 0;
    m_startFrame = 0;
    m_lastFrame = 0;
    m_delay = 0.0f;
    m_loop = false;
    m_currentClip.clear();
}

void project::Animation::Play(const std::string& name, bool loop)
{
    if (name != m_currentClip)
    {
        const AnimationClip _clip = m_clips[name];
        m_currentFrame = _clip.start;
        m_startFrame = _clip.start;
        m_endFrame = _clip.start + _clip.count - 1;
        m_delay = _clip.delay;
        m_loop = loop;

        m_elapsed = _clip.delay;
        m_lastFrame = -1;

        UpdateFrame();
        m_playing = true;
        m_currentClip = name;
    }
}

void project::Animation::UpdateFrame()
{
    char temp[128] = { 0 };
    snprintf(temp, 128, "%s%d", m_currentClip.c_str(), m_currentFrame);
    SetFrame(std::string(temp));
}
