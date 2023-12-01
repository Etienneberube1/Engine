#pragma once
#include "Component.h"
#include "IDrawable.h"
#include "IUpdatable.h"
#include "Entity.h"


namespace project {

	class EndGameMenuUI : public Component, public IDrawable, public IUpdatable
	{
	public:
		EndGameMenuUI();
		EndGameMenuUI(Entity* parent);
		~EndGameMenuUI();

		virtual void Update(float DeltaTime) override;
		virtual void Draw() override;
	private:
		size_t m_fontId;

	};
}