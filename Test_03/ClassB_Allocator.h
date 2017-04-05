#pragma once
#include <cstdint>

class ClassB_Allocator
{
public:
	static ClassB_Allocator* getInstance();
	void* allocate();

private:
	ClassB_Allocator();
	~ClassB_Allocator();

	static ClassB_Allocator* instance;
	uint32_t allocation_count;
	uint32_t max_num_elements;
};

