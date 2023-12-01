#include "Controller.h"

#include "Engine.h"
#include "Animation.h"
#include "EKey.h"
#include "Entity.h"
#include "RigidBody.h"
#include "Physic.h"
#include "Tilemap.h"

project::Controller::Controller(Entity* entity) : Component(entity),
m_isFlying(false), m_isMoving(false), m_isOnGround(false), m_isPlayerAlive(true),
m_numberOfBalloon(2), m_Scores(0), m_timeBetweenSound(0.2f)
{
	playerFlapSound = Engine::Get().Audio().LoadSound("assets/audio/PlayerFlap.mp3");
	killEnemySound = Engine::Get().Audio().LoadSound("assets/audio/EnemyFalls.mp3");
	m_elapsed = m_timeBetweenSound;
}

void project::Controller::Update(float dt)
{
	if (CheckIfPlayerIsDead())
	{
		Engine::Get().World().Load("endmenu");
		return;
	}
	if (Engine::Get().Physics().NumberOfEnemyLeft() <= 0)
	{
		Engine::Get().World().Load("endmenu");
		return;
	}
	auto rigidBody = m_entity->GetComponent<RigidBody>();
	auto playerAnimation = m_entity->GetComponent<Animation>();

	if (!rigidBody || !playerAnimation) return;

	CheckEnemyCol();
	HandleWorldBoundaries(rigidBody);


	Vector3 velocity = rigidBody->GetVelocity();
	bool isMoving = false;



	// Check movement and update velocity accordingly
	if (Input().IsKeyDown(EKey::EKEY_D)) {
		velocity.x += m_speed * dt * 2;
		playerAnimation->SetFlip(true, false);
		isMoving = true;

	}
	if (Input().IsKeyDown(EKey::EKEY_A)) {
		velocity.x -= m_speed * dt * 2;
		playerAnimation->SetFlip(false, false);
		isMoving = true;


	}
	if (Input().IsKeyDown(EKey::EKEY_W)) {
		velocity.y -= m_speed * dt * 4.5f;
		isMoving = true;


	}
	if (Input().IsKeyDown(EKey::EKEY_S)) {
		velocity.y += m_speed * dt * 3;
		isMoving = true;


	}


	if (isMoving)
	{
		m_elapsed -= dt;
		if (m_elapsed <= 0)
		{
			Engine::Get().Audio().PlaySFX(playerFlapSound);
			m_elapsed = m_timeBetweenSound;
		}
	}


	// Apply gravity and set new velocity
	velocity.y += rigidBody->GetGravityScale();
	rigidBody->SetVelocity(velocity);



	// Transition to flying animation
	if (isMoving && !m_isFlying) {
		if (m_isOnGround) {
			playerAnimation->Stop();
			m_isOnGround = false;
		}
		playerAnimation->Play("flying", true);
		m_isFlying = true;
	}

	// Transition to idle animation when not moving in the air
	if (!isMoving && m_isFlying) {
		playerAnimation->Play("flyIdle", true);
		m_isFlying = false;
	}

	// Transition to running animation when on the ground
	if (isMoving && m_isOnGround) {
		if (!m_isRunningAnimationActive) {
			playerAnimation->Play("groundRun", true);
			m_isRunningAnimationActive = true;
		}
	}
	else {
		m_isRunningAnimationActive = false;
	}

	// Transition to idle animation when not moving on the ground
	if (!isMoving && m_isOnGround) {
		playerAnimation->Play("groundIdle", true);
		m_isOnGround = false;
	}


}





void project::Controller::HandleWorldBoundaries(RigidBody* rb)
{
	if (m_entity->GetX() >= 800)
	{
		m_entity->SetPosition(Vector3(0.0f, m_entity->GetY(), 0.0f));
	}
	else if (m_entity->GetX() < -10 - m_entity->GetWidth())
	{
		m_entity->SetPosition(Vector3(800.0f, m_entity->GetY(), 0.0f));
	}
	else if (m_entity->GetY() <= 0.0f)
	{
		Vector3 v3 = rb->GetVelocity();
		m_entity->SetPosition(Vector3(m_entity->GetX(), 0.0f, 0.0f));
		rb->SetVelocity(Vector3(v3.x, 0.0f, 0.0f));
	}
}

void project::Controller::TakeDamage()
{
	m_numberOfBalloon--;
	if (m_numberOfBalloon <= 0) {
		m_isPlayerAlive = false;
	}
	return;
}

void project::Controller::CheckEnemyCol()
{
	Entity* colEntity = nullptr;

	if (Engine::Get().Physics().CollideWithEnemy(m_entity, &colEntity))
	{
		m_Scores += 1000;
		OnScoreChanged.Invoke(m_Scores);

		Engine::Get().Physics().Remove(colEntity);
		colEntity->Destroy();
		Engine::Get().Audio().PlaySFX(killEnemySound);
	}

}

bool project::Controller::CheckIfPlayerIsDead()
{
	if (m_entity->GetY() >= 770)
	{
		return true;
	}

	return false;
}




void project::Controller::Start()
{

}

void project::Controller::Destroy()
{
}
