#pragma once
#include <string>
#include "RectF.h"
#include "Vector3.h"

namespace project
{
    class Entity;

    // Interface for physics functionalities.
    class IPhysic
    {
    public:
        // Virtual destructor.
        virtual ~IPhysic() = default;

        // Checks if a point is inside a circle.
        virtual bool CheckPointCircle(float px, float py, float cx, float cy, float cr) = 0;

        // Checks if two circles intersect.
        virtual bool CheckCircles(float c1x, float c1y, float c1r, float c2x, float c2y, float c2r) = 0;

        // Checks if a point is inside a rectangle.
        virtual bool CheckPointRect(float px, float py, float rx, float ry, float rw, float rh) = 0;

        // Checks if two rectangles intersect.
        virtual bool CheckRects(float r1x, float r1y, float r1w, float r1h, float r2x, float r2y, float r2w, float r2h) = 0;

        // Adds an entity to the enemy list for collision checks.
        virtual void AddToEnemyList(Entity* entity) = 0;

        // Checks if two entities' bounding rectangles intersect.
        virtual bool CheckRects(Entity* entity1, Entity* entity2) = 0;

        // Checks if a rectangle intersects with a circle.
        virtual bool CheckRectCircle(float rx, float ry, float rw, float rh, float cx, float cy, float cr) = 0;

        // Checks if two RectF objects intersect.
        virtual bool CheckRects(const RectF& rect1, const RectF& rect2) = 0;

        // Adds an entity to a specific collision layer.
        virtual void AddToLayer(const std::string& layerName, Entity* entity) = 0;

        // Checks for collisions between an entity and entities in a specific layer.
        virtual bool CollideWithLayer(Entity* entity, const std::string& layerName, Entity** other, RectF* collidingTile) = 0;

        // Checks for collisions between an entity and enemies.
        virtual bool CollideWithEnemy(Entity* entity, Entity** other) = 0;

        // Returns the number of enemies left.
        virtual int NumberOfEnemyLeft() = 0;

        // Removes an entity from physics processing.
        virtual void Remove(Entity* entity) = 0;

        // Calculates the intersection rectangle of two RectF objects.
        virtual bool CalculateIntersection(const RectF& rect1,  const RectF& rect2, RectF* intersection) = 0;

        // Calculates the distance between two points in 3D space.
        virtual float CalculateDistance(const Vector3& point1, const Vector3& point2) = 0;
    };
}
