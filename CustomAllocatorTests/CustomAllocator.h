#pragma once

class CustomAllocator
{
public:
	CustomAllocator() = delete;
	CustomAllocator(int max_num_elements, int element_size);
	CustomAllocator& operator=(const CustomAllocator&) = delete;
	~CustomAllocator();

	void* allocate();

private:
	void *pool_start, *pool_end;
};

