#pragma once 
#include <string>
#include "Vector3.h"
#include "Entity.h"
#include <memory>

namespace project {

	class Enemy
	{
	public:
		Enemy(const std::string& name, Vector3 pos) :m_position(pos), m_name(name), m_Entity(nullptr)
		{}


		virtual ~Enemy() = default;
			

		virtual std::unique_ptr<Enemy> Clone() = 0;

	protected:

		Vector3 m_position;

		const std::string m_name;

		Entity* m_Entity = nullptr;

	};

}

