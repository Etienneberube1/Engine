#pragma once
#include "Component.h"
#include "IDrawable.h"
#include "IUpdatable.h"
#include "Entity.h"


namespace project {

	class MenuUI : public Component, public IDrawable, public IUpdatable
	{
	public:
		MenuUI();
		MenuUI(Entity* parent);
		~MenuUI();

		virtual void Update(float DeltaTime) override;
		virtual void Draw() override;
	private:
		size_t m_fontId;
	};
}