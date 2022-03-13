
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

	// std::cout << "test :" << FromString<int>(s)<< std::endl;
	// std::cout << "test eq :" << (ToString(FromString<double>(s)) == s)<< std::endl;
	// std::cout << "test ts :" << ToString(FromString<double>(s))<< std::endl;
	// std::cout << "test :" << FromString<float>(s)<< std::endl;
	// std::cout << "test :" << FromString<double>(s)<< std::endl;
	// std::cout << "test :" << FromString<char>(s)<< std::endl;
	return 0;
}