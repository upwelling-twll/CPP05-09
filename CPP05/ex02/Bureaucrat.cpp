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

void	Bureaucrat::incrementGrade()
{
	std::cout << "Increment Grade function called for " << this->name << std::endl;
	if (this->grade == 1)
		throw GradeTooHighException();
	else
		this->grade--;
}

void	Bureaucrat::signForm(AForm& formToSign)
{
	if (formToSign.getStatus() == true)
		std::cout << this->name << " couldn`t sign form "<< formToSign.getName() << " because it`ve been alredy signed" << std::endl;
	else
	{
		try
		{
			formToSign.beSigned(*this);
			std::cout << "Bureaucrat "<< this->name << " successfully signed " << formToSign.getName() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << this->name << " couldn`t sign form "<< formToSign.getName() << " because ";
			std::cerr << e.what() << '\n';
		}
	} 
	//	std::cout << "Bureaucrat couldn`t sign form because their grade is too low" << std::endl;
}

void	Bureaucrat::executeForm(AForm const & form)
{
	if (form.execute(*this))
		std::cout << "Bureaucrat " << this->name << " executed " << form.getName() << std::endl;
	else
		std::cout << "Bureaucrat " << this->name << " did not seceed executing " << form.getName() << std::endl;
}

/*Getters*/
const std::string& Bureaucrat::getName()
{
	return(this->name);
}

const unsigned int& Bureaucrat::getGrade() const
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
	std::cout << "Bureaucrat constructor is called for " << name << std::endl;
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
