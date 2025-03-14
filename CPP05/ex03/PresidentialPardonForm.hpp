#ifndef _PRESIDENTIALPARDONFORM_HPP_
# define  _PRESIDENTIALPARDONFORM_HPP_

# include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	private:
	std::string	_target;

	public:

	/*Member functions*/
	bool		execute(Bureaucrat const & executor) const;

	/*Getters and Setters*/
	std::string &getTarget();

	/*Constructors*/
	PresidentialPardonForm(void);
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &src);

	/*Destructors*/
	virtual ~PresidentialPardonForm( void );

	/*Operators*/
	PresidentialPardonForm &operator=(const PresidentialPardonForm& src);
};

std::ostream& operator<<(std::ostream &output_stream, PresidentialPardonForm& src);

#endif