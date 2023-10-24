#pragma once
#include "IScene.h"
#include "IDrawable.h"

namespace project {

	class BaseScene : public IScene {
	public:

		virtual void Load() override;
	private:

	};

}