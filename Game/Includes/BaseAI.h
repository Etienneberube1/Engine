#pragma once
#include "Component.h"
#include "IUpdatable.h"
#include "Vector3.h"


namespace project {

	class BaseAI : public Component, public IUpdatable
	{
	public:  
		BaseAI();
		BaseAI(Entity* parent);
		virtual ~BaseAI() =  default;
		
		virtual void Update(float DeltaTime) override;
		virtual void Start() override;

        void PickRandomPointInMap();
        bool IsTargetReached();
        void MoveTowardsTarget(float deltaTime);
		void SetInitialVelocityTowardsTarget();

	private:
        Vector3 position; // Current position
        Vector3 targetPoint; // Target point to move to
		float StoppingDistance; // Distance the AI should stop before reaching is point

        const float waitDuration = 1.0f; // Example wait duration in seconds

		float elapsed;

		bool asReachedPoint;

		float horizontalSpeed = 70.0f; // Adjust as needed
		float verticalSpeed = 70.0f; // Adjust as needed
	};

}
