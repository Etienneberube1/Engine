#include "BaseAI.h"
#include <cmath>     // For basic math operations
#include "Engine.h"
#include "Entity.h"
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()
#include "RigidBody.h"
#include "Animation.h"

namespace project {

    BaseAI::BaseAI(Entity* parent) : Component(parent),
        m_hasReachedPoint(false), m_hasStarted(false)
    {
        std::srand(static_cast<unsigned int>(time(NULL)));
    }

    void BaseAI::Update(float deltaTime) {
        RigidBody* rb = m_entity->GetComponent<RigidBody>();
        auto aiAnimation = m_entity->GetComponent<Animation>();

        if (!rb || !aiAnimation) return;

        HandleWorldBoundaries(rb);

        m_startingTimer -= deltaTime;
        if (m_startingTimer < 0 && !m_hasStarted)
        {
            PickRandomPointInMap();
            m_hasStarted = true;
            m_entity->SetSize(43.0f, 64.0f);
            aiAnimation->Play("flying", true);
        }

        // Normal movement logic
        if (IsTargetReached()) {
            m_hasReachedPoint = true;
        }
        else if (m_hasStarted) {
            MoveTowardsTarget(deltaTime);
        }

        if (m_hasReachedPoint) {
            m_elapsed -= deltaTime;
            if (m_elapsed < 0) {
                PickRandomPointInMap();
                m_elapsed = m_waitDuration;
                m_hasReachedPoint = false;
            }
        }

        if (rb->GetVelocity().x > 0) {
            aiAnimation->SetFlip(true, false); // Facing right
        }
        else if (rb->GetVelocity().x < 0) {
            aiAnimation->SetFlip(false, false); // Facing left
        }
    }

    void BaseAI::Start()
    {
        m_startingTimer = m_startingWaitDuration;
        m_elapsed = m_waitDuration;
    }

    void BaseAI::PickRandomPointInMap() {
        // Pick a new target point
        float x = static_cast<float>(rand() % 800);
        float y = static_cast<float>(rand() % 500);
        m_targetPoint = Vector3(x, y, 0.0f);
    }

    bool BaseAI::IsTargetReached() {
        float distance = Vector3::Distance(m_entity->GetPosition(), m_targetPoint);
        // Define the threshold distance for picking a new target
        const float thresholdDistance = 50.0f;
        if (distance < thresholdDistance) {
            return true;
        }
        return false;
    }

    void BaseAI::MoveTowardsTarget(float deltaTime) {
        RigidBody* rb = m_entity->GetComponent<RigidBody>();
        if (!rb) return;

        Vector3 currentVelocity = rb->GetVelocity();
        Vector3 direction = (m_targetPoint - m_entity->GetPosition()).Normalized();
        float distanceToTarget = Vector3::Distance(m_entity->GetPosition(), m_targetPoint);

        // Define base speed values
        float maxSpeed = 120.0f;
        float acceleration = 110.0f;

        // Adjust speed based on distance to the target
        float speedModifier = std::min(distanceToTarget / 100.0f, 1.0f); // Ensures the speed decreases as it approaches the target

        // Calculate horizontal and vertical forces
        float horizontalForce = acceleration * direction.x * speedModifier;
        float verticalForce = acceleration * direction.y * speedModifier;

        // Apply the forces to the current velocity
        currentVelocity.x += horizontalForce * deltaTime;
        currentVelocity.y += verticalForce * deltaTime;

        // Limit the maximum speed
        if (currentVelocity.Length() > maxSpeed) {
            currentVelocity = currentVelocity.Normalized() * maxSpeed;
        }

        // Set the new velocity
        rb->SetVelocity(currentVelocity);
    }

    void BaseAI::HandleWorldBoundaries(RigidBody* rb)
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
            rb->SetVelocity(Vector3(v3.x, 0.0f, v3.z));
        }
    }

}
