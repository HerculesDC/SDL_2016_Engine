#include "../include/SDL/SDL_image.h"
//#include "../include/SDL/SDL.h"
#include "./headers/SingletonHolder.hpp"
#include "./headers/GameObject.hpp"
#include "./headers/Component.hpp"
#include "./headers/ComponentFactory.hpp"

//template <template <typename U> class T> T<U>* SingletonHolder<T<U>>::sInstance = new T<U>();
//template <typename T> T* SingletonHolder<T>::sInstance = new T();

template<typename T>
std::shared_ptr<T> GameObject::addComponent(std::string compName) {
	if (hasComponent(compName)) {
		return m_ComponentMap.at(compName);
	}
	m_ComponentMap.emplace(compName,SingletonHolder<ComponentFactory>::sInstance->createDefaultSubcomponent<T>(compName));
	return m_ComponentMap.at(compName);
}

template<typename T>
std::shared_ptr<T> GameObject::removeComponent(std::string compName) {
	if (!hasComponent(compName)) {
		return nullptr;
	}
	std::shared_ptr<T> removed = m_ComponentMap.at(compName);
	m_ComponentMap.erase(compName);
	removed.get()->setParent(nullptr);
	return removed;
}

template<typename T>
std::shared_ptr<T> GameObject::getComponent(std::string compName) {
	if (!hasComponent(compName)) {
		return nullptr;
	}
	return m_ComponentMap.at(compName);
}

bool GameObject::hasComponent(std::string key) const {
	return m_ComponentMap.find(key)!= m_ComponentMap.end();
}

GameObject::GameObject(std::string name, unsigned int id) :
	m_iID(id),
	m_name(name),
	m_surf(nullptr)
{
	if (!m_surf) {
		m_surf = IMG_Load("../Media/Images/Spaceship_01_ORANGE.png");
	}
	SDL_GetClipRect(m_surf, &m_rect);
}

GameObject::compl GameObject() {
	SDL_free(m_surf);
}

void GameObject::init() {
	m_rect.x = 150;
	m_rect.y = 100;
}

void GameObject::update(unsigned int delta_ms) {}

void GameObject::render(SDL_Renderer* renderTarget) {
	SDL_RenderCopy(renderTarget, SDL_CreateTextureFromSurface(renderTarget, m_surf), nullptr, &m_rect);
}
