#include "Animation.h"
#include "SDLGraphics.h"

project::Animation::Animation()
{
}

void project::Animation::Draw()
{
}

void project::Animation::Update(float dt)
{

}

void project::Animation::Start()
{
}

void project::Animation::Destroy()
{
}

void project::Animation::InitAnimation(int frameInRows, int frameWidth, int frameHeight)
{
	for (int i = 0; i < frameInRows; i++) {
		m_spriteClips[i].x = i * frameWidth;
		m_spriteClips[i].y = 0;
		m_spriteClips[i].w = 43;
		m_spriteClips[i].h = 64;
	}
}

void project::Animation::AddClip(const std::string& name, int start, int count, float delay)
{
}

void project::Animation::Stop()
{
}

void project::Animation::Play(const std::string& name, bool loop)
{
}


