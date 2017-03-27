#include <iostream>
#include <stdio.h>
#include "SimplePoolAllocator.h"
#include "ProxyAllocator.h"

int main(int argc, char *argv[]) 
{

	ProxyAllocator* pa = ProxyAllocator::getInstance();

	pa->allocate<char>();
	pa->allocate<int>();
	pa->allocate<double>();

	getchar();
	return 0;
}