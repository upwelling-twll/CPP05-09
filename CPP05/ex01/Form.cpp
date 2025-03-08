#include "Form.hpp"

/*Member functions*/
void	Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeToSign)
	{
		if (this->_status)
			std::cout << "The Form is already signed" << std::endl;
		else
		{
			this->_status = true;
			std::cout << "The Form is successfully signed" << std::endl;
		}
	}
	else
		throw GradeTooLowException();
}

/*Getters*/
const std::string& Form::getName()
{
	return(this->_name);
}

bool& Form::getStatus()
{
	return(this->_status);
}

/*Constructors*/

Form::Form(void) : _name("Default name"), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "Form default constructor is called" << std::endl;
	this->_status = false;
}

Form::Form(const std::string name, unsigned int gradeToSign, unsigned int gradeToExecute) : _gradeToSign(gradeToSign), \
	_gradeToExecute(gradeToExecute), _name(name)
{
	std::cout << "Form constructor is called" << std::endl;
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &src) : _name(src._name), _gradeToSign(src._gradeToSign), \
	_gradeToExecute(src._gradeToExecute)
{
	std::cout << "Form copy constructor is called" << std::endl;
	this->_status = src._status;
}

/*Destructors*/

Form::~Form( void )
{
	std::cout << "Form destructor is called for " << this->_name << std::endl;
}

/*Operators*/

std::ostream& operator<<(std::ostream& output_stream, Form& src)
{
	output_stream << src.getName() << ", Form status " << src.getStatus();
	return output_stream;
}

Form&	Form::operator=(const Form& src)
{
	std::cout << "Form copy assignment is called for " << src._name << std::endl;
	if (this != &src)
	{
		this->_status = src._status;
	}
	return (*this);
}
