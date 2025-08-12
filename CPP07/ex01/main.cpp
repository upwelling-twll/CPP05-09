#include <iostream>
#include "Iter.hpp"
#include "Swap.hpp"

class Awesome
{
    public:
    Awesome( void ) : _n( 42 ) {return;}
    int get(void) const { return this->_n; }
    private:
    int _n;
};

std::ostream & operator<<(std::ostream & o,Awesome const & rhs){o<<rhs.get(); return o; }


template <typename T>
void printArr(T const  &element)
{
	std::cout << element << " ";
}

template <typename T>
void addSymbol(T& element)
{
	element =  element + "!";
}

template <typename T>
void incr(T &elem)
{
	elem += 1;
}

template <typename T, std:: size_t N>
std::size_t lengthArr(T (&arr)[N])
{
	if (arr)
		return (N);
	return (0);
}

template <typename T>
void print( T const & x )
{
    std::cout << x << std::endl;
    return;
}


int main()
{
	std::string Arr[] = {"ABU DHABI", "RAS AL KHAIMAH", "UMM AL QUWAIN", "FUJAIRAH", "DUBAI", "AJMAN", "SHARJAH"};
	int length = sizeof(Arr) / sizeof(Arr[0]);

	iter(Arr, length, printArr<std::string>);

	std::cout << std::endl;
	swap(Arr[0], Arr[length - 1]);
	iter(Arr, length, printArr<std::string>);

	std::cout << std::endl;
	iter(Arr, length, addSymbol<std::string>);
	iter(Arr, length, printArr<std::string>);

	std::cout << std::endl;

	int	Arr2[] = {1, 10, 100, 1000};
	int length2 = lengthArr(Arr2);
	iter(Arr2, length2, printArr<int>);

	std::cout << std::endl;

	const int Arr3[] = {-1, -2, -3, -4};
	int length3 = sizeof(Arr3) / sizeof(Arr3[0]);
	// iter(Arr3, lengthArr(Arr3), incr<int>); // <-----test const write
	iter(Arr3, length3, printArr<int>);
	
	std::cout << std::endl;

	// iter(Arr3, lengthArr(Arr3), incr<int>); // <-----test const write
	std::cout << std::endl;
	iter(Arr2, length3, print<int>);

	Awesome tab2[5];
	const int tab[] = {1,2,3,4};

	iter(tab2, 5, printArr<Awesome>);
	std::cout << std::endl;
    iter(tab, 4, printArr<const int>);
    // iter(tab, 4, incr<int>); // <-----test const write
}


