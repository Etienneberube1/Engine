#include "Animation.h"
#include "SDLGraphics.h"

project::Animation::Animation(Entity* entity) : Component(entity),
isPlaying(false)
{
}

void project::Animation::Draw()
{
}

void project::Animation::Update(float dt)
{
    if (isPlaying) {
        AnimationClip& clip = clips[currentClip];
        clip.accumulator += dt;

        if (clip.accumulator >= clip.frameDelay) {
            clip.accumulator -= clip.frameDelay; // Reset accumulator
            clip.currentFrame++;

            if (clip.currentFrame >= clip.startFrame + clip.frameCount) {
                if (clip.loop) {
                    clip.currentFrame = clip.startFrame; // Loop back to start
                }
                else {
                    Stop(); // Stop if not looping
                }
            }
        }
    }
}

void project::Animation::Start()
{
}

void project::Animation::Destroy()
{
}

void project::Animation::InitAnimation(int frameInRows, int frameWidth, int frameHeight)
{
    rows = frameInRows;
    frameWidth = frameWidth;
    frameHeight = frameHeight;
}

void project::Animation::AddClip(const std::string& name, int start, int count, float delay)
{
	clips[name] = AnimationClip(start, count, delay);
}

void project::Animation::Stop()
{
	isPlaying = false;
}

void project::Animation::Play(const std::string& name, bool loop)
{
	auto it = clips.find(name);
	if (it != clips.end()) {
		currentClip = name;
		isPlaying = true;
		clips[name].loop = loop;
		clips[name].currentFrame = clips[name].startFrame;
		clips[name].accumulator = 0.0f; // Reset the accumulator
	}
}


