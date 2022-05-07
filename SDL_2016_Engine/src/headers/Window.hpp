#pragma once

#ifndef WINDOW_HPP
#define WINDOW_HPP

struct SDL_Window;
template <typename T> class SingletonHolder;

class Window {
	public:
		SDL_Window* getWindow() const;

	private:
		friend class SingletonHolder<Window>;
		Window();
		Window(const Window&) = delete;
		Window& operator=(Window) = delete;
		compl Window();

	private:
		SDL_Window* m_pWindow;
};

#endif