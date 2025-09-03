#include "Span.hpp"

void Span::addNumber(int n)
{
	if (_size == _max_size)
		throw std::runtime_error("Span is full");
	_vec.push_back(n);
	_sorted.insert(n);
	_size++;	
}

long long int	Span::shortestSpan()
{
	if (_size < 2)
		throw std::runtime_error("Not enough numbers to find a span");
	long long minDiff = LLONG_MAX;
	for (std::multiset<int>::iterator it = _sorted.begin(), next = ++_sorted.begin(); next != _sorted.end(); ++it, ++next)
	{
		long long diff = static_cast<long long>(*next) - *it;
		if (diff < minDiff)
			minDiff = diff;
	}
    return minDiff;
}

long long int	Span::longestSpan()
{
	if (_size < 2)
		throw std::runtime_error("Not enough numbers to find a span");
	return (std::llabs(static_cast<long long int>(*(_sorted.rbegin())) - static_cast<long long int>(*(_sorted.begin()))));
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