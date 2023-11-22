#include "RigidBody.h"
#include "Engine.h"
#include "Entity.h"
#include "Physic.h"

#include <iostream>

project::RigidBody::RigidBody() :RigidBody(nullptr)
{
}

project::RigidBody::RigidBody(Entity* parent) : Component(parent)
{
}

void project::RigidBody::SetMass(float mass)
{
    m_Mass = mass;
}

void project::RigidBody::AddForce(const Vector3& force)
{
    
}

void project::RigidBody::SetVelocity(const Vector3& velocity)
{
    m_Velocity = velocity;
}

void project::RigidBody::SetGravityScale(float gravityScale)
{
    m_GravityScale = gravityScale;
}

int temp;
void project::RigidBody::Update(float dt) {
    ApplyGravity();
    Integrate(dt);

    Entity* other;
    if (Engine::Get().Physics().CollideWithLayer(m_Entity, "ground", &other)) {
        temp++;
        std::cout << "Collided with ground_" << temp << std::endl;
    }
}

void project::RigidBody::ApplyGravity() {
    Vector3 gravity(0.0f, -1 * m_GravityScale, 0.0f);
    AddForce(gravity * m_Mass);
}

void project::RigidBody::Integrate(float dt) {
   
    m_Velocity = m_Velocity + (m_Forces / m_Mass) * dt;

    // Get the current position
    Vector3 currentPosition = m_Entity->GetPosition();
    
    // Update the position
    Vector3 newPosition = currentPosition + m_Velocity * dt;

    // Set the new position
    m_Entity->SetPosition(newPosition);
}