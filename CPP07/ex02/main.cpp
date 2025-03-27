#include "Array.hpp"
#include <iostream>

int main()
{
	std::cout << "		Test regular array" << std::endl;
	int* a = new int();
	std::cout << *a << std::endl;
	std::cout << std::endl;
	for (unsigned int i = 0; i <  3; ++i)
	{
		std::cout << a[i] << std::endl;
	}

	std::cout << std::endl;
	std::cout << "		Test template Array class" << std::endl;
	Array<int> b(3);
	for (unsigned int i = 0; i <  3; ++i)
	{
		b[i] = 10;
	}
	for (unsigned int i = 0; i <  3; ++i)
	{
		std::cout << b[i] << std::endl;
	}

	std::cout << std::endl;
	std::cout << "c=b" << std::endl;
	Array<int> c = b;
	std::cout << "c" << std::endl;
	for (unsigned int i = 0; i <  3; ++i)
	{
		std::cout << c[i] << std::endl;
	}
	std::cout << "b" << std::endl;
	for (unsigned int i = 0; i <  3; ++i)
	{
		std::cout << b[i] << std::endl;
	}

	std::cout << std::endl;
	Array<std::string> fun(10);
	// std::cout << fun << std::endl;
	for (unsigned int i = 0; i < fun.size(); ++i)
	{
		fun[i] = "haHa!";
	}
	for (unsigned int i = 0; i < fun.size(); ++i)
	{
		std::cout << fun[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Array sizes" << std::endl;
	std::cout << b.size() <<std::endl;
	std::cout << c.size() <<std::endl;
	std::cout << fun.size() <<std::endl;
	
	std::cout << std::endl;

	std::cout << "Ceck out of bounds acces for b" << std::endl;
	try 
	{
		for (unsigned int i = 0; i <  4; ++i)
		{
			std::cout << b[i] << std::endl;
		}
	} 
	catch (const std::exception& e) 
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	return 0;
}