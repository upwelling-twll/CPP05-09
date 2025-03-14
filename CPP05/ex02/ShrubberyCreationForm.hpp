#ifndef _SHRUBBERYCREATIONFORM_HPP_
# define  _SHRUBBERYCREATIONFORM_HPP_

# include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{

public:

	/*Member functions*/
	void		execute(Bureaucrat const & executor) const override;

	/*Getters*/
	const std::string&	getName();
	bool&				getStatus();

	/*Constructors*/
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const std::string name, unsigned int gradeToSign, unsigned int gradeToExecute);
	ShrubberyCreationForm(const ShrubberyCreationForm &src);

	/*Destructors*/
	virtual ~ShrubberyCreationForm( void );

	/*Operators*/
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm& src);
};

std::ostream& operator<<(std::ostream &output_stream, ShrubberyCreationForm& src);

#endif