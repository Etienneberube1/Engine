#pragma once 
#include "Enemy.h"
#include "Rigidbody.h"
#include "Animation.h"
#include "Engine.h"
#include "Entity.h"
#include "BaseAI.h"
#include <string>
#include "Vector3.h"

namespace project {

	class BaseEnemy : public Enemy
	{
	public:
		BaseEnemy(const std::string name, Vector3 pos) : Enemy(name, pos) {}
		~BaseEnemy() = default;


		virtual Enemy* Clone() override
		{
			auto instance = new BaseEnemy(m_name, m_position);

			m_Entity = Engine::Get().World().Create(m_name);


			m_Entity->AddComponent<BaseAI>();

			auto enemyAnimation = m_Entity->AddComponent<Animation>();
			auto enemyRigidBody = m_Entity->AddComponent<RigidBody>();

			
			enemyRigidBody->SetVelocity(Vector3(30.0f, 30.0f, 0.0f));
			enemyRigidBody->SetGravityScale(2.0f);


			enemyAnimation->Load("assets/playerAssets/enemySpriteSheet.png");



			// ===========================ENEMY_FLY_ANIM==========================
			enemyAnimation->AddFrame("flying0", 0, 0, 37, 63);
			enemyAnimation->AddFrame("flying1", 37, 0, 37, 63);
			enemyAnimation->AddFrame("flying2", 79, 0, 37, 63);



			enemyAnimation->Init(3, 37, 63);
			enemyAnimation->AddClip("flying", 0, 3, 0.1f);
			// ====================================================================

			enemyAnimation->Play("flying", true);


			m_Entity->SetPosition(Vector3(m_position));
			m_Entity->SetSize(43.0f, 64.0f);



			return instance;

		}

	};
}