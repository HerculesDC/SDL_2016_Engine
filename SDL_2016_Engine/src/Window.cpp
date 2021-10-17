#include "../include/SDL/SDL.h"

#include "headers\Window.hpp"

Window::Window() {
	SDL_Init(SDL_INIT_VIDEO);
	m_pWindow = SDL_CreateWindow("Hello from Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0|SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE);
}

Window::compl Window() { SDL_DestroyWindow(m_pWindow); }

SDL_Window* Window::getWindow() const { return m_pWindow; }