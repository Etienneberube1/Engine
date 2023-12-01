#pragma once
#include <Component.h>
#include <IDrawable.h>
#include <Color.h>
#include <Flip.h>
#include <RectI.h>
#include <string>

namespace project {

    // Class representing a drawable sprite.
    class Sprite : public Component, public IDrawable
    {
    public:
        // Destructor.
        virtual ~Sprite() = default;

        // Constructors.
        Sprite();
        Sprite(Entity* parent);

        // Draws the sprite.
        virtual void Draw() override;

        // Loads a texture from a file.
        virtual void Load(const std::string& filename);

        // Sets the color of the sprite.
        void SetColor(const Color& color);

        // Sets the horizontal and vertical flip state of the sprite.
        void SetFlip(bool h, bool v);

        // Gets the horizontal flip state of the sprite.
        bool GetFlipH() const { return m_Flip.h; }

        // Gets the vertical flip state of the sprite.
        bool GetFlipV() const { return m_Flip.v; }

    private:
        // ID of the texture associated with the sprite.
        size_t m_TextureId = 0;

        // Current color of the sprite.
        Color m_Color{ 255, 255, 255, 255 };

        // Flip state of the sprite.
        Flip m_Flip;

    protected:
        // Source rectangle for texture rendering.
        RectI m_Source{ 0, 0, 0, 0 };
    };
}
