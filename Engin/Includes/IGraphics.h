#pragma once

#include <string>
#include "Color.h"
#include <vector>
#include <map>

namespace project {

	struct RectI
	{
		RectI() : RectI(0, 0, 0, 0) {}
		RectI(float x, float y, float w, float h) : RectI(static_cast<int>(x), static_cast<int>(y), static_cast<int>(w), static_cast<int>(h)) {}
		RectI(int _x, int _y, int _w, int _h) : x(_x), y(_y), w(_w), h(_h) {}

		int x;
		int y;
		int w;
		int h;

		bool operator==(const RectI& other) const {
			return x == other.x && y == other.y && w == other.w && h == other.h;

		};
	};

	struct RectF
	{
		RectF() :RectF(0, 0, 0, 0) {}
		RectF(int x, int y, int w, int h) : RectF(static_cast<float>(x), static_cast<float>(y), static_cast<float>(w), static_cast<float>(h)) {}
		RectF(float _x, float _y, float _w, float _h) : x(_x), y(_y), w(_w), h(_h) {}
		float x;
		float y;
		float w;
		float h;
	};
	struct Flip
	{
		bool h;
		bool v;
	};

	typedef std::vector<std::vector<int>> TLayer;
	typedef std::map<std::string, TLayer> TTilemap;
	typedef std::vector<RectI> TTileset;

	class IGraphics {
	public:
		virtual ~IGraphics() = default;

		virtual bool Initialize(const char* title, int w, int h) = 0;
		virtual void Shutdown() = 0;
		virtual void SetColor(const Color& color) = 0;
		virtual void Clear() = 0;
		virtual void Present() = 0;
		virtual void DrawRect(float x, float y, float w, float h, const Color& color) = 0;
		virtual void DrawRect(const RectF& rect, const Color& color) = 0;
		virtual void FillRect(float x, float y, float w, float h, const Color& color) = 0;
		virtual void FillRect(const RectF& rect, const Color& color) = 0;
		virtual void DrawLine(float x1, float y1, float x2, float y2, const Color& color) = 0;
		virtual size_t LoadTexture(const std::string& filename) = 0;
		virtual void DrawTexture(size_t id, const RectI& src, const RectF& dst, double angle, const Flip& flip, const Color& color) = 0;
		virtual void DrawTexture(size_t id, const RectF& dst, const Color& color) = 0;
		virtual void DrawTexture(size_t id, const Color& color) = 0;
		virtual void GetTextureSize(size_t id, int* w, int* h) = 0;
		virtual size_t LoadFont(const std::string& filename, int fontSize) = 0;
		virtual void DrawString(const std::string& text, size_t fontId, float x, float y, float w, float h, const Color& color) = 0;
		virtual void GetTextSize(const std::string& text, size_t fontId, int* w, int* h) = 0;
		virtual void LoadTiledSet(const std::string& image, int tileW, int tileH, int col, int count) = 0;
		virtual void RenderFrame() = 0;
		virtual void DrawTiles(int tileW, int tileH) = 0;
		virtual void AddLayer(const std::string& layerName, TLayer* layer) = 0;
	};

}
