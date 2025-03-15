#include "ScalarConverter.hpp"

/*Member functions*/

void ScalarConverter::convert(std::string input)
{
	switch (check_type)
	{
		case 1:
		{
			convertChar();
			break;
		}
		case 2:
		{
			convertInt();
			break;
		}
		case 3:
		{
			convertFloat();
			break;
		}
		case 4:
		{
			convertDouble();
			break;
		}
		case 5:
		{
			convertPseudoLiteral();
			break;
		}
		default:
			break;
	}
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

