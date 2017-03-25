#pragma once
#include <cstdint>

template <class T>
class SimplePoolAllocator
{
public:
	~SimplePoolAllocator();
	static SimplePoolAllocator<T>* getInstance();

	int templatedClassSize();

private:
	SimplePoolAllocator() = delete;
	SimplePoolAllocator(int);

	static SimplePoolAllocator<T>* instance;
	uint32_t max_num_elements;
};

template <class T>
SimplePoolAllocator<T>* SimplePoolAllocator<T>::instance = 0;

template <class T>
SimplePoolAllocator<T>::SimplePoolAllocator(int n = 32) :
	max_num_elements(n)
{}

template <class T>
SimplePoolAllocator<T>::~SimplePoolAllocator()
{}

template <class T>
SimplePoolAllocator<T>* SimplePoolAllocator<T>::getInstance()
{
	if (!instance)
		instance = new SimplePoolAllocator<T>(32);
	return instance;
}

template <class T>
int SimplePoolAllocator<T>::templatedClassSize()
{
	return sizeof(T);
}