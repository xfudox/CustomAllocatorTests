#include "ClassB.h"



ClassB::ClassB()
{
}

ClassB::ClassB(long long input) :
	ll(input)
{
}


ClassB::~ClassB()
{
}

long long ClassB::getValue()
{
	return ll;
}
