#pragma once 
#include <string>
#include "Vector3.h"
#include "Entity.h"
#include <memory>

namespace project {

    // Base class for enemy entities in the game.
    class Enemy
    {
    public:
        // Constructor to initialize an enemy with a name and position.
        Enemy(const std::string& name, Vector3 pos) : m_position(pos), m_name(name), m_Entity(nullptr) {}

        // Virtual destructor for proper cleanup in derived classes.
        virtual ~Enemy() = default;

        // Pure virtual function to clone the enemy, creating a new instance of the same type.
        virtual std::unique_ptr<Enemy> Clone() = 0;

    protected:
        // Position of the enemy.
        Vector3 m_position;

        // Name of the enemy.
        const std::string m_name;

        // Pointer to the entity associated with the enemy.
        Entity* m_Entity;
    };

}
