#pragma once
#include <cstdint>
#include <iostream>
#include <typeinfo>

#include <stdlib.h>

#define PRINT_ALLOCATION(x) std::cout << "Allocating " << sizeof(x) << " bytes" << std::endl;

template <class T>
class PoolAllocator
{
public:
	static PoolAllocator<T>* getInstance();
	T* allocate();

private:
	PoolAllocator() = delete;
	PoolAllocator(uint16_t);
	~PoolAllocator();

	static PoolAllocator<T>* instance;
	uint32_t getFirstFreeSlotIndex();
	uint32_t getFirstFreePointerIndex();
	uint32_t max_num_elements;
	uint32_t element_size;

	void*		pool_start;
	void*		pool_end;
	T**			pointers;
	std::vector<bool> bitmap;
};

template <class T>
PoolAllocator<T>* PoolAllocator<T>::instance = 0;

template <class T>
PoolAllocator<T>::PoolAllocator(uint16_t n = 32) :
	max_num_elements(n),
	element_size(sizeof(T))
{
	pool_start = calloc(max_num_elements, element_size);
	pool_end = (char*)pool_start + (max_num_elements*element_size);

	pointers = calloc(max_num_elements, sizeof(T*));
}

template <class T>
PoolAllocator<T>::~PoolAllocator()
{}

template<class T>
inline uint32_t PoolAllocator<T>::getFirstFreeSlotIndex()
{
	return uint32_t();
}

template<class T>
inline uint32_t PoolAllocator<T>::getFirstFreePointerIndex()
{
	return uint32_t();
}

template <class T>
PoolAllocator<T>* PoolAllocator<T>::getInstance()
{
	if (!instance) {
		std::cout << "Creating new PoolAllocator<" << typeid(T).name << ">(" << max_num_elements << ");" << std::endl;
		instance = new PoolAllocator<T>(32);
	}
	return instance;
}

template<class T>
inline T * PoolAllocator<T>::allocate()
{
	PRINT_ALLOCATION(T);
	uint32_t free_slot_index	= getFirstFreeSlotIndex();
	uint32_t free_pointer_index	= getFirstFreePointerIndex();
	return nullptr;
}