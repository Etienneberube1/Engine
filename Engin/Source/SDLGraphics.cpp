#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SdlGraphics.h>
#include <Engine.h>

#include <cmath>


bool project::SdlGraphics::Initialize(const std::string& title, int w, int h)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        const char* _msg = SDL_GetError();
        project::Engine::Get().Logger().LogMessage(_msg);
        return false;
    }

    int _x = SDL_WINDOWPOS_CENTERED;
    int _y = SDL_WINDOWPOS_CENTERED;
    Uint32 _flag = SDL_WINDOW_TOOLTIP;
    m_Window = SDL_CreateWindow(title.c_str(), _x, _y, w, h, _flag);

    if (!m_Window)
    {
        const char* _msg = SDL_GetError();
        project::Engine::Get().Logger().LogMessage(_msg);
        return false;
    }

    _flag = SDL_RENDERER_ACCELERATED;
    m_Renderer = SDL_CreateRenderer(m_Window, -1, _flag);

    if (!m_Renderer)
    {
        const char* _msg = SDL_GetError();
        project::Engine::Get().Logger().LogMessage(_msg);
        return false;
    }

    TTF_Init();

    return true;
}

void project::SdlGraphics::SetColor(uchar r, uchar g, uchar b, uchar a)
{
    SDL_SetRenderDrawColor(m_Renderer, r, g, b, a);
}

void project::SdlGraphics::SetColor(const Color& color)
{
    SetColor(color.red, color.green, color.blue, color.alpha);
}

void project::SdlGraphics::Clear()
{
    SDL_RenderClear(m_Renderer);
}

void project::SdlGraphics::Present()
{
    SDL_RenderPresent(m_Renderer);
}

void project::SdlGraphics::DrawRect(float x, float y, float w, float h, const Color& color)
{
    SDL_Rect _rect = {
        static_cast<int>(x),
        static_cast<int>(y),
        static_cast<int>(w),
        static_cast<int>(h) };

    SetColor(color);

    SDL_RenderDrawRect(m_Renderer, &_rect);
}

void project::SdlGraphics::DrawRect(const RectF& rect, const Color& color)
{
    DrawRect(rect.x, rect.y, rect.w, rect.h, color);
}

void project::SdlGraphics::FillRect(float x, float y, float w, float h, const Color& color)
{
    SDL_Rect _rect = {
        static_cast<int>(x),
        static_cast<int>(y),
    static_cast<int>(w),
    static_cast<int>(h) };

    SetColor(color);

    SDL_RenderFillRect(m_Renderer, &_rect);
}

void project::SdlGraphics::FillRect(const RectF& rect, const Color& color)
{
    FillRect(rect.x, rect.y, rect.w, rect.h, color);
}

void project::SdlGraphics::DrawCircle(float x, float y, float r, const Color& color)
{
    float tx = x;
    float ty = y;
    double angle = 0.0;

    while (angle < 6.3)
    {
        tx = static_cast<float>(x + r * cos(angle));
        ty = static_cast<float>(y + r * sin(angle));
        DrawPoint(tx, ty, color);

        angle += 0.01;
    }
}

void project::SdlGraphics::DrawPoint(float x, float y, const Color& color)
{
    const int _x = static_cast<int>(x);
    const int _y = static_cast<int>(y);
    SDL_SetRenderDrawColor(m_Renderer,
        color.red, color.green, color.blue, color.alpha);

    SDL_RenderDrawPoint(m_Renderer, _x, _y);
}

void project::SdlGraphics::DrawLine(float x1, float y1, float x2, float y2, const Color& color)
{
    SetColor(color);
    SDL_RenderDrawLine(m_Renderer,
        static_cast<int>(x1),
        static_cast<int>(y1),
        static_cast<int>(x2),
        static_cast<int>(y2));
}

size_t project::SdlGraphics::LoadTexture(const std::string& filename)
{
    const size_t _texId = std::hash<std::string>()(filename);
    if (m_TextureCache.count(_texId) > 0)
    {
        return _texId;
    }

    SDL_Texture* _texture = IMG_LoadTexture(m_Renderer, filename.c_str());
    if (_texture)
    {
        m_TextureCache.emplace(_texId, _texture);
        return _texId;
    }

    project::Engine::Get().Logger().LogMessage("Error with texture: " + filename);
    return 0;
}

