#include "CustomAllocator_02.h"

#include <stdlib.h>

CustomAllocator_02::CustomAllocator_02(uint32_t n=32, uint32_t s=0) :
	num_elements(n),
	element_size(s)
{
	pool_start = calloc(num_elements, element_size);
	pool_end = ((char*)pool_start) + (num_elements*element_size);
}

CustomAllocator_02::~CustomAllocator_02()
{
}

CustomAllocator_02* CustomAllocator_02::getInstance()
{
	if (!instance)
		instance = new CustomAllocator_02();
	return instance;
}

TestClass_02 * CustomAllocator_02::allocate()
{
	std::cout << "Allocating" << std::endl;
	return nullptr;
}
