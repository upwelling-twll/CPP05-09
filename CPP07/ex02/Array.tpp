// #ifndef ARRAY_HPP
// # define ARRAY_HPP

#include "Array.hpp"

/*Member functions*/
template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

/*Constructors*/
template <typename T>
Array<T>::Array() : _data(NULL), _size(0)
{
	std::cout << "Array default constructor is called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	_data = new T[_size];
	for (unsigned int i = 0; i < _size; ++i)
		_data[i] = T();
   std::cout << "Array parameterized constructor is called" << std::endl;
}

template <typename T>
Array<T>::Array(const Array& other) : _size(other._size)
{
	_data = new T[_size];
	for (unsigned int i = 0; i < _size; ++i)
		_data[i] = other._data[i];
	std::cout << "Array copy constructor is called" << std::endl;
	
}

/*Destructors*/
template <typename T>
Array<T>::~Array()
{
	delete[] _data; 
    std::cout << "Array destructor is called" << std::endl;
}

/*Overload operators*/
template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
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
	std::cout << "Array copy assignment is called" << std::endl;
	return (*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
	{
		throw std::out_of_range("Index out of bounds");
	}
	return _data[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
	{
		throw std::out_of_range("Index out of bounds");
	}
	return _data[index];
}

// template <typename T>
// std::ostream& operator<<(std::ostream& output_stream, Array<T>& src)
// {
// 	output_stream << "* Array Class info*\n";
// 	for (unsigned int i = 0; i < src._size; ++i)
// 	{
// 		output_stream << src._data[i];
// 	}
// 	return output_stream;
// }

// #endif