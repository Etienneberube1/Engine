#include "Atlas.h"


namespace project {

	Atlas::Atlas(Entity* entity) : Sprite(entity)
	{

	}

	void Atlas::AddFrame(const std::string& name, int x, int y, int w, int h) {
		m_frames[name] = { x, y, w, h };
	}

	void Atlas::SetFrame(const std::string& name) {
		if (m_frames.find(name) != m_frames.end()) {
			SetSourceRect(m_frames[name]);
		}
	}

}