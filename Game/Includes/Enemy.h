#pragma once 
#include <string>
#include "Vector3.h"


namespace project {

	class Enemy
	{
	public:
		Enemy(const std::string& name, Vector3 pos, float speed) :m_speed(speed), m_position(pos), m_name(name)
		{}


		virtual ~Enemy() = default;

		virtual Enemy* Clone() = 0;
	protected:
		float m_speed = 0;

		Vector3 m_position;

		const std::string& m_name;

		Entity* m_Entity = nullptr;

	};}

