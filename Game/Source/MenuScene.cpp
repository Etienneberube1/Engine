#include "Engine.h"
#include "MenuScene.h"

#include "Entity.h"
#include "Animation.h"
#include "Sprite.h"
#include "Atlas.h"
#include "Controller.h"

void project::MenuScene::Load()
{
	Entity* player = Instantiate("player");

	player->AddComponent<Sprite>();
	player->AddComponent<Atlas>();
	player->AddComponent<Animation>();
	player->AddComponent<Controller>()->SetSpeedValue(1.0f);

	Sprite* sprite = player->GetComponent<Sprite>();
	Atlas* altas = player->GetComponent<Atlas>();
	Animation* animation = player->GetComponent<Animation>();

	sprite->Load("assets/player.png");

	player->SetPosition(300.0f, 200.0f);
	player->SetSize(43.0f, 64.0f);


	//altas->AddFrame("fly", 0, 0, 43, 64);



	/*animation->Init(3, 43, 64);

	animation->AddClip("fly", 0, 3, 0.3f);

	animation->Play("fly", true);*/

}

