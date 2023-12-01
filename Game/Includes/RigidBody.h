#pragma once
#include "Vector3.h"
#include "Component.h"
#include "IUpdatable.h"



namespace project {

    // Forward declaration of Entity class
    class Entity;

    // RigidBody class represents the physics properties of an entity
    class RigidBody : public Component, public IUpdatable {
    public:
        // Destructor
        virtual ~RigidBody() = default;

        // Constructors
        RigidBody();
        RigidBody(Entity* parent);

        // Update method called to update the physics simulation for this rigid body
        virtual void Update(float dt) override;

        // Physics properties and methods

        // Set the mass of the rigid body
        void SetMass(float mass);

        // Add a force to the rigid body
        void AddForce(const Vector3& force);

        // Set the velocity of the rigid body
        void SetVelocity(const Vector3& velocity);

        // Set the gravity scale factor for the rigid body
        void SetGravityScale(float gravityMass);

        // Apply gravity to the rigid body based on the gravity scale
        void ApplyGravity();

        // Integrate the rigid body's position and velocity over a given time step
        void Integrate(float dt);

        // Get the gravity scale of the rigid body
        float GetGravityScale() { return m_gravityScale; }

        // Get the velocity of the rigid body
        Vector3 GetVelocity() { return m_velocity; }

    private:
        // Current velocity of the rigid body
        Vector3 m_velocity;

        // Accumulated forces acting on the rigid body
        Vector3 m_forces;

        // Mass of the rigid body
        float m_mass;

        // Scale factor for gravity
        float m_gravityScale;

        // Previous position for collision detection
        Vector3 m_previousPosition;

        // Threshold for collision detection, indicating significant movement
        const float collisionThreshold = 2.0f;
    };

}
