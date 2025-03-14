#include "Form.hpp"
#include "Bureaucrat.hpp"

/*Member functions*/
void	Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeToSign)
	{
		this->_status = true;
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

const unsigned int& Form::getGradeToExecute() const 
{
	return(this->_gradeToExecute);
}

const unsigned int& Form::getGradeToSign() const 
{
	return(this->_gradeToSign);
}

/*Constructors*/

Form::Form(void) : _name("Default form"), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "Form default constructor is called" << std::endl;
	this->_status = false;
}

Form::Form(const std::string name, unsigned int gradeToSign, unsigned int gradeToExecute) :  _name(name), _gradeToSign(gradeToSign), \
	_gradeToExecute(gradeToExecute)
{
	std::cout << "Form constructor is called for " << name << std::endl;
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
	this->_status = false;
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
	output_stream << "\n*******Form_Info************\n" \
	 << src.getName() << ", status " << src.getStatus() \
	 << "\ngradeToSign:" << src.getGradeToSign() << "\ngradeToExecute:" << src.getGradeToExecute() \
	 << "\n****************************" << std::endl;
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
