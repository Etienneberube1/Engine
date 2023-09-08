
#include "Engine.h"
#include <time.h>
#include "SDLInput.h"


static SDL_Renderer* _renderer = NULL;
static SDL_Window* _window = NULL;
bool project::Engine::Init(const char* name, int w, int h) {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		SDL_Log(SDL_GetError());
		return false;
	}
	int _x = SDL_WINDOWPOS_CENTERED;
	int _y = SDL_WINDOWPOS_CENTERED;
	Uint32 _flag = SDL_WINDOW_RESIZABLE;

	_window = SDL_CreateWindow(name, _x, _y, w, h, _flag);
	if (!_window) {
		SDL_Log(SDL_GetError());
		return false;
	}

	_flag = SDL_RENDERER_ACCELERATED;
	_renderer = SDL_CreateRenderer(_window, -1, _flag);
	if (!_renderer){
		SDL_Log(SDL_GetError());
		return false;
	}

	m_Input = new SdlInput();
	m_IsInit = true;
	return true;
}
void project::Engine::Start(void) {
	if (!m_IsInit) {
		if (!Init("Unknown title", 800, 800)) {
			return;
		}
	}

	m_IsRunning = true;

	clock_t _end = clock();
	while (m_IsRunning) {
		const clock_t _start = clock();
		float dt = (_start - _end)* 0.001f;
		ProcessInput();
		Update(dt);
		Render();

		_end = _start;
	}
	Shutdown();
}
static const Uint8* _keyStates = NULL;

void project::Engine::ProcessInput(void)
{
	Input().Update();
}

static float x = 0.0f;
void project::Engine::Update(float dt)
{
	if (_keyStates[SDL_SCANCODE_D])
	{
		x += 50 * dt;
	}
}

void project::Engine::Render(void)
{
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
	SDL_RenderClear(_renderer);

	SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 255);
	SDL_Rect get_rect = { 0 };
	get_rect.x = x;
	get_rect.y = 100;
	get_rect.h = 100;
	get_rect.w = 100;
	SDL_RenderDrawRect(_renderer, &get_rect);

	SDL_RenderPresent(_renderer);

}

void project::Engine::Shutdown(void)
{
	if (m_Input != nullptr)
	{
		delete m_Input;
	}
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}
