#pragma once
#include <string>
#include <IInput.h>
#include <ILogger.h>
#include <IGraphics.h>
#include <IAudio.h>
#include <IWorld.h>
#include <IPhysic.h>

#include "vld.h"
#include "vld_def.h"

namespace project
{
    class Engine final
    {
    public:
        static Engine& Get()
        {
            static Engine _instance;
            return _instance;
        }

        bool Init(const std::string& title, int w, int h);
        void Start();
        void Exit();

    private:
        Engine() = default;

        void ProcessInput();
        void Update(float dt);
        void Render();
        void Shutdown();

    public:
        IInput& Input() const { return *m_Input; }
        ILogger& Logger() const { return *m_Logger; }
        IGraphics& Graphics() const { return *m_Graphics; }
        IAudio& Audio() const { return *m_Audio; }
        IWorld& World() const { return *m_World; }
        IPhysic& Physics() const { return *m_Physics; }

    private:
        bool m_IsRunning = false;
        bool m_IsInit = false;

        IInput* m_Input = nullptr;
        ILogger* m_Logger = nullptr;
        IGraphics* m_Graphics = nullptr;
        IAudio* m_Audio = nullptr;
        IWorld* m_World = nullptr;
        IPhysic* m_Physics = nullptr;
    };
}