#include "ScalarConverter.hpp"

/*Member functions*/
static bool	hasDigit(std::string str)
{
	
    for (size_t i = 0; i < str.length(); ++i)
	{
		if (std::isdigit(str[i]))
			return (true);
	}
	return (false);
}
// static int	countOccurence(std::string str, char symbol)
// {
// 	int count = 0;

//     for (size_t i = 0; i < str.length(); ++i)
// 	{
//         if (str[i] == symbol) 
//             ++count;
//     }
// 	return (count);
// }

static void printAll(std::string charValue, std::string intValue, std::string floatValue, std::string doubleValue)
{
	std::cout << "char: " << charValue << std::endl;
	std::cout << "int: " << intValue << std::endl;
	std::cout << "float: " << floatValue << std::endl;
	std::cout << "double: " << doubleValue << std::endl;
}

static std::string precisionFloat(float value)
{
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(1) << value;
    return ss.str();
;
}

static std::string precisionDouble(double value)
{
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(1) << value;
    return ss.str();

}


static void	convertChar(char c)
{
	if (isprint(c))
	{
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) <<  std::endl;
	}
	else
	{
		std::cout << "char: "<< "non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) <<  std::endl;
	}
}

static void	convertInt(std::string str)
{
	if (!hasDigit(str) || str.length() > 12)
	{
		printAll("impossible", "impossible", "impossible", "impossible");
		return;
	}
	long long value1 = std::stoll(str);
	if (value1 < std::numeric_limits<int>::min() || value1 > std::numeric_limits<int>::max())
	{
		printAll("impossible", "impossible", "impossible", "impossible");
		return;
	}
	int value = std::atoi(str.c_str());
	if (isascii(value))
	{
		if (isprint(value))
			std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
		else
			std::cout << "char: non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << value << std::endl;
	std::cout << "float: " << precisionFloat(static_cast<float>(value)) << "f" << std::endl;
	std::cout << "double: " << precisionDouble(static_cast<double>(value)) << std::endl;
}

static void convertFloat(std::string str)
{
	float value;

	value = std::strtof(str.c_str(), nullptr);
	if (str == "nanf" || str == "+inff" || str == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " <<  precisionFloat(value) << "f" << std::endl;
		std::cout << "double: " <<  precisionDouble(static_cast<double>(value)) << std::endl;
		return;
	}
	if (static_cast<double>(value) < static_cast<double>(INT_MIN) || value > static_cast<double>(INT_MAX))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << precisionFloat(value) << "f" << std::endl;
		std::cout << "double: " <<  precisionDouble(static_cast<double>(value)) << std::endl;
		return;
	}
	if (isascii(value))
	{
		if (isprint(value))
			std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
		else
			std::cout << "char: non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << "float: " << precisionFloat(value) << "f" << std::endl;
	std::cout << "double: " <<  precisionDouble(static_cast<double>(value)) << std::endl;
}

static void convertDouble(std::string str)
{
	double value;

	value = std::strtod(str.c_str(), nullptr);
	if ((str == "nan" || str == "+inf" || str == "-inf") || value < static_cast<double>(INT_MIN) || value > static_cast<double>(INT_MAX))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << precisionFloat(static_cast<float>(value)) << "f" << std::endl;
		std::cout << "double: " <<  precisionDouble(value) << std::endl;
		return ;
	}
	if (isascii(value))
	{
		if (isprint(value))
			std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
		else
			std::cout << "char: non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << "float: " << precisionFloat(static_cast<float>(value)) << "f" << std::endl;
	std::cout << "double: " <<  precisionDouble(value) << std::endl;
}

static bool	isInt(std::string str)
{
	size_t i = 0;

	if (str[0] == '-' || str[0] == '+')
		i++;
	for (; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}

static bool	isFloat(std::string str)
{
	bool hasDigit = false;
	bool hasDot = false;
	std::size_t i = 0;
		
	if (str == "nanf" || str == "+inff" || str == "-inff")
		return (true);
		
	if (str.size() < 2 || str[str.size() - 1] != 'f')
		return (false);
	
	std::string numberPart = str.substr(0, str.size() - 1);
	if (numberPart[i] == '+' || numberPart[i] == '-')
		i++;
	for (; i < numberPart.size(); ++i)
	{
		if (std::isdigit(numberPart[i]))
			hasDigit = true;
		else if (numberPart[i] == '.')
		{
			if (hasDot)
				return (false);
			hasDot = true;
		}
		else
			return (false);
	}
	if (hasDigit && hasDot)
		return (true);
	return (false);	
}

static bool isDouble(std::string str)
{
	bool hasDigit = false;
	bool hasDot = false;
	std::size_t i = 0;

	if (str == "nan" || str == "+inf" || str == "-inf")
		return (true);
		
	if (str.empty() || str.size() < 2)
		return (false);
		
	if (str[i] == '+' || str[i] == '-')
		i++;
	for (; i < str.size(); ++i)
	{
		if (std::isdigit(str[i]))
			hasDigit = true;
		else if (str[i] == '.')
		{
			if (hasDot)
				return (false);
			hasDot = true;
		}
		else
			return (false);
	}
	if (hasDigit && hasDot)
		return (true);
	return (false);	
}


static ScalarType whichType(std::string str)
{
	if (str.length() == 0)
		return (CHAR);
	if (str.length() == 1)
	{
		if (isdigit(str[0]))
			return INT;
		if (isascii(str[0]))
			return CHAR;
		return (INVALID);
	}
	else if (str.length() > 0)
	{
		if (isInt(str))
			return (INT);
		if (isFloat(str))
			return (FLOAT);
		if (isDouble(str))
			return (DOUBLE);
	}
	return (INVALID);
}

void ScalarConverter::convert(std::string input)
{
	std::cout << std::fixed;
	switch (whichType(input))
	{
		case CHAR:
			convertChar(input[0]);
			break;
		case INT:
			convertInt(input);
			break;
		case FLOAT:
			convertFloat(input);
			break;
		case DOUBLE:
			convertDouble(input);
			break;
		case INVALID:
			printAll("impossible", "impossible", "impossible", "impossible");
			break;
	}
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
