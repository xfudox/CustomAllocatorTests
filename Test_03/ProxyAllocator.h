#pragma once
#include <map>
#include <typeinfo>
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
	void incrementCount(const char*);

	static ProxyAllocator* instance;
	std::map<char*, uint32_t> allocationCount;
};

template<class C>
inline C * ProxyAllocator::allocate()
{
	std::cout << "Allocating a " << typeid(C).name() << std::endl;
	C* tmp;
	tmp = SimplePoolAllocator<C>::getInstance()->allocate();
	return tmp;
}
