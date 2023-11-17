#include <BaseScene.h>
#include <Entity.h>
#include <Engine.h>


project::Entity* project::BaseScene::Instantiate(const std::string& name)
{
    return Engine::Get().World().Create(name);
}
