#include "../include/SDL/SDL_render.h"
#include "headers/SingletonHolder.hpp"
#include "headers/Window.hpp"
#include "headers/Renderer.hpp"

template <class T> T* SingletonHolder<T>::sInstance = new T();
Renderer::Renderer() {
	m_pRenderer = SDL_CreateRenderer(SingletonHolder<Window>::sInstance->getWindow(), -1, 0);
}

Renderer::compl Renderer() { SDL_DestroyRenderer(m_pRenderer); }

SDL_Renderer* Renderer::getRenderer() const{ return m_pRenderer; }