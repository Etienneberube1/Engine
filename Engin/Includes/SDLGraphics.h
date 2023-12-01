#pragma once
#include <IGraphics.h>
#include <map>

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Texture;
typedef struct _TTF_Font TTF_Font;

namespace project
{
    // Class implementing SDL-based graphics functionalities.
    class SdlGraphics : public IGraphics
    {
    public:
        // Destructor.
        virtual ~SdlGraphics() = default;

        // Initializes the SDL graphics system with a window title and dimensions.
        virtual bool Initialize(const std::string& title, int w, int h) override;

        // Shuts down the SDL graphics system and releases resources.
        virtual void Shutdown() override;

        // Sets the current drawing color.
        virtual void SetColor(uchar r, uchar g, uchar b, uchar a) override;
        virtual void SetColor(const Color& color) override;

        // Clears the screen with the current drawing color.
        virtual void Clear() override;

        // Presents the rendered content to the screen.
        virtual void Present() override;

        // Draws and fills rectangles, points, circles, and lines with specified colors.
        virtual void DrawRect(float x, float y, float w, float h, const Color& color) override;
        virtual void DrawRect(const RectF& rect, const Color& color) override;
        virtual void FillRect(float x, float y, float w, float h, const Color& color) override;
        virtual void FillRect(const RectF& rect, const Color& color) override;
        virtual void DrawPoint(float x, float y, const Color& color) override;
        virtual void DrawCircle(float x, float y, float r, const Color& color) override;
        virtual void DrawLine(float x1, float y1, float x2, float y2, const Color& color) override;

        // Loads textures and fonts, and provides methods for drawing them.
        virtual size_t LoadTexture(const std::string& filename) override;
        virtual void DrawTexture(size_t id, const RectI& src, const RectF& dst, double angle, const Flip& flip, const Color& color) override;
        virtual void DrawTexture(size_t id, const RectF& dst, const Color& color) override;
        virtual void DrawTexture(size_t id, const Color& color) override;
        virtual void GetTextureSize(size_t id, int* w, int* h) override;
        virtual size_t LoadFont(const std::string& filename, int fontSize) override;
        virtual void DrawString(const std::string& text, size_t fontId, float x, float y, const Color& color) override;
        virtual void GetTextSize(const std::string& text, size_t fontId, int* w, int* h) override;

    private:
        // Helper method to set the color mode for textures.
        void SetColorMode(size_t id, const Color& color);

        // SDL-specific members for window and rendering.
        SDL_Window* m_Window;     // SDL window.
        SDL_Renderer* m_Renderer; // SDL renderer.

        // Maps for caching loaded textures and fonts.
        typedef std::map<size_t, SDL_Texture*> TTextureMap;
        typedef std::map<size_t, TTF_Font*> TFontMap;

        TTextureMap m_TextureCache; // Map of textures.
        TFontMap m_FontCache;       // Map of fonts.
    };
}
