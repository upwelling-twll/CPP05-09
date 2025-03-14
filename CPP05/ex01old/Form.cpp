#include "Form.hpp"

/*Member functions*/
void	Form::beSigned()
{
	std::cout << "Attempting to sign the form " << this->name << std::endl;
	if (this->gradeToSign < bureaucrats grade)
		throw GradeTooLowException();
	else
		this->grade++;
}

/*Getters*/
const std::string& Form::getName()
{
	return(this->name);
}

const unsigned int& Form::getStatus()
{
	return(this->status);
}

/*Constructors*/

Form::Form(void)
{
	std::cout << "Form default constructor is called" << std::endl;
	this->name = "Default Form name";
	this->status = false;
	this->gradeToSign = 150;
	this->gradeToExecute = 150;
}

Form::Form(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute)
{
	std::cout << "Form constructor is called" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->name = name;
	this->grade = grade;
}

Form::Form(const Form &src)
{
	std::cout << "Form copy constructor is called" << std::endl;
	*this = src;
}

/*Destructors*/

Form::~Form( void )
{
	std::cout << "Form destructor is called for " << this->name << std::endl;
}

/*Operators*/

std::ostream& operator<<(std::ostream& output_stream, Form& src)
{
	output_stream << src.getName() << ", Form grade " << src.getGrade();
	return output_stream;
}

Form&	Form::operator=(const Form& src)
{
	std::cout << "Form copy assignment is called for " << src.name << std::endl;
	if (this != &src)
	{
		this->name = src.name;
		this->grade = src.grade;
	}
	return (*this);
}
