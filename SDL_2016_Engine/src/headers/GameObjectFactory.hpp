#pragma once
#ifndef GAMEOBJECTFACTORY_HPP
#define GAMEOBJECTFACTORY_HPP
#include <memory>
#include <string>

class GameObject;
template <class T> class SingletonHolder;
class GameObjectFactory {
	public:
		static std::shared_ptr<GameObject> createGameObject(std::string);

	public:
		compl GameObjectFactory() = default;

	private:
		friend class SingletonHolder<GameObjectFactory>;
		GameObjectFactory() = default;
		GameObjectFactory(const GameObjectFactory&) = delete;
		GameObjectFactory& operator=(GameObjectFactory) = delete;

	private:
		static unsigned int ms_CurrentGameObjectID;
};

#endif