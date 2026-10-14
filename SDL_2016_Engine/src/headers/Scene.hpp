#pragma once
#ifndef SCENE_HPP
#define SCENE_HPP
#include <map>
#include <string>
#include <memory>

class SceneFactory;
class GameObject;
struct SDL_Renderer;
class Scene {

	public:
	enum /*class*/ SceneStates : unsigned short {UNINITIALIZED=0,
											 INITIALIZED=1,
											 RUNNING=INITIALIZED<<1,
											 PAUSED=RUNNING<<1,
											 FINISHED=PAUSED<<1,
											 FAILED=FINISHED<<1,
											 ABORTED=FAILED<<1,};
	
	public:
		Scene();
		compl Scene() = default;
		Scene(const Scene&) = default;
		Scene& operator=(Scene) = delete;

	public:
		bool init(/*this will receive parameters in the future*/);
		SceneStates getState() const;
		bool update(unsigned int);
		bool render(SDL_Renderer*);
		bool clear();

	private:
		friend class SceneFactory;

	private:
		SceneStates m_state;
		std::map<std::string, std::shared_ptr<GameObject>> m_GOmap;
};

#endif