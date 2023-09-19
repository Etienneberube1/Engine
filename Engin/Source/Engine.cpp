#include "SDLGraphics.h"
#include "Engine.h"
#include <time.h>
#include "SDLInput.h"
#include <iostream>
#include "Logs.h"
#include "LogConsole.h"

float FPS = 60;
float MS_PER_SEC = 1000 / FPS;

bool project::Engine::Init(const char* name, int w, int h) 
{
#if _DEBUG
	m_Logger = new LogConsole();
	m_Logger->WriteLogText("Engine init");
#elif RELEASE
	m_Logger = new Logs();
	m_Logger->WriteLogText("Engine Initialize");
#endif  

	m_Graphics = new SDLGraphics;
	m_Graphics->Initialize("Game", 800, 800);

	m_Input = new SdlInput();

	return true;
}

void project::Engine::Start(void) {
	
	if (!m_IsInit) {
		if (!Init("Unknown title", 800, 800)) {
			return;
		}
	}
	clock_t _end = clock();
	while (m_Input->m_IsRunning) {
		const clock_t _start = clock();
		float dt = (_start - _end)* 0.001f;
		float sleepTime = clock() - (_start + MS_PER_SEC);
		
		ProcessInput();
		Update(dt);
		Render();

		_end = _start;

		if (!m_Input->m_IsRunning)
		{
			break;
		}
		if (sleepTime > 0) {
			Sleep(sleepTime);
		}
	}
	Shutdown();
}

//static const Uint8* _keyStates = NULL;

void project::Engine::ProcessInput(void)
{
	m_Input->Update();
}

static float x = 0.0f;
static float y = 0.0f;
void project::Engine::Update(float dt)
{
	if (m_Input->IsKeyDown(static_cast<int>(EKey::EKEY_RIGHT))) {
		x += 100.0f * dt;
	}
	else if (m_Input->IsKeyDown(static_cast<int>(EKey::EKEY_LEFT))) {
		x -= 100.0f * dt;
	}
	else if (m_Input->IsKeyDown(static_cast<int>(EKey::EKEY_DOWN))) {
		y += 100.0f * dt;
	}
	else if (m_Input->IsKeyDown(static_cast<int>(EKey::EKEY_UP))) {
		y -= 100.0f * dt;
	}
}

void project::Engine::Render(void)
{
	m_Graphics->SetColor(Color::Black);
	m_Graphics->Clear();
	m_Graphics->SetColor(Color::Black);
	m_Graphics->Present();
}

void project::Engine::Shutdown(void)
{
	if (m_Input != nullptr)
	{
		delete m_Input;
	}
	m_Graphics->Shutdown();
}
