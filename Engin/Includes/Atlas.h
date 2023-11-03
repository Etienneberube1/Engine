#pragma once
#include "Sprite.h"


namespace project {


	class Atlas : public Sprite {
	public:
		Atlas(Entity* entity);
		~Atlas() = default;

		void AddFrame(const std::string& name, int x, int y, int w, int h);
		void SetFrame(const std::string& name);
	private:
		std::map<const std::string&, SDL_Texture*>& _textureCache = *new std::map<const std::string&, SDL_Texture*>;

	};
}