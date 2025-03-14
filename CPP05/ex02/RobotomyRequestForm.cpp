#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <random>

/*Member functions*/
bool RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (getStatus() == false)
		throw FormIsNotSigned();
	if (executor.getGrade() >= getGradeToExecute())
		throw ExecutorGradeTooLow();
	else
	{
		std::cout << "DRRRRRR - DRRRRRRRR - DRRRRRRRRRR" << std::endl;
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(0,1);
		if (dis(gen) == 1)
			std::cout << this->_target << " has been robotomized" << std::endl;
		else
			throw RobotomyRequestError();
		return (true);
	}
	return (false);
}

/*Getters and Setters*/
std::string &RobotomyRequestForm::getTarget()
{
	return (this->_target);
}

/*Constructors*/

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm default constructor is called" << std::endl;
	this->_target = "Default_Shrubbery_target";
}

RobotomyRequestForm::RobotomyRequestForm( std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm constructor is called" << std::endl;
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src)
{
	std::cout << "RobotomyRequestForm copy constructor is called" << std::endl;
	this->_target = src._target;
}

/*Destructors*/

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	std::cout << "RobotomyRequestForm destructor is called for " << this->getName() << std::endl;
}

/*Operators*/

std::ostream& operator<<(std::ostream& output_stream, RobotomyRequestForm& src)
{
	output_stream << "\n*******Form_Info************\n" \
	 << src.getName() << ", status " << src.getStatus() \
	 << "\ngradeToSign:" << src.getGradeToSign() << "\ngradeToExecute:" << src.getGradeToExecute() \
	 <<  "\nTarget: " << src.getTarget() << "\n****************************" << std::endl;
	return output_stream;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	std::cout << "RobotomyRequestForm copy assignment is called for RobotomyRequestForm " << std::endl;
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
	}
	return (*this);
}
