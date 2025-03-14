#ifndef _SHRUBBERYCREATIONFORM_HPP_
# define  _SHRUBBERYCREATIONFORM_HPP_

# include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	private:
	std::string	_target;

	public:

	/*Member functions*/
	bool		execute(Bureaucrat const & executor) const;

	/*Getters and Setters*/
	std::string &getTarget();

	/*Constructors*/
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &src);

	/*Destructors*/
	virtual ~ShrubberyCreationForm( void );

	/*Operators*/
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm& src);
};

std::ostream& operator<<(std::ostream &output_stream, ShrubberyCreationForm& src);

class ShrubberyCreationException : public AFormException
{
public:
    const char* what() const throw()
    {
        return "ShrubberyCreationForm Exception occurred!";
    }
};

// Specific exception for file error in ShrubberyCreationForm
class ShrubberyFileError : public ShrubberyCreationException
{
public:
    const char* what() const throw()
    {
        return "Error creating the shrubbery file!";
    }
};

#endif