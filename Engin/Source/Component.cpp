#include "Component.h"
#include <Engine.h>

project::Component::Component() : Component(nullptr)
{
}

project::Component::Component(Entity* parent) : m_entity(parent)
{
}

void project::Component::Exit()
{
    Engine::Get().Exit();
}

project::IInput& project::Component::Input() const
{
    return Engine::Get().Input();
}
project::ILogger& project::Component::Logger() const
{
    return Engine::Get().Logger();
}

project::IGraphics& project::Component::Graphics() const
{
    return Engine::Get().Graphics();
}

project::IAudio& project::Component::Audio() const
{
    return Engine::Get().Audio();
}

project::IWorld& project::Component::World() const
{
    return Engine::Get().World();
}