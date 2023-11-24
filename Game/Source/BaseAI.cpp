#include "BaseAI.h"
#include <cmath> // For basic math operations
#include "Engine.h"
#include "Entity.h"
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include "RigidBody.h"



project::BaseAI::BaseAI(Entity* parent) : Component(parent) {
}

void project::BaseAI::Update(float deltaTime) {
    RigidBody* rb = m_Entity->GetComponent<RigidBody>();
    if (!rb) return;

    // Check for collision with specific layers

        // Normal movement logic
        if (IsTargetReached()) {
            Engine::Get().Logger().LogMessage("Target reached. Picking a new target.");


            elapsed -= deltaTime;
            if (elapsed < 0) {
                PickRandomPointInMap();
                elapsed = waitDuration;
            }
        }
        else {
            MoveTowardsTarget(deltaTime);
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
    float y = static_cast<float>(rand() % 300);
    targetPoint = Vector3(x, y, 0.0f);

    Engine::Get().Logger().LogMessage("New target point: " + std::to_string(x) + ", " + std::to_string(y));

    // Set the initial velocity towards the target point
    //SetInitialVelocityTowardsTarget();
}

bool project::BaseAI::IsTargetReached() {
    float distance = Vector3::Distance(m_Entity->GetPosition(), targetPoint);
    // Define the threshold distance for picking a new target
    const float thresholdDistance = 60.0f;
    if (distance < thresholdDistance) {
        Engine::Get().Logger().LogMessage("Close to target. Picking a new target.");
        return true;
    }
    return false;
}


void project::BaseAI::SetInitialVelocityTowardsTarget() {
    RigidBody* rb = m_Entity->GetComponent<RigidBody>();
    if (!rb) return;

    Vector3 currentVelocity = rb->GetVelocity(); // Get the current velocity
    Vector3 direction = (targetPoint - m_Entity->GetPosition()).Normalized();

    // Adjust the current velocity to point towards the new target
    // Keep the current speed (magnitude of the velocity) constant
    float currentSpeed = currentVelocity.Length();
    Vector3 newVelocity = direction * currentSpeed;

    rb->SetVelocity(newVelocity);
}

//void project::BaseAI::SetInitialVelocityTowardsTarget() {
//    RigidBody* rb = m_Entity->GetComponent<RigidBody>();
//    if (!rb) return;
//
//    Vector3 direction = (targetPoint - m_Entity->GetPosition()).Normalized();
//    float initialHorizontalSpeed = 20.0f; // Adjust this value for desired horizontal speed
//    float initialVerticalSpeed = 20.0f;   // Adjust this value for desired vertical speed
//
//    // Apply horizontal and vertical components of the initial velocity
//    Vector3 initialVelocity = Vector3(direction.x * initialHorizontalSpeed, direction.y * initialVerticalSpeed, 0.0f);
//
//    rb->SetVelocity(initialVelocity);
//}




void project::BaseAI::MoveTowardsTarget(float deltaTime) {
    RigidBody* rb = m_Entity->GetComponent<RigidBody>();
    if (!rb) return;

    Vector3 currentVelocity = rb->GetVelocity();
    Vector3 direction = (targetPoint - m_Entity->GetPosition()).Normalized();
    float distanceToTarget = Vector3::Distance(m_Entity->GetPosition(), targetPoint);

    // Define base speed values
    float maxSpeed = 100.0f;
    float acceleration = 50.0f; // Adjust as needed for smoother acceleration

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

//void project::BaseAI::MoveTowardsTarget(float deltaTime) {
//    RigidBody* rb = m_Entity->GetComponent<RigidBody>();
//    if (!rb) return;
//
//    Vector3 currentVelocity = rb->GetVelocity();
//    Vector3 direction = (targetPoint - m_Entity->GetPosition()).Normalized();
//
//    // Define base speed values
//    float baseHorizontalSpeed = 100.0f;
//    float baseUpwardSpeedAdjustment = 30.0f;
//
//    // Calculate horizontal force needed to move towards the target
//    float horizontalForce = baseHorizontalSpeed * direction.x;
//    // Adjust horizontal force based on current velocity to change direction if needed
//    horizontalForce -= currentVelocity.x;
//
//    // Apply the horizontal force
//    currentVelocity.x += horizontalForce * deltaTime;
//
//    // Vertical movement control
//    float verticalDistance = targetPoint.y - m_Entity->GetPosition().y;
//    float verticalForce = baseUpwardSpeedAdjustment * verticalDistance - currentVelocity.y;
//    // Apply gravity
//    verticalForce -= rb->GetGravityScale() * deltaTime;
//
//    // Apply the vertical force
//    currentVelocity.y += verticalForce * deltaTime;
//
//    // Limit the downward speed to prevent too fast falling
//    const float maxDownwardSpeed = -5.0f;
//    if (currentVelocity.y < maxDownwardSpeed) {
//        currentVelocity.y = maxDownwardSpeed;
//    }
//
//    // Set the new velocity
//    rb->SetVelocity(currentVelocity);
//}
