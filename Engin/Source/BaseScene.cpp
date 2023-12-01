#include <BaseScene.h>
#include <Entity.h>
#include <Engine.h>

// Implementation of Instantiate function.
project::Entity* project::BaseScene::Instantiate(const std::string& name)
{
    // Creates an entity within the world using the provided name.
    return Engine::Get().World().Create(name);
}
