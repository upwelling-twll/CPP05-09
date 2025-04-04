#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cmath>
# include <limits>
# include <cstdlib>
# include <exception>

# define MIN_INT std::numeric_limits<int>::min()
# define MAX_INT std::numeric_limits<int>::max()
# define MINFLOAT -std::numeric_limits<float>::max()
# define MIN_DOUBLE std::numeric_limits<double>::min()
# define MAX_DOUBLE std::numeric_limits<double>::max()

class ScalarConverter
{
private:
    // Add member variables here

public:
	/*Member functions*/
    static void convert(std::string input);

	/*Getters and Setters*/

	/*Constructors*/
    // ScalarConverter(/*Parameterized Constructor*/);
	ScalarConverter(void);

	/*Destructors*/
    ~ScalarConverter( void );

	/*Overload operators*/
	ScalarConverter &operator=(const ScalarConverter& src);
};
class ErrorConvertingChar : public std::exception
{
	const char * what () const throw ()
	{
		return "Char: This char can not be converted";
	}
};

std::ostream& operator<<(std::ostream &output_stream, ScalarConverter& src);

#endif // SCALARCONVERTER_HPP
