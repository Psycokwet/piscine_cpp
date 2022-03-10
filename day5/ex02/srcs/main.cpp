#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main()
{
    std::cout << "Should sign" << std::endl;
    try
    {
        Bureaucrat todd(42, "Todd");
        ShrubberyCreationForm f1;
        std::cout << todd << std::endl;
        std::cout << f1 << std::endl;
		todd.signForm(f1);
        std::cout << f1 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "Should not sign" << std::endl;
    try
    {
        Bureaucrat todd(42, "Todd");
        ShrubberyCreationForm f1;
        std::cout << todd << std::endl;
        std::cout << f1 << std::endl;
		todd.signForm(f1);
        std::cout << f1 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl << "Should get a too low exception" << std::endl;
    try
	{
        ShrubberyCreationForm f1;
		std::cout << f1 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl << "Should get a too high exception" << std::endl;
    try
    {
        ShrubberyCreationForm f1;
		std::cout << f1 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
	return 0;
}