#pragma once
#ifndef SINGLETONHOLDER_HPP
#define SINGLETONHOLDER_HPP

template <class T> class SingletonHolder {
	public:
		static T* sInstance;
};

#endif
