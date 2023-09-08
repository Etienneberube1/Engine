#include "SDLInput.h"
#include <SDL.h>
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
	_keyStates = SDL_GetKeyboardState(nullptr);
}

bool SdlInput::IsKeyDown(int keycode)
{
	return false;
}

bool SdlInput::IsButtonDown(int button)
{
	return false;
}

void SdlInput::GetMousePosition(int* x, int* y)
{
}
