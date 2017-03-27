#pragma once
#include <cstdint>
#include <iostream>

#include <stdlib.h>

#define PRINT_ALLOCATION(x) std::cout << "Allocating " << sizeof(x) << " bytes" << std::endl;

template <class T>
class SimplePoolAllocator
{
public:
	static SimplePoolAllocator<T>* getInstance();
	T* allocate();

private:
	SimplePoolAllocator() = delete;
	SimplePoolAllocator(int);
	~SimplePoolAllocator();

	static SimplePoolAllocator<T>* instance;
	uint32_t getFirstFreeSlotIndex();
	uint32_t getFirstFreePointerIndex();
	uint32_t max_num_elements;
	uint32_t element_size;

	void*		pool_start;
	void*		pool_end;
	uint32_t*	bitmap;
	T**			pointers
};

template <class T>
SimplePoolAllocator<T>* SimplePoolAllocator<T>::instance = 0;

template <class T>
SimplePoolAllocator<T>::SimplePoolAllocator(int n = 32) :
	max_num_elements(n),
	element_size(sizeof(T))
{
	pool_start = calloc(max_num_elements, element_size);
	pool_end = (char*)pool_start + (max_num_elements*element_size);

	bitmap = calloc((n >> 5), sizeof(uint32_t));
	pointers = calloc(max_num_elements, sizeof(T*));
}

template <class T>
SimplePoolAllocator<T>::~SimplePoolAllocator()
{}

template<class T>
inline uint32_t SimplePoolAllocator<T>::getFirstFreeSlotIndex()
{
	uint32_t index = uint32_t(0);
	while (((bitmap >> index) & 0b1) == 0)
		index++;
	return index;
}

template<class T>
inline uint32_t SimplePoolAllocator<T>::getFirstFreePointerIndex()
{
	return uint32_t();
}

template <class T>
SimplePoolAllocator<T>* SimplePoolAllocator<T>::getInstance()
{
	if (!instance)
		instance = new SimplePoolAllocator<T>(32);
	return instance;
}

template<class T>
inline T * SimplePoolAllocator<T>::allocate()
{
	PRINT_ALLOCATION(T);
	uint32_t free_slot_index	= getFirstFreeSlotIndex();
	uint32_t free_pointer_index	= getFirstFreePointerIndex();
	return nullptr;
}