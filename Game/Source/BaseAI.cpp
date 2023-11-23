#include "BaseAI.h"
#include <cmath> // For basic math operations
#include "Engine.h"


namespace project {

    BaseAI::BaseAI() : BaseAI(nullptr) {}

    BaseAI::BaseAI(Entity* parent) : Component(parent), StoppingDistance(10.0f) {
        PickNewPoint();
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
        targetPoint = PickRandomPointInMap();
        waitTime = waitDuration;
    }

    bool BaseAI::IsTargetReached() {
        float distance = Engine::Get().Physics().CalculateDistance(position, targetPoint);
        return distance < StoppingDistance;
    }

    void BaseAI::MoveToTarget(float DeltaTime) {
        // Move towards the target point
        Vector3 direction = (targetPoint - position).Normalized(); 
        float speed = 100.0f; // Set your AI speed here
        position += direction * speed * DeltaTime;
    }

}

