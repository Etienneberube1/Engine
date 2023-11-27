#pragma once
#include "Observer.h"
#include "IDrawable.h"
#include "Engine.h"

namespace project {

	class GameUI : public Observer<int>, public IDrawable
	{
	public:
		virtual void OnNotify(const int& value)
		{
			Engine::Get().Logger().LogMessage("Change Health");
		}

		virtual void Draw() override;
	};

}