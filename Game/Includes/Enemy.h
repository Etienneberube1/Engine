#pragma once 
#include <string>
#include "Vector3.h"
#include "Entity.h"

namespace project {

	class Enemy
	{
	public:
		Enemy(const std::string& name, Vector3 pos) :m_position(pos), m_name(name)
		{}


		virtual ~Enemy()
		{
			//if (m_Entity != nullptr)
			//{
			//	delete m_Entity;
			//}
		}

		virtual Enemy* Clone() = 0;
	protected:

		Vector3 m_position;

		const std::string& m_name;

		Entity* m_Entity = nullptr;

	};

}

