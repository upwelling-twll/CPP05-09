#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
	std::cout << " 	~Test Mutant Stack (subject tests)~" << std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	// mstack.printStack("mstack");

	std::cout << "\n 	~Compare with list~" << std::endl;
	std::list<int> mlist;
	mlist.push_back(5);
	mlist.push_back(17);
	std::cout << mlist.back() << std::endl;
	mlist.pop_back();
	std::cout << mlist.size() << std::endl;
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	//[...]
	mlist.push_back(0);
	std::list<int>::iterator itl = mlist.begin();
	std::list<int>::iterator itle = mlist.end();
	++itl;
	--itl;
	while (itl != itle)
	{
		std::cout << *itl << std::endl;
		++itl;
	}
	std::list<int> l(mlist);


	std::cout << "\n 	~Test Mutant Stack (my tests)~" << std::endl;
	s.push(42);
	std::cout << "After pushing 42 to s: ";
	mstack.printStack("mstack");
	std::cout << "s: ";
	while (!s.empty())
	{
		std::cout << s.top() << " ";
		s.pop();
	}
	std::cout << std::endl;
	
	return 0;
}

