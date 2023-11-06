#pragma once
#include "Component.h"
#include <map>

namespace project {

	class Animation : public Component, public IUpdatable, public IDrawable {
	public:

		struct AnimationClip {
			int startFrame; // The index of the first frame in the clip
			int frameCount; // Number of frames in the clip
			float frameDelay; // Delay between frames
			bool loop; // Should the animation loop
			int currentFrame; // Current frame of the animation
			float accumulator; // Accumulates the time that has passed for frame switching

			AnimationClip(int start, int count, float delay)
				: startFrame(start), frameCount(count), frameDelay(delay),
				loop(false), currentFrame(start), accumulator(0.0f) {}
		};

		Animation(Entity* entity);
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


		std::map<std::string, AnimationClip> clips; // Stores all the animation clips
		std::string currentClip; // The name of the currently playing clip
		bool isPlaying; // Is the animation currently playing?
		int rows;          // Number of frame rows in the sprite sheet
		int frameWidth;    // Width of each frame
		int frameHeight;   // Height of each frame
	};
}