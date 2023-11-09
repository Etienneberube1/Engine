#include "BaseScene.h"
#include "Entity.h"
#include "Engine.h"
#include "Component.h"
#include "Square.h"
#include "Controller.h"


namespace project {

	void project::BaseScene::Load()
	{
		std::cout << "loaded scene" << std::endl;
		project::IWorld* world = Engine::Get().World();

		Entity* e1 = world->Create("e2", 200.0f, 200.0f, 50.0f, 50.0f,  Color::Red);
		Entity* e2 = world->Create("e2", 200.0f, 200.0f, 50.0f, 50.0f, Color::Red);

		e1->AddComponent<Square>();
		e2->AddComponent<Square>();

		e1->AddComponent<Controller>();
		e2->AddComponent<Controller>();
	}

}
