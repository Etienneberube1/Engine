#pragma once
#include <string>
#include <RectI.h>
#include <RectF.h>
#include <Color.h>
#include <Flip.h>

namespace project {

    // Interface for graphics rendering functionalities.
    class IGraphics {
    public:
        // Virtual destructor.
        virtual ~IGraphics() = default;

        // Initializes the graphics system with a window title and dimensions.
        virtual bool Initialize(const std::string& title, int w, int h) = 0;

        // Shuts down the graphics system and releases resources.
        virtual void Shutdown() = 0;

        // Sets the current drawing color.
        virtual void SetColor(uchar r, uchar g, uchar b, uchar a) = 0;
        virtual void SetColor(const Color& color) = 0;

        // Clears the screen with the current drawing color.
        virtual void Clear() = 0;

        // Presents the rendered content to the screen.
        virtual void Present() = 0;

        // Draws a rectangle outline.
        virtual void DrawRect(float x, float y, float w, float h, const Color& color) = 0;
        virtual void DrawRect(const RectF& rect, const Color& color) = 0;

        // Fills a rectangle with color.
        virtual void FillRect(float x, float y, float w, float h, const Color& color) = 0;
        virtual void FillRect(const RectF& rect, const Color& color) = 0;

        // Draws a single point.
        virtual void DrawPoint(float x, float y, const Color& color) = 0;

        // Draws a circle outline.
        virtual void DrawCircle(float x, float y, float r, const Color& color) = 0;

        // Draws a line.
        virtual void DrawLine(float x1, float y1, float x2, float y2, const Color& color) = 0;

        // Loads a texture from a file and returns its ID.
        virtual size_t LoadTexture(const std::string& filename) = 0;

        // Draws a texture with various transformations.
        virtual void DrawTexture(size_t id, const RectI& src, const RectF& dst, double angle, const Flip& flip, const Color& color) = 0;
        virtual void DrawTexture(size_t id, const  RectF& dst, const Color& color) = 0;
        virtual void DrawTexture(size_t id, const Color& color) = 0;

        // Retrieves the dimensions of a texture.
        virtual void GetTextureSize(size_t id, int* w, int* h) = 0;

        // Loads a font from a file and returns its ID.
        virtual size_t LoadFont(const std::string& filename, int fontSize) = 0;

        // Draws text using a specific font.
        virtual void DrawString(const std::string& text, size_t fontId, float x, float y, const Color& color) = 0;

        // Retrieves the dimensions of rendered text.
        virtual void GetTextSize(const std::string& text, size_t fontId, int* w, int* h) = 0;
    };

}
