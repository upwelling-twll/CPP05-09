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

bool	convertChar(std::string str)
{
	char	c = 0;

	if (str.length() == 1)
		c = str[0];
	else
		c = str[1];
	std::cout << "char: ";
	if (isprint(c))
	{
		std::cout << "'" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
	return (true);
	}
	else
		std::cout << "Non displayable" << std::endl;
	return (false);
}

bool	isChar(std::string str)
{
	if (str.length() == 1 && std::isdigit(str[0]))
	{
		return (true);
	}
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
	{
		return (true);
	}
	return (false);
}

void	prinInfNan(const std::string& str)
{
	if (str == "nan" || str == "nanf")
	{
		std::cout << "char: impossible" << std::endl; 
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (str == "+inf" || str == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (str == "-inf" || str == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}


bool	convertInt(const std::string& str)
{
	long	l = std::atol(str.c_str());

	std::cout << "char: ";
	if (l < 0 || l > 127)
		std::cout << "impossible" << std::endl;
	else
	{
		if (isprint(l))
			std::cout << "'" << static_cast<char>(l) << "'" << std::endl;
		else
			return (false);
	}
	std::cout << "int: ";
	if (l < MIN_INT || l > MAX_INT)
		std::cout << "impossible" << std::endl;
	else
		std::cout	<< static_cast<int>(l) << std::endl;
	std::cout << "float: " << static_cast<float>(l) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(l) << ".0" << std::endl;
	return (true);
}

bool	isInt(std::string str)
{
	int		i;
	bool	notInt = false;
	int		len;

	i = 0;
	len = str.length();
	if (str[0] == '-' || str[0] == '+')
	{
		i++;
		notInt = true;
	}
	while ((str[i] && len > 0 && len < 12) || (str[i] && !notInt && len > 0 && len < 11))
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (true);
}

bool	convertFloat(const std::string& str)
{
	float	f = std::atof(str.c_str());
	bool	tolerance = std::fabs(f - static_cast<int>(f)) < 0.0000000000001;

	std::cout << "char: ";
	if (f < 0 || f > 127)
		std::cout << "impossible" << std::endl;
	else
	{
		if (isprint(f))
			std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
		else 
			return (false);
	}
	std::cout << "int: ";
	if (static_cast<long>(f) < MIN_INT || static_cast<long>(f) > MAX_INT)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(f) << std::endl;
	std::cout << "float: ";
	if (f < MINFLOAT || f > MAXFLOAT)
		std::cout << "impossible" << std::endl;
	else
		std::cout << f << (tolerance ? ".0f" : "f") << std::endl;
	std::cout << "double: " << static_cast<double>(f) << (tolerance ? ".0" : "") << std::endl;
	return (true);
}

static int	isFloat(const std::string& str)
{
	size_t	len;
	size_t	dot;

	len = str.length();
	dot = str.find('.');
	for (int j = dot - 1; j >= 0; j--)
	{
		if (!isdigit(str[j]) && j != 0)
			return 0;
		if (!isdigit(str[j]) && j == 0 && str[j] != '+' && str[j] != '-')
			return 0;
	}
	for (size_t i = dot + 1; i < len; i++)
	{
		if (!isdigit(str[i]) && str[i] != 'f')
			return 0;
		if (str[i] == 'f' && i != len - 1)
			return 0;
	}
	return 1;
}

bool	isDouble(std::string &str)
{
	size_t	f;
	size_t	dot;

	f = str.find('f');
	dot = str.find('.');
	if((f == std::string::npos) && (dot != std::string::npos))
		return (true);
	return (false);
}

static int	convertDouble(const std::string& str)
{
	double		d = std::atof(str.c_str());
	bool		tolerance = std::fabs(d - static_cast<int>(d)) < 0.0000000000001;

	std::cout << "char: ";
	if (d < 0 || d > 127)
		std::cout << "impossible" << std::endl;
	else
	{
		if (isprint(d))
			std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
		else 
			std::cout << "Non displayable" << std::endl;
	}
	std::cout << "int: ";
	if (d < MIN_INT || d > MAX_INT)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;
	std::cout << "float: ";
	if (d < MINFLOAT || d > MAXFLOAT)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<float>(d) << (tolerance ? ".0f" : "f") << std::endl;
	std::cout << "double: ";
	if (d < MIN_DOUBLE || d > MAX_DOUBLE)
		std::cout << "impossible" << std::endl;
	else
		std::cout << d << std::endl;
	return (1);
}

bool	invalidType(std::string str)
{
	std::string  allowedChar = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	std::string  allowedInt = {"0123456789"};
	std::string  allowedFloat = {"0123456789"};
	std::string  allowedDouble = {"0123456789"};
	std::string  allowedFloatSymb = {"+-.f"};
	std::string  allowedDoubleSymb = {"+-."};

	if (find_first_not_of(allowedChar, str) || countStrOccurence(allowedChar, str) > 1 || str.length() > 1)
		
}

void ScalarConverter::convert(std::string input)
{
	if (invalidType(input))
	{
		std::cout << "Invalid input" << std::endl;
		return ;
	}
	else if (isChar(input))
	{
		if (!convertChar(input))
			throw ErrorConvertingChar();
	}
	else if (isInt(input))
	{
		if (!convertInt(input))
			throw;
	}
	else if (!isFloat(input))
	{
		if (!convertFloat(input))
			throw;
	}
	else if (isDouble(input))
	{
		if (!convertDouble(input))
			throw;
	}
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
