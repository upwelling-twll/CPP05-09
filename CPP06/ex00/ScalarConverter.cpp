#include "ScalarConverter.hpp"

/*Member functions*/
int	countOccurence(std::string str, char symbol)
{
	int count = 0;

    for (size_t i = 0; i < str.length(); ++i)
	{
        if (str[i] == symbol) 
            ++count;
    }
	return (count);
}

bool	validInput(std::string str)
{
	std::string	allowedSymbols = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ.+-";
	int			alph = 0;

	if (str.find_first_not_of(allowedSymbols) != std::string::npos)
		return (false);
	if (countOccurence(str, '+') > 1 || countOccurence(str, '-') > 1 || countOccurence(str, '.') > 1)
		return (false);
	if (str == "nan")
		return (true);
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (std::isalpha(str[i])) 
			alph++;
		if (alph > 1)
			return (false);
	}
	return (true);
}

bool	convertToChar(std::string str)
{
	int		i;
	std::string	allowedSymbols = "0123456789f.+-";

	if (str.length() == 1 &&  std::isalpha(str[0]))
	{
		std::cout << str[0] << std::endl;
		return (true);
	}
	if (str.find_first_not_of(allowedSymbols) != std::string::npos)
		return (false);
	std::stringstream ss(str);
	ss >> i;
	if (i > 32  && i < 127)
		std::cout << static_cast<char>(i) << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	return (true);
}

bool	convertToInt(std::string str)
{
	long long	i;
	std::string	allowedSymbols = "0123456789f.+-";

	if (str.find_first_not_of(allowedSymbols) != std::string::npos)
		return (false);
	std::stringstream ss(str);
	ss >> i;
	if (i > 2147483647 || i < -2147483648)
		return (false);
	else
		std::cout << static_cast<int>(i) << std::endl;
	return (true);
}

bool	hasDigit(std::string str)
{
	
    for (size_t i = 0; i < str.length(); ++i)
	{
		if (std::isdigit(str[i]))
			return (true);
	}
	return (false);
}

bool	convertToFloat(std::string str)
{
	std::string			allowedSymbols = "0123456789f.+-";
	std::stringstream	ss(str);
	float				num;

	if (str == "+inff" || str == "-inff")
	{
		std::cout << str << std::endl;
		return (true);
	}
	if (str == "+inf" || str == "-inf" || str == "nan")
	{
		std::cout << str + "f" << std::endl;
		return (true);
	}
	if (str.find_first_not_of(allowedSymbols) != std::string::npos)
		return (false);
	if (str[str.length()] == 'f' && str.length() > 1 && hasDigit(str))
	{	
		std::cout << str << std::endl;
		return (true);
	}
	ss >> num;
	if (ss.fail())
		return (false);
	else
		std::cout << num << std::endl;
	return (true);
}

bool	convertToDouble(std::string str)
{
	std::string			allowedSymbols = "0123456789f.+-";
	std::stringstream	ss(str);
	double				num;

	if (str == "+inf" || str == "-inf" || str == "nan")
	{
		std::cout << str << std::endl;
		return (true);
	}
	if (str == "+inff" || str == "-inff")
	{
		std::cout << str.substr(0, str.length() - 1) << std::endl;
		return (true);
	}
	if (str.find_first_not_of(allowedSymbols) != std::string::npos)
		return (false);
	ss >> num;
	if (ss.fail())
		return (false);
	else
		std::cout << num << std::endl;
	return (true);
}

void ScalarConverter::convert(std::string input)
{
	if (!validInput(input))
	{
		std::cout << "Invalid input" << std::endl;
		return ;
	}
	std::cout << "Char: ";
	if (!convertToChar(input))
		std::cout << "Impossible" << std::endl;
	std::cout << "Int: ";
	if (!convertToInt(input))
		std::cout << "Impossible" << std::endl;
	std::cout << "Float: ";
	if (!convertToFloat(input))
		std::cout << "Impossible" << std::endl;
	std::cout << "Double: ";
	if (!convertToDouble(input))
		std::cout << "Impossible" << std::endl;
}

/*Getters and Setters*/

/*Constructors*/
// ScalarConverter::ScalarConverter()
// {
//    std::cout << "ScalarConverter parameterized constructor is called" << std::endl;
// }

// ScalarConverter::ScalarConverter()
// {
//     std::cout << "ScalarConverter default constructor is called" << std::endl;
// }

// /*Destructors*/
// ScalarConverter::~ScalarConverter( void )
// {
//     std::cout << "ScalarConverter destructor is called" << std::endl;
// }

/*Overload operators*/
// ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src)
// {
// 	std::cout << "ScalarConverter copy assignment is called" << std::endl;
// 	if (this != &src)
// 	{
// 		// Assinment variables
// 	}
// 	return (*this);
// }

// std::ostream& operator<<(std::ostream& output_stream, ScalarConverter& src)
// {
// 	output_stream << "* ScalarConverter Class info*" << std::endl;
// 	return output_stream;
// }

