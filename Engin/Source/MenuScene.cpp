#pragma once
#include "MenuScene.h"
#include "Entity.h"
#include "Engine.h"
#include "Square.h"
#include "Controller.h"
#include "Sprite.h"

namespace project {

	void MenuScene::Load()
	{
		project::IWorld* world = Engine::Get().World();

		Entity* player = new Entity("e1", 500.0f, 100.0f, 50.0f, 50.0f, Color::Green);

		world->Add(player);

		RectF rect = { };

		rect.x = player->GetPosX();
		rect.y = player->GetPosY();
		rect.w = player->GetWidth();
		rect.h = player->GetHeight();
		

		player->AddComponent<Sprite>()->SetSpriteValue("assets/player.png", rect, player->GetColor());
		player->AddComponent<Controller>()->SetSpeedValue(100.0f);

		
	}

}
