#ifndef _BUREAUCRAT_HPP_
# define  _BUREAUCRAT_HPP_

# include <iostream>
# include <fstream>
# include <exception>
# include "AForm.hpp"

class Bureaucrat
{
protected:

	const std::string		name;
	unsigned int			grade;

public:

	/*Member functions*/
	void	incrementGrade();
	void	decrementGrade();
	void	signForm(AForm& formToSign);
	void	executeForm(AForm const & form);

	/*Getters*/
	const std::string&	getName() const;
	const unsigned int&	getGrade() const;

	/*Constructors*/
	Bureaucrat(void);
	Bureaucrat(std::string name, unsigned int grade);
	Bureaucrat(const Bureaucrat &src);

	/*Destructors*/
	~Bureaucrat( void );

	/*Operators*/
	Bureaucrat &operator=(const Bureaucrat& src);
};

std::ostream& operator<<(std::ostream &output_stream, Bureaucrat& src);

class GradeTooHighException : public std::exception
{
	const char * what () const throw ()
	{
		return "Grade is too high";
	}
};

class GradeTooLowException : public std::exception
{
	const char * what () const throw ()
	{
		return "Grade is too low";
	}
};

#endif