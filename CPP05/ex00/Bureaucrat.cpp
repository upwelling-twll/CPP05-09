#include "Bureaucrat.hpp"

/*Constructors*/

Bureaucrat::Bureaucrat(void)
{
	std::cout << "Bureaucrat constructor is called" << std::endl;
	this->name = "Default name";
	this->grade = 150;
}

Bureaucrat::Bureaucrat(std::string& name, unsigned int grade)
{
	if (grade < 1)
		throw GradeTooHighException;
	else if (grade > 150)
		throw GradeTooLowException;
	this->name = name;
	this->grade = grade;
}



/*Destructors*/

Bureaucrat::~Bureaucrat( void )
{
	std::cout << "Bureaucrat destructor is called for " << this->name << std::endl;
}

/*Operators*/

std::ostream& operator<<(std::ostream& output_stream, Bureaucrat& src)
{
	output_stream << src.getName() << ", bureaucrat grade " << src.getGrade();
	return output_stream;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& src)
{
	std::cout << "Bureaucrat copy assignment is called for " << src.name << std::endl;
	if (this != &src)
	{
		this->name = src.name;
		this->grade = src.grade;
	}
	return (*this);
}
