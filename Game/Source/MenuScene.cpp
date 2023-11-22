#include "MenuScene.h"
#include "Vector3.h"
#include "Engine.h"
#include "Entity.h"
#include "Controller.h"



void project::MenuScene::Load()
{

	Entity* menu = CreateMenu();

}



project::Entity* project::MenuScene::CreateMenu()
{
	Entity* menu = Instantiate("menu");

	//Controller* menuController = menu->AddComponent<Controller>();


	return menu;
}
