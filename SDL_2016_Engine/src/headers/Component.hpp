

#ifndef COMPONENT_HPP
#define COMPONENT_HPP

template <typename T> class ComponentFactory;
class GameObject;
class SDL_Renderer;
class Component {
	public:
		virtual void init();
		virtual void update(unsigned int delta_ms);
		virtual void render(SDL_Renderer* renderTarget);
		virtual compl Component() = 0;

	protected:
		friend class ComponentFactory<Component>;
		Component();		
		compl Component();

		unsigned int m_compID;
		Component* m_parent;
		GameObject* m_owner;
};

#endif
