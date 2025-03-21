#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Other.hpp"
#include <random>
#include <exception>

Base * generate(void)
{
	std::random_device				rd;
	std::mt19937					gen(rd());
	std::uniform_int_distribution<> dis(0,2);

	if (dis(gen) == 0)
		return (new A);
	else if (dis(gen) == 1)
		return (new B);
	else
		return (new C);
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "It is an object of class A (by pointer)" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "It is an object of class B (by pointer)" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "It is an object of class C (by pointer)" << std::endl;
	else
		std::cout << "Unknown class (by pointer)" << std::endl;
}

void	identify(Base& p)
{
	A	classA;
	B	classB;
	C	classC;
	try
	{
		classA = dynamic_cast<A&>(p);
		std::cout << "It is an object of class A (by ref)" << std::endl;
	}
	catch(const std::bad_cast& e)
	{
		;
	}
	try
	{
		classB = dynamic_cast<B&>(p);
		std::cout << "It is an object of class B (by ref)" << std::endl;
	}
	catch(const std::bad_cast& e)
	{
		;
	}
	try
	{
		classC = dynamic_cast<C&>(p);
		std::cout << "It is an object of class C (by ref)" << std::endl;
	}
	catch(const std::bad_cast& e)
	{
		std::cerr <<  "Unknown class (by ref)" << '\n';
	}
}

int main()
{
	Base *obj;

	std::cout << "Test A, B, C classes" << std::endl;
	obj = generate();
	Base& ref1 = *obj;
	identify(obj);
	identify(ref1);
	delete obj;
	
	std::cout  << std::endl;
	
	obj = generate();
	Base& ref2 = *obj;
	identify(obj);
	identify(ref2);
	delete obj;
	
	std::cout  << std::endl;	
	
	obj = generate();
	Base& ref3 = *obj;
	identify(obj);
	identify(ref3);
	delete obj;
	
	std::cout  << std::endl;	
	
	std::cout << "Test Other class" << std::endl;
	Base *obj2 = new Other;
	Base& ref4 = *obj2;
	identify(obj2);
	identify(ref4);
	return (0);
}