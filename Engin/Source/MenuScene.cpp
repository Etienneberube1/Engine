#pragma once
#include "MenuScene.h"
#include "Entity.h"
#include "Engine.h"

namespace project {

	void MenuScene::Load()
	{
		project::IWorld* world = Engine::Get().World();

		Entity* e3 = new Entity("e1", 100.0f, 100.0f, 50.0f, 50.0f, Color::Green);
		Entity* e4 = new Entity("e2", 200.0f, 200.0f, 50.0f, 50.0f, Color::White);

		world->Add(e3);
		world->Add(e4);
	}

}
