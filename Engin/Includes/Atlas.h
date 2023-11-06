#pragma once
#include "Sprite.h"
#include <map>
#include <string>

//
//namespace project {
//
//
//	class Atlas : public Sprite {
//	public:
//		Atlas(Entity* entity);
//		~Atlas();
//
//		void SetCurrentFrame(const RectF& frame);
//		void AddFrame(const std::string& name, int x, int y, int w, int h);
//		RectF GetFrame(const std::string& name) const;
//
//	private:
//		std::map<std::string, RectF> frames;
//		RectF currentFrame;
//		Atlas* altas;
//	};
//}

namespace project {

	class Atlas : public Sprite {
	public:
		Atlas(Entity* entity);
		virtual ~Atlas() = default;

		void AddFrame(const std::string& name, int x, int y, int w, int h);
		void SetFrame(const std::string& name);
	private:
		std::map<std::string, RectF> m_frames;
	};

}
