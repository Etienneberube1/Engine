#include "BaseAI.h"
#include <cmath> // For basic math operations
#include "Engine.h"
#include "Entity.h"
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include "RigidBody.h"



project::BaseAI::BaseAI(Entity* parent) : Component(parent) ,
asReachedPoint(false)
{
}

void project::BaseAI::Update(float deltaTime) {
    RigidBody* rb = m_Entity->GetComponent<RigidBody>();
    if (!rb) return;

    // Check for collision with specific layers

        // Normal movement logic
        if (IsTargetReached()) {

            asReachedPoint = true;
        }
        else {
            MoveTowardsTarget(deltaTime);
        }

        if (asReachedPoint) {
            elapsed -= deltaTime;
            if (elapsed < 0) {
                PickRandomPointInMap();
                asReachedPoint = false;
                elapsed = waitDuration;
            }
        }



        if (m_Entity->GetX() >= 800)
        {
            m_Entity->SetPosition(Vector3(0.0f, m_Entity->GetY(), 0.0f));
        }
        else if (m_Entity->GetX() < 0 - m_Entity->GetWidth())
        {
            m_Entity->SetPosition(Vector3(800.0f, m_Entity->GetY(), 0.0f));
        }
        else if (m_Entity->GetY() <= 0.0f)
        {
            Vector3 v3 = rb->GetVelocity();
            m_Entity->SetPosition(Vector3(m_Entity->GetX(), 0.0f, 0.0f));
            rb->SetVelocity(Vector3(v3.x, 0.0f, v3.z));
        }

}


void project::BaseAI::Start()
{
	srand(time(NULL));
	PickRandomPointInMap();

    elapsed = waitDuration;
}

void project::BaseAI::PickRandomPointInMap() {
    // Pick a new target point
    float x = static_cast<float>(rand() % 800);
    float y = static_cast<float>(rand() % 400);
    targetPoint = Vector3(x, y, 0.0f);

    Engine::Get().Logger().LogMessage("New target point: " + std::to_string(x) + ", " + std::to_string(y));

}

bool project::BaseAI::IsTargetReached() {
    float distance = Vector3::Distance(m_Entity->GetPosition(), targetPoint);
    // Define the threshold distance for picking a new target
    const float thresholdDistance = 50.0f;
    if (distance < thresholdDistance) {
        return true;
    }
    return false;
}






void project::BaseAI::MoveTowardsTarget(float deltaTime) {
    RigidBody* rb = m_Entity->GetComponent<RigidBody>();
    if (!rb) return;

    Vector3 currentVelocity = rb->GetVelocity();
    Vector3 direction = (targetPoint - m_Entity->GetPosition()).Normalized();
    float distanceToTarget = Vector3::Distance(m_Entity->GetPosition(), targetPoint);

    // Define base speed values
    float maxSpeed = 120.0f;
    float acceleration = 170.0f; // Adjust as needed for smoother acceleration

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