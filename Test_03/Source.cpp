#include <iostream>
#include <stdio.h>
#include "SimplePoolAllocator.h"
#include "ProxyAllocator.h"
#include "ClassA.h"
#include "ClassB.h"

int main(int argc, char *argv[]) 
{

	ProxyAllocator* pa = ProxyAllocator::getInstance();

	pa->allocate<ClassA>();
	pa->allocate<ClassB>();

	getchar();
	return 0;
}