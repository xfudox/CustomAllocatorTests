#pragma once

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
	void *_pool_start, *_pool_end;
	uint32_t _max_num_elements;
};

