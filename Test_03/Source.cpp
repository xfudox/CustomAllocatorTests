#include <iostream>
#include <stdio.h>
#include "SimplePoolAllocator.h"
#include "ClassA.h"
#include "ClassB.h"

int main(int argc, char *argv[]) 
{
	SimplePoolAllocator<ClassA>* class_a_allocator = SimplePoolAllocator<ClassA>::getInstance();

	getchar();
	return 0;
}