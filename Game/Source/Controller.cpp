#include "Controller.h"
#include "Engine.h"
#include "Animation.h"
#include "EKey.h"
#include "Entity.h"
#include "RigidBody.h"

#include "Physic.h"
#include "Tilemap.h"


#include <iostream>

project::Controller::Controller(Entity* entity) : Component(entity)
{
}

void project::Controller::Update(float dt)
{
    auto rigidBody = m_Entity->GetComponent<RigidBody>();
    if (!rigidBody) return; 

    Vector3 velocity = rigidBody->GetVelocity();

    // Move right
    if (Input().IsKeyDown(EKey::EKEY_D)) {
        velocity.x += m_speed * dt * 2;
        ChangeFlip(true, false);
    }

    // Move left
    if (Input().IsKeyDown(EKey::EKEY_A)) {
        velocity.x -= m_speed * dt * 2;
        ChangeFlip(false, false);
    }

    // Move up
    if (Input().IsKeyDown(EKey::EKEY_W)) {
        velocity.y -= m_speed * dt * 4.5f;
    }

    // Move down
    if (Input().IsKeyDown(EKey::EKEY_S)) {
        velocity.y += m_speed * dt * 3; 
    }



    velocity.y += rigidBody->GetGravityScale();
    // Set the new velocity
    rigidBody->SetVelocity(velocity);	
    
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
