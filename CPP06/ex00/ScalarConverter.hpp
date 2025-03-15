#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

class ScalarConverter
{
private:
    // Add member variables here

public:
	/*Member functions*/
    static void convert(std::string input);

	/*Getters and Setters*/

	/*Constructors*/
    ScalarConverter(/*Parameterized Constructor*/) = delete;
	ScalarConverter(void) = delete;

	/*Destructors*/
    ~ScalarConverter( void );

	/*Overload operators*/
	ScalarConverter &operator=(const ScalarConverter& src);
};

std::ostream& operator<<(std::ostream &output_stream, ScalarConverter& src);

#endif // SCALARCONVERTER_HPP
