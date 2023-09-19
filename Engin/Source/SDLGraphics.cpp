#pragma once
#include "SDLGraphics.h"
#include "SDL.h"



static SDL_Renderer* _renderer = NULL;
static SDL_Window* _window = NULL;

namespace project {

	bool SDLGraphics::Initialize(const char* title, int w, int h) {
		if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
			SDL_Log(SDL_GetError());
			return false;
		}
		int _x = SDL_WINDOWPOS_CENTERED;
		int _y = SDL_WINDOWPOS_CENTERED;
		Uint32 _flag = SDL_WINDOW_RESIZABLE;

		_window = SDL_CreateWindow(title, _x, _y, w, h, _flag);
		if (!_window) {
			SDL_Log(SDL_GetError());
			return false;
		}

		_flag = SDL_RENDERER_ACCELERATED;
		_renderer = SDL_CreateRenderer(_window, -1, _flag);
		if (!_renderer) {
			SDL_Log(SDL_GetError());
			return false;
		}

		m_IsInit = true;
		return true;
	}
	void SDLGraphics::Shutdown() {
		SDL_DestroyRenderer(_renderer);
		SDL_DestroyWindow(_window);
		SDL_Quit();
	}
	void SDLGraphics::SetColor(const Color& color) {
		SDL_SetRenderDrawColor(_renderer, color.red, color.green, color.blue, color.alpha);

	}
	void SDLGraphics::Clear() {
		SDL_RenderClear(_renderer);
	}
	void SDLGraphics::Present() {
		SDL_RenderPresent(_renderer);
	}
	void SDLGraphics::DrawRect(float x, float y, float w, float h, const Color& color) {
	
	}
	void SDLGraphics::DrawRect(const RectF& rect, const Color& color) {
	
	}
	void SDLGraphics::FillRect(float x, float y, float w, float h, const Color& color) {
	
	}
	void SDLGraphics::FillRect(const RectF& rect, const Color& color) {
	
	}
	void SDLGraphics::DrawLine(float x1, float y1, float x2, float y2, const Color& color) {
	
	}
	size_t SDLGraphics::LoadTexture(const std::string& filename) {
		return NULL;
	}
	void SDLGraphics::DrawTexture(size_t id, const RectI& src, const RectF& dst, double angle, const Flip& flip, const Color& color) {
	
	}
	void SDLGraphics::DrawTexture(size_t id, const RectF& dst, const Color& color) {
	
	}
	void SDLGraphics::DrawTexture(size_t id, const Color& color) {
	
	}
	void SDLGraphics::GetTextureSize(size_t id, int* w, int* h) {
	
	}
	size_t SDLGraphics::LoadFont(const std::string& filename, int fontSize) {
		return NULL;
	}
	void SDLGraphics::DrawString(const std::string& text, size_t fontId, float x, float y, const Color& color) {
	
	}
	void SDLGraphics::GetTextSize(const std::string& text, size_t fontId, int* w, int* h) {
	
	}
}
