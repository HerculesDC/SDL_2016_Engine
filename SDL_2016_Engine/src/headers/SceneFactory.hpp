#pragma once
#ifndef SCENEFACTORY_HPP
#define SCENEFACTORY_HPP

#include <memory>

template<typename T> class SingletonHolder;
class Scene;
class SceneFactory {
	public:
		static std::unique_ptr<Scene> createScene(/*will get params later*/);

	private:
		friend class SingletonHolder<SceneFactory>;
		SceneFactory() = default;
		compl SceneFactory() = default;
		SceneFactory(const SceneFactory&) = delete;
		SceneFactory& operator=(SceneFactory) = delete;

		static unsigned int ms_currentSceneID;
};

#endif