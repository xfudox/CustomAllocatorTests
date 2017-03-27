#pragma once
#include <map>
#include <typeinfo>
#include <ctime>
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
	std::map<char*, uint32_t > statistics;
};



template<class C>
inline C * ProxyAllocator::allocate()
{
	// std::cout << "Allocating a " << typeid(C).name() << " (" << typeid(C).hash_code() << ")" << std::endl;
	clock_t time;
	C* tmp;

	time = clock();
	tmp = SimplePoolAllocator<C>::getInstance()->allocate();
	time = clock() - time;

	if (statistics.find(typeid(C).name()) == statistics.end())
	{
		statistics.insert(std::pair<char*, uint32_t>(typeid(C).name(),1));
	}
	else
	{
		std::pair<char*, uint32_t>  stats;
	}

	return tmp;
}
