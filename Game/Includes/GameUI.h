#pragma once
#include "Observer.h"
#include "IDrawable.h"
#include "Engine.h"
#include "Component.h"


namespace project {

	class GameUI : public IDrawable, public Component, public Observer<int>
	{
	public:		
		
		GameUI();
		GameUI(Entity* parent);

		virtual void OnNotify(const int& value)
		{
			m_playerScore += value;
		}

		virtual void Draw() override;
	private:
		float m_playerScore;
		size_t m_fontId;
	};

}