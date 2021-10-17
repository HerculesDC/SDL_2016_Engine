#pragma once
#ifndef RENDERER_HPP
#define RENDERER_HPP

struct SDL_Renderer;
template <class T> class SingletonHolder;
class Renderer {
	public:
		compl Renderer();
		SDL_Renderer* getRenderer() const;

	private:
		friend class SingletonHolder<Renderer>;
		Renderer();

	private:
		SDL_Renderer* m_pRenderer;
};

#endif