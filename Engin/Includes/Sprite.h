#pragma once
#include <Component.h>
#include <IDrawable.h>
#include <Color.h>
#include <Flip.h>
#include <RectI.h>
#include <string>


namespace project {

    class Sprite : public Component, public IDrawable
    {
    public:
        virtual ~Sprite() = default;
        Sprite();
        Sprite(Entity* parent);

        virtual void Draw() override;
        virtual void Load(const std::string& filename);

        void SetColor(const Color& color);
        void SetFlip(bool h, bool v);
        bool GetFlipH() const { return m_Flip.h; }
        bool GetFlipV() const { return m_Flip.v; }

    private:
        size_t m_TextureId = 0;
        Color m_Color{ 255, 255, 255, 255 };
        Flip m_Flip;

    protected:
        RectI m_Source{ 0, 0, 0, 0 };
    };
}