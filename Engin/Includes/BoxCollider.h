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

		virtual void CheckRectCollision(float x, float y, float w, float h);
	private:
		float m_posX;
		float m_posY;
		float m_widht;
		float m_height;
	};
}
