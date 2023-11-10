#include "Animation.h"

project::Animation::Animation(Entity* _entity)
	: Component(_entity)
{
	m_Texture = 0;
	m_CurrentFrame = 0;
	m_Loop = false;
	m_isPlaying = false;
	m_Flip = Flip();
	m_Time = 0.0f;
	m_NextFrame = 0;
}

project::Animation::~Animation()
{
	m_Frameset.second.clear(); 
	m_Framemap.clear();
}

void project::Animation::SetPath(const std::string path)
{
	m_Texture = Graphics()->LoadTexture(path);
}

void project::Animation::InitAnimation(int frameInRows, int frameWidth, int frameHeight)
{
	m_FrameInRows = frameInRows;
	m_FrameWidth = frameWidth;
	m_FrameHeight = frameHeight;
}

void project::Animation::AddClip(const std::string& name, int start, int count, int row, float delay)
{
	m_StartFrame = start;
	m_FrameCount = count;
	m_FramesRow = row;
	m_Delay = delay;

	TFrameset newFrameset;
	newFrameset.first = delay;

	const int _y = m_FramesRow;
	for (int i = start; i < start + count; i++)
	{
		const int _x = i;
		RectI _tile(
			_x * m_FrameWidth,
			_y * m_FrameHeight,
			m_FrameWidth,
			m_FrameHeight);
		newFrameset.second.push_back(_tile);
	}

	m_Framemap.emplace(name, newFrameset);
	m_Frameset = newFrameset;
}

void project::Animation::Stop()
{
	m_isPlaying = false;
}

void project::Animation::Play(const std::string& name, bool loop)
{
	m_NextFrame = 1;
	m_Loop = loop;
	m_isPlaying = true;
	m_CurrentFrame = 0;
	m_Time = 0.0f;
	m_Frameset = m_Framemap[name];
}

void project::Animation::Draw()
{
	float x = m_Entity->GetPosX();
	float y = m_Entity->GetPosY();
	float w = m_Entity->GetWidth();
	float h = m_Entity->GetHeight();

	RectF _dst{
		x,
		y,
		w,
		h
	};

	Graphics()->DrawTexture(m_Texture, m_Frameset.second[m_CurrentFrame], _dst, 0.0, m_Flip, Color::White);
}

void project::Animation::Update(float dt)
{
	if (m_isPlaying)
	{
		m_Time += dt;
		if (m_Time > m_Frameset.first)
		{
			m_CurrentFrame += m_NextFrame;
			if (m_CurrentFrame == m_Frameset.second.size() - 1 || m_CurrentFrame == 0)
			{
				m_NextFrame *= -1;
			}
			m_Time = 0.0f;
		}
	}
}