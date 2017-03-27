#pragma once
class ClassB
{
public:
	ClassB();
	ClassB(long long);
	~ClassB();

	void* operator new(size_t);

	long long getValue();

private:
	long long ll;
};

