#include "GameScene.h"
#include "Engine.h"
#include "Animation.h"
#include "Atlas.h"
#include "Entity.h"
#include "Controller.h"
#include "Tilemap.h"
#include "Vector3.h"
#include "RigidBody.h"


void project::GameScene::Load()
{
	Entity* Tilemap = CreateTileMap();
	Entity* player = CreatePlayer();
}

project::Entity* project::GameScene::CreatePlayer()
{
	// Instantiate a new player entity
	Entity* player = Instantiate("player");
	Animation* playerAnimation = player->AddComponent<Animation>();
	Controller* playerController = player->AddComponent<Controller>();
	RigidBody* playerRigidBody = player->AddComponent<RigidBody>();



	playerRigidBody->SetVelocity(Vector3(0.0f, 75.0f, 0.0f));
	playerRigidBody->SetGravityScale(3.0f);


	playerAnimation->Load("assets/playerAssets/anim_playerFly.png");

	player->SetPosition(Vector3(200.0f, 200.0f, 0.0f));
	player->SetSize(43.0f, 64.0f);


	playerController->SetSpeedValue(100.0f);



	playerAnimation->AddFrame("flying0", 0, 0, 43, 64);
	playerAnimation->AddFrame("flying1", 43, 0, 43, 64);
	playerAnimation->AddFrame("flying2", 86, 0, 43, 64);


	playerAnimation->Init(3, 43, 64);
	playerAnimation->AddClip("flying", 0, 3, 0.1f);




	playerAnimation->AddFrame("idle0", 129, 0, 43, 64);
	playerAnimation->AddFrame("idle1", 172, 0, 43, 64);

	playerAnimation->Init(2, 43, 64);
	playerAnimation->AddClip("idle", 0, 2, 0.1f);



	playerAnimation->Play("idle", true);


	return player;
}


project::Entity* project::GameScene::CreateTileMap()
{
	Entity* tilemap = Instantiate("tilemap");

	Tilemap* tilemapCmp = tilemap->AddComponent<Tilemap>();

	tilemapCmp->Load("assets/map/Terrain.png", 32, 32, 8, 43);

	TLayer backgroundLayer = tilemapCmp->CreateLayer("assets/map/map_1_background.csv");
	TLayer groundLayer = tilemapCmp->CreateLayer("assets/map/map_1_ground.csv");
	TLayer waterLayer = tilemapCmp->CreateLayer("assets/map/map_1_water.csv");

	tilemapCmp->AddLayer("background", backgroundLayer);
	tilemapCmp->AddLayer("ground", groundLayer);
	tilemapCmp->AddLayer("water", waterLayer);

	project::Engine::Get().Physics().AddToLayer("ground", tilemap);

	return tilemap;
}




