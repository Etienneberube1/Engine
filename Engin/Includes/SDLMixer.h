#include "IAudio.h"
#include <map>

struct Mix_Chunk;
typedef struct _Mix_Music Mix_Music;
namespace project {
	



	class SDLMixer : public IAudio {
	public:
		virtual void ShutDown() override;
		virtual size_t LoadMusic(const std::string& filename) override;
		virtual size_t LoadSound(const std::string& filename) override;
		virtual void PlayMusic(size_t id)  override;
		virtual void PlayMusic(size_t id, int loop)  override;
		virtual void PlaySFX(size_t id)  override;
		virtual void PlaySFX(size_t id, int loop) override;
		virtual void PauseMusic() override;
		virtual void StopMusic()  override;
		virtual void ResumeMusic()  override;
		virtual void SetVolume(int volume)  override;
		virtual void SetVolume(size_t soundId, int volume)  override;
	private:
		std::map<size_t, Mix_Chunk*> &_soundCache = *new std::map<size_t, Mix_Chunk*>;
		std::map<size_t, Mix_Music*> &_musicCache = *new std::map<size_t, Mix_Music*>;

	};
}
