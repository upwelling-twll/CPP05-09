#include <iostream>
#include "Span.hpp"

template <typename T>
void	testEasyfind(T& container, int i)
{
	int res;
	
	std::cout << "\nSearching for: " << i << std::endl;
	try {
		res = *easyfind(container, i);
		std::cout << "Found: " << res << std::endl;
	}
	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}
}

int main()
{
	std::cout << " 	~Test span of 0 elements~" << std::endl;
	Span s0(0);
	try {
		std::cout << "Shortest span: " << s0.shortestSpan() << std::endl;
	}
	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "Longest span: " << s0.longestSpan() << std::endl;
	}
	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n 	~Test span of 5 elements~" << std::endl;

	Span s(5);
	s.addNumber(1);
	s.addNumber(2);
	s.addNumber(3);
	s.addNumber(-40);
	s.addNumber(-50);
	try {
		s.addNumber(6);
	}
	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "Shortest span: " << s.shortestSpan() << std::endl;
	std::cout << "Longest span: " << s.longestSpan() << std::endl;


	std::cout << "\n\n 	~Test span of 1 element~" << std::endl;
	Span s1(1);
	s1.addNumber(1);

	try {
		std::cout << "Shortest span: " << s1.shortestSpan() << std::endl;
	}
	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "Longest span: " << s1.longestSpan() << std::endl;
	}
	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n\n 	~Test span of 2 elements~" << std::endl;
	Span s2(2);
	s2.addNumber(1);
	s2.addNumber(1);
	try {
		std::cout << "Shortest span: " << s2.shortestSpan() << std::endl;
	}
	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "Longest span: " << s2.longestSpan() << std::endl;
	}
	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n\n 	~Test span of 2 max_int & min_int elements~" << std::endl;
	Span s4(2);
	s4.addNumber(2147483647);
	s4.addNumber(-2147483648);
	try {
		std::cout << "Shortest span: " << s4.shortestSpan() << std::endl;
	}
	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "Longest span: " << s4.longestSpan() << std::endl;
	}
	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}


	std::cout << "\n\n 	~Test span of 15 000 random elements~" << std::endl;
	Span s3(15003);
	for (int i = 0; i < 15000; ++i) {
		s3.addNumber(rand());
	}
	s3.addNumber(2147483647);
	s3.addNumber(-2147483648);
	s3.addNumber(-2147483647);
	try {
		std::cout << "Shortest span: " << s3.shortestSpan() << std::endl;
	}
	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "Longest span: " << s3.longestSpan() << std::endl;
	}
	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}


	std::cout << "\n\n 	~Test span of 3 elements~" << std::endl;
	Span s5(3);
	s5.addNumber(1);
	s5.addNumber(-20);
	s5.addNumber(-19);
	try {
		std::cout << "Shortest span: " << s5.shortestSpan() << std::endl;
	}
	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "Longest span: " << s5.longestSpan() << std::endl;
	}
	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}


	std::cout << "\n\n 	~Subject test~" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "\n\n 	~Range of iterators test~" << std::endl;
	Span s6(100);
	s6.addRange(1, 100);
	std::cout << "Shortest span: " << s6.shortestSpan() << std::endl;
	std::cout << "Longest span: " << s6.longestSpan() << std::endl;	
	
	std::cout << "\n\n 	~Bad range of iterators test~" << std::endl;
	Span s7(100);

	try
	{
		s7.addRange(20, 200);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "Shortest span: " << s7.shortestSpan() << std::endl;
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "Longest span: " << s7.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}

