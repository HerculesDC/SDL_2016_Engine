#include "./headers/GameObjectFactory.hpp"
#include "./headers/GameObject.hpp"

unsigned int GameObjectFactory::ms_CurrentGameObjectID = 0;
std::shared_ptr<GameObject> GameObjectFactory::createGameObject(std::string goName) {

	std::shared_ptr<GameObject> gameObject = std::make_shared<GameObject>(goName, ms_CurrentGameObjectID++);
	return gameObject;
}