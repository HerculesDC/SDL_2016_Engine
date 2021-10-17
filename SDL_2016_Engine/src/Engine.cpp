#include "headers/SingletonHolder.hpp"
#include "headers/Engine.hpp"
#include "headers/Window.hpp"
#include "headers/Renderer.hpp"

#include "../include/SDL/SDL.h"

template <typename T> T* SingletonHolder<T>::sInstance = new T();
Engine::Engine(): m_bIsInit(false){}

Engine::compl Engine() {
	SDL_Quit();
}

void Engine::run() { 
	init();
	SDL_Delay(5000);
	quit();
}

void Engine::init() {
	SDL_Window* w = SingletonHolder<Window>::sInstance->getWindow();
	SDL_Renderer* r = SingletonHolder<Renderer>::sInstance->getRenderer();
	SDL_SetRenderDrawColor(r, 50, 0, 128, 255);
	SDL_RenderClear(r);
	SDL_RenderPresent(r);
}

void Engine::quit() {

	m_bIsInit = false;
}