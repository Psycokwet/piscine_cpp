#include <iostream>
#include <string>
#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << "Exception should occurs when adding the next number" << std::endl;
	try{
		sp.addNumber(11);
	}catch(const std::exception &e)
	{
		std::cout << "An error occured:" << e.what() << std::endl;
	}
	std::cout << sp << std::endl;
	Span sp2 = Span(10);
	std::vector<int> src;
	src.push_back(1);
	src.push_back(2);
	src.push_back(3);
	src.push_back(4);
	src.push_back(5);
	sp2.addRange(src.begin(), src.end());
	sp2.addRange(src.begin(), src.end());

	std::cout << sp2 << std::endl;
	std::cout << "Exception should occurs when adding the next number" << std::endl;
	try{
		sp2.addNumber(11);
	}catch(const std::exception &e)
	{
		std::cout << "An error occured:" << e.what() << std::endl;
	}
	return 0;
}