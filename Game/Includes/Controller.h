#pragma once
#include "Component.h"
#include "IUpdatable.h"

namespace project {

	class Controller : public IUpdatable, public Component {

	public:
		Controller(Entity* entity);
		~Controller() = default;

		virtual void Update(float dt) override;
		virtual void Start() override;
		virtual void Destroy() override;
		virtual void SetSpeedValue(float speed);
		void ChangeFlip(bool h, bool v);
		void ChangeAnim();

		void SetOnGroundBool(bool isOnGround)
		{
			m_isOnGround = isOnGround;
		}

	private:
		float m_posX;
		float m_posY;
		float m_speed;

		bool m_isFlying;
		bool m_isMoving;
		bool m_isOnGround;
	};
}