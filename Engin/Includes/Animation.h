#pragma once
#include "Component.h"



namespace project {

	class Animation : public Component, public IUpdatable, public IDrawable {
	public:
		Animation();
		~Animation() = default;

		virtual void Update(float dt) override;
		virtual void Draw() override;
		virtual void Start() override;
		virtual void Destroy() override;
	};
}