#pragma once
#include "Engine.h"
#include "SDLGraphics.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include <SDL_image.h>



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

		TTF_Init();

		m_IsInit = true;

		return true;
	}
	void SDLGraphics::Shutdown() {

		for (auto texture : _textureCache)
		{
			SDL_DestroyTexture(texture.second);
		}
		delete &_textureCache;

		for (auto font : _fontCache)
		{
			TTF_CloseFont(font.second);
		}
		delete &_fontCache;


		SDL_DestroyRenderer(_renderer);
		SDL_DestroyWindow(_window);
		TTF_Quit();
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
		SetColor(color);
		SDL_Rect rect = {x, y, w, h};
		rect.x = x;
		rect.y = y;
		rect.w = w;
		rect.h = h;
		SDL_RenderDrawRect(_renderer, &rect);
	}
	void SDLGraphics::DrawRect(const RectF& rect, const Color& color) {

	}
	void SDLGraphics::FillRect(float x, float y, float w, float h, const Color& color) {
		
	}
	void SDLGraphics::FillRect(const RectF& rect, const Color& color) {
	
	}
	void SDLGraphics::DrawLine(float x1, float y1, float x2, float y2, const Color& color) {
		SDL_RenderDrawLine(_renderer, x1, y1, x2, y2);
	}
	size_t SDLGraphics::LoadTexture(const std::string& filename) {

		size_t textureID = std::hash<std::string>()(filename);
		if (_textureCache.count(textureID) > 0 ) {
			return textureID;
		}

		SDL_Texture* texture = IMG_LoadTexture(_renderer, filename.c_str());
		if(texture != nullptr)
		{
			_textureCache[textureID] = texture;
			return textureID;
		}
	}
	void SDLGraphics::DrawTexture(size_t id, const RectI& src, const RectF& dst, double angle, const Flip& flip, const Color& color) {


	}
	void SDLGraphics::DrawTexture(size_t id, const RectF& dst, const Color& color) {
		
		SDL_Rect rect{ 0 };
		rect.x = dst.x;
		rect.y = dst.y;
		rect.w = dst.w;
		rect.h = dst.h;

		SetColor(color);
		SDL_Texture* texture = _textureCache[id];
		SDL_QueryTexture(texture, nullptr, nullptr, &rect.w, &rect.h);
		SDL_RenderCopyEx(_renderer, texture, nullptr, &rect, 0, nullptr, SDL_FLIP_NONE);

	}
	void SDLGraphics::DrawTexture(size_t id, const Color& color) {
	}
	void SDLGraphics::GetTextureSize(size_t id, int* w, int* h) {
	
	}
	size_t SDLGraphics::LoadFont(const std::string& filename, int fontSize) {
		
		size_t fontID = std::hash<std::string>()(filename);
		
		if (_fontCache.count(fontID) > 0) {
			return fontID;
		}

		TTF_Font* _font = TTF_OpenFont(filename.c_str(), fontSize);
		if (_font != nullptr)
		{
			_fontCache[fontID] = _font;
			return fontID;
		}
		else
		{
			project::IILogger* logger = Engine::Get().Logger();
			logger->WriteLogText("ERROR LOADING FONT");
		}
	}
	void SDLGraphics::DrawString(const std::string& text, size_t fontId, float x, float y,float w, float h,const Color& color) {
		
		SDL_Rect _dst;
		_dst.x = x;
		_dst.y = y;
		_dst.w = w;
		_dst.h = h;

		SDL_Color sdlcolor = {0};
		sdlcolor.r = color.red;
		sdlcolor.g = color.green;
		sdlcolor.b = color.blue;
		sdlcolor.a = color.alpha;

		if (_fontCache.count(fontId) > 0)
		{
			TTF_Font* _font = _fontCache[fontId];
			SDL_Surface* _surface = TTF_RenderText_Solid(_font, text.c_str(), sdlcolor);
			_textureBuffer = SDL_CreateTextureFromSurface(_renderer, _surface);
			SDL_RenderCopy(_renderer, _textureBuffer, nullptr, &_dst);
			SDL_FreeSurface(_surface);
		}

	}
	void SDLGraphics::GetTextSize(const std::string& text, size_t fontId, int* w, int* h) {
	
	}
}
