#pragma once

namespace project {

	class IScene {

	public:
		virtual ~IScene() = default;
		virtual void Load() = 0;
	};

}