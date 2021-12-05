#pragma once
#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include "../include/SDL/SDL.h"

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
};

#endif