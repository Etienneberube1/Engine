#pragma once
#include "Enemy.h"
#include <map>
#include <string>

namespace project {

	typedef std::map<std::string, Enemy*> TProtoMap;

	class Spawner
	{
	public:
		~Spawner() 
		{
			for (auto proto : m_Prototypes) {
				delete proto.second;
			}
		}

		void AddPrototype(const std::string& name, Enemy* proto)
		{
			m_Prototypes[name] = proto;
		}

		Enemy* Spawn(const std::string& name)
		{
			if (m_Prototypes.count(name) > 0)
			{
				return m_Prototypes[name]->Clone();
			}
			return nullptr;
		}
	private:
		TProtoMap m_Prototypes;
	};


}