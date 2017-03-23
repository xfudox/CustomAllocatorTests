#include "CustomAllocator.h"
#include <iostream>
#include <stdlib.h>

CustomAllocator::CustomAllocator(int n, int size) :
	max_num_elements(n),
	element_size(size),
	bitmap(0)
{
	pool_start = calloc(max_num_elements, element_size);
	pool_end = ((char*)pool_start) + (max_num_elements*element_size);
}


CustomAllocator::~CustomAllocator()
{
	free(pool_start);
	pool_end = nullptr;
}

void CustomAllocator::printPoolInfo()
{
	std::cout << "\tPool Info:" << std::endl;
	std::cout << "Start-end: " << (void *)pool_start << " - " << (void *)pool_end << std::endl;
	std::cout << "Size: " << ((char *)pool_end - (char *)pool_start) << " bytes" << std::endl;
}

void * CustomAllocator::allocate()
{
	uint32_t index{ getFirstFreeSlotIndex() };
	std::cout << "Allocating at " << index << std::endl;
	return (char*)pool_start+(index*element_size);
}

uint32_t CustomAllocator::getFirstFreeSlotIndex()
{
	uint32_t i{ 0 };
	while (i < max_num_elements && (bitmap >> i) & 0b1 == 1) {
		i++;
	}
	return i;
}
