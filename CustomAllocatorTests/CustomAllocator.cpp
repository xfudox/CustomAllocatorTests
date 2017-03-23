#include "CustomAllocator.h"
#include <iostream>
#include <stdlib.h>

CustomAllocator::CustomAllocator(int max_num_elements, int element_size)
{
	pool_start = calloc(max_num_elements, element_size);
	pool_end = ((char*)pool_start) + (max_num_elements*element_size);
}


CustomAllocator::~CustomAllocator()
{
	free(pool_start);
	pool_end = nullptr;
}

void * CustomAllocator::allocate()
{
	std::cout << "Allocated" << std::endl;
	return nullptr;
}
