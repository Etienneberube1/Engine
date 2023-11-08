#pragma once
#include "Component.h"
#include "Engine.h"

project::Component::Component(Entity* entity)
    :m_Entity(entity)
{
    
}

project::IWorld* project::Component::World() const
{
    return project::Engine::Get().World();
}

project::IAudio* project::Component::Audio() const
{
    return project::Engine::Get().Audio();
}

project::IInput* project::Component::Input() const
{
    return project::Engine::Get().Input();
}

project::IGraphics* project::Component::Graphics() const
{
    return project::Engine::Get().Graphics();
}

project::IILogger* project::Component::Logger() const
{
    return project::Engine::Get().Logger();
}

