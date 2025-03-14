#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat	Vanya("Vanya", 150);
	Bureaucrat	Sveta("Sveta", 10);

	try
	{
		Sveta.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout<<Sveta<<std::endl;
	try
	{
		Sveta.decrementGrade();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout<<Sveta<<std::endl;

	std::cout<<"\nTHE STORY OF VANYA"<<std::endl;
	std::cout<<Vanya<<std::endl;
	try
	{
		Vanya.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout<<Vanya<<std::endl;

	try
	{
		Bureaucrat	Borboskin("Borboskin", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
