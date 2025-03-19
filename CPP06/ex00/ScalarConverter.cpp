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
	if (str == "nan")
		return (true);
	for (char c : str)
	{
		if (std::isalpha(c))
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

	if (str.length() == 1 &&  std::isalpha(str.front()))
	{
		std::cout << str.front() << std::endl;
		return (true);
	}
	if (str.find_first_not_of(allowedSymbols) != std::string::npos)
		return (false);
	i = stoi(str);
	if (i > 32  && i < 127)
		std::cout << static_cast<char>(i) << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

bool	convertToInt(std::string str)
{
	int	i;
	std::string	allowedSymbols = "0123456789f.+-";

	if (str.find_first_not_of(allowedSymbols) != std::string::npos)
		return (false);
	i = stoll(str);
	if (i > 2147483647 || i < -2147483648)
		return (false);
	else
		std::cout << static_cast<int>(i) << std::endl;
}

bool	hasDigit(std::string str)
{
	for (char c : str)
	{
		if (std::isdigit(c))
			return (true);
	}
	return (false);
}

bool	convertToFloat(std::string str)
{
	int	i;
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
	if (str.back() == 'f' && str.length() > 1 && hasDigit(str))
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
	if (!validInput(input));
	{
		std::cout << "Invalid input" << std::endl;
		return ;
	}
	if (!convertToChar(input))
		std::cout << "Impossible" << std::endl;
	if (!convertToInt(input))
		std::cout << "Impossible" << std::endl;
	if (!convertToFloat(input))
		std::cout << "Impossible" << std::endl;
	if (!convertToDouble(input))
		std::cout << "Impossible" << std::endl;
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

