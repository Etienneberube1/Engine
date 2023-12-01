#pragma once

namespace project {

    class Entity;
    class IInput;
    class ILogger;
    class IGraphics;
    class IAudio;
    class IWorld;

    // Base class for components in the project.
    class Component
    {
    public:
        // Virtual destructor.
        virtual ~Component() = default;

        // Default constructor.
        Component();

        // Constructor with an associated entity.
        Component(Entity* parent);

        // Virtual function for initialization logic.
        virtual void Start() {}

        // Virtual function for cleanup logic.
        virtual void Destroy() {}

    protected:
        // Exits the component.
        void Exit();

        // Provides access to input systems.
        IInput& Input() const;

        // Provides access to logging systems.
        ILogger& Logger() const;

        // Provides access to graphics systems.
        IGraphics& Graphics() const;

        // Provides access to audio systems.
        IAudio& Audio() const;

        // Provides access to the world systems.
        IWorld& World() const;

        Entity* m_entity = nullptr; // Pointer to the associated entity.
    };
}