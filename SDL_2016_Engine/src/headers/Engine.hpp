#pragma once
#ifndef ENGINE_HPP
#define ENGINE_HPP

template <typename T> class SingletonHolder;
class Engine {
	public:
		compl Engine();
		void run();
	private:
		friend class SingletonHolder<Engine>;
		Engine();

		void init();
		void quit();

	private:
		bool m_bIsInit;
};

#endif
