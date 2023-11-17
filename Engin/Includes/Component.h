#pragma once


namespace project {

    class Entity;
    class IInput;
    class ILogger;
    class IGraphics;
    class IAudio;
    class IWorld;

    class Component
    {
    public:
        virtual ~Component() = default;
        Component();
        Component(Entity* parent);

        virtual void Start() {}
        virtual void Destroy() {}

    protected:
        void Exit();
        IInput& Input() const;
        ILogger& Logger() const;
        IGraphics& Graphics() const;
        IAudio& Audio() const;
        IWorld& World() const;

        Entity* m_Entity = nullptr;
    };
}




