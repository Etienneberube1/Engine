#include "RigidBody.h"
#include "Engine.h"
#include "Entity.h"
#include "Physic.h"

#include <iostream>

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
        // Store the position at the beginning of the update
        Vector3 lastPosition = m_Entity->GetPosition();

        ApplyGravity(); // Apply gravity every frame

        Entity* other = nullptr;
        RectF collidingTile;
        bool onGround = false;


        if (Engine::Get().Physics().CollideWithLayer(m_Entity, "ground", &other, &collidingTile)) {
            // Now, collidingTile contains the specific tile's rect that you're colliding with
            auto entityRect = m_Entity->GetRect();

            // Check if the player's bottom is currently below the top of the colliding tile
            if (entityRect.y + entityRect.h > collidingTile.y) {
                m_Entity->SetY(collidingTile.y - entityRect.h); // Position on top of the colliding tile
                m_Velocity.y = 0; // Reset vertical velocity
                onGround = true;
                Engine::Get().Logger().LogMessage("Should stay on ground");
            }
        }

        if (!onGround) {
            Integrate(dt); // Integrate to update position only if not on ground
        }
        else {
            // Even if on ground, update horizontal position based on horizontal velocity
            Vector3 newPosition = m_Entity->GetPosition();
            newPosition.x += m_Velocity.x * dt;
            m_Entity->SetPosition(newPosition);
        }

        // Update previous position for the next frame
        m_previousPosition = lastPosition;

        // Reset forces after integration
        m_Forces = Vector3(0.0f, 0.0f, 0.0f);
    }

	void RigidBody::Integrate(float dt) {
		m_Velocity += (m_Forces / m_Mass) * dt;
		Vector3 newPosition = m_Entity->GetPosition() + m_Velocity * dt;
		m_Entity->SetPosition(newPosition);
	}

}