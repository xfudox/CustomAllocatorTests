#include "TestClass_02.h"



TestClass_02::TestClass_02() :
	str("default")
{
}

TestClass_02::TestClass_02(const char * input) :
	str(input)
{
}

TestClass_02::~TestClass_02()
{
}

void TestClass_02::print()
{
	std::cout << str << std::endl;
}
