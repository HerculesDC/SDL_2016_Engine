#pragma once
#ifndef SINGLETONHOLDER_HPP
#define SINGLETONHOLDER_HPP

template <class T> class SingletonHolder {
	public:
		static T* sInstance;

	private:
		SingletonHolder() = default;
		SingletonHolder(const SingletonHolder&) = delete;
		SingletonHolder& operator=(SingletonHolder) = delete;
		compl SingletonHolder(){}
};

#endif
