#pragma once
#include <string>

namespace project {

	class Entity;
	class BaseScene;

	class IWorld
	{
	public:
		virtual ~IWorld() = default;

		virtual Entity* Create(const std::string& name) = 0;
		virtual void Update(float dt) = 0;
		virtual void Draw() = 0;
		virtual void Shutdown() = 0;
		virtual Entity* Find(const std::string& name) = 0;
		virtual void Remove(const std::string& name) = 0;
		virtual void Remove(Entity* entity) = 0;
		virtual void Load(const std::string& sceneName) = 0;
		virtual void Unload() = 0;
		virtual void Register(const std::string& sceneName, BaseScene* scene) = 0;
	};
}

