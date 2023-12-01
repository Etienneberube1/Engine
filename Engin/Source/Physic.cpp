#include <Physic.h>
#include <math.h>
#include <Entity.h>
#include "Tilemap.h"
#include "RectF.h"
#include "Engine.h"

bool project::Physic::CheckPointCircle(float px, float py, float cx, float cy, float cr)
{
	float vecX = px - cx;
	float vecY = py - cy;
	float d = sqrtf((vecX * vecX) + (vecY * vecY));

	return d <= cr;
}



bool project::Physic::CheckCircles(float c1x, float c1y, float c1r, float c2x, float c2y, float c2r)
{
	float vecX = c1x - c2x;
	float vecY = c1y - c2y;
	float d = sqrtf((vecX * vecX) + (vecY * vecY));

	return d <= (c1r + c2r);
}




bool project::Physic::CheckPointRect(float px, float py, float rx, float ry, float rw,
	float rh)
{
	return px >= rx && py >= ry && px <= (rx + rw) && py <= (ry + rh);
}



bool project::Physic::CheckRects(float r1x, float r1y, float r1w, float r1h, float r2x,
	float r2y, float r2w, float r2h)
{
	return (r1x <= (r2x + r2w) && (r1x + r1w) >= r2x &&
		r1y <= (r2y + r2h) && (r1y + r1h) >= r2y);
}




bool project::Physic::CheckRects(const RectF& rect1, const RectF& rect2) {
	return (rect1.x <= (rect2.x + rect2.w) && (rect1.x + rect1.w) >= rect2.x &&
		rect1.y <= (rect2.y + rect2.h) && (rect1.y + rect1.h) >= rect2.y);
}


bool project::Physic::CheckRects(Entity* entity1, Entity* entity2) {
	return CheckRects(entity1->GetRect(), entity2->GetRect());
}



bool project::Physic::CheckRectCircle(float rx, float ry, float rw, float rh, float cx, float cy, float cr)
{
	if (CheckPointRect(cx, cy, rx, ry, rw, rh))
	{
		return true;
	}

	float tx = cx;
	float ty = cy;

	if (tx < rx) tx = rx;
	if (tx > rx + rw) tx = rx + rw;
	if (ty < ry) ty = ry;
	if (ty > ry + rh) ty = ry + rh;

	return CheckPointCircle(tx, ty, cx, cy, cr);
}



void project::Physic::AddToLayer(const std::string& layerName, Entity* entity)
{
	if (m_Layers.count(layerName) == 0)
	{
		m_Layers.emplace(layerName, std::vector<Entity*>());
	}

	m_Layers[layerName].push_back(entity);
}

void project::Physic::AddToEnemyMap(const std::string& EnemyName, Entity* entity)
{
	if (m_Layers.count(EnemyName) == 0)
	{
		m_Layers.emplace(EnemyName, std::vector<Entity*>());
	}

	m_Layers[EnemyName].push_back(entity);
}



bool project::Physic::CalculateIntersection(const RectF& rect1, const RectF& rect2, RectF* intersection) {
	float x1 = std::max(rect1.x, rect2.x);
	float y1 = std::max(rect1.y, rect2.y);
	float x2 = std::min(rect1.x + rect1.w, rect2.x + rect2.w);
	float y2 = std::min(rect1.y + rect1.h, rect2.y + rect2.h);

	if (x2 >= x1 && y2 >= y1) {
		if (intersection != nullptr) {
			intersection->x = x1;
			intersection->y = y1;
			intersection->w = x2 - x1;
			intersection->h = y2 - y1;
		}
		return true;
	}

	return false;
}

float project::Physic::CalculateDistance(const Vector3& point1, const Vector3& point2) {
	float dx = point1.x - point2.x;
	float dy = point1.y - point2.y;
	float dz = point1.z - point2.z;
	return static_cast<float>(sqrt(dx * dx + dy * dy + dz * dz));
}


bool project::Physic::CollideWithLayer(Entity* entity, const std::string& layerName, Entity** other, RectF* collidingTile) {
	RectF entityRect = entity->GetRect();

	for (Entity* e : m_Layers[layerName]) {
		if (Tilemap* tilemap = e->GetComponent<Tilemap>()) {
			if (tilemap->IsColliding(entityRect, collidingTile, layerName)) {
				*other = e; // The tilemap is the colliding entity
				return true;
			}
		}
	}
	return false;
}

bool project::Physic::CollideWithEnemy(Entity* entity, Entity** other)
{
	for (auto enemy : m_EnemyMap)
	{
		std::vector<Entity*>::iterator it = enemy.second.begin();
		if(it != enemy.second.end())
		{
			if (CheckRects(entity->GetRect(), enemy.second.front()->GetRect()))
			{
				Engine::Get().Logger().LogMessage(std::to_string(enemy.second.front()->GetX()));
				Engine::Get().Logger().LogMessage(std::to_string(enemy.second.front()->GetY()));
				return true;
			}
		}
	}
	return false;
}





void project::Physic::Remove(Entity* entity)
{
	for (auto layer : m_Layers)
	{
		std::vector<Entity*>::iterator it = layer.second.begin();
		while (it != layer.second.end())
		{
			if (*it == entity)
			{
				layer.second.erase(it);
				return;
			}

			it++;
		}
	}

	for (auto enemy : m_EnemyMap)
	{
		std::vector<Entity*>::iterator it = enemy.second.begin();
		while (it != enemy.second.end())
		{
			if (*it == entity)
			{
				enemy.second.erase(it);
				return;
			}

			it++;
		}
	}



}