#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

class ScalarConverter
{
private:
    // Add member variables here

public:
	/*Member functions*/
    void method();

	/*Getters and Setters*/

	/*Constructors*/
    ScalarConverter(/*Parameterized Constructor*/);
	ScalarConverter(void);

	/*Destructors*/
    ~ScalarConverter( void );

	/*Overload operators*/
	ScalarConverter &operator=(const ScalarConverter& src);
};

std::ostream& operator<<(std::ostream &output_stream, ScalarConverter& src);

#endif // SCALARCONVERTER_HPP
