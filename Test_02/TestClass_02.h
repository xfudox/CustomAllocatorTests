#pragma once
#include <string>
#include <iostream>

class TestClass_02
{
public:
	TestClass_02();
	TestClass_02(const char* input);
	~TestClass_02();

	void print();

private:
	char c;
	std::string str;
};

