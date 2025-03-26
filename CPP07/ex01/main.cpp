#include <iostream>
#include "Iter.hpp"
#include "Swap.hpp"

template <typename T>
void printArr(T &element)
{
	std::cout << element << " ";
}

template <typename T>
void addSymbol(T& element)
{
	element =  element + "!";
}

template <typename T, std:: size_t N>
std::size_t lengthArr(T (&arr)[N])
{
	if (arr)
		return (N);
	return (0);
}

int main()
{
	std::string Arr[] = {"ABU DHABI", "RAS AL KHAIMAH", "UMM AL QUWAIN", "FUJAIRAH", "DUBAI", "AJMAN", "SHARJAH"};
	int length = sizeof(Arr) / sizeof(Arr[0]);

	iter(Arr, length, printArr);

	std::cout << std::endl;
	swap(Arr[0], Arr[length - 1]);
	iter(Arr, length, printArr);

	std::cout << std::endl;
	iter(Arr, length, addSymbol);
	iter(Arr, length, printArr);

	std::cout << std::endl;
	int	Arr2[] = {1, 10, 100, 1000};
	int length2 = lengthArr(Arr2);
	// iter(Arr2, length2, );
	iter(Arr2, length2, printArr);
}