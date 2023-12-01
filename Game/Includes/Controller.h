#pragma once
#include "Component.h"
#include "IUpdatable.h"
#include "Subject.h"

namespace project {

    class Animation;
    class RigidBody;

    // Class responsible for controlling an entity, including movement and interactions.
    class Controller : public IUpdatable, public Component {

    public:
        // Constructor.
        Controller(Entity* entity);

        // Destructor.
        ~Controller() = default;

        // Update method called every frame.
        virtual void Update(float dt) override;

        // Initialization logic for the controller.
        virtual void Start() override;

        // Cleanup logic for the controller.
        virtual void Destroy() override;

        // Sets the speed value for the controller.
        virtual void SetSpeedValue(float speed) { m_speed = speed; };

        // Handles entity's interactions with world boundaries.
        void HandleWorldBoundaries(RigidBody* rb);

        // Logic for taking damage.
        void TakeDamage();

        // Checks for collisions with enemies.
        void CheckEnemyCol();

        // Checks if the player is dead.
        bool CheckIfPlayerIsDead();

        // Sets the ground state of the entity.
        void SetOnGroundBool(bool isOnGround) {
            m_isOnGround = isOnGround;
        }

        // Subject for score change notifications.
        Subject<int> OnScoreChanged;

    private:
        // Positional variables.
        float m_posX;
        float m_posY;

        // Speed of the entity.
        float m_speed;

        // State variables.
        bool m_isMoving;
        bool m_isFlying;
        bool m_isOnGround;
        bool m_isRunningAnimationActive;

        // Player state.
        bool m_isPlayerAlive;
        int m_numberOfBalloon; // Number of lives the player has.

        // Score and timing variables.
        int m_Scores;
        float m_elapsed;
        float m_timeBetweenSound;

        // Sound identifiers.
        size_t playerFlapSound;
        size_t killEnemySound;
    };
}
