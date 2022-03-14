#include <iostream>
#include <string>
#include "Array.hpp"


int main()
{
	{
		Array<int> ints;
		std::cout << "Should throw an exception" << std::endl;
		try
		{
			std::cout << ints.size() << std::endl;
			std::cout << ints[0] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		Array<int> ints(2);
		std::cout << std::endl << "Should not throw an exception" << std::endl;
		try
		{
			std::cout << ints.size() << std::endl;
			for(unsigned int i = 0; i < ints.size(); i++)
				std::cout << i << ":"<< ints[i] << std::endl;
			ints[0] = 42;
			ints[1] = 43;
			std::cout << std::endl;
			for(unsigned int i = 0; i < ints.size(); i++)
				std::cout << i << ":"<< ints[i] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	
	{
		Array<std::string> strings(2);
		std::cout << std::endl << "Should not throw an exception" << std::endl;
		try
		{
			std::cout << strings.size() << std::endl;
			for(unsigned int i = 0; i < strings.size(); i++)
				std::cout << i << ":"<< strings[i] << std::endl;
			strings[0] = "Like a pony";
			strings[1] = "In the pony world";
			std::cout << std::endl;
			for(unsigned int i = 0; i < strings.size(); i++)
				std::cout << i << ":"<< strings[i] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	
	
	return 0;
}