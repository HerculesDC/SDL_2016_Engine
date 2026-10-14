#ifndef COMPONENTFACTORY_HPP
#define COMPONENTFACTORY_HPP
#include <memory>
#include <string>
#include <map>

//Forward declarations
template <class T> class SingletonHolder;
class Component;

//Typedefs
typedef Component* (*factoryMethod)(void);
typedef unsigned int ComponentTypeID;

class ComponentFactory{
	public:
		std::shared_ptr<Component> createDefaultSubcomponent(std::string);
		
	private:
		friend class SingletonHolder<ComponentFactory>;
		ComponentFactory();
		ComponentFactory(const ComponentFactory&) = delete;
		ComponentFactory& operator=(ComponentFactory) = delete;
		compl ComponentFactory();

	private:
		bool registerFactory(std::string, factoryMethod);
		bool isFactoryRegistered(std::string);
	
	private:
		static unsigned long int ms_currentComponentID;
		static ComponentTypeID ms_componentTypeID;
		std::map <std::string, factoryMethod> m_componentFactoryMap;
};
#endif