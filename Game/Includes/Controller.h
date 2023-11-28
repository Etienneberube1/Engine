#pragma once
#include "Component.h"
#include "IUpdatable.h"
#include "Subject.h"


namespace project {

	class Animation;
	class RigidBody;


	class Controller : public IUpdatable, public Component {

	public:
		Controller(Entity* entity);
		~Controller() = default;

		virtual void Update(float dt) override;
		virtual void Start() override;
		virtual void Destroy() override;

		virtual void SetSpeedValue(float speed) { m_speed = speed; };

		void HandleWorldBoundaries(RigidBody* rb);

		void TakeDamage();

		void CheckEnemyCol();

		void SetOnGroundBool(bool isOnGround)
		{
			m_isOnGround = isOnGround;
		}


		Subject<int> OnScoreChanged;

	private:

		float m_posX;
		float m_posY;
		float m_speed;

		bool m_isMoving;
		bool m_isFlying;
		bool m_isOnGround;
		bool m_isRunningAnimationActive;

		bool m_isPlayerAlive;
		int m_numberOfBalloon; // number of life the player as

		int m_Scores;

	};
}