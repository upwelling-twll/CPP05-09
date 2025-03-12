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
	Bureaucrat	Borboskin("Borboskin", 130);

	std::cout<<"\nFORMS TEST"<<std::endl;
	Form FirstForm("Spread kindness", 100, 100);
	std::cout << FirstForm << std::endl;
	Borboskin.signForm(FirstForm);
	std::cout << FirstForm << std::endl;
	Sveta.signForm(FirstForm);
	std::cout << FirstForm << std::endl;
	try
	{
		Borboskin.signForm(FirstForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "\nANOTHER TEST" << std::endl;
	try
	{
		Form MostSecretForm("!!!TOP SECRET!!!", 0, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	Form MostSecretForm("!!!TOP SECRET!!!", 1, 1);
	std::cout << MostSecretForm << std::endl;
	Borboskin.signForm( MostSecretForm);
	std::cout << MostSecretForm << std::endl;
	Bureaucrat SuperCat("Barsik", 1);
	SuperCat.signForm(MostSecretForm);
	std::cout << MostSecretForm << std::endl;
	Bureaucrat Stranger("Reptilian Humonoid", 1);
	Stranger.signForm(MostSecretForm);
}