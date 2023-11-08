#pragma once
#include "Component.h"

namespace project {

	class BoxCollider : public Component,  public IDrawable, public IUpdatable
	{
	public:
		BoxCollider(Entity* entity);
		~BoxCollider() = default;

		virtual void Draw() override;
		virtual void Update(float dt) override;

		virtual void Start() override;
		virtual void Destroy() override;

		virtual bool CheckRectCollision(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2);
	private:
		float m_posX;
		float m_posY;
		float m_widht;
		float m_height;
	};
}
