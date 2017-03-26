#include <iostream>
#include <stdio.h>
#include "SimplePoolAllocator.h"
#include "ProxyAllocator.h"

int main(int argc, char *argv[]) 
{
	/*
	SimplePoolAllocator<int>* allocator_int = SimplePoolAllocator<int>::getInstance();
	SimplePoolAllocator<char>* allocator_char = SimplePoolAllocator<char>::getInstance();
	std::cout << "allocator_int->templatedClassSize() = "  << allocator_int->templatedClassSize()  << std::endl;
	std::cout << "allocator_char->templatedClassSize() = " << allocator_char->templatedClassSize() << std::endl;
	*/

	ProxyAllocator* pa = ProxyAllocator::getInstance();

	pa->allocate<char>();
	pa->allocate<int>();
	pa->allocate<double>();

	getchar();
	return 0;
}