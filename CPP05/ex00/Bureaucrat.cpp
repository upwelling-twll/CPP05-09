#include "Bureaucrat.hpp"

/*Member functions*/
void	Bureaucrat::decrementGrade()
{
	std::cout << "Decrement Grade function called for " << this->name << std::endl;
	if (this->grade == 150)
		throw GradeTooLowException();
	else
		this->grade++;
}

/*Member functions*/
void	Bureaucrat::incrementGrade()
{
	std::cout << "Increment Grade function called for " << this->name << std::endl;
	if (this->grade == 1)
		throw GradeTooHighException();
	else
		this->grade--;
}

/*Getters*/
const std::string& Bureaucrat::getName()
{
	return(this->name);
}

const unsigned int& Bureaucrat::getGrade()
{
	return(this->grade);
}

/*Constructors*/

Bureaucrat::Bureaucrat(void)
{
	std::cout << "Bureaucrat default constructor is called" << std::endl;
	this->name = "Default name";
	this->grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade)
{
	std::cout << "Bureaucrat constructor is called" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->name = name;
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	std::cout << "Bureaucrat copy constructor is called" << std::endl;
	*this = src;
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
