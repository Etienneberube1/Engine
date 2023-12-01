#include "EndGameMenuUI.h"
#include "EKey.h"
#include "Engine.h"

project::EndGameMenuUI::EndGameMenuUI()
{
}

project::EndGameMenuUI::EndGameMenuUI(Entity* parent) : Component(parent), m_fontId(0)
{
	m_fontId = Engine::Get().Graphics().LoadFont("assets/fonts/pixelFont.ttf", 40);
}

project::EndGameMenuUI::~EndGameMenuUI()
{
}

void project::EndGameMenuUI::Update(float DeltaTime)
{
	if (Input().IsKeyDown(EKey::EKEY_SPACE)) {
		//Engine::Get().World().Load("menu");
		// CRASHING THE GAME IF RESTART
	}
	if (Input().IsKeyDown(EKey::EKEY_ESCAPE)) {
		Exit();
	}

}

void project::EndGameMenuUI::Draw()
{
	Engine::Get().Graphics().DrawString("   PRESS SPACE TO", m_fontId, 180.0f, 350.0f, Color::GREEN);
	Engine::Get().Graphics().DrawString(" GO BACK TO MAINMENU", m_fontId, 180.0f, 400.0f, Color::GREEN);
	
	Engine::Get().Graphics().DrawString("   PRESS ESCAPE TO", m_fontId, 180.0f, 500.0f, Color::RED);
	Engine::Get().Graphics().DrawString(" GO BACK TO MAINMENU", m_fontId, 180.0f, 550.0f, Color::RED);

}
