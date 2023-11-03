#pragma once
#include "Component.h"


namespace project {

	class Animation : public Component, public IUpdatable, public IDrawable {
	public:
		Animation();
		~Animation() = default;

		virtual void Update(float dt) override;
		virtual void Draw() override;
		virtual void Start() override;
		virtual void Destroy() override;

		void InitAnimation(int frameInRows, int frameWidth, int frameHeight);
		void AddClip(const std::string& name, int start, int count, float delay);
		void Stop();
		void Play(const std::string& name, bool loop);

	private:

		int m_animationFrames;
		int m_currentFrames;
		RectI m_spriteClips[5] = {};
	};
}