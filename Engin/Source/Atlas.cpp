#include "Atlas.h"
//
//using namespace project;
//
//Atlas::Atlas(Entity* entity) : Sprite(entity) {}
//
//Atlas::~Atlas() = default;
//
//void Atlas::AddFrame(const std::string& name, int x, int y, int w, int h) {
//    RectF rect = { x, y, w, h };
//    frames[name] = rect;
//}
//
//void Atlas::SetCurrentFrame(const RectF& frame) { 
//    currentFrame = frame;
//}
//
//RectF Atlas::GetFrame(const std::string& name) const {
//    auto it = frames.find(name);
//    if (it != frames.end()) {
//        return it->second;
//    }
//    // Handle the case where the frame does not exist.
//    return RectF{}; // Return an empty RectI or throw an exception.
//}

namespace project {

	Atlas::Atlas(Entity* entity) : Sprite(entity)
	{}

	void Atlas::AddFrame(const std::string& name, int x, int y, int w, int h) {
		m_frames[name] = { x, y, w, h };
	}

	void Atlas::SetFrame(const std::string& name) {
		if (m_frames.find(name) != m_frames.end()) {
			// Adjust the source rectangle of the sprite based on the frame's rect
			// TODO: You might want to add a way to set the source rect in Sprite
		}
	}

}