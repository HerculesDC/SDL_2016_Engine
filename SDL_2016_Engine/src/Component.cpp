#include "headers/Component.hpp"

Component::Component() :
	m_compID(0),
	m_compName(""),
	m_compTypeID(0),
	m_parentGO(nullptr),
	m_compState(ComponentState::CREATED)
{
}

Component::compl Component() {
	
	m_parentGO = nullptr;
	delete m_parentGO;
	m_compState = ComponentState::DEINITIALIZED;
}

void Component::initComponent(ComponentTypeID compTypeID, unsigned long int componentID, std::string compName, GameObject* parent) {
	m_compTypeID = compTypeID;
	m_compID = componentID;
	m_compName = compName;
	m_parentGO = parent;
}

void Component::update(unsigned int delta_ms){}

void Component::render(SDL_Renderer* renderTarget){}

void Component::setParent(GameObject* parent) {
	m_parentGO = parent;
}