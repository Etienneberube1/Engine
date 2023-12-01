#pragma once
#include <string>

namespace project {

    // Interface for audio functionality in the game engine.
    class IAudio {

    public:
        // Virtual destructor.
        virtual ~IAudio() = default;

        // Loads a music file and returns its ID.
        virtual size_t LoadMusic(const std::string& filename) = 0;

        // Loads a sound effect file and returns its ID.
        virtual size_t LoadSound(const std::string& filename) = 0;

        // Plays a music track by ID.
        virtual void PlayMusic(size_t id) = 0;

        // Plays a music track by ID with looping options.
        virtual void PlayMusic(size_t id, int loop) = 0;

        // Plays a sound effect by ID.
        virtual void PlaySFX(size_t id) = 0;

        // Plays a sound effect by ID with looping options.
        virtual void PlaySFX(size_t id, int loop) = 0;

        // Pauses the currently playing music.
        virtual void PauseMusic() = 0;

        // Stops the currently playing music.
        virtual void StopMusic() = 0;

        // Resumes the currently paused music.
        virtual void ResumeMusic() = 0;

        // Sets the global volume level.
        virtual void SetVolume(int volume) = 0;

        // Sets the volume level for a specific sound.
        virtual void SetVolume(size_t soundId, int volume) = 0;

    };
}
