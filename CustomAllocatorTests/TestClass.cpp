#include "TestClass.h"
#include <iostream>

TestClass::TestClass()
{
	a = 'a';
	b = 'b';
	c = 'c';
	d = 'd';
}

TestClass::TestClass(char input) :
	a(input),
	b(input),
	c(input),
	d(input)
{
}


TestClass::~TestClass()
{
}

void TestClass::testMethod()
{
	std::cout << a << " " << b << " " << c << " " << d << std::endl;
}
