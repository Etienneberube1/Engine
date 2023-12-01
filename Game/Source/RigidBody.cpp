#include "RigidBody.h"
#include "Engine.h"
#include "Entity.h"
#include "Physic.h"
#include "Controller.h"

namespace project {

	RigidBody::RigidBody(Entity* parent) : Component(parent), m_mass(1.0f), m_gravityScale(1.0f) {
		m_forces = Vector3(0.0f, 0.0f, 0.0f);
		m_velocity = Vector3(0.0f, 0.0f, 0.0f);
	}

	void RigidBody::SetMass(float mass) {
		m_mass = mass;
	}

	void RigidBody::AddForce(const Vector3& force) {
		m_forces += force;
	}

	void RigidBody::SetVelocity(const Vector3& velocity) {
		m_velocity = velocity;
	}

	void RigidBody::SetGravityScale(float gravityScale) {
		m_gravityScale = gravityScale;
	}

	void RigidBody::ApplyGravity() {
		if (m_gravityScale != 0) {
			Vector3 gravity(0, 9.81f * m_gravityScale, 0); // Assuming positive y-direction is downward
			AddForce(gravity * m_mass); // Gravity force = mass * gravity acceleration
		}
	}



    void project::RigidBody::Update(float dt) {
        ApplyGravity();

        Entity* other = nullptr;
        RectF collidingTile;
        bool onGround = false;
        bool hitCeiling = false;

        if (Engine::Get().Physics().CollideWithLayer(m_entity, "ground", &other, &collidingTile)) {
            auto entityRect = m_entity->GetRect();

            // Collision detection logic
            if (m_velocity.y >= 0 && entityRect.y + entityRect.h > collidingTile.y &&
                entityRect.y < collidingTile.y) {
                // Collision from above
                m_entity->SetY(collidingTile.y - entityRect.h);
                m_velocity.y = 0;
                onGround = true;
            }
            else if (m_velocity.y < 0 && entityRect.y < collidingTile.y + collidingTile.h &&
                entityRect.y + entityRect.h > collidingTile.y + collidingTile.h) 
            {
                // Collision from below
                m_entity->SetY(collidingTile.y + collidingTile.h);
                m_velocity.y = 0;
                hitCeiling = true;
            }
        }

        if (!onGround && !hitCeiling) {
            Integrate(dt);
        }
        else {
            // Update horizontal position
            Vector3 newPosition = m_entity->GetPosition();
            newPosition.x += m_velocity.x * dt;
            m_entity->SetPosition(newPosition);
        }
        

        // Update previous position for the next frame
        m_previousPosition = m_entity->GetPosition();
        m_forces = Vector3(0.0f, 0.0f, 0.0f);


        // setting the on ground to change animation in controller
        if (Controller* playerController = m_entity->GetComponent<Controller>()) 
        {
           playerController->SetOnGroundBool(onGround);
        }
    }


    
    
    void RigidBody::Integrate(float dt) {
		m_velocity += (m_forces / m_mass) * dt;
		Vector3 newPosition = m_entity->GetPosition() + m_velocity * dt;
		m_entity->SetPosition(newPosition);
	}

}