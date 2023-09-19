#pragma once 
#include "Entity.h"
namespace project {


	class IWorld
	{
	public:
		virtual ~IWorld();
		virtual void Start() = 0;
		virtual void Update(float dt) = 0;
		virtual void Draw() = 0;
		virtual void Destroy() = 0;
		virtual void Add(Entity* entity) = 0;
	};
}

