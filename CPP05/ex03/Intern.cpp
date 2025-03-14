#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

static	AForm* createShrubberyCreatorForm(std::string const &target)
{
	return new ShrubberyCreationForm(target);
}

static	AForm* createRobotomyRequestForm(std::string const &target)
{
	return new RobotomyRequestForm(target);
}

static	AForm* createPresidentialPardonForm(std::string const &target)
{
	return new PresidentialPardonForm(target);
}

AForm&	Intern::makeForm(std::string const &formName, std::string const &formTarget)
{
	std::string formNames[3] = {"shrubbery creation", "robotomy request",\
	 "presidential pardon"};
	AForm* (*formConstructors[3])(std::string const &) = {createShrubberyCreatorForm, \
	 createRobotomyRequestForm, createPresidentialPardonForm};

	for (int i = 0; i < 3; i++)
	{
		if (formNames[i] == formName)
		{
			std::cout << "Intern created " << formName << std::endl;
			return (*(formConstructors[i])(formTarget));
		}
	}
	throw FormNotFound();
}

/*Constructors*/

Intern::Intern(void)
{
	std::cout << "Intern default constructor is called" << std::endl;
}

Intern::Intern(const Intern &src)
{
	std::cout << "Intern copy constructor is called" << std::endl;
	*this = src;
}

/*Destructors*/

Intern::~Intern( void )
{
	std::cout << "Intern destructor is called "  << std::endl;
}

/*Operators*/

std::ostream& operator<<(std::ostream& output_stream, Intern& src)
{
	if (sizeof(src))
		output_stream << "This is Intern, it only can makeForm ";
	return output_stream;
}

Intern&	Intern::operator=(const Intern& src)
{
	if (sizeof(src))
		std::cout << "Intern copy assignment is called" << std::endl;
	return (*this);
}
