#include "ScalarConverter.hpp"

/*Member functions*/
int	countOccurence(std::string str, char symbol)
{
	int count = 0;

    for (char c : str) 
	{
        if (c == symbol) 
            ++count;
    }
    return count;
}

bool	validInput(std::string str)
{
	std::string	allowedSymbols = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ.+-";
	int			alph = 0;

	if (str.find_first_not_of(allowedSymbols) != std::string::npos)
		return (false);
	if (countOccurence(str, '+') > 1 || countOccurence(str, '-') > 1 || countOccurence(str, '.') > 1)
		return (false);
	for (char c : str)
	{
		if (!std::isalpha(c))
			++alph;
		if (alph > 1)
			return (false);
	}
	return (true);
}

bool	convertToChar(std::string str)
{
	int	i;
	std::string	allowedSymbols = "0123456789f.+-";

	if (str.find_first_not_of(allowedSymbols) != std::string::npos)
		return (false);
	i = stoi(str);
	if (i > 32  && i < 127)
		std::cout << static_cast<char>(i) << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

}

void ScalarConverter::convert(std::string input)
{
	if (!validInput(input));
	{
		std::cout << "Invalid input" << std::endl;
		return ;
	}
	if (!convertToChar(input))
		std::cout << "Impossible" << std::endl;
	// if (!convertToInt(input))
	// 	std::cout << "Impossible to convert to int" << std::endl;
	// if (!convertToFloat(input))
	// 	std::cout << "Impossible to convert to float" << std::endl;
	// if (!convertToDouble(input))
	// 	std::cout << "Impossible to convert to double" << std::endl;
}

/*Getters and Setters*/

/*Constructors*/
ScalarConverter::ScalarConverter(/*Parameterized Constructor*/)
{
   std::cout << "ScalarConverter parameterized constructor is called" << std::endl;
}

ScalarConverter::ScalarConverter()
{
    std::cout << "ScalarConverter default constructor is called" << std::endl;
}

/*Destructors*/
ScalarConverter::~ScalarConverter( void )
{
    std::cout << "ScalarConverter destructor is called" << std::endl;
}

/*Overload operators*/
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src)
{
	std::cout << "ScalarConverter copy assignment is called" << std::endl;
	if (this != &src)
	{
		// Assinment variables
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& output_stream, ScalarConverter& src)
{
	output_stream << "* ScalarConverter Class info*" << std::endl;
	return output_stream;
}

