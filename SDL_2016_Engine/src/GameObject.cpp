#include "../include/SDL/SDL_image.h"
#include "headers/GameObject.hpp"


GameObject::GameObject(unsigned int id, SDL_Surface* surf = nullptr):
	m_iID(id),
	m_surf(surf)
{
	if (!m_surf) {
		m_surf = IMG_Load("../Media/Images/Spaceship_01_ORANGE.png");
	}
	SDL_GetClipRect(m_surf, &m_rect);
}

void GameObject::init() {
	m_rect.x = 150;
	m_rect.y = 100;
}

void GameObject::update(unsigned int delta_ms) {}

void GameObject::render(SDL_Renderer* renderTarget) {
	SDL_RenderCopy(renderTarget, SDL_CreateTextureFromSurface(renderTarget, m_surf), nullptr, &m_rect);
}