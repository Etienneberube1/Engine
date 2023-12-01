#pragma once
#include "BaseScene.h"

namespace project {
	class Entity;

	class EndGameMenu : public BaseScene
	{
	public:
		~EndGameMenu() = default;
		virtual void Load() override;

	private:
		Entity* CreateMenu();

		Entity* m_UI;
		size_t m_fontId;
	};
}