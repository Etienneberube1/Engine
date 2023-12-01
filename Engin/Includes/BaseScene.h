#pragma once
#include <string>

namespace project {

    class Entity;

    // Abstract base class for scenes in the project.
    class BaseScene
    {
    public:
        // Virtual destructor.
        virtual ~BaseScene() = default;

        // Pure virtual function to load the scene.
        virtual void Load() = 0;

    protected:
        // Instantiates an entity with the given name.
        Entity* Instantiate(const std::string& name);
    };
}