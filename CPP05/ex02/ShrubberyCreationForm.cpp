#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

/*Member functions*/
void	ShrubberyCreationForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeToSign)
	{
		this->_status = true;
	}
	else
		throw GradeTooLowException();
}

/*Getters*/
const std::string& ShrubberyCreationForm::getName()
{
	return(this->_name);
}

bool& ShrubberyCreationForm::getStatus()
{
	return(this->_status);
}

/*Constructors*/

ShrubberyCreationForm::ShrubberyCreationForm(void) : _name("Default ShrubberyCreationForm"), \ 
	_gradeToSign(150), _gradeToExecute(150)
{\
	std::cout << "ShrubberyCreationForm default constructor is called" << std::endl;
	this->_status = false;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name, unsigned int gradeToSign,	\
	 unsigned int gradeToExecute) :  _name(name), _gradeToSign(gradeToSign), \
	_gradeToExecute(gradeToExecute)
{
	std::cout << "ShrubberyCreationForm constructor is called for " << name << std::endl;
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
	this->_status = false;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : _name(src._name), \
 _gradeToSign(src._gradeToSign), \
	_gradeToExecute(src._gradeToExecute)
{
	std::cout << "ShrubberyCreationForm copy constructor is called" << std::endl;
	this->_status = src._status;
}

/*Destructors*/

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	std::cout << "ShrubberyCreationForm destructor is called for " << this->_name << std::endl;
}

/*Operators*/

std::ostream& operator<<(std::ostream& output_stream, ShrubberyCreationForm& src)
{
	output_stream << src.getName() << ", ShrubberyCreationForm status " << src.getStatus();
	return output_stream;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	std::cout << "ShrubberyCreationForm copy assignment is called for " << src._name << std::endl;
	if (this != &src)
	{
		this->_status = src._status;
	}
	return (*this);
}
