#include "ClassB.h"
#include "ClassB_Allocator.h"

ClassB::ClassB() :
	ll(10)
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
	return ClassB_Allocator::getInstance()->allocate();
}

long long ClassB::getValue()
{
	return ll;
}
