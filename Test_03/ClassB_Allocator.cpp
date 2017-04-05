#include "ClassB_Allocator.h"
#include "PoolAllocator.h"
#include "ClassB.h"

ClassB_Allocator * ClassB_Allocator::getInstance()
{
	if (!instance)
		instance = new ClassB_Allocator();
	return instance;
}

void * ClassB_Allocator::allocate()
{
	allocation_count++;
	return PoolAllocator<ClassB>::getInstance()->allocate();
}

ClassB_Allocator::ClassB_Allocator()
	: max_num_elements(32)
{
}


ClassB_Allocator::~ClassB_Allocator()
{
}
