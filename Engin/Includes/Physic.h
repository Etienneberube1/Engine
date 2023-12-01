#pragma once
#include <IPhysic.h>
#include <map>
#include <vector>
#include "RectF.h"

namespace project
{
    class Physic : public IPhysic
    {
    public:
        ~Physic()
        {
            m_EnemyList.size();
        }
        virtual bool CheckPointCircle(float px, float py, float cx, float cy, float cr) override;
        virtual bool CheckCircles(float c1x, float c1y, float c1r, float c2x, float c2y, float c2r) override;
        virtual bool CheckPointRect(float px, float py, float rx, float ry, float rw, float rh) override;
        virtual bool CheckRects(float r1x, float r1y, float r1w, float r1h, float r2x, float r2y, float r2w, float r2h) override;
        virtual bool CheckRectCircle(float rx, float ry, float rw, float rh, float cx, float cy, float cr) override;
        virtual void AddToLayer(const std::string& layerName, Entity* entity) override;
        virtual void AddToEnemyList(Entity* entity) override;
        virtual bool CollideWithLayer(Entity* entity, const std::string& layerName, Entity** other, RectF* collidingTile) override;
        virtual bool CollideWithEnemy(Entity* entity, Entity** other) override;
        virtual void Remove(Entity* entity) override;
        virtual bool CheckRects(Entity* entity1, Entity* entity2) override;
        virtual bool CheckRects(const RectF& rect1, const RectF& rect2) override;
        virtual bool CalculateIntersection(const RectF& rect1, const RectF& rect2, RectF* intersection) override;
        virtual float CalculateDistance(const Vector3& point1, const Vector3& point2) override;
    private:
        std::map<std::string, std::vector<Entity*>> m_Layers;
        std::vector<Entity*> m_EnemyList;

    };
}