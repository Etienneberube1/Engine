#pragma once
#include <string>
#include "RectF.h"
#include "Vector3.h"

namespace project
{
    class Entity;

    class IPhysic
    {
    public:
        virtual ~IPhysic() = default;

        virtual bool CheckPointCircle(float px, float py, float cx, float cy, float cr) = 0;
        virtual bool CheckCircles(float c1x, float c1y, float c1r, float c2x, float c2y, float c2r) = 0;
        virtual bool CheckPointRect(float px, float py, float rx, float ry, float rw, float rh) = 0;
        virtual bool CheckRects(float r1x, float r1y, float r1w, float r1h, float r2x, float r2y, float r2w, float r2h) = 0;
        virtual void AddToEnemyList( Entity* entity) = 0;
        virtual bool CheckRects(Entity* entity1, Entity* entity2) = 0;
        virtual bool CheckRectCircle(float rx, float ry, float rw, float rh, float cx, float cy, float cr) = 0;
        virtual bool CheckRects(const RectF& rect1, const RectF& rect2) = 0;
        virtual void AddToLayer(const std::string& layerName, Entity* entity) = 0;
        virtual bool CollideWithLayer(Entity* entity, const std::string& layerName, Entity** other, RectF* collidingTile) = 0;
        virtual bool CollideWithEnemy(Entity* entity,  Entity** other) = 0;

        virtual void Remove(Entity* entity) = 0;
        virtual bool CalculateIntersection(const RectF& rect1, const RectF& rect2, RectF* intersection) = 0;
        virtual float CalculateDistance(const Vector3& point1, const Vector3& point2) = 0;

    };
}