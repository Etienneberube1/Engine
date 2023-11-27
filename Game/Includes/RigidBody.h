#pragma once
#include "IUpdatable.h"
#include "Component.h"
#include "Vector3.h"

namespace project {

	class RigidBody : public Component, public IUpdatable
	{
	public:
		virtual ~RigidBody() = default;
		RigidBody();
		RigidBody(Entity* parent);

        virtual void Update(float dt) override;

        // Physics properties
        void SetMass(float mass);
        void AddForce(const Vector3& force);
        void SetVelocity(const Vector3& velocity);
        void SetGravityScale(float gravityMass);
        void ApplyGravity();
        void Integrate(float dt);
        float GetGravityScale() { return m_GravityScale; }
        Vector3 GetVelocity() { return  m_Velocity; }
    private:
        Vector3 m_Velocity;
        Vector3 m_Forces;
        float m_Mass;
        float m_GravityScale;
        Vector3 m_previousPosition;
        const float collisionThreshold = 2.0f;
    };

}
