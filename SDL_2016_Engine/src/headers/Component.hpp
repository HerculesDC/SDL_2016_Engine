#ifndef COMPONENT_HPP
#define COMPONENT_HPP
#include <string>
#include <memory>

typedef unsigned int ComponentTypeID;

class GameObject;
class ComponentFactory;
struct SDL_Renderer;
class Component {
	public:
		Component();
		virtual compl Component()=0;
		enum class ComponentState:unsigned short{CREATED=0,INITIALIZED=1,DEINITIALIZED=2,PARENTLESS=3,FAILED=4};

	public:
		virtual void update(unsigned int);
		virtual void render(SDL_Renderer*);

	public:	
		void setParent(GameObject*);
		GameObject* getParent() { return m_parentGO; }
		std::string getName() const { return m_compName; }
		unsigned long int getID() const { return m_compID; }
		ComponentTypeID getTypeId() const { return m_compTypeID; }

	private:
		virtual void initComponent(ComponentTypeID, unsigned long int, std::string, GameObject*);

	protected:
		friend class GameObject;
		friend class ComponentFactory;
		ComponentState m_compState;
		ComponentTypeID m_compTypeID;
		unsigned long int m_compID;
		std::string m_compName;
		GameObject* m_parentGO;
};

#endif
