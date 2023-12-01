#include <Engine.h>
#include <time.h>
#include <Windows.h>
#include <SdlInput.h>
#include <SdlGraphics.h>
#include <SdlAudio.h>
#include <EKey.h>
#include <WorldService.h>
#include <Physic.h>

#if _DEBUG
#include "ConsoleLogger.h"
#else
#include "FileLogger.h"
#endif

bool project::Engine::Init(const std::string& title, int w, int h)
{
#if _DEBUG
    m_logger = new ConsoleLogger();
#else
    m_logger = new FileLogger("engine.log");
#endif

    m_graphics = new SdlGraphics();
    if (!m_graphics->Initialize(title, w, h))
    {
        m_logger->LogError("Cannot create window");
        return false;
    }

    m_audio = new SdlAudio();
    m_input = new SdlInput();
    m_world = new WorldService();
    m_physics = new Physic();

    m_isInit = true;
    return true;
}

void project::Engine::Start()
{
    if (!m_isInit)
    {
        if (!Init("Balloon Fight", 800, 600))
        {
            return;
        }
    }

    m_isRunning = true;
    clock_t end = clock();
    const int TARGET_FPS = 60;
    const int MS_PER_FRAME = 1000 / TARGET_FPS;

    while (m_isRunning)
    {
        const clock_t start = clock();
        float dt = (start - end) * 0.001f;

        ProcessInput();
        Update(dt);
        Render();

        int restTime = start + MS_PER_FRAME - clock();
        if (restTime > 0)
        {
            Sleep(restTime);
        }

        end = start;
    }

    Shutdown();
}

void project::Engine::Exit()
{
    m_isRunning = false;
}

void project::Engine::ProcessInput()
{
    m_input->Update();

#if _DEBUG
    if (m_input->IsKeyDown(EKey::EKEY_ESCAPE))
    {
        Exit();
    }
#endif
}

void project::Engine::Update(float dt)
{
    m_world->Update(dt);
}

void project::Engine::Render()
{
    m_graphics->SetColor(Color::BLACK);
    m_graphics->Clear();
    m_world->Draw();
    m_graphics->Present();
}

void project::Engine::Shutdown()
{
    if (m_world != nullptr)
    {
        m_world->Shutdown();
        delete m_world;
    }

    if (m_physics != nullptr)
    {
        delete m_physics;
    }

    if (m_input != nullptr)
    {
        delete m_input;
    }

    if (m_audio != nullptr)
    {
        delete m_audio;
    }

    if (m_graphics != nullptr)
    {
        m_graphics->Shutdown();
        delete m_graphics;
    }

    if (m_logger != nullptr)
    {
        delete m_logger;
    }
}
