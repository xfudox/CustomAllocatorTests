#include "ClassA.h"



ClassA::ClassA()
{
}

ClassA::ClassA(int input):
	i(input)
{
}


ClassA::~ClassA()
{
}

int ClassA::getValue()
{
	return i;
}
