#pragma once
#include "Square.h"
#include "SDLGraphics.h"
#include "Engine.h"
#include <iostream>
#include "Color.h"

project::Square::Square(Entity* entity) : Component(entity)
{
	//m_X = entity->GetPosX();
	//m_Y = entity->GetPosY();
	//m_W = entity->GetWidth();
	//m_H = entity->GetHeight();
}

void project::Square::Draw()
{
	//RectF rect;
	//rect.x = m_X;
	//rect.y = m_Y;
	//rect.w = m_W;
	//rect.h = m_H;
	//Color color = project::Color::Blue;
	
	m_X = m_Entity->GetPosX();
	m_Y = m_Entity->GetPosY();
	m_W = m_Entity->GetWidth();
	m_H = m_Entity->GetHeight();

	project::Engine::Get().Graphics()->DrawRect(m_X, m_Y, m_W, m_H, m_Entity->GetColor());
	std::cout << m_X << std::endl;
	std::cout << m_Y << std::endl;

}

void project::Square::Start()
{
}

void project::Square::Destroy()
{
}
