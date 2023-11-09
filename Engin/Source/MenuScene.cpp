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
		Entity* enemy1 = world->Create("enemy1", 300.0f, 200.0f, 100.0f, 100.0f, Color::White);


		enemy1->AddComponent<BoxCollider>();

		RectF rect = { };

		rect.x = player->GetPosX();
		rect.y = player->GetPosY();
		rect.w = player->GetWidth();
		rect.h = player->GetHeight();


		player->AddComponent<Controller>()->SetSpeedValue(100.0f);
		player->AddComponent<Sprite>();
		player->AddComponent<BoxCollider>();
		player->AddComponent<Animation>();

		Sprite* playerSprite = player->GetComponent<Sprite>();
		playerSprite->SetSpriteValue("assets/player.png", rect, Color::White);

		Animation* playerAnim = player->GetComponent<Animation>();
		playerAnim->InitAnimation(3, 43, 64);
		playerAnim->SetPath("assets/anim_playerFly.png");
		playerAnim->AddClip("fly", 0, 3, 0, 0.1f);

		//playerAnim->InitAnimation(2, 43, 64);
		//playerAnim->AddClip("idle", 0, 2, 0, 0.1f);

		playerAnim->Play("fly", true);
	}

}
