#include "ScalarConverter.hpp"

int	main()
{
	std::string	input;

	if (argc != 1 || !argv[1] || isempty(argv[1]))
	{
		std::cout << "No correct input" << std::endl;
		return(1);
	}
	input = argv[1];
	ScalarConverter::convert(input);
	return 0;
}
