#pragma once
#include "SimplePoolAllocator.h"

class ProxyAllocator
{
public:
	~ProxyAllocator();
	static ProxyAllocator* getInstance();

	template <class C>
	C* allocate();

private:
	ProxyAllocator();
	static ProxyAllocator* instance;
};

template<class C>
inline C * ProxyAllocator::allocate()
{
	C* tmp;
	tmp = SimplePoolAllocator<C>::getInstance()->allocate();
	return tmp;
}
