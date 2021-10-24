#include "headers/SingletonHolder.hpp"
#include "headers/Engine.hpp"
#include "headers/Window.hpp"
#include "headers/Renderer.hpp"

#include "../include/SDL/SDL.h"

template <typename T> T* SingletonHolder<T>::sInstance = new T();
Engine::Engine(): m_bIsInit(false), m_bIsRun(false),
				  m_iStart(0), m_iEnd(0), m_iDelta(0)
{
	m_iFPS = (int)(1000.0 / 60);
}

Engine::compl Engine() {
	SDL_Quit();
}

void Engine::run() { 
	init();
	while (m_bIsRun) {
		wake();
		processEvents();
		update(m_iDelta);
		render(SingletonHolder<Renderer>::sInstance->getRenderer());
		sleep();
	}
	quit();
}

void Engine::init() {
	SingletonHolder<Window>::sInstance->getWindow();
	m_bIsInit = true;
	m_bIsRun = true;
}

void Engine::wake() {
	m_iStart = SDL_GetTicks();
}

void Engine::sleep(){
	m_iEnd = SDL_GetTicks();
	m_iDelta = m_iEnd - m_iStart;
	if (m_iDelta < m_iFPS) {
		SDL_Delay(m_iFPS - m_iDelta);
	}
}

void Engine::processEvents() {
	SDL_Event evt;
	if (SDL_PollEvent(&evt)){
		switch (evt.type) {
			case SDL_QUIT:
				m_bIsRun = false;
				break;
		}
	}
}

void Engine::update(unsigned int delta_ms) {}

void Engine::render(SDL_Renderer* renderTarget) {
	SDL_SetRenderDrawColor(renderTarget, 50, 0, 128, 255);
	SDL_RenderClear(renderTarget);
	SDL_RenderPresent(renderTarget);
}

void Engine::quit() {

	m_bIsInit = false;
}