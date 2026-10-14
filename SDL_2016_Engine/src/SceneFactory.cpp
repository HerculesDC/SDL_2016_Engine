#include "./headers/SceneFactory.hpp"
#include "./headers/Scene.hpp"

unsigned int SceneFactory::ms_currentSceneID = 0;

std::unique_ptr<Scene> SceneFactory::createScene() {
	
	std::unique_ptr<Scene> scene = std::make_unique<Scene>();
	scene->init();
	return scene;
}
