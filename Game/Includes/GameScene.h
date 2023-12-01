#pragma once
#include "BaseScene.h"


namespace project {

	class Entity;

	class GameScene : public BaseScene
	{
		~GameScene() = default;
		virtual void Load() override;

	private:
		Entity* CreatePlayer();
		Entity* CreateTileMap();
		void CreateEnemy();

		Entity* m_gameUI;
		size_t m_fontId;
	};
}