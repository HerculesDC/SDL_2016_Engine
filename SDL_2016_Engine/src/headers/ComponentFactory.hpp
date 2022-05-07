#ifndef COMPONENTFACTORY_HPP
#define COMPONENTFACTORY_HPP

template <typename T> class SingletonHolder;
class Component;
template <class T>
class ComponentFactory{
	public:
		static T* createDefaultComponent(const char*);

	private:
		friend class SingletonHolder<ComponentFactory>;
		ComponentFactory();
		ComponentFactory(const ComponentFactory&) = delete;
		ComponentFactory& operator=(ComponentFactory) = delete;
		compl ComponentFactory();

	private:
		static unsigned long long int ms_currentComponentID;
};

#endif