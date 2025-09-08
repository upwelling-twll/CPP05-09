#include "BitcoinExchange.hpp"

/*Member functions*/
void BitcoinExchange::method()
{
    // Method implementation
}

/*Getters and Setters*/

/*Constructors*/
BitcoinExchange::BitcoinExchange(/*Parameterized Constructor*/)
{
   std::cout << "BitcoinExchange parameterized constructor is called" << std::endl;
}

BitcoinExchange::BitcoinExchange()
{
    std::cout << "BitcoinExchange default constructor is called" << std::endl;
}

/*Destructors*/
BitcoinExchange::~BitcoinExchange( void )
{
    std::cout << "BitcoinExchange destructor is called" << std::endl;
}

/*Overload operators*/
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
	std::cout << "BitcoinExchange copy assignment is called" << std::endl;
	if (this != &src)
	{
		// Assinment variables
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& output_stream, BitcoinExchange& src)
{
	output_stream << "* BitcoinExchange Class info*" << std::endl;
	return output_stream;
}

