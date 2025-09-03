#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <cstdlib>
#include <set>
#include <climits>


// template <typename T>
class Span
{

private:
	unsigned int		_size;
	
	unsigned int		_max_size;
	std::vector<int>	_vec;
	
	std::multiset<int>	_sorted;

public:
	/*Member functions*/
	void 			addNumber(int n);
	void			addRange(int start, int end);
	long long int	shortestSpan();
	long long int	longestSpan();

	/*Constructors*/
	Span(unsigned int max_size);
	Span(void);
	Span(const Span& other);
	
	/*Destructor*/
	~Span();

	/*Assignment operator*/
	Span& operator=(const Span& other);
};

 #endif