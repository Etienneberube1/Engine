#pragma once
#include "Component.h"

project::Component::Component(Entity* entity)
    :m_Entity(entity)
{
    
}

project::IAudio* project::Component::Audio() const
{
    return nullptr;
}

project::IInput* project::Component::Input() const
{
    return nullptr;
}

project::IGraphics* project::Component::Graphics() const
{
    return nullptr;
}

project::IILogger* project::Component::Logger() const
{
    return nullptr;
}
