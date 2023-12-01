#include "EndGameMenu.h"
#include "Vector3.h"
#include "Entity.h"
#include "EndGameMenuUI.h"
#include "Sprite.h"
#include "Animation.h"
#include "Engine.h"


void project::EndGameMenu::Load()
{
	m_UI = Instantiate("endMenuUI");
	Entity* menu = CreateMenu();
	
	m_menuMusic = Engine::Get().Audio().LoadMusic("assets/audio/EndGameSound.mp3");
	Engine::Get().Audio().PlayMusic(m_menuMusic);
}

project::Entity* project::EndGameMenu::CreateMenu()
{
	Entity* menu = Instantiate("EndGameMenu");

	m_UI->AddComponent<EndGameMenuUI>();

	Sprite* menuBackGroundSprite = m_UI->AddComponent<Sprite>();

	menuBackGroundSprite->Load("assets/menu/MenuTitle.png");
	m_UI->SetPosition(Vector3(50.0f, 50.0f, 0.0f));
	m_UI->SetSize(700.0f, 300.0f);


	return menu;
}
