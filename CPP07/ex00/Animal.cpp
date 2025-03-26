#include "Animal.hpp"

/*Member functions*/

/*Getters and Setters*/
const std::string Animal::getSpecie() const
{
	return (this->specie);
}

int Animal::getAge() const
{
	return (this->age);
}

int Animal::getSize() const
{
	return (this->size);
}

/*Constructors*/
Animal::Animal(std::string specie, int age, int size) : specie(specie), size(size)
{
	this->age = age;
	std::cout << "Animal parameterized constructor is called" << std::endl;
}

Animal::Animal() : specie("Cat"), size(1)
{
	this->age = 1;
    std::cout << "Animal default constructor is called" << std::endl;
}

/*Destructors*/
Animal::~Animal( void )
{
    std::cout << "Animal destructor is called" << std::endl;
}

/*Overload operators*/
Animal& Animal::operator=(const Animal& src)
{
	std::cout << "Animal copy assignment is called" << std::endl;
	if (this != &src)
	{
		this->age = src.age;
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& output_stream, const Animal& src)
{
	output_stream << "\n* Animal Class info*\n Specie: " << src.getSpecie() \
	 << "\nAge: " << src.getAge() << std::endl;
	return output_stream;
}

bool Animal::operator<(const Animal& other) const
{
	if (this->size < other.getSize())
		return (true);
	return (false);
}

bool Animal::operator>(const Animal& other) const 
{
	if (this->size > other.getSize())
		return (true);
	return (false);
}
