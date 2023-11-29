#pragma once
#include "Enemy.h"
#include <map>
#include <memory>

namespace project {

    typedef std::map<std::string, std::unique_ptr<Enemy>> TProtoMap;

    class Spawner {
    public:
        void AddPrototype(const std::string& name, std::unique_ptr<Enemy> proto) {
            m_Prototypes[name] = std::move(proto);
        }

        std::unique_ptr<Enemy> Spawn(const std::string& name) {
            if (m_Prototypes.count(name) > 0) {
                return m_Prototypes[name]->Clone();
            }
            return nullptr;
        }

    private:
        TProtoMap m_Prototypes;
    };
}