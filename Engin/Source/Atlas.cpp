#include "Atlas.h"



project::Atlas::Atlas(Entity* entity) : Sprite(entity) {

}

project::Atlas::~Atlas() {
}

void project::Atlas::AddFrame(const std::string& name, int x, int y, int w, int h) {
    frames[name] = RectI{ x, y, w, h };

}

void project::Atlas::SetFrame(const std::string& name) {
    auto it = frames.find(name);
    if (it != frames.end()) {
        currentFrame = it->second;
    }
    // add if frame dosent exist
}