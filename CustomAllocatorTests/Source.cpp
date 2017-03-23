#include <iostream>
#include <stdio.h>	//getc

#include "CustomAllocator.h"
#include "TestClass.h"

#define MAX_NUM_ELEMENTS 32

int main(int argc, char *argv[])
{

	CustomAllocator testAllocator{ MAX_NUM_ELEMENTS,sizeof(TestClass) };

	getchar();
	return 0;
}