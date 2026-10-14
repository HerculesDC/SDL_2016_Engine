#include "./headers/Scene.hpp"
#include "../include/SDL/SDL_render.h"

#include "./headers/SingletonHolder.hpp"
#include "./headers/GameObject.hpp"
#include "./headers/GameObjectFactory.hpp"

Scene::Scene() : m_state(SceneStates::UNINITIALIZED) {
}

#include <iostream>
#include "./headers/Component.hpp"
//#include "./headers/ComponentFactory.hpp"
bool Scene::init() {
	std::string name = std::string("ship");
	m_GOmap.emplace(name, SingletonHolder<GameObjectFactory>::sInstance->createGameObject(name));

	std::cout << "GO ID: " << m_GOmap.at(name).get()->addComponent<Component>(name).get()->getName() << "\n";

	m_state = SceneStates::INITIALIZED;
	return true;
}

bool Scene::update(unsigned int delta_ms) {

	for (auto go : m_GOmap) {
		go.second->update(delta_ms);
	}
	return true;
}

bool Scene::render(SDL_Renderer* target) {

	SDL_SetRenderDrawColor(target, 50, 0, 128, 255);
	SDL_RenderClear(target);
	for (auto go : m_GOmap) {
		go.second->render(target);
	}
	SDL_RenderPresent(target);
	return true;
}

bool Scene::clear() {
	return true;
}

Scene::SceneStates Scene::getState()const {
	return m_state;
}