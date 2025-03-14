#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

/*Member functions*/
bool PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (getStatus() == false)
		throw FormIsNotSigned();
	if (executor.getGrade() >= getGradeToExecute())
		throw ExecutorGradeTooLow();
	else
	{
		std::cout << this->_target << " has been pardonet by Zaphod Beeblebox" << std::endl; 
		return (true);
	}
	return (false);
}

/*Getters and Setters*/
std::string &PresidentialPardonForm::getTarget()
{
	return (this->_target);
}

/*Constructors*/

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 72, 45)
{
	std::cout << "PresidentialPardonForm default constructor is called" << std::endl;
	this->_target = "Default_Shrubbery_target";
}

PresidentialPardonForm::PresidentialPardonForm( std::string target) : AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << "PresidentialPardonForm constructor is called" << std::endl;
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src)
{
	std::cout << "PresidentialPardonForm copy constructor is called" << std::endl;
	this->_target = src._target;
}

/*Destructors*/

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	std::cout << "PresidentialPardonForm destructor is called for " << this->getName() << std::endl;
}

/*Operators*/

std::ostream& operator<<(std::ostream& output_stream, PresidentialPardonForm& src)
{
	output_stream << "\n*******Form_Info************\n" \
	 << src.getName() << ", status " << src.getStatus() \
	 << "\ngradeToSign:" << src.getGradeToSign() << "\ngradeToExecute:" << src.getGradeToExecute() \
	 <<  "\nTarget: " << src.getTarget() << "\n****************************" << std::endl;
	return output_stream;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	std::cout << "PresidentialPardonForm copy assignment is called for PresidentialPardonForm " << std::endl;
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
	}
	return (*this);
}
