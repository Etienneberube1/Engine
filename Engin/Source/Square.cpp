#pragma once
#include "Square.h"
#include "SDLGraphics.h"
#include "Engine.h"
#include <iostream>


project::Square::Square(Entity* entity) : Component(entity)
{

}

void project::Square::Draw()
{
	m_X = m_Entity->GetPosX();
	m_Y = m_Entity->GetPosY();
	m_W = m_Entity->GetWidth();
	m_H = m_Entity->GetHeight();

	Graphics()->DrawRect(m_X, m_Y, m_W, m_H, m_Entity->GetColor());

}

void project::Square::Start()
{
}

void project::Square::Destroy()
{
}
