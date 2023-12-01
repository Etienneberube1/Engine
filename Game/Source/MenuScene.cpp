#include "MenuScene.h"
#include "Vector3.h"
#include "Engine.h"
#include "Entity.h"
#include "Controller.h"
#include "MenuUI.h"
#include "Sprite.h"
#include "Vector3.h"
#include "Animation.h"

void project::MenuScene::Load()
{

	m_menuUI = Instantiate("menuUI");
	Entity* menu = CreateMenu();

}



project::Entity* project::MenuScene::CreateMenu()
{
	Entity* menu = Instantiate("menu");
	Entity* selectBalloon = Instantiate("selectBalloon");
	selectBalloon->AddComponent<MenuUI>();

	MenuUI* menuUI = m_menuUI->AddComponent<MenuUI>();
	Sprite* menuBackGroundSprite = m_menuUI->AddComponent<Sprite>();


	menuBackGroundSprite->Load("assets/menu/MenuTitle.png");
	m_menuUI->SetPosition(Vector3(50.0f, 50.0f, 0.0f));
	m_menuUI->SetSize(700.0f, 300.0f);





	Animation* animationBalloon = selectBalloon->AddComponent<Animation>();
	animationBalloon->Load("assets/menu/SelectBalloon.png");
	
	animationBalloon->AddFrame("balloonIdle0", 0, 0, 25, 40);	
	animationBalloon->AddFrame("balloonIdle1", 25, 0, 25, 40);
	animationBalloon->AddFrame("balloonIdle2", 50, 0, 25, 40);
	animationBalloon->AddFrame("balloonIdle3", 75, 0, 25, 40);

	animationBalloon->Init(4, 25, 40);
	animationBalloon->AddClip("balloonIdle", 0, 4, 0.3f);

	animationBalloon->Play("balloonIdle", true);

	selectBalloon->SetSize(25.0f, 40.0f);
	selectBalloon->SetPosition(Vector3(150.0f, 400.0f, 0.0f));



	

	return menu;
}
