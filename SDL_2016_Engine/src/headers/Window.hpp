#pragma once

#ifndef WINDOW_HPP
#define WINDOW_HPP

struct SDL_Window;
template <typename T> class SingletonHolder;

class Window {
	public:
		compl Window();
		SDL_Window* getWindow() const;

	private:
		friend class SingletonHolder<Window>;
		Window();
	
	private:
		SDL_Window* m_pWindow;
};

#endif