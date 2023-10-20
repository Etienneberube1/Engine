#include "BaseScene.h"
#include "Entity.h"
#include "Engine.h"

namespace project {

	void project::BaseScene::Load()
	{
		project::IWorld* world = Engine::Get().World();

		Entity* e1 = new Entity("e1", 100.0f, 100.0f, 50.0f, 50.0f, Color::Blue);
		Entity* e2 = new Entity("e2", 200.0f, 200.0f, 50.0f, 50.0f, Color::Red);
		
		world->Add(e1);
		world->Add(e2);
	}

}