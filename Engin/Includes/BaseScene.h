#pragma once
#include <string>

namespace project {

    class Entity;

    class BaseScene
    {
    public:
        virtual ~BaseScene() = default;
        virtual void Load() = 0;

    protected:
        Entity* Instantiate(const std::string& name);
    };
}