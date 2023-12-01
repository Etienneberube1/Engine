#pragma once
#include "Enemy.h"
#include <map>
#include <memory>

namespace project {

    // Define a map to store enemy prototypes
    typedef std::map<std::string, std::unique_ptr<Enemy>> TProtoMap;

    // Spawner class responsible for creating and spawning enemy instances
    class Spawner {
    public:
        // Add a prototype enemy to the spawner
        void AddPrototype(const std::string& name, std::unique_ptr<Enemy> proto) {
            m_Prototypes[name] = std::move(proto);
        }

        // Spawn an enemy instance based on its name
        std::unique_ptr<Enemy> Spawn(const std::string& name) {
            // Check if the prototype exists in the map
            if (m_Prototypes.count(name) > 0) {
                // Clone the prototype to create a new enemy instance
                return m_Prototypes[name]->Clone();
            }
            // If the prototype doesn't exist, return nullptr
            return nullptr;
        }

    private:
        // Map to store enemy prototypes with their names
        TProtoMap m_Prototypes;
    };
}
