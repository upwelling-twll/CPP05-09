#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>

class	AForm;

class	Intern
{
public:
	/*Member functions*/
	AForm&	makeForm(std::string const &formName, std::string const &formTarget);

	/*Constructors*/
	Intern( void );
	Intern(const Intern &src);

	/*Destructors*/
	~Intern(void);

	/*Operators*/
	Intern &operator=(const Intern& src);
};

std::ostream& operator<<(std::ostream& output_stream, Intern& src);

#endif