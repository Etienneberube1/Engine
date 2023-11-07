#pragma once
#include "MenuScene.h"
#include "Entity.h"
#include "Engine.h"
#include "Square.h"
#include "Controller.h"
#include "Sprite.h"
#include "Animation.h"
#include "Atlas.h"
#include "BoxCollider.h"

namespace project {

	void MenuScene::Load()
	{
		project::IWorld* world = Engine::Get().World();

		Entity* player = new Entity("e1", 200.0f, 100.0f, 43.0f, 64.0f, Color::White);

		world->Add(player);

		RectF rect = { };

		rect.x = player->GetPosX();
		rect.y = player->GetPosY();
		rect.w = player->GetWidth();
		rect.h = player->GetHeight();

		RectI recti = {};
		recti.x = 0;
		recti.y = 0;
		recti.w = 43;
		recti.h = 64;


		player->AddComponent<Controller>()->SetSpeedValue(100.0f);

		auto sprite = player->AddComponent<Sprite>();
		sprite->SetSpriteValue("assets/anim_playerFly.png", rect, player->GetColor());

		player->AddComponent<Atlas>()->AddFrame("test", 0, 0, 43, 64);
		
		sprite->SetSourceRect(recti);
		
		player->AddComponent<BoxCollider>();
		
		


		Entity* enemy1 = new Entity("enemy1", 300.0f, 200.0f, 43.0f, 64.0f, Color::White);
		enemy1->AddComponent<BoxCollider>();

		world->Add(enemy1);
		//player->AddComponent<Atlas>();

		//auto atlas = player->AddComponent<Atlas>();
		//for (int i = 0; i < 5; i++) {
		//	atlas->AddFrame("frame_" + std::to_string(i), i * 0, 0, 43, 64);
		//}

		// Add the animation component, initialize it, add a clip, and play it
		//auto animation = player->AddComponent<Animation>();
		//animation->InitAnimation(5, 43, 64); // 5 frames in a row each 43x64 pixels
		//animation->AddClip("run", 0, 5, 0.1f);
		//animation->Play("run", true); // Play the "run" clip in a loop



	}

}
