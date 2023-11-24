#include "Controller.h"
#include "Engine.h"
#include "Animation.h"
#include "EKey.h"
#include "Entity.h"
#include "RigidBody.h"

#include "Physic.h"
#include "Tilemap.h"


#include <iostream>

project::Controller::Controller(Entity* entity) : Component(entity),
m_isFlying(false), m_isMoving(false), m_isOnGround(false)
{
}

void project::Controller::Update(float dt)
{
    auto rigidBody = m_Entity->GetComponent<RigidBody>();
    auto playerAnimation = m_Entity->GetComponent<Animation>();

    if (!rigidBody || !playerAnimation) return;

    Vector3 velocity = rigidBody->GetVelocity();
    bool isMoving = false;

    // Check movement and update velocity accordingly
    if (Input().IsKeyDown(EKey::EKEY_D)) {
        velocity.x += m_speed * dt * 2;
        ChangeFlip(true, false);
        isMoving = true;
    }
    if (Input().IsKeyDown(EKey::EKEY_A)) {
        velocity.x -= m_speed * dt * 2;
        ChangeFlip(false, false);
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



    // Trigger flying animation if any movement key is pressed
    if (isMoving && !m_isFlying) {
        playerAnimation->Play("flying", true);
        m_isFlying = true;
    }

    // Revert back to idle animation if no movement key is pressed
    if (!isMoving && m_isFlying) {
        playerAnimation->Play("groundIdle", true);
        m_isFlying = false;
    }

    if (isMoving && m_isOnGround) {
        playerAnimation->Play("groundRun", true);
        m_isOnGround = true;
    }

    if (!isMoving && m_isOnGround) {
       // playerAnimation->Play("groundIdle", true);
        m_isOnGround = false;
    }

    // Apply gravity and set new velocity
    velocity.y += rigidBody->GetGravityScale();
    rigidBody->SetVelocity(velocity);


    
    if (m_Entity->GetX()  >= 800)
    {
        m_Entity->SetPosition(Vector3(0.0f, m_Entity->GetY(), 0.0f));
    }
    else if(m_Entity->GetX() < -10 - m_Entity->GetWidth() )
    {
        m_Entity->SetPosition(Vector3(800.0f, m_Entity->GetY(), 0.0f));
    }
    else if (m_Entity->GetY() <= 0.0f )
    {
        Vector3 v3 = rigidBody->GetVelocity();       
        m_Entity->SetPosition(Vector3(m_Entity->GetX(), 0.0f, 0.0f));
        rigidBody->SetVelocity(Vector3(v3.x, 0.0f,v3.z));
    }



}

void project::Controller::Start()
{
}

void project::Controller::Destroy()
{
}

void project::Controller::SetSpeedValue(float speed)
{
	m_speed = speed;
}

void project::Controller::ChangeFlip(bool h, bool v)
{
	if (m_Entity->GetComponent<Animation>() != nullptr)
	{
		m_Entity->GetComponent<Animation>()->SetFlip(h,v);
	}
}

void project::Controller::ChangeAnim()
{
    if (!m_isFlying) {

        auto playerAnimation = m_Entity->GetComponent<Animation>();

        if (!playerAnimation) return;

        playerAnimation->Play("flying", true);
        m_isFlying = true;
    }
}
