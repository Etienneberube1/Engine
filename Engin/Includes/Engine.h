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
    // Singleton class representing the main engine.
    class Engine final
    {
    public:
        // Returns the singleton instance of the Engine.
        static Engine& Get()
        {
            static Engine instance;
            return instance;
        }

        // Initializes the engine with a window title and dimensions.
        bool Init(const std::string& title, int w, int h);

        // Starts the main loop of the engine.
        void Start();

        // Exits the engine and shuts down all subsystems.
        void Exit();

    private:
        // Default constructor (private for singleton pattern).
        Engine() = default;

        // Processes input from the user or system.
        void ProcessInput();

        // Updates the engine and its subsystems.
        void Update(float dt);

        // Renders the current state to the screen.
        void Render();

        // Shuts down the engine and releases resources.
        void Shutdown();

    public:
        // Accessors for various subsystems.
        IInput& Input() const { return *m_input; }
        ILogger& Logger() const { return *m_logger; }
        IGraphics& Graphics() const { return *m_graphics; }
        IAudio& Audio() const { return *m_audio; }
        IWorld& World() const { return *m_world; }
        IPhysic& Physics() const { return *m_physics; }

    private:
        // Flags to indicate running and initialization status.
        bool m_isRunning = false;
        bool m_isInit = false;

        // Pointers to various subsystem interfaces.
        IInput* m_input = nullptr;
        ILogger* m_logger = nullptr;
        IGraphics* m_graphics = nullptr;
        IAudio* m_audio = nullptr;
        IWorld* m_world = nullptr;
        IPhysic* m_physics = nullptr;
    };
}
