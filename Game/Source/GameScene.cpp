#include "GameScene.h"
#include "Engine.h"
#include "Animation.h"
#include "Entity.h"
#include "Controller.h"
#include "Tilemap.h"
#include "Vector3.h"
#include "RigidBody.h"
#include "Spawner.h"
#include "BaseEnemy.h"
#include "GameUI.h"
#include <memory>

void project::GameScene::Load()
{

	m_gameUI = Instantiate("gameUI");
	auto Tilemap = CreateTileMap();
	auto player = CreatePlayer();

	CreateEnemy();
}

project::Entity* project::GameScene::CreatePlayer()
{
	// Instantiate a new player entity
	auto player = Instantiate("player");
	auto playerAnimation = player->AddComponent<Animation>();
	auto playerController = player->AddComponent<Controller>();
	auto playerRigidBody = player->AddComponent<RigidBody>();



	playerRigidBody->SetVelocity(Vector3(0.0f, 75.0f, 0.0f));
	playerRigidBody->SetGravityScale(3.0f);


	playerAnimation->Load("assets/playerAssets/playerSpriteSheet.png");

	player->SetPosition(Vector3(100.0f, 650.0f, 0.0f));
	player->SetSize(43.0f, 64.0f);


	playerController->SetSpeedValue(100.0f);

	GameUI* uiCmp = m_gameUI->AddComponent<GameUI>();
	playerController->OnScoreChanged.AddListener(uiCmp);



	// ===========================PLAYER_FLY_ANIM==========================
	playerAnimation->AddFrame("flying0", 0, 128, 43, 64);
	playerAnimation->AddFrame("flying1", 43, 128, 43, 64);
	playerAnimation->AddFrame("flying2", 86, 128, 43, 64);


	playerAnimation->Init(3, 43, 64);
	playerAnimation->AddClip("flying", 0, 3, 0.1f);
	// ====================================================================






	// ===========================PLAYER_FLY_IDLE_ANIM=====================
	playerAnimation->AddFrame("flyIdle0", 0, 192, 43, 64);
	playerAnimation->AddFrame("flyIdle1", 43, 192, 43, 64);
	playerAnimation->AddFrame("flyIdle2", 86, 192, 43, 64);

	playerAnimation->Init(3, 43, 64);
	playerAnimation->AddClip("flyIdle", 0, 3, 0.1f);
	// ====================================================================







	// ==========================PLAYER_GROUND_IDLE_ANIM===================
	playerAnimation->AddFrame("groundIdle0", 0, 64, 43, 64);
	playerAnimation->AddFrame("groundIdle1", 43, 64, 43, 64);
	playerAnimation->AddFrame("groundIdle2", 86, 64, 43, 64);

	playerAnimation->Init(3, 43, 64);
	playerAnimation->AddClip("groundIdle", 0, 3, 0.1f);
	// ====================================================================






	// ==========================PLAYER_GROUND_RUN_ANIM====================
	playerAnimation->AddFrame("groundRun0", 0, 0, 43, 64);
	playerAnimation->AddFrame("groundRun1", 43, 0, 43, 64);
	playerAnimation->AddFrame("groundRun2", 86, 0, 43, 64);

	playerAnimation->Init(3, 43, 64);
	playerAnimation->AddClip("groundRun", 0, 3, 0.1f);
	// ====================================================================






	playerAnimation->Play("flyIdle", true);


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

void project::GameScene::CreateEnemy()
{
	Spawner spawner;

	auto enemy_0 = std::make_unique<BaseEnemy>("enemy_0", Vector3(270.0f, 120.0f, 0.0f));
	auto enemy_1 = std::make_unique<BaseEnemy>("enemy_1", Vector3(600.0f, 155.0f, 0.0f));
	auto enemy_2 = std::make_unique<BaseEnemy>("enemy_2", Vector3(120.0f, 280.0f, 0.0f));
	auto enemy_3 = std::make_unique<BaseEnemy>("enemy_3", Vector3(570.0f, 410.0f, 0.0f));
	auto enemy_4 = std::make_unique<BaseEnemy>("enemy_4", Vector3(240.0f, 470.0f, 0.0f));

	spawner.AddPrototype("enemy_0", std::move(enemy_0));
	spawner.AddPrototype("enemy_1", std::move(enemy_1));
	spawner.AddPrototype("enemy_2", std::move(enemy_2));
	spawner.AddPrototype("enemy_3", std::move(enemy_3));
	spawner.AddPrototype("enemy_4", std::move(enemy_4));


	spawner.Spawn("enemy_0");
	spawner.Spawn("enemy_1");
	spawner.Spawn("enemy_2");
	spawner.Spawn("enemy_3");
	spawner.Spawn("enemy_4");
}







