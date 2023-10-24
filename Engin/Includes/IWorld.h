#pragma once 
#include "Entity.h"
#include "IScene.h"

namespace project {


	class IWorld
	{
	public:
		virtual ~IWorld() = default;
		virtual Entity* Create(const std::string& name,float posX, float posY, float widht, float height, const Color& color) = 0;
		virtual void Start() = 0;
		virtual void Update(float dt) = 0;
		virtual void Draw() = 0;
		virtual void Destroy() = 0;
		virtual void Add(Entity* entity) = 0;
		virtual void Load(const std::string& scene) = 0;
		virtual void Register(const std::string& name, IScene* scene) = 0;
	};
}

