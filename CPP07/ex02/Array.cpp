#include "Array.hpp"

/*Member functions*/
unsigned int Array::size() const
{
	return _size;
}

/*Getters and Setters*/

/*Constructors*/
Array::Array(/*Parameterized Constructor*/)
{
   std::cout << "Array parameterized constructor is called" << std::endl;
}

Array::Array() : _data(NULL), _size(0)
{
    std::cout << "Array default constructor is called" << std::endl;
}

/*Destructors*/
Array::~Array( void )
{
	delete[] _data; 
    std::cout << "Array destructor is called" << std::endl;
}

/*Overload operators*/
Array& Array::operator=(const Array& other)
{
	std::cout << "Array copy assignment is called" << std::endl;
	if (this != &other)
	{
		delete[] _data;

        _size = other._size;
        _data = new T[_size];
        for (unsigned int i = 0; i < _size; ++i)
		{
            _data[i] = other._data[i];
        }
	}
	return (*this);
}

T& Array::operator[](unsigned int index)
{
	if (index >= _size) {
		throw std::out_of_range("Index out of bounds");
	}
	return _data[index];
}

const T& Array::operator[](unsigned int index) const
{
	if (index >= _size) {
		throw std::out_of_range("Index out of bounds");
	}
	return _data[index];
}

std::ostream& operator<<(std::ostream& output_stream, Array& src)
{
	output_stream << "* Array Class info*" << std::endl;
	return output_stream;
}

