#include "MenuUI.h"
#include "Engine.h"
#include "EKey.h"

project::MenuUI::MenuUI()
{
}

project::MenuUI::MenuUI(Entity* parent) : Component(parent), m_fontId(0)
{
	m_fontId = Engine::Get().Graphics().LoadFont("assets/fonts/pixelFont.ttf", 40);

}

project::MenuUI::~MenuUI()
{
}

void project::MenuUI::Update(float dt)
{
	if (Input().IsKeyDown(EKey::EKEY_RETURN)) {

		Engine::Get().World().Load("game");
		Engine::Get().Audio().StopMusic();
	}
}

void project::MenuUI::Draw()
{
	Engine::Get().Graphics().DrawString("A  1-PLAYER GAME", m_fontId, 200.0f, 400.0f, Color::WHITE);
	Engine::Get().Graphics().DrawString("B  2-PLAYER GAME", m_fontId, 200.0f, 470.0f, Color::WHITE);
	Engine::Get().Graphics().DrawString("C  BALLOON  TRIP", m_fontId, 200.0f, 540.0f, Color::WHITE);

	Engine::Get().Graphics().DrawString("PRESS ENTER TO SELECT", m_fontId, 150.0f, 750.0f, Color::YELLOW);
}
