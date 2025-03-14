#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

/*Member functions*/
bool ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (getStatus() == false)
		throw FormIsNotSigned();
	if (executor.getGrade() >= getGradeToExecute())
		throw ExecutorGradeTooLow();
	std::string filename = this->_target + "_shrubbery";
	std::ofstream 	file(filename);
	if (!file.is_open())
	{
        std::cerr << "Error opening file: " << filename << std::endl;
        throw ShrubberyFileError();
    }
	else
	{
		file << "       _-_" << std::endl;
        file << "    /~~   ~~\\" << std::endl;
        file << " /~~         ~~\\" << std::endl;
        file << "{               }" << std::endl;
        file << " \\  _-     -_  /" << std::endl;
        file << "   ~  \\ //  ~" << std::endl;
        file << "       ||" << std::endl;
        file << "       ||" << std::endl;
        file << "       ||" << std::endl;
        file.close();
		return (true);
	}
	return (false);
}

/*Getters and Setters*/
std::string &ShrubberyCreationForm::getTarget()
{
	return (this->_target);
}

/*Constructors*/

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm default constructor is called" << std::endl;
	this->_target = "Default_Shrubbery_target";
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm constructor is called" << std::endl;
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src)
{
	std::cout << "ShrubberyCreationForm copy constructor is called" << std::endl;
	this->_target = src._target;
}

/*Destructors*/

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	std::cout << "ShrubberyCreationForm destructor is called for " << this->getName() << std::endl;
}

/*Operators*/

std::ostream& operator<<(std::ostream& output_stream, ShrubberyCreationForm& src)
{
	output_stream << "\n*******Form_Info************\n" \
	 << src.getName() << ", status " << src.getStatus() \
	 << "\ngradeToSign:" << src.getGradeToSign() << "\ngradeToExecute:" << src.getGradeToExecute() \
	 <<  "\nTarget: " << src.getTarget() << "\n****************************" << std::endl;
	return output_stream;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	std::cout << "ShrubberyCreationForm copy assignment is called for ShrubberyCreationForm " << std::endl;
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
	}
	return (*this);
}
