#ifndef _FORM_HPP_
# define  _FORM_HPP_

# include <iostream>
# include <fstream>
# include <exception>

class Bureaucrat;
class Form
{
private:
	const std::string	_name;
	bool				_status;
	const unsigned int	_gradeToSign;
	const unsigned int	_gradeToExecute;

public:
	/*Member functions*/
	void	beSigned(Bureaucrat& bureaucrat);

	/*Getters*/
	const std::string&	getName();
	bool&	getStatus();
	const unsigned int&			getGradeToExecute() const;
	const unsigned int&			getGradeToSign() const;

	/*Constructors*/
	Form(void);
	Form(const std::string name, unsigned int gradeToSign, unsigned int gradeToExecute);
	Form(const Form &src);

	/*Destructors*/
	~Form( void );

	/*Operators*/
	Form &operator=(const Form& src);
};

std::ostream& operator<<(std::ostream &output_stream, Form& src);

#endif