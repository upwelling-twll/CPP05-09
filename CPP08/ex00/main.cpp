#include <iostream>
#include "easyfind.hpp"
#include <vector>

template <typename T>
void	testEasyfind(T& container, int i)
{
	int res;
	
	std::cout << "\nSearching for: " << i << std::endl;
	try {
		res = *easyfind(container, i);
		std::cout << "Found: " << res << std::endl;
	}
	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}
}

int main()
{
	std::vector<int> cont;
	for (int i = 1; i <= 5; ++i) {
		cont.push_back(i);
	}
	testEasyfind(cont, 3);
	testEasyfind(cont, 6);

	std::vector<int> cont2;
	for (int i = 1; i <= 5; ++i) {
		cont2.push_back(1);
	}
	testEasyfind(cont2, 1);

	std::vector<int> cont3;
	cont3.push_back(1);
	cont3.push_back(2);
	cont3.push_back(1);
	cont3.push_back(2);
	testEasyfind(cont3, 2);
	return 0;
}
