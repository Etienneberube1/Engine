#include "Animation.h"
#include "Atlas.h"
#include <string>


namespace project {

	Animation::Animation(Entity* entity) 
		: Component(entity), m_isPlaying(false), m_loop(false), m_timer(0.0f), m_currentClip(nullptr), m_currentFrameIndex(0)
	{
	}

	void Animation::InitAnimation(int frameInRows, int frameWidth, int frameHeight) {
		
		for (int i = 0; i < frameInRows; i++) {
			int x = (i % frameInRows) * frameWidth;
			int y = (i / frameInRows) * frameHeight;
			std::string frameName = "frame_" + std::to_string(i);


			Atlas* atlas = m_Entity->GetComponent<Atlas>();
			if (!atlas) return;
			atlas->AddFrame(frameName, x, y, frameWidth, frameHeight);
		}
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

			std::string frameName = "frame_" + std::to_string(m_currentFrameIndex);

			Atlas* atlas = m_Entity->GetComponent<Atlas>();
			if (!atlas) return;
			atlas->SetFrame(frameName);
		}
	}
	void Animation::AddClip(const std::string& name, int start, int count, float delay) {
		Clip newClip;
		newClip.start = start;
		newClip.count = count;
		newClip.delay = delay;

		m_clips[name] = newClip;
	}

	void Animation::Draw()
	{
		if (m_isPlaying && m_currentClip) {
			// Fetch the Atlas component from the parent entity
			Atlas* atlas = m_Entity->GetComponent<Atlas>();
			if (!atlas) {
				// No Atlas component attached to this entity, can't draw
				return;
			}

			// Set the frame based on the current frame index using the Atlas
			std::string frameName = "frame_" + std::to_string(m_currentFrameIndex);
			atlas->SetFrame(frameName);

			// Call the base Sprite's Draw method to handle the rendering.
			Sprite* sprite = m_Entity->GetComponent<Sprite>();

			if (!sprite) return;
			sprite->Draw();
		}
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
				std::string frameName = "frame_" + std::to_string(m_currentFrameIndex);

				Atlas* atlas = m_Entity->GetComponent<Atlas>();
				if (!atlas) return;
				atlas->SetFrame(frameName);


				m_timer = m_currentClip->delay;
			}
		}
	}
}