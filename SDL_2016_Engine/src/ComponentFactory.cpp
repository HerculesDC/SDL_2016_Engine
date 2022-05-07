#include "headers/ComponentFactory.hpp"
#include "headers/Component.hpp"

unsigned long long int ComponentFactory<Component>::ms_currentComponentID = 0;

ComponentFactory<Component>::ComponentFactory() {}

ComponentFactory<Component>::compl ComponentFactory() {}

Component* ComponentFactory<Component>::createDefaultComponent(const char* componentName) {
	return nullptr;
}