#include <iostream>
#include <stdio.h>	//getc
//#include <new>

#include "CustomAllocator.h"
#include "TestClass.h"

#define MAX_NUM_ELEMENTS 32

int main(int argc, char *argv[])
{

	CustomAllocator testClassAllocator{ MAX_NUM_ELEMENTS,sizeof(TestClass) };

	testClassAllocator.printPoolInfo();

	TestClass* tc = new((TestClass*)testClassAllocator.allocate()) TestClass();

	std::cout << "*tc = " << (void*)tc << std::endl;
	tc->testMethod();

	getchar();
	return 0;
}