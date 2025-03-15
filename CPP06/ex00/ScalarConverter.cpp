#include "ScalarConverter.hpp"

/*Member functions*/
void ScalarConverter::method()
{
    // Method implementation
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

