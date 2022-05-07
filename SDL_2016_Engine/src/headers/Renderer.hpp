#pragma once
#ifndef RENDERER_HPP
#define RENDERER_HPP

struct SDL_Renderer;
template <class T> class SingletonHolder;
class Renderer {
	public:
		SDL_Renderer* getRenderer() const;

	private:
		friend class SingletonHolder<Renderer>;
		Renderer();
		Renderer(const Renderer&) = delete;
		Renderer& operator=(Renderer) = delete;
		compl Renderer();

	private:
		SDL_Renderer* m_pRenderer;
};

#endif