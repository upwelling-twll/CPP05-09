#ifndef _FORM_HPP_
# define  _FORM_HPP_

# include <iostream>
# include <fstream>
# include <exception>

class Form
{
private:

	const std::string		name;
	bool					status;
	const unsigned int		gradeToSign;
	const unsigned int		gradeToExecute;

public:

	/*Member functions*/
	void	beSigned();

	/*Getters*/
	const std::string&	getName();
	const unsigned int&	getStatus();

	/*Constructors*/
	Form(void);
	Form(const std::string name, unsigned int gradeToSign, \
		unsigned int gradeToExecute);
	Form(const Form &src);

	/*Destructors*/
	~Form( void );

	/*Operators*/
	Form &operator=(const Form& src);
};

std::ostream& operator<<(std::ostream &output_stream, Form& src);

class GradeTooHighException : public std::exception
{
	const char * what () const throw ()
	{
		return "The grade is too high";
	}
};

class GradeTooLowException : public std::exception
{
	const char * what () const throw ()
	{
		return "The grade is too low";
	}
};

#endif