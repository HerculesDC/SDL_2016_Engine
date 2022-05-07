#pragma once
#ifndef ENGINE_HPP
#define ENGINE_HPP

class GameObject;

struct SDL_Surface;
struct SDL_Renderer;
template <typename T> class SingletonHolder;
class Engine {
	public:
		void run();
	private:
		friend class SingletonHolder<Engine>;
		Engine();
		Engine(const Engine&) = delete;
		Engine& operator=(Engine other) = delete;
		compl Engine();

		void init();
		void wake();
		void sleep();
		void processEvents();
		void update(unsigned int);
		void render(SDL_Renderer*);
		void quit();

	private:
		bool m_bIsInit;
		bool m_bIsRun;
		unsigned int m_iStart, m_iEnd, m_iDelta, m_iFPS;

		//REMOVE LATER:
		GameObject* go_test;
};

#endif
