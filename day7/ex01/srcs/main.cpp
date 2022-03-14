#include <iostream>
#include <string>
#include "iter.hpp"
#include "Awesome.hpp"

template <typename T>
void print(T const &x)
{
	std::cout << x << std::endl; return;
}

int main()
{
	std::string tab_s[] = {"pwett", "pwot", "pwit"};
	char tab_c[] = {'a', 'b', 'c'};
	iter(tab_s, 3, print);
	iter(tab_c, 3, print);

	std::cout <<"-----------"<< std::endl;;

	int tab[] = {0, 1, 2, 3, 4};
	Awesome tab2[5];
	iter(tab, 5, print);
	iter(tab2, 5, print);
	return 0;
}