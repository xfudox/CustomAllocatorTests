#include "ClassB.h"
#include "SimplePoolAllocator.h"


ClassB::ClassB()
{
}

ClassB::ClassB(long long input) :
	ll(input)
{
}


ClassB::~ClassB()
{
}

void * ClassB::operator new(size_t)
{
	return SimplePoolAllocator<ClassB>::getInstance()->allocate();
}

long long ClassB::getValue()
{
	return ll;
}
