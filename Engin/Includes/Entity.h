#pragma once
#include <string>
#include <vector>
#include "IUpdatable.h"
#include "IDrawable.h"
#include <map>
#include <typeinfo>
#include <cstdlib>
#include "Color.h"

namespace project {
	class SDLGraphics;
	class Component;


	class Entity final {
	public:

		Entity(std::string name, float posX, float posY, float widht, float height, const Color& color);
		~Entity();
		virtual void Start();
		virtual void Update(float dt);
		virtual void Draw();
		virtual void Destroy();
		virtual void SetPosition(float posX, float posY);
		template<typename T> inline T* AddComponent();

		template<typename T> inline T* GetComponent();

		virtual float GetPosX() { return m_posX; }
		virtual float GetPosY() { return m_posY; }
		virtual float GetWidth() { return m_width; }
		virtual float GetHeight() { return m_heigth; }
		virtual Color GetColor() { return m_color; }
		virtual float GetSpeed() { return m_speed; }
		virtual std::string GetName() { return m_entityName; }
	private:
		float m_posX;
		float m_posY;
		float m_width;
		float m_heigth;
		Color m_color;
		float m_speed;
		std::string m_entityName;

		std::vector<IUpdatable*> m_Updatables = *new std::vector<IUpdatable*>();
		std::vector<IDrawable*> m_Drawables = *new std::vector<IDrawable*>();

		std::map<const type_info*, Component*>& m_Components = *new std::map<const type_info*, Component*>();
	};

	template<typename T>
	inline T* Entity::AddComponent()
	{
		T* cmp = new T(this);
		std::cout << "added comp" << std::endl;
		m_Components.emplace(&typeid(T), cmp);

		IDrawable* drawCmp = dynamic_cast<IDrawable*>(cmp);
		if (drawCmp != nullptr) {
			m_Drawables.push_back(drawCmp);
		}

		IUpdatable* UpdateCmp = dynamic_cast<IUpdatable*>(cmp);
		if (UpdateCmp != nullptr) {
			m_Updatables.push_back(UpdateCmp);
		}
		return cmp;
	}


	template<typename T>
	inline T* Entity::GetComponent() {
		auto it = m_Components.find(&typeid(T));
		if (it != m_Components.end()) {
			return static_cast<T*>(it->second);
		}
		return nullptr; // If the component was not found
	}
}