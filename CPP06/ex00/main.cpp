#include "ScalarConverter.hpp"

int	main(int argc, char *argv[])
{
	std::string	input;

	if (argc != 2 || !argv[1])
	{
		std::cout << "No correct input" << std::endl;
		return(1);
	}
	input = argv[1];
	if (input.empty())
	{
		std::cout << "Empty input" << std::endl;
		return(1);
	}
	ScalarConverter::convert(input);
	return 0;
}
