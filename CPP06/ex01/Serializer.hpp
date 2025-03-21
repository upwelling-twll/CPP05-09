#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include "Data.hpp"

class Serializer
{
private:
    // Add member variables here

public:
	/*Member functions*/
    static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
	/*Getters and Setters*/

	/*Constructors*/
	Serializer(void);

	/*Destructors*/
    ~Serializer( void );

	/*Overload operators*/
	Serializer &operator=(const Serializer& src);
};

#endif // SERIALIZER_HPP
