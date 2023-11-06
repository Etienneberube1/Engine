#pragma once
#include "Component.h"
#include <vector>
#include <map>
#include "IDrawable.h"
#include "IUpdatable.h"


//namespace project {
//
//    class AnimationClip {
//    public:
//        bool loop;
//        float frameDuration;
//        std::vector<RectF> frames;
//    };    
//
//    class Animation : public Component, public IDrawable, IUpdatable{
//    public:
//        Animation();
//
//        void AddAnimationClip(const std::string& name, const std::vector<std::string>& frameNames, float frameDuration);
//        // Add a frame to a specific animation clip
//        void AddFrame(const std::string& animationName, const std::string& frameName, float frameTime);
//
//        // Set whether a specific animation should loop
//        void SetLoop(const std::string& animationName, bool shouldLoop);
//
//        // Start playing an animation by name
//        void Play(const std::string& animationName);
//
//        // Stop the current animation
//        void Stop();
//
//        // Update method to be called every frame with the time elapsed
//        void Update(float deltaTime) ;
//
//        void draw();
//
//    private:
//        std::map<std::string, AnimationClip> animationClips;
//        std::string currentAnimationName;
//        size_t currentFrameIndex;
//        float accumulator; // Time accumulated towards the next frame
//        bool isPlaying;
//    };
//}


namespace project {

	struct Clip {
		std::string name;
		int start;
		int count;
		float delay;
	};

	class Animation :  public IDrawable,public IUpdatable {
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