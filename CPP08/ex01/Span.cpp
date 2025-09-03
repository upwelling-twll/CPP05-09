#include "Span.hpp"

void Span::addNumber(int n)
{
	if (_size == _max_size)
		throw std::runtime_error("Span is full");
	_vec.push_back(n);
	_size++;
	if (_size == 1)
	{
		_max_value = n;
		_min_value = n;
		_premin_value = n;
	}
	else if (_size > 1)
	{
		if (n > _max_value)
			_max_value = n;
		if (n < _min_value)
		{
			_premin_value = _min_value;
			_min_value = n;
		}
		else if (n < _premin_value)
		{
			_premin_value = n;
		}
	}
}

long long int	Span::shortestSpan()
{
	if (_size < 2)
		throw std::runtime_error("Not enough numbers to find a span");
	else if (_size == 2)
		return ((std::llabs((static_cast<long long int>(_vec[1]) - static_cast<long long int>(_vec[0])))));
	else
		return ((std::llabs(static_cast<long long int>(_min_value) - static_cast<long long int>(_premin_value))) - 1);
}

long long int	Span::longestSpan()
{
	if (_size < 2)
		throw std::runtime_error("Not enough numbers to find a span");
	else if (_size == 2)
		return (std::llabs(static_cast<long long int>(_vec[1]) - static_cast<long long int>(_vec[0])));
	else
		return (std::llabs(static_cast<long long int>(_max_value) - static_cast<long long int>(_min_value)));
}


/*Constructors*/
Span::Span(unsigned int max_size)
{
	_size = 0;
	_max_size = max_size;
	std::cout << "Span constructor called" << std::endl;
}

Span::Span(void)
{
	_size = 0;
	_max_size = 0;
	std::cout << "Span default constructor called" << std::endl;
}

Span::Span(const Span& other)
{
	*this = other;
	std::cout << "Span copy constructor called" << std::endl;
}
	
/*Destructor*/
Span::~Span()
{
	std::cout << "Span destructor called" << std::endl;
}

/*Assignment operator*/
Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_vec = other._vec;
		_size = other._size;
		_max_size = other._max_size;
	}
	return *this;
}