#include "CustomAllocator.h"
#include <iostream>
#include <stdlib.h>

CustomAllocator::CustomAllocator(int n, int size) :
	_max_num_elements(n)
{
	_pool_start = calloc(_max_num_elements, size);
	_pool_end = ((char*)_pool_start) + (_max_num_elements*size);
}


CustomAllocator::~CustomAllocator()
{
	free(_pool_start);
	_pool_end = nullptr;
}

void CustomAllocator::printPoolInfo()
{
	std::cout << "\tPool Info:" << std::endl;
	std::cout << "Start-end: " << (void *)_pool_start << " - " << (void *)_pool_end << std::endl;
	std::cout << "Size: " << ((char *)_pool_end - (char *)_pool_start) << "bytes" << std::endl;
}

void * CustomAllocator::allocate()
{
	std::cout << "Allocated" << std::endl;
	return nullptr;
}
