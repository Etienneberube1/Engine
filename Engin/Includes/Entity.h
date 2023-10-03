#pragma once
#include <string>
#include "SDLGraphics.h"

namespace project {
	class Entity {
	public:

		Entity(std::string name,float posX, float posY, float widht, float height, const Color& color);
		~Entity();
		virtual void Start();
		virtual void Update(float dt);
		virtual void Draw();
		virtual void Destroy();
		virtual float GetPosX() { return m_posX; }
		virtual float GetPosY() { return m_posY; }
		virtual float GetWidth() { return m_width; }
		virtual float GetHeight() { return m_heigth; }
	private:
		float m_posX;
		float m_posY;
		float m_width;
		float m_heigth;
		std::string m_entityName;


	};
}