#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include<Windows.h>
#include "Engine.h"

#include "WorldService.h"
#include "MenuScene.h"

void InitGameplay(void)
{
	project::MenuScene* menu = new project::MenuScene();

	project::Engine::Get().World().Register("menu", menu);

	project::Engine::Get().World().Load("menu");
}


INT WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ PSTR, _In_ INT) {
	project::Engine& engine = project::Engine::Get();
	if (engine.Init("Balloon Fight", 800, 600)) {
		InitGameplay();
		engine.Start();
	}
	return 0;
}