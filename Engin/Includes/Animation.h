#pragma once
#include "Atlas.h"
#include <IUpdatable.h>

#include <map>
#include <string>


namespace project
{
    class Entity;

    // Structure representing an animation clip.
    struct AnimationClip
    {
        int start;    // Starting frame of the animation clip.
        int count;    // Number of frames in the animation clip.
        float delay;  // Time delay between frames in the animation clip.
    };

    // Class for handling animations.
    class Animation final : public Atlas, public IUpdatable
    {
    public:
        // Destructor.
        virtual ~Animation() = default;

        // Default constructor.
        Animation();

        // Constructor with an associated entity.
        Animation(Entity* parent);

        // Updates the animation frame based on delta time.
        void Update(float dt) override;

        // Initializes animation with frame dimensions and row count.
        void Init(int frameInRows, int frameWidth, int frameHeight);

        // Adds an animation clip with specified properties.
        void AddClip(const std::string& name, int start, int count, float delay);

        // Stops the current animation.
        void Stop();

        // Plays the specified animation clip, with an option to loop.
        void Play(const std::string& name, bool loop);

    private:

        // Updates the current frame of the animation.
        void UpdateFrame();

        std::map<std::string, AnimationClip> m_clips; // Map of animation clips by name.

        int m_frameInRowCount = 0; // Number of frames in a row.
        int m_frameWidth = 0;      // Width of each frame.
        int m_frameHeight = 0;     // Height of each frame.
        int m_startFrame = 0;      // Starting frame of the current clip.
        int m_endFrame = 0;        // Ending frame of the current clip.
        int m_lastFrame = 0;       // Last frame that was played.
        float m_delay = 0.0f;      // Delay between frames.
        float m_elapsed = 0.0f;    // Elapsed time since last frame update.
        bool m_playing = false;    // Indicates if an animation is currently playing.
        bool m_loop = false;       // Indicates if the current animation should loop.
        int m_currentFrame = 0;    // Current frame being displayed.
        std::string m_currentClip; // Name of the current animation clip being played.
    };
}