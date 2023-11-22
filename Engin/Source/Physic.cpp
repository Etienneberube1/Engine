#include <Physic.h>
#include <math.h>
#include <Entity.h>
#include "Tilemap.h"
#include "RectF.h"

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




bool project::Physic::CollideWithLayer(Entity* entity, const std::string& layerName, Entity** other) {
    RectF entityRect = entity->GetRect();

    for (Entity* e : m_Layers[layerName]) {
        if (Tilemap* tilemap = e->GetComponent<Tilemap>()) {
            RectF collidingTile;
            if (tilemap->IsColliding(entityRect, &collidingTile)) {
                *other = e; // The tilemap is the colliding entity
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
}