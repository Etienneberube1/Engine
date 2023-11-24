#include "RigidBody.h"
#include "Engine.h"
#include "Entity.h"
#include "Physic.h"
#include "Controller.h"

namespace project {

	RigidBody::RigidBody(Entity* parent) : Component(parent), m_Mass(1.0f), m_GravityScale(1.0f) {
		m_Forces = Vector3(0.0f, 0.0f, 0.0f);
		m_Velocity = Vector3(0.0f, 0.0f, 0.0f);
	}

	void RigidBody::SetMass(float mass) {
		m_Mass = mass;
	}

	void RigidBody::AddForce(const Vector3& force) {
		m_Forces += force;
	}

	void RigidBody::SetVelocity(const Vector3& velocity) {
		m_Velocity = velocity;
	}

	void RigidBody::SetGravityScale(float gravityScale) {
		m_GravityScale = gravityScale;
	}

	void RigidBody::ApplyGravity() {
		if (m_GravityScale != 0) {
			Vector3 gravity(0, 9.81f * m_GravityScale, 0); // Assuming positive y-direction is downward
			AddForce(gravity * m_Mass); // Gravity force = mass * gravity acceleration
		}
	}







    void project::RigidBody::Update(float dt) {
        ApplyGravity();

        Entity* other = nullptr;
        RectF collidingTile;
        bool onGround = false;
        bool hitCeiling = false;

        if (Engine::Get().Physics().CollideWithLayer(m_Entity, "ground", &other, &collidingTile)) {
            auto entityRect = m_Entity->GetRect();

            // Collision detection logic
            if (m_Velocity.y >= 0 && entityRect.y + entityRect.h > collidingTile.y &&
                entityRect.y < collidingTile.y) {
                // Collision from above
                m_Entity->SetY(collidingTile.y - entityRect.h);
                m_Velocity.y = 0;
                onGround = true;
            }
            else if (m_Velocity.y < 0 && entityRect.y < collidingTile.y + collidingTile.h &&
                entityRect.y + entityRect.h > collidingTile.y + collidingTile.h) 
            {
                // Collision from below
                m_Entity->SetY(collidingTile.y + collidingTile.h);
                m_Velocity.y = 0;
                hitCeiling = true;
            }
        }

        if (!onGround && !hitCeiling) {
            Integrate(dt);
        }
        else {
            // Update horizontal position
            Vector3 newPosition = m_Entity->GetPosition();
            newPosition.x += m_Velocity.x * dt;
            m_Entity->SetPosition(newPosition);
        }
        

        // Update previous position for the next frame
        m_previousPosition = m_Entity->GetPosition();
        m_Forces = Vector3(0.0f, 0.0f, 0.0f);


        // setting the on ground to change animation in controller
        if (Controller* playerController = m_Entity->GetComponent<Controller>()) 
        {
           playerController->SetOnGroundBool(onGround);
        }
    }


    
    
    void RigidBody::Integrate(float dt) {
		m_Velocity += (m_Forces / m_Mass) * dt;
		Vector3 newPosition = m_Entity->GetPosition() + m_Velocity * dt;
		m_Entity->SetPosition(newPosition);
	}

}