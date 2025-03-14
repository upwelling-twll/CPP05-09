#include "AForm.hpp"
#include "Bureaucrat.hpp"

/*Member functions*/
void	AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeToSign)
	{
		this->_status = true;
		std::cout << "Form " << this->_name << " is signed by " << bureaucrat.getName() << std::endl;
 	}
	else
		throw GradeTooLowException();
}

/*Getters*/
const std::string& AForm::getName() const
{
	return(this->_name);
}

const bool& AForm::getStatus() const 
{
	return(this->_status);
}

const unsigned int& AForm::getGradeToExecute() const 
{
	return(this->_gradeToExecute);
}

const unsigned int& AForm::getGradeToSign() const 
{
	return(this->_gradeToSign);
}

/*Constructors*/

AForm::AForm(void) : _name("Default AForm"), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "AForm default constructor is called" << std::endl;
	this->_status = false;
}

AForm::AForm(const std::string name, unsigned int gradeToSign, \
	unsigned int gradeToExecute) :  _name(name), _gradeToSign(gradeToSign), \
	_gradeToExecute(gradeToExecute)
{
	std::cout << "AForm constructor is called for " << name << std::endl;
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
	this->_status = false;
}

AForm::AForm(const AForm &src) : _name(src._name), _gradeToSign(src._gradeToSign), \
	_gradeToExecute(src._gradeToExecute)
{
	std::cout << "AForm copy constructor is called" << std::endl;
	this->_status = src._status;
}

/*Destructors*/

AForm::~AForm( void )
{
	std::cout << "AForm destructor is called for " << this->_name << std::endl;
}

/*Operators*/

std::ostream& operator<<(std::ostream& output_stream, AForm& src)
{
	output_stream << "\n*******Form_Info************\n" \
	 << src.getName() << ", status " << src.getStatus() \
	 << "\ngradeToSign:" << src.getGradeToSign() << "\ngradeToExecute:" << src.getGradeToExecute() \
	 << "\n****************************" << std::endl;
	return output_stream;
}

AForm&	AForm::operator=(const AForm& src)
{
	std::cout << "AForm copy assignment is called for " << src._name << std::endl;
	if (this != &src)
	{
		this->_status = src._status;
	}
	return (*this);
}
