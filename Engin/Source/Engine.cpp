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
    m_Logger = new ConsoleLogger();
#else
    m_Logger = new FileLogger("engine.log");
#endif

    m_Graphics = new SdlGraphics();
    if (!m_Graphics->Initialize(title, w, h))
    {
        m_Logger->LogError("Cannot create window");
        return false;
    }

    m_Audio = new SdlAudio();
    m_Input = new SdlInput();
    m_World = new WorldService();
    m_Physics = new Physic();

    m_IsInit = true;
    return true;
}

void project::Engine::Start()
{
    if (!m_IsInit)
    {
        if (!Init("Balloon Fight", 800, 600))
        {
            return;
        }
    }

    m_IsRunning = true;
    clock_t _end = clock();
    const int TARGET_FPS = 60;
    const int MS_PER_FRAME = 1000 / TARGET_FPS;

    while (m_IsRunning)
    {
        const clock_t _start = clock();
        float _dt = (_start - _end) * 0.001f;

        ProcessInput();
        Update(_dt);
        Render();

        int _restTime = _start + MS_PER_FRAME - clock();
        if (_restTime > 0)
        {
            Sleep(_restTime);
        }

        _end = _start;
    }

    Shutdown();
}

void project::Engine::Exit()
{
    m_IsRunning = false;
}

void project::Engine::ProcessInput()
{
    m_Input->Update();

#if _DEBUG
    if (m_Input->IsKeyDown(EKey::EKEY_ESCAPE))
    {
        Exit();
    }
#endif
}

void project::Engine::Update(float dt)
{
    m_World->Update(dt);
}

void project::Engine::Render()
{
    m_Graphics->SetColor(Color::CORNFLOWERBLUE);
    m_Graphics->Clear();
    m_World->Draw();
    m_Graphics->Present();
}

void project::Engine::Shutdown()
{
    if (m_World != nullptr)
    {
        m_World->Shutdown();
        delete m_World;
    }

    if (m_Physics != nullptr)
    {
        delete m_Physics;
    }

    if (m_Input != nullptr)
    {
        delete m_Input;
    }

    if (m_Audio != nullptr)
    {
        delete m_Audio;
    }

    if (m_Graphics != nullptr)
    {
        m_Graphics->Shutdown();
        delete m_Graphics;
    }

    if (m_Logger != nullptr)
    {
        delete m_Logger;
    }
}