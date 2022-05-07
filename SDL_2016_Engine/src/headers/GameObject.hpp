#pragma once
#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP
#include <map>
#include <string>

#include "../include/SDL/SDL.h"
class Component;
class GameObject {
	public:
		void init();
		void update(unsigned int delta_ms);
		void render(SDL_Renderer* renderTarget);

		GameObject(unsigned int id, SDL_Surface* surf);

	private:
		unsigned int m_iID;
		SDL_Surface* m_surf;
		SDL_Rect m_rect;
		std::map<std::string, Component*> m_components;
};

#endif