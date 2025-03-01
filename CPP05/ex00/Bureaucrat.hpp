#ifndef _BUREAUCRAT_HPP_
# define  _BUREAUCRAT_HPP_

# include <iostream>
# include <fstream>

class Bureaucrat
{
protected:

	std::string		name;
	unsigned int	grade;

public:

	/*Member functions*/
	void	incrementGrade();
	void	decrementGrade();

	/*Getters*/
	const std::string&	getName();
	const unsigned int&	getGrade();

	/*Setters*/
	//

	/*Constructors*/
	Bureaucrat(void);
	Bureaucrat(std::string& name, unsigned int grade);
	Bureaucrat(const Bureaucrat &src);

	/*Destructors*/
	~Bureaucrat( void );

	/*Operators*/
	Bureaucrat &operator=(const Bureaucrat& src);
};

std::ostream& operator<<(std::ostream &output_stream, Bureaucrat& src);

#endif