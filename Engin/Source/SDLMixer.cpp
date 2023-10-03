#include "SDLMixer.h"
#include "SDL_mixer.h"

namespace project {

	size_t SDLMixer::LoadMusic(const std::string& filename)
	{
		size_t musicID = std::hash<std::string>()(filename);
		if (_musicCache.count(musicID) > 0) {
			return musicID;
		}

		Mix_Music* music = Mix_LoadMUS(filename.c_str());
		if (music != nullptr)
		{
			_musicCache[musicID] = music;
			return musicID;
		}
	}

	size_t SDLMixer::LoadSound(const std::string& filename)
	{
		size_t soundID = std::hash<std::string>()(filename);
		if (_soundCache.count(soundID) > 0) {
			return soundID;
		}

		Mix_Chunk* sound = Mix_LoadWAV(filename.c_str());
		if (sound != nullptr)
		{
			_soundCache[soundID] = sound;
			return soundID;
		}

	}

	void SDLMixer::PlayMusic(size_t id)
	{
	}

	void SDLMixer::PlayMusic(size_t id, int loop)
	{
		Mix_Music* music = _musicCache[id];
		Mix_PlayMusic(music, loop);
	}

	void SDLMixer::PlaySFX(size_t id)
	{

	}

	void SDLMixer::PlaySFX(size_t id, int loop)
	{
		Mix_Chunk* sound = _soundCache[id];
		Mix_PlayChannel(-1, sound, loop);
	}

	void SDLMixer::PauseMusic()
	{
	}

	void SDLMixer::StopMusic()
	{
	}

	void SDLMixer::ResumeMusic()
	{
	}

	void SDLMixer::SetVolume(int volume)
	{
	}

	void SDLMixer::SetVolume(size_t soundId, int volume)
	{
	}
}

