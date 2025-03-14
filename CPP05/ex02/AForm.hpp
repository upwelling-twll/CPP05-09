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
	AForm(void);
	AForm(const AForm &src);

public:
	/*Member functions*/
	void				beSigned(Bureaucrat& bureaucrat);
	virtual bool		execute(Bureaucrat const & executor) const = 0;

	/*Getters*/
	const std::string&	getName() const;
	const bool&			getStatus() const;
	const unsigned int&			getGradeToExecute() const;
	const unsigned int&			getGradeToSign() const;

	/*Destructors*/
	virtual ~AForm( void );

	/*Operators*/
	AForm &operator=(const AForm& src);
};

std::ostream& operator<<(std::ostream &output_stream, AForm& src);

class AFormException : public std::exception
{
public:
    virtual const char* what() const throw()
    {
        return "AForm Exception occurred!";
    }
};

class FormIsNotSigned : public AFormException
{
public:
    const char* what() const throw()
    {
        return "Form is not signed!";
    }
};

class ExecutorGradeTooLow : public AFormException
{
public:
    const char* what() const throw()
    {
        return "Executor's grade is too low to execute the form!";
    }
};

#endif