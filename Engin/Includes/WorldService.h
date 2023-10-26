#pragma once
#include "IWorld.h"
#include "Entity.h"
#include <vector>
#include "IScene.h"
#include <map>

namespace project {


	class WorldService : public IWorld
	{
	public:
		virtual Entity* Create(const std::string& name,float posX, float posY, float widht, float height,float speed, const Color& color) override;
		virtual void Start() override;
		virtual void Update(float dt) override;
		virtual void Draw() override;
		virtual void Destroy() override;
		virtual void Add(Entity* entity) override;
		
		void Load(const std::string& scene);
		void Register(const std::string& name, IScene* scene);
		void Unload();
	private:
		IScene* m_CurrentScene = nullptr;
		std::vector<Entity*> m_entityList;
		std::map<std::string, IScene*>& m_Scenes = *new std::map<std::string, IScene*>;
	};
}
