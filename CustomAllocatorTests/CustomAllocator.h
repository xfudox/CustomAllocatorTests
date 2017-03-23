#pragma once
#include <cstdint>

class CustomAllocator
{
public:
	CustomAllocator() = delete;
	CustomAllocator(int max_num_elements, int element_size);
	CustomAllocator& operator=(const CustomAllocator&) = delete;
	~CustomAllocator();

	void printPoolInfo();

	void* allocate();

private:
	void *pool_start, *pool_end;
	uint32_t max_num_elements;
	uint32_t element_size;
	uint32_t bitmap;

	uint32_t getFirstFreeSlotIndex();
};

