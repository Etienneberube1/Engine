#pragma once
#include "Component.h"
#include "IUpdatable.h"
#include "Vector3.h"

namespace project {
    class RigidBody;

    // Class representing a basic AI component.
    class BaseAI : public Component, public IUpdatable
    {
    public:
        // Constructors.
        BaseAI();
        BaseAI(Entity* parent);

        // Destructor.
        virtual ~BaseAI() = default;

        // Update method called every frame.
        virtual void Update(float deltaTime) override;

        // Initialization logic for the AI.
        virtual void Start() override;

        // Picks a random point in the map for the AI to move towards.
        void PickRandomPointInMap();

        // Checks if the AI has reached its target point.
        bool IsTargetReached();

        // Moves the AI towards the target point.
        void MoveTowardsTarget(float deltaTime);

        // Handles world boundaries for the AI, adjusting its course as necessary.
        void HandleWorldBoundaries(RigidBody* rb);

    private:
        Vector3 m_position; // Current position of the AI.
        Vector3 m_targetPoint; // Target point for the AI to move to.
        float m_stoppingDistance; // Distance at which the AI stops before reaching the target point.

        const float m_waitDuration = 1.0f; // Duration for the AI to wait at a point.

        float m_elapsed; // Elapsed time for timing purposes.

        const float m_startingWaitDuration = 2.0f; // Initial wait duration before the AI starts moving.
        float m_startingTimer = 0.0f; // Timer for the initial wait.
        bool m_hasStarted = false; // Flag to check if the AI has started.

        bool m_hasReachedPoint; // Flag to check if the AI has reached the target point.

        float m_horizontalSpeed = 70.0f; // Horizontal speed of the AI.
        float m_verticalSpeed = 70.0f; // Vertical speed of the AI.
    };
}
