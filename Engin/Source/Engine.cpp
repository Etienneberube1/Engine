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
#include "SDL_mixer.h"
#include "SDLMixer.h"
//#include "vld.h"



#include "BaseScene.h"
#include "MenuScene.h"

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


	m_Audio = new SDLMixer();

	m_Input = new SdlInput();

	LoadAudio();


	// open the audio
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);


	// SCENE
	m_World = new WorldService();
	

	m_menuScene = new MenuScene();
	m_World->Register("MenuScene", m_menuScene);

	m_baseScene = new BaseScene();
	m_World->Register("BaseScene", m_baseScene);


	m_IsInit = true;

	return true;
}

void project::Engine::Start(void) {
	
	m_World->Load("MenuScene");
	std::cout << "loaded scene" << std::endl;

	m_Audio->PlayMusic(m_Audio->LoadMusic("assets/audio/soundtrack.mp3"),0);


	if (!m_IsInit) {
		if (!Init("Unknown title", 800, 800)) {
			return;
		}
	}
	clock_t _end = clock();
	while (m_Input->m_IsRunning) {
		const clock_t _start = clock();
		float dt = (_end - _start)* 0.001f;
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

void project::Engine::LoadAudio()
{
	m_Audio->LoadMusic("assets/audio/soundtrack.mp3");
	m_Audio->LoadSound("assets/audio/clicksound.wav");
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
	m_World->Update(dt);
	if (m_Input->IsKeyDown((static_cast<int>(EKey::EKEY_SPACE)))) {
		std::cout << "loaded scene" << std::endl;
		m_World->Load("BaseScene");
	}
}

void project::Engine::Render(void)
{
	m_Graphics->SetColor(Color::Black);
	m_Graphics->Clear();

	m_World->Draw();

	m_Graphics->DrawString("Press space to play sound", m_Graphics->LoadFont("assets/ARCADECLASSIC.TTF", 30), 100, 0, 600, 50, Color::Blue);

	m_Graphics->Present();

}

void project::Engine::Shutdown(void)
{
	if (m_Input != nullptr) {
		delete m_Input;
	}
	if (m_Audio != nullptr) {
		m_Audio->ShutDown();
		delete m_Audio;
	}
	if (m_Logger != nullptr) {
		delete m_Logger;
	}
	//if (m_World != nullptr) {
	//	delete m_World;
	//}

	m_Graphics->Shutdown();
	if (m_Graphics != nullptr) {
		delete m_Graphics;
		m_Graphics = nullptr;
	}
}
