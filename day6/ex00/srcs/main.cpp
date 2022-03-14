
#include <iostream>

#include "Converter.hpp"


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Incorrect number of arg, should offer one expression to convert" << std::endl;
		return 0;
	}
	const std::string s = argv[1];
	Converter c(s);
	std::cout << c << std::endl;
	return 0;
}