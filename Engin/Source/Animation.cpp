#include "Animation.h"
#include "Atlas.h"

//project::Animation::Animation()
//	: currentFrameIndex(0), accumulator(0.0f), isPlaying(false)
//{
//   
//}
//
//void project::Animation::AddAnimationClip(const std::string& name, const std::vector<std::string>& frameNames, float frameDuration) {
//    AnimationClip clip;
//    clip.frameDuration = frameDuration;
//
//    Atlas* atlas = m_Entity->GetComponent<Atlas>();
//    if (!atlas) return;
//
//    for (const auto& frameName : frameNames) {
//        RectF frame = atlas->GetFrame(frameName);
//        clip.frames.push_back(frame);
//    }
//
//    animationClips[name] = clip;
//}
//
//void project::Animation::AddFrame(const std::string& animationName, const std::string& frameName, float frameTime)
//{
//	animationClips[animationName].frames.emplace_back(frameName, frameTime);
//}
//
//void project::Animation::SetLoop(const std::string& animationName, bool shouldLoop)
//{
//	animationClips[animationName].loop = shouldLoop;
//}
//
//void project::Animation::Play(const std::string& animationName)
//{
//	currentAnimationName = animationName;
//	isPlaying = true;
//	currentFrameIndex = 0;  // Restart from the first frame
//	accumulator = 0.0f;     // Reset the time accumulator
//}
//
//void project::Animation::Stop()
//{
//	isPlaying = false;
//}
//
//void project::Animation::Update(float deltaTime)
//{
//    if (!isPlaying) return;
//
//    auto it = animationClips.find(currentAnimationName);
//    if (it == animationClips.end()) return;
//
//    auto& currentAnimation = it->second;
//
//    accumulator += deltaTime;
//    if (accumulator >= currentAnimation.frameDuration) {
//        accumulator -= currentAnimation.frameDuration;
//        currentFrameIndex++;
//
//        if (currentFrameIndex >= currentAnimation.frames.size()) {
//            if (currentAnimation.loop) {
//                currentFrameIndex = 0; // Loop to start
//            }
//            else {
//                currentFrameIndex = currentAnimation.frames.size() - 1; // Stay on last frame
//                isPlaying = false; // Stop playing
//            }
//        }
//
//        Atlas* atlas = m_Entity->GetComponent<Atlas>();
//        if (!atlas) return;
//
//        atlas->SetCurrentFrame(currentAnimation.frames[currentFrameIndex]);
//
//    }
//}
//
//void project::Animation::draw()
//{
//    if (!isPlaying) return;
//
//    //const RectF &frameRect = animationClips[currentAnimationName].frames[currentFrameIndex];
//
//    //Graphics()->DrawTexture(Graphics()->LoadTexture("anim_playerFly.png"), frameRect, Color::White);
//}
namespace project {

	Animation::Animation(Entity* entity) : m_isPlaying(false), m_loop(false), m_timer(0.0f), m_currentClip(nullptr), m_currentFrameIndex(0)
	{}

	void Animation::InitAnimation(int frameInRows, int frameWidth, int frameHeight) {
		// TODO: Implement the initialization logic, likely setting up the total frames in the atlas based on rows, width, and height.
	}

	void Animation::AddClip(const std::string& name, int start, int count, float delay) {
		m_clips[name] = { name, start, count, delay };
	}

	void Animation::Stop() {
		m_isPlaying = false;
	}

	void Animation::Play(const std::string& name, bool loop) {
		if (m_clips.find(name) != m_clips.end()) {
			m_isPlaying = true;
			m_loop = loop;
			m_currentClip = &m_clips[name];
			m_currentFrameIndex = m_currentClip->start;
			m_timer = m_currentClip->delay;
			//SetFrame(name); // or based on your frame naming logic
		}
	}

	void Animation::Draw()
	{
	}

	void Animation::Update(float dt) {
		if (m_isPlaying) {
			m_timer -= dt;
			if (m_timer <= 0) {
				m_currentFrameIndex++;
				if (m_currentFrameIndex >= (m_currentClip->start + m_currentClip->count)) {
					if (m_loop) {
						m_currentFrameIndex = m_currentClip->start;
					}
					else {
						Stop();
						return;
					}
				}
				//SetFrame(/* Your frame name logic */);
				m_timer = m_currentClip->delay;
			}
		}
	}

}