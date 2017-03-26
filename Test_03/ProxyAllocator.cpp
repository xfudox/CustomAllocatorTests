#include "ProxyAllocator.h"

ProxyAllocator* ProxyAllocator::instance = 0;

ProxyAllocator::ProxyAllocator()
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
