#include "./headers/ComponentFactory.hpp"
#include "./headers/Component.hpp"

unsigned long int ComponentFactory::ms_currentComponentID = 0;

ComponentFactory::ComponentFactory() {}

ComponentFactory::compl ComponentFactory() {
	m_componentFactoryMap.clear();
}

bool ComponentFactory::registerFactory(std::string methodName, factoryMethod method) {
	if (isFactoryRegistered(methodName)) {
		return false; //method already registered
	}
	m_componentFactoryMap.emplace(methodName, method);

	return isFactoryRegistered(methodName);
}

bool ComponentFactory::isFactoryRegistered(std::string methodName) {
	return m_componentFactoryMap.find(methodName) != m_componentFactoryMap.end();
}

std::shared_ptr<Component> ComponentFactory::createDefaultSubcomponent(std::string componentName) {
	//This is where it gets hairy
	//std::shared_ptr<Component> comp = std::make_shared<Component>();
	auto searchComponent = m_componentFactoryMap.find(componentName);
	if (searchComponent == m_componentFactoryMap.end())
		return nullptr;
	std::shared_ptr<Component> comp = std::make_shared<Component>(searchComponent->second());
	return comp;
}