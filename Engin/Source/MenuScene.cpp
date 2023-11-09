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

		Entity* player = world->Create("player", 200.0f, 100.0f, 43.0f, 64.0f, Color::White);
		Entity* enemy1 = world->Create("enemy1", 300.0f, 200.0f, 50.0f, 50.0f, Color::White);

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


		enemy1->AddComponent<BoxCollider>();


		player->AddComponent<Sprite>();
		player->AddComponent<BoxCollider>();
		player->AddComponent<Animation>();
		player->AddComponent<Controller>();

		Animation* playerAnim = player->GetComponent<Animation>();
		playerAnim->SetPath("assets/anim_playerFly.png");
		playerAnim->InitAnimation(5, 43, 64);
		playerAnim->AddClip("fly", 0, 5, 0, 0.1f);

		playerAnim->Play("fly", true);








	}

}
