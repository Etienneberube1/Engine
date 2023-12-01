#pragma once
#include <Sprite.h>
#include <map>
#include <string>
#include <RectI.h>

namespace project
{
    class Entity;

    // Class for handling a collection of frames (sprites) as an atlas.
    class Atlas : public Sprite
    {
    public:
        // Destructor.
        virtual ~Atlas() = default;

        // Default constructor.
        Atlas();

        // Constructor with an associated entity.
        Atlas(Entity* parent);

        // Adds a frame to the atlas with specified properties.
        void AddFrame(const std::string& name, int x, int y, int w, int h);

        // Sets the current frame of the atlas to the specified frame.
        void SetFrame(const std::string& name);

    private:
        std::map<std::string, RectI> m_frames; // Map of frame names to their RectI specifications.
    };
}