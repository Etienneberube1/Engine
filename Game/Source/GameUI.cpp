#include "GameUI.h"
#include <cmath>

project::GameUI::GameUI()
{
}

project::GameUI::GameUI(Entity* parent)
	:Component(parent), m_playerScore(0), m_fontId(0)
{
	m_fontId = Engine::Get().Graphics().LoadFont("assets/fonts/pixelFont.ttf", 32);
}

void project::GameUI::Draw()
{

	Engine::Get().Graphics().DrawString("SCORE: " + std::to_string(static_cast<int>(m_playerScore)) ,m_fontId, 0.0f,0.0f, Color::WHITE);
}
