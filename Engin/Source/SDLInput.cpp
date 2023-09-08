#include "SDLInput.h"
#include <SDL.h>

using namespace project;

void SdlInput::Update()
{
	SDL_Event _event;
	while (SDL_PollEvent(&_event))
	{
		switch (_event.type)
		{
		case SDL_QUIT:
			m_IsRunning = false;
			break;
		}
	}
	m_KeyStates = SDL_GetKeyboardState(nullptr);
}

bool SdlInput::IsKeyDown(int keycode)
{
	return m_KeyStates[static_cast<int>(keycode)];
}

bool SdlInput::IsButtonDown(int button)
{
	return false;
}

void SdlInput::GetMousePosition(int* x, int* y)
{
}
