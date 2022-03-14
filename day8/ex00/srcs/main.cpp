#include <iostream>
#include <string>
#include <list>
#include "easyfind.hpp"

int main()
{
	std::list<int> l;
	l.push_back(10);
	l.push_back(11);
	l.push_back(12);
	l.push_back(13);
	l.push_back(14);

    std::cout << "l = { ";
	std::list<int>::iterator it;
	for (it = l.begin(); it != l.end(); ++it){
		std::cout << "\t" << *it << std::endl;
	}
    std::cout << "};\n";
	int needle = 12;
	int index = easyfind(l, needle);
	if (index != NOT_FOUND)
    	std::cout << "needle " << needle << " found at " << index << std::endl;
	else
    	std::cout << "needle " << needle << " not found" << std::endl;
	return 0;
}