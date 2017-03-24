#pragma once
#include <cstdint>
#include <iostream>

class TestClass_02;

class CustomAllocator_02
{
public:
	CustomAllocator_02(CustomAllocator_02 const&) = delete;
	~CustomAllocator_02();
	void operator=(CustomAllocator_02 const&) = delete;

	static CustomAllocator_02* getInstance();
	TestClass_02* allocate();

private:
	CustomAllocator_02(uint32_t, uint32_t);
	static CustomAllocator_02* instance;
	void* pool_start;
	void* pool_end;
	uint32_t element_size;
	uint32_t num_elements;
};

