#ifndef ITER_HPP
#define ITER_HPP

template <typename T, typename F>
void iter(T* arr, int length, F func)
{
	for (int i = 0; i < length; ++i)
		func(arr[i]);
}

// template <typename T>
// void iterOld(T* arr, int length,  void (*func)(T&))
// {
// 	for (int i = 0; i < length; ++i)
// 		func(arr[i]);
// }

#endif