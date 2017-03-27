#pragma once

template<class C>
inline C * ProxyAllocator::allocate()
{
	// std::cout << "Allocating a " << typeid(C).name() << " (" << typeid(C).hash_code() << ")" << std::endl;

	C* tmp;
	tmp = SimplePoolAllocator<C>::getInstance()->allocate();
	return tmp;
}
