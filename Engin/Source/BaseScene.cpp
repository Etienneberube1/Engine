#include "BaseScene.h"
#include "Entity.h"
#include "Engine.h"
#include "Component.h"
#include "Square.h"
#include "Controller.h"
#include "BoxCollider.h"

namespace project {

	void project::BaseScene::Load()
	{
		project::IWorld* world = Engine::Get().World();

		Entity* e1 = world->Create("e1", 400.0f, 200.0f, 50.0f, 50.0f,  Color::Red);
		Entity* e2 = world->Create("e2", 600.0f, 200.0f, 50.0f, 50.0f, Color::Blue);

		e1->AddComponent<BoxCollider>();
		e2->AddComponent<BoxCollider>();

	}

}
