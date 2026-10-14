#pragma once
#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP
#include <map>
#include <memory>
#include <string>

#include "../include/SDL/SDL.h"

class GameObjectFactory;
class Component;

class GameObject {

	public:
		template <typename T>
		std::shared_ptr<T> addComponent(std::string);
		template <typename T>
		std::shared_ptr<T> removeComponent(std::string);
		template <typename T>
		std::shared_ptr<T> getComponent(std::string);
		bool hasComponent(std::string) const;

	public:
		void init();
		void update(unsigned int delta_ms);
		void render(SDL_Renderer* renderTarget);


	public:
		compl GameObject();
		GameObject(std::string, unsigned int);
		GameObject() = delete;

	private:
		friend class GameObjectFactory;

	private:
		unsigned int m_iID;
		std::string m_name;
		SDL_Surface* m_surf;
		SDL_Rect m_rect;
		std::map<std::string, std::shared_ptr<Component>> m_ComponentMap;
};

#endif