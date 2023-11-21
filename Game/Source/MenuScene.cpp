#include "MenuScene.h"

#include "Engine.h"
#include "Animation.h"
#include "Atlas.h"
#include "Entity.h"
#include "Controller.h"

#include <iostream>


void project::MenuScene::Load()
{
	Entity* player = CreatePlayer();

}

project::Entity* project::MenuScene::CreatePlayer()
{
	// Instantiate a new player entity
	Entity* player = Instantiate("player");

	Sprite* playerSprite = player->AddComponent<Sprite>();
	Atlas* playerAtlas = player->AddComponent<Atlas>();
	Animation* playerAnimation = player->AddComponent<Animation>();

	Controller* playerController = player->AddComponent<Controller>();


	playerSprite->Load("assets/player.png");

	player->SetPosition(200.0f, 200.0f);
	player->SetSize(43.0f, 64.0f);


	playerController->SetSpeedValue(100.0f);



	//playerAtlas->AddFrame("flying", 0, 0, 43, 64);



	//playerAnimation->Init(3, 43,64);
	//playerAnimation->AddClip("flying", 0, 3, 0.1f);
	//playerAnimation->Play("flying", true);





	if (!playerSprite) { std::cout << "no sprite"; }
	if (!playerAtlas) { std::cout << "no atlas"; }
	if (!playerAnimation) { std::cout << "no animation"; }
	if (!playerController) { std::cout << "no controller"; }

	if (playerSprite) { std::cout << "as sprite\n"; }
	if (playerAtlas) { std::cout << "as atlas\n"; }
	if (playerAnimation) { std::cout << "as animation\n"; }
	if (playerController) { std::cout << "as controller\n"; }

	return player;
}

