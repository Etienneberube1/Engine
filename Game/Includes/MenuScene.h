#pragma once
#include "BaseScene.h"


namespace project {

	class Entity;

	class MenuScene : public BaseScene
	{
		~MenuScene() = default;
		virtual void Load() override;

	private:
		Entity* CreateMenu();

		Entity* m_menuUI;
		size_t m_fontId;
	};
}