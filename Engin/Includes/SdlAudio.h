#include "IAudio.h"
#include <map>

struct Mix_Chunk;
typedef struct _Mix_Music Mix_Music;

namespace project {

    // Class implementing SDL-based audio functionalities.
    class SdlAudio : public IAudio {
    public:
        // Constructor.
        SdlAudio();

        // Destructor.
        virtual ~SdlAudio();

        // Loads a music file and returns its ID.
        virtual size_t LoadMusic(const std::string& filename) override;

        // Loads a sound effect file and returns its ID.
        virtual size_t LoadSound(const std::string& filename) override;

        // Plays a music track by ID.
        virtual void PlayMusic(size_t id) override;

        // Plays a music track by ID with looping options.
        virtual void PlayMusic(size_t id, int loop) override;

        // Plays a sound effect by ID.
        virtual void PlaySFX(size_t id) override;

        // Plays a sound effect by ID with looping options.
        virtual void PlaySFX(size_t id, int loop) override;

        // Pauses the currently playing music.
        virtual void PauseMusic() override;

        // Stops the currently playing music.
        virtual void StopMusic() override;

        // Resumes the currently paused music.
        virtual void ResumeMusic() override;

        // Sets the global volume level.
        virtual void SetVolume(int volume) override;

        // Sets the volume level for a specific sound.
        virtual void SetVolume(size_t soundId, int volume) override;

    private:
        // Type definitions for maps storing chunks and music.
        typedef std::map<size_t, Mix_Chunk*> TChunkMap;
        typedef std::map<size_t, Mix_Music*> TMusicMap;

        // Maps for caching loaded sound effects and music tracks.
        TChunkMap m_SoundCache; // Map of sound effects.
        TMusicMap m_MusicCache; // Map of music tracks.
    };
}
