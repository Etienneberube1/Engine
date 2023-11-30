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

	class BaseEnemy : public Enemy {
	public:
		BaseEnemy(const std::string& name, const Vector3& pos) : Enemy(name, pos) {}
		~BaseEnemy() = default;


		virtual std::unique_ptr<Enemy> Clone() override {

			auto instance = std::make_unique<BaseEnemy>(m_name, m_position);
			// Create a new entity for the cloned instance
			instance->m_Entity = Engine::Get().World().Create(m_name);

			instance->m_Entity->AddComponent<BaseAI>();
			auto enemyAnimation = instance->m_Entity->AddComponent<Animation>();
			auto enemyRigidBody = instance->m_Entity->AddComponent<RigidBody>();

			enemyRigidBody->SetVelocity(Vector3(0.0f, 0.0f, 0.0f));
			enemyRigidBody->SetGravityScale(2.0f);

			enemyAnimation->Load("assets/playerAssets/enemySpriteSheet.png");

			enemyAnimation->AddFrame("flying0", 0, 0, 37, 63);
			enemyAnimation->AddFrame("flying1", 37, 0, 37, 63);
			enemyAnimation->AddFrame("flying2", 79, 0, 37, 63);

			enemyAnimation->Init(3, 37, 63);
			enemyAnimation->AddClip("flying", 0, 3, 0.1f);

															  
			enemyAnimation->AddFrame("startAnim0",  0,  64, 36, 38);
			enemyAnimation->AddFrame("startAnim1", 36,  64, 36, 38);
			enemyAnimation->AddFrame("startAnim2", 72,  64, 36, 38);
			enemyAnimation->AddFrame("startAnim3", 108, 64, 36, 38);
			enemyAnimation->AddFrame("startAnim4", 144, 64, 36, 38);
			enemyAnimation->AddFrame("startAnim5", 180, 64, 36, 38);
			enemyAnimation->AddFrame("startAnim6", 216, 64, 36, 38);			
			enemyAnimation->AddFrame("startAnim7", 252, 64, 36, 38);

			enemyAnimation->Init(7, 36, 38);
			enemyAnimation->AddClip("startAnim", 0, 7, 0.3f);

			enemyAnimation->Play("startAnim", false);

			instance->m_Entity->SetPosition(Vector3(m_position));
			instance->m_Entity->SetSize(43.0f, 40.0f);

			Engine::Get().Physics().AddToEnemyMap(m_name, m_Entity);

			return instance;
		}
	};
}