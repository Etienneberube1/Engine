#pragma once
#include "IWorld.h"
#include "Entity.h"
#include <vector>

namespace project {


	class WorldService : public IWorld
	{
	public:
		virtual void Start() override;
		virtual void Update(float dt) override;
		virtual void Draw() override;
		virtual void Destroy() override;
		virtual void Add(Entity* entity) override;
	private:
		std::vector<Entity*> m_entityList;
	};
}