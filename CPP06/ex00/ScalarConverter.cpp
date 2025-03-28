#include "ScalarConverter.hpp"

/*Member functions*/
bool	hasDigit(std::string str)
{
	
    for (size_t i = 0; i < str.length(); ++i)
	{
		if (std::isdigit(str[i]))
			return (true);
	}
	return (false);
}
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

int	countStrOccurence(std::string str1, std::string str2)
{
	int count = 0;

   for (std::string::const_iterator it1 = str1.begin(); it1 != str1.end(); ++it1)
   {
        for (std::string::const_iterator it2 = str2.begin(); it2 != str2.end(); ++it2)
		{
            if (*it1 == *it2)
			{
                count++;
            }
        }
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
	if (str == "nan" || str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff")
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

	if (str == "+inff" || str == "-inff")
	{
		return (false);
	}
	if (str == "+inf" || str == "-inf" || str == "nan")
	{
		return (false);
	}
	if (countStrOccurence(str, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") > 1)
	{
		std::cout << "Inaceptable symbols for this type" << std::endl;
		return (false);
	}
	std::stringstream ss(str);
	ss >> i;
	if (i > 2147483647 || i < -2147483648)
		return (false);
	else
		std::cout << i << std::endl;
	return (true);
}

bool	hasZeroAfterPoint(float num)
{
	int	intNum;

	intNum = static_cast<int>(num);
	if (num == intNum)
		return (false);
	else
		return (true);
}

int	digitsAfterPoint(std::string str, float num)
{
	int 	count = 0;
	bool	afterPoint = false;

   for (std::string::const_iterator it = str.begin(); it != str.end() ; ++it)
   {
		if (*it == '.')
			afterPoint = true;
        if (afterPoint)
			count++;
    }
	if (num > -1 && num < 1)
		return (0);
	return (count);
}

bool	convertToFloat(std::string str)
{
	std::string			allowedSymbols = "0123456789f.+-";
	std::stringstream	ss(str);
	float				num = 0.0f;

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
	{
		std::cout << "Inaceptable symbol" << std::endl;
		return (false);
	}
	if (str[str.length()] == 'f' && str.length() > 1 && hasDigit(str))
	{	
		std::cout << str << std::endl;
		return (true);
	}
	ss >> num;
	if (ss.fail())
		return (false);
	if ((countOccurence(str, '.') == 1 && hasZeroAfterPoint(num) && digitsAfterPoint(str, num) <= 7))
		std::cout << num << 'f' << std::endl;
	else
		std::cout << num << ".0f" << std::endl;
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
	if (std::fabs(num - static_cast<int>(num) < 0.0000000000001))
		std::cout << num << ".0" << std::endl;
	else
		std::cout << num << std::endl;
	return (true);
}

bool	converChar(char c)
{
	int		i;
	float	f;
	double	d;

	if (c > 32  && c < 127)
	{
		std::cout << c << std::endl;
		return (true);
	}
	else
	{
		std::cout << "Non displayable" << std::endl;
		return (true);
	}
	std::cout << "Int: ";
	i = static_cast<int>(c);
	std::cout << i << std::endl;

	std::cout << "Float: ";
	f = static_cast<float>(c);
	std::cout << f << std::endl;

	std::cout << "Double: ";
	d = static_cast<int>(c);
	std::cout << d << std::endl;
	return (true);
}

bool	isChar(std::string str, char *c)
{
	std::string	allowedSymbols = "0123456789f.+-";
	int	i;

	if (str.length() == 1 && std::isalpha(str[0]))
	{
		*c = static_cast<char>(str[0]);
		return (true);
	}
	if (str.find_first_not_of(allowedSymbols) != std::string::npos)
	{
		if (str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff")
			return (false);
	}
	i = std::atoi(str.c_str());
	*c = static_cast<char>(i);
	return (true);
}

void ScalarConverter::convert(std::string input)
{
	char 	c;
	int		i;
	// float	f;
	// double 	d;

	if (!validInput(input))
	{
		std::cout << "Invalid input" << std::endl;
		return ;
	}
	std::cout << "Char: ";
	if (isChar(input, &c))
	{
		if (!converChar(c))
			throw ErrorConvertingChar();
	}
	else if (isInt(input, &i))
	{
		if (!converInt(i))
			throw;
	}
	// else if (isDouble(input, &d))
	// {
	// 	if (!converDouble(d))
	// 		throw;
	// }
	// else if (!isFloat(input, &f))
	// {
	// 	if (!converFloat(f))
	// 		throw;
	// }
	else
		std::cout << "Imposssible" << std::endl;
}

/*Getters and Setters*/

/*Constructors*/

ScalarConverter::ScalarConverter()
{
    std::cout << "ScalarConverter default constructor is called" << std::endl;
}

// /*Destructors*/
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
		*this = src;
	}
	return (*this);
}
