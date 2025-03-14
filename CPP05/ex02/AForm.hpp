#ifndef _AFORM_HPP_
# define  _AFORM_HPP_

# include <iostream>
# include <fstream>
# include <exception>

class Bureaucrat;
class AForm
{
private:
	const std::string	_name;
	bool				_status;
	const unsigned int	_gradeToSign;
	const unsigned int	_gradeToExecute;
	
protected:
	/*Constructors*/
	AForm(const std::string name, unsigned int gradeToSign, unsigned int gradeToExecute);

public:
	/*Member functions*/
	void				beSigned(Bureaucrat& bureaucrat);
	virtual void		execute(Bureaucrat const & executor) const = 0;

	/*Getters*/
	const std::string&	getName();
	bool&				getStatus();

	/*Constructors*/
	AForm(void);
	AForm(const AForm &src);

	/*Destructors*/
	virtual ~AForm( void );

	/*Operators*/
	AForm &operator=(const AForm& src);
};

std::ostream& operator<<(std::ostream &output_stream, AForm& src);

#endif