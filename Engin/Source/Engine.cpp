#pragma once
#include "Engine.h"
#include <time.h>
#include <iostream>

#include "Ilogger.h"
#include "IGraphics.h"
#include "Entity.h"
#include "IWorld.h"
#include "SDLInput.h"
#include "Logs.h"
#include "LogConsole.h"
#include "SDLGraphics.h"

float FPS = 60;
float MS_PER_SEC = 1000 / FPS;

bool project::Engine::Init(const char* name, int w, int h) 
{
#if _DEBUG
	m_Logger = new LogConsole;
	m_Logger->WriteLogText("Engine init");
#elif RELEASE
	m_Logger = new Logs();
	m_Logger->WriteLogText("Engine Initialize");
#endif  
	m_Graphics = new SDLGraphics();
	m_Graphics->Initialize("Game", 800, 800);


	m_Square1 = new Entity("Square1", 100, 100, 100, 100, Color::Green);
	m_Square1->Draw();

	m_Input = new SdlInput();

	m_Graphics->LoadFont("assets/ARCADECLASSIC.TTF", 50);
	
	m_IsInit = true;


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
void project::Engine::LoadTexture()
{
}


void project::Engine::ProcessInput(void)
{
	m_Input->Update();
#if _DEBUG
	if(m_Input->IsKeyDown((static_cast<int>(EKey::EKEY_ESCAPE)))) {
		m_Input->m_IsRunning = false;
	}
#endif
}

void project::Engine::Update(float dt)
{
	m_Square1->Update(dt);
	m_Square1->Draw();
}

void project::Engine::Render(void)
{
	m_Graphics->SetColor(Color::Black);
	m_Graphics->Clear();

	m_Square1->Draw();
	m_Graphics->DrawString("SCORE 100", m_Graphics->LoadFont("assets/ARCADECLASSIC.TTF", 30), 350, 0, 100, 50, Color::Blue);

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
