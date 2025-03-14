#ifndef _ROBOTOMYREQUESTFORM_HPP_
# define  _ROBOTOMYREQUESTFORM_HPP_

# include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:
	std::string	_target;

	public:

	/*Member functions*/
	bool		execute(Bureaucrat const & executor) const;

	/*Getters and Setters*/
	std::string &getTarget();

	/*Constructors*/
	RobotomyRequestForm(void);
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &src);

	/*Destructors*/
	virtual ~RobotomyRequestForm( void );

	/*Operators*/
	RobotomyRequestForm &operator=(const RobotomyRequestForm& src);
};

std::ostream& operator<<(std::ostream &output_stream, RobotomyRequestForm& src);

class RobotomyRequestException : public AFormException
{
public:
    const char* what() const throw()
    {
        return "RobotomyRequestForm Exception occurred!";
    }
};

// Specific exception for file error in RobotomyRequestForm
class RobotomyRequestError : public RobotomyRequestException
{
public:
    const char* what() const throw()
    {
        return  "Robotomy failed!";
    }
};

#endif