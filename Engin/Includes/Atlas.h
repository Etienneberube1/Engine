#pragma once
#include "Sprite.h"
#include <map>
#include <string>

namespace project {


	class Atlas : public Sprite {
	public:
		Atlas(Entity* entity);
		~Atlas() = default;

		void AddFrame(const std::string& name, int x, int y, int w, int h);
		void SetFrame(const std::string& name);
	private:
		std::map<const std::string&, RectI>& frames = *new std::map<const std::string&, RectI>;
		RectI currentFrame;
	};
}