void project::SdlGraphics::DrawTexture(size_t id, const RectI& src, const RectF& dst, double angle, const Flip& flip, const Color& color)
{
    SDL_Rect _src = {
    static_cast<int>(src.x),
    static_cast<int>(src.y),
    static_cast<int>(src.w),
    static_cast<int>(src.h) };

    SDL_Rect _dst = {
    static_cast<int>(dst.x),
    static_cast<int>(dst.y),
    static_cast<int>(dst.w),
    static_cast<int>(dst.h) };

    int _flip = SDL_FLIP_NONE;
    if (flip.h)
    {
        _flip = SDL_FLIP_HORIZONTAL;
    }

    if (flip.v)
    {
        _flip |= SDL_FLIP_VERTICAL;
    }

    const SDL_RendererFlip _rf = static_cast<SDL_RendererFlip>(_flip);

    SetColorMode(id, color);
    SDL_RenderCopyEx(m_Renderer, m_TextureCache[id], &_src, &_dst, angle, nullptr, _rf);
}

void project::SdlGraphics::DrawTexture(size_t id, const RectF& dst, const Color& color)
{
    SDL_Rect _dst = {
        static_cast<int>(dst.x),
        static_cast<int>(dst.y),
        static_cast<int>(dst.w),
        static_cast<int>(dst.h) };

    SetColorMode(id, color);
    SDL_RenderCopy(m_Renderer, m_TextureCache[id], nullptr, &_dst);
}

void project::SdlGraphics::DrawTexture(size_t id, const Color& color)
{
    SetColorMode(id, color);
    SDL_RenderCopy(m_Renderer, m_TextureCache[id], nullptr, nullptr);
}

void project::SdlGraphics::GetTextureSize(size_t id, int* w, int* h)
{
    if (m_TextureCache.count(id) > 0)
    {
        SDL_QueryTexture(m_TextureCache[id], nullptr, nullptr, w, h);
    }
    else
    {
        *w = 0;
        *h = 0;
    }
}

size_t project::SdlGraphics::LoadFont(const std::string& filename, int fontSize)
{
    const size_t _fntId = std::hash<std::string>()(filename);
    if (m_FontCache.count(_fntId) > 0)
    {
        return _fntId;
    }

    TTF_Font* _font = TTF_OpenFont(filename.c_str(), fontSize);
    if (_font)
    {
        m_FontCache.emplace(_fntId, _font);
        return _fntId;
    }

    project::Engine::Get().Logger().LogMessage("Error with font: " + filename);
    return 0;
}

SDL_Texture* g_TextureBuffer;

void project::SdlGraphics::DrawString(const std::string& text, size_t fontId, float x, float y, const Color& color)
{
    const SDL_Color _color = {
        static_cast<Uint8>(color.red),
        static_cast<Uint8>(color.green),
        static_cast<Uint8>(color.blue),
        static_cast<Uint8>(color.alpha)
    };

    SDL_Surface* _surface = TTF_RenderText_Solid(m_FontCache[fontId],text.c_str(), _color);

    SDL_Rect _dst = {
        static_cast<int>(x),
        static_cast<int>(y),
        _surface->w,
        _surface->h
    };

    g_TextureBuffer = SDL_CreateTextureFromSurface(m_Renderer, _surface);
    SDL_RenderCopy(m_Renderer, g_TextureBuffer, nullptr, &_dst);
    SDL_FreeSurface(_surface);
    SDL_DestroyTexture(g_TextureBuffer);
}

void project::SdlGraphics::GetTextSize(const std::string& text, size_t fontId, int* w, int* h)
{
    if (m_FontCache.count(fontId) > 0)
    {
        TTF_SizeText(m_FontCache[fontId], text.c_str(), w, h);
    }
    else
    {
        *w = 0;
        *h = 0;
    }
}

void project::SdlGraphics::SetColorMode(size_t id, const Color& color)
{
    SDL_Texture* _tex = m_TextureCache[id];
    SDL_SetTextureBlendMode(_tex, SDL_BLENDMODE_BLEND);
    SDL_SetTextureAlphaMod(_tex, color.alpha);
    SDL_SetTextureColorMod(_tex, color.red, color.green, color.blue);
}

void project::SdlGraphics::Shutdown()
{
    TTF_Quit();
    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(m_Window);

    m_FontCache.clear();
    m_TextureCache.clear();

    SDL_Quit();
}