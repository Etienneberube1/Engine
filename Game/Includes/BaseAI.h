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

        Vector3 PickRandomPointInMap();
        void PickNewPoint();
        bool IsTargetReached();
        void MoveToTarget(float DeltaTime);

	private:
        Vector3 position; // Current position
        Vector3 targetPoint; // Target point to move to
		float StoppingDistance; // Distance the AI should stop before reaching is point
        float waitTime; // Time to wait at the target point
        const float waitDuration = 2.0f; // Example wait duration in seconds
	};

}
