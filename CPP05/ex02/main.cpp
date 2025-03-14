#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

void	test1()
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
	Bureaucrat	Borboskin("Borboskin", 130);

	// std::cout<<"\nFORMS TEST"<<std::endl;
	// AForm FirstForm("Spread kindness", 100, 100);
	// std::cout << FirstForm << std::endl;
	// Borboskin.signForm(FirstForm);
	// std::cout << FirstForm << std::endl;
	// Sveta.signForm(FirstForm);
	// std::cout << FirstForm << std::endl;
	// try
	// {
	// 	Borboskin.signForm(FirstForm);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	
	// std::cout << "\nANOTHER TEST" << std::endl;
	// try
	// {
	// 	AForm MostSecretForm("!!!TOP SECRET!!!", 0, 0);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// AForm MostSecretForm("!!!TOP SECRET!!!", 1, 1);
	// std::cout << MostSecretForm << std::endl;
	// Borboskin.signForm( MostSecretForm);
	// std::cout << MostSecretForm << std::endl;
	// Bureaucrat SuperCat("Barsik", 1);
	// SuperCat.signForm(MostSecretForm);
	// std::cout << MostSecretForm << std::endl;
	// Bureaucrat Stranger("Reptilian Humonoid", 1);
	// Stranger.signForm(MostSecretForm);
}

int main()
{
	// test1();
	Bureaucrat	Vanya("Vanya", 130);
	std::cout << Vanya;
	std::cout << "\n* * * * * * * EX02 TEST * * * * * * *" << std::endl;

	ShrubberyCreationForm other("dacha");
	std::cout << other;
	std::cout << std::endl;

	std::cout << std::endl;
	try 
	{
		Vanya.executeForm(other);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << other;
	std::cout << std::endl;

	Vanya.signForm(other);
	std::cout << std::endl;
	// Vanya.executeForm(other);
	// std::cout << std::endl;
	// std::cout << other;

	// std::cout << std::endl;
	// Vanya.executeForm(other);
	// std::cout << std::endl;
	// std::cout << other << std::endl;;

	Bureaucrat	kotunya("Barsik", 10);
	std::cout << kotunya << std::endl;
	try
	{
		kotunya.executeForm(other);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n		ROBOTOMY TEST 				\n" << std::endl;
	RobotomyRequestForm robot("Mars");
	std::cout << robot << std::endl;
	std::cout << std::endl;
	kotunya.signForm(robot);
	try
	{
		kotunya.executeForm(robot);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
}