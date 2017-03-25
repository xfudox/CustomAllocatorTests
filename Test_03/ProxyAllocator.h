#pragma once
#include <iostream>

#define PRINT_ALLOCATION(x) std::cout<<"Allocating "<<#x<<std::endl;

class ProxyAllocator
{
public:
	~ProxyAllocator();
	static ProxyAllocator* getInstance();

private:
	ProxyAllocator();
	static ProxyAllocator* instance;
};
