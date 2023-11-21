#pragma once
#include "BaseScene.h"


namespace project {

	class Entity;

	class MenuScene : public BaseScene
	{
		~MenuScene() = default;
		virtual void Load() override;

	private:
		Entity* CreatePlayer();
	};
}