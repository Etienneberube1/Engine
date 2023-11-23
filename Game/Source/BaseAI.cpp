#include "BaseAI.h"
#include <cmath> // For basic math operations
#include "Engine.h"
#include "Entity.h"
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include "RigidBody.h"



namespace project {

    BaseAI::BaseAI() : BaseAI(nullptr) {}

    BaseAI::BaseAI(Entity* parent) : Component(parent), StoppingDistance(10.0f) {
        PickNewPoint();
        srand(time(NULL));
    }

    void BaseAI::Update(float DeltaTime) {
        if (!IsTargetReached()) {
            MoveToTarget(DeltaTime);
        }
        else {
            waitTime -= DeltaTime;
            if (waitTime <= 0) {
                PickNewPoint();
            }
        }
    }

    Vector3 BaseAI::PickRandomPointInMap() {
        // Implement logic to pick a random point in the upper part of the map
        // This is just a placeholder. You'll need to replace it with your actual map dimensions
        float x = rand() % 800; // picking map width
        float y = (rand() % 400); // picking in the upper half
        float z = 0; // Assuming a 2D game
        return Vector3(x, y, z);
    }

    void BaseAI::PickNewPoint() {
        const float minDistance = 75.0f; // Minimum distance from the current position
        bool isPointValid = false;

        while (!isPointValid) {
            Vector3 newPoint = PickRandomPointInMap();

            // Calculate the distance between the current position and the new point
            float distance = Engine::Get().Physics().CalculateDistance(position, newPoint);

            if (distance > minDistance) {
                // If the new point is sufficiently far, use it
                targetPoint = newPoint;
                isPointValid = true;
            }
            // Otherwise, loop again to pick another point
        }

        waitTime = waitDuration;
    }
    bool BaseAI::IsTargetReached() {
        float distance = Engine::Get().Physics().CalculateDistance(position, targetPoint);
        return distance < StoppingDistance;
    }

    void BaseAI::MoveToTarget(float DeltaTime) {
        RigidBody* rb = m_Entity->GetComponent<RigidBody>();
        if (!rb) return;

        Vector3 directionToTarget = (targetPoint - position).Normalized();

        float upwardForceMagnitude = 20.0f; // Value to counteract gravity
        float forwardForceMagnitude = 5.0f; // Gentle horizontal movement

        Vector3 totalForce(0, 0, 0);

        //if (!rb->IsOnGround()) {
        //    totalForce.y = upwardForceMagnitude;
        //}

        directionToTarget.y = 0; // Focus on horizontal direction
        totalForce += directionToTarget * forwardForceMagnitude;

        rb->AddForce(totalForce);
    }



}

