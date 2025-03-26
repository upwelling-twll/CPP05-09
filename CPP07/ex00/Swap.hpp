#ifndef SWAP_HPP
# define SWAP_HPP

#include <iostream>
#include "Animal.hpp"

template <typename T>
T min(T a, T b)
{
	if (a < b)
		return (a);
	return (b);
}

template <typename T>
T max(T a, T b)
{
	if (a > b)
		return (a);
	return (b);
}

template <typename T>
void swap(T& a, T& b)
{
	T temp = a;

	a = b;
	b = temp;
}

#endif