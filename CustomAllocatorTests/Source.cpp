#include <iostream>
#include <stdio.h>

#include "CustomAllocator.h"
#include "TestClass.h"

#define MAX_NUM_ELEMENTS 32

int main(int argc, char *argv[])
{

	CustomAllocator testClassAllocator{ MAX_NUM_ELEMENTS,sizeof(TestClass) };

	testClassAllocator.printPoolInfo();

	TestClass* tc_01 = new((TestClass*)testClassAllocator.allocate()) TestClass();
	TestClass* tc_02 = new((TestClass*)testClassAllocator.allocate()) TestClass();

	getchar();
	return 0;
}