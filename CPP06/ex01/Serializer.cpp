#include "Serializer.hpp"

/*Member functions*/
uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

/*Constructors*/

Serializer::Serializer()
{
    std::cout << "Serializer default constructor is called" << std::endl;
}

/*Destructors*/
Serializer::~Serializer( void )
{
    std::cout << "Serializer destructor is called" << std::endl;
}

/*Overload operators*/
Serializer& Serializer::operator=(const Serializer& src)
{
	std::cout << "Serializer copy assignment is called" << std::endl;
	if (this != &src)
	{
		*this = src;
	}
	return (*this);
}
