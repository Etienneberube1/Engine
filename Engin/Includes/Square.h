#pragma once
#include "Component.h"

namespace project {

	class Square : public IDrawable, public Component {
	public:
		Square(Entity* entity);
		~Square() = default;

		virtual void Draw() override;
		virtual void Start() override;
		virtual void Destroy() override;
	private:
		float m_X;
		float m_Y;
		float m_W;
		float m_H;
	};
}