#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <vector>

template <typename T>
typename T::iterator easyfind(T& container, int i)
{
	typename T::iterator it = std::find(container.begin(), container.end(), i);
	if (it != container.end())
	{
		return it;
	}
	else
	{
		throw std::runtime_error("Value not found in container");
	}
}

#endif