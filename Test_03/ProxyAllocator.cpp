#include "ProxyAllocator.h"

ProxyAllocator* ProxyAllocator::instance = 0;

ProxyAllocator::ProxyAllocator()
{
}

void ProxyAllocator:: incrementCount(const char *)
{
}

ProxyAllocator::~ProxyAllocator()
{
}

ProxyAllocator * ProxyAllocator::getInstance()
{
	if (!instance)
		instance = new ProxyAllocator();
	return instance;
}
