#pragma once
#include "Square.h"
#include "SDLGraphics.h"
#include "Engine.h"
#include <iostream>

project::Square::Square(Entity* entity) : Component(entity)
{
	m_X = entity->GetPosX();
	m_Y = entity->GetPosY();
	m_W = entity->GetWidth();
	m_H = entity->GetHeight();
	//m_color = entity->GetColor();
}

void project::Square::Draw()
{
	RectF rect;
	rect.x = m_X;
	rect.y = m_Y;
	rect.w = m_W;
	rect.h = m_H;
	Color color = project::Color::Blue;
	project::Engine::Get().Graphics()->DrawRect(rect, color);
}

void project::Square::Start()
{
}

void project::Square::Destroy()
{
}
