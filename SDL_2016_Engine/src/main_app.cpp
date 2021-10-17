#define SDL_MAIN_HANDLED

#include "../include/SDL/SDL.h"

#include "headers/SingletonHolder.hpp"
#include "headers/Engine.hpp"

template <class T> T* SingletonHolder<T>::sInstance = new T();
int main(void) {
	
	SingletonHolder<Engine>::sInstance->run();
	return 0;
}