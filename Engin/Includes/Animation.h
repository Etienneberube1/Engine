#pragma once
#include "Component.h"
#include <vector>
#include <map>
#include "Atlas.h"

namespace project {

	struct Clip {
		int start;
		int count;
		float delay;
	};

	class Animation :  public Atlas, public IDrawable, public IUpdatable {
	public:
		Animation(Entity* entity);
		virtual ~Animation() = default;

		void InitAnimation(int frameInRows, int frameWidth, int frameHeight);
		void AddClip(const std::string& name, int start, int count, float delay);
		void Stop();
		void Play(const std::string& name, bool loop);

		virtual void Draw() override;
		virtual void Update(float dt) override; 

	private:
		std::map<std::string, Clip> m_clips;
		bool m_isPlaying;
		bool m_loop;
		float m_timer;
		Clip* m_currentClip;
		int m_currentFrameIndex;
	};

}