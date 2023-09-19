#pragma once

namespace project {
	class Entity {
	public:

		Entity();
		~Entity();
		virtual void Start();
		virtual void Update(float dt);
		virtual void Draw();
		virtual void Destroy();
	private:
	};
}