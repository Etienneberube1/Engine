#pragma once
#include "IGraphics.h"
#include <map>


struct  SDL_Renderer;
struct SDL_Window;
struct SDL_Texture;
typedef struct _TTF_Font TTF_Font;
struct SDL_Rect;

namespace project {
	class SDLGraphics : public IGraphics {
	public:
		virtual bool Initialize(const char* title, int w, int h) override;
		virtual void Shutdown()override;
		virtual void SetColor(const Color& color) override;
		virtual void Clear() override;
		virtual void Present() override;
		virtual void DrawRect(float x, float y, float w, float h, const Color& color) override;
		virtual void DrawRect(const RectF& rect, const Color& color) override;
		virtual void FillRect(float x, float y, float w, float h, const Color& color) override;
		virtual void FillRect(const RectF& rect, const Color& color) override;
		virtual void DrawLine(float x1, float y1, float x2, float y2, const Color& color) override;
		virtual size_t LoadTexture(const std::string& filename) override;
		virtual void DrawTexture(size_t id, const RectI& src, const RectF& dst, double angle, const Flip& flip, const Color& color) override;
		virtual void DrawTexture(size_t id, const RectF& dst, const Color& color) override;
		virtual void DrawTexture(size_t id, const Color& color) override;
		virtual void GetTextureSize(size_t id, int* w, int* h) override;
		virtual size_t LoadFont(const std::string& filename, int fontSize) override;
		virtual void DrawString(const std::string& text, size_t fontId, float x, float y, float w, float h,const Color& color) override;
		virtual void GetTextSize(const std::string& text, size_t fontId, int* w, int* h) override;
		virtual void LoadTiledSet(const std::string& image, int tileW, int tileH, int col, int count) override;
		virtual void RenderFrame() override;
		virtual void DrawTiles(int tileW, int tileH) override;
		virtual void AddLayer(const std::string& layerName, TLayer* layer) override;

	private:
		SDL_Renderer* _renderer = NULL;
		SDL_Window* _window = NULL;

		std::map<size_t, SDL_Texture*> &_textureCache = *new std::map<size_t, SDL_Texture*>;

		std::map<size_t, TTF_Font*> &_fontCache = *new std::map<size_t, TTF_Font*>;

		SDL_Texture* _textureBuffer = nullptr;

		SDL_Texture* m_TilesetTexture = nullptr;
		TTileset m_Tileset;
		TTilemap m_Tilemap;


		bool m_IsInit = false;
	};
}


