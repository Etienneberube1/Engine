#pragma once
#include "Component.h"


struct SDL_Texture;

namespace project {

	class Sprite : public IDrawable, public Component {
	public:
		Sprite(Entity* entity);
		~Sprite() = default;
		void SetSourceRect(const RectI& src);
		virtual size_t LoadTexture(const std::string& filename);
		virtual void Draw() override;
		virtual void SetSpriteValue(const std::string& filename, const RectF& dst, const Color color);
	private:
		size_t m_texture;
		RectF m_dst;
		RectI m_src;
		Color m_color;
	};
}