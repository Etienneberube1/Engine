#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include<Windows.h>
#include "Engine.h"


void InitGameplay(void)
{

}
INT WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ PSTR, _In_ INT) {
	project::Engine& engine = project::Engine::Get();
	if (engine.Init("Balloon Fight", 800, 600)) {
		InitGameplay();
		engine.Start();
	}
	return 0;
}