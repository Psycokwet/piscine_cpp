#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    std::cout << "Should not get an exception" << std::endl;
    try
    {
        Bureaucrat todd(42, "Todd");
        std::cout << todd << std::endl;
        todd.decGrade();
        std::cout << todd << std::endl;
        todd.incGrade();
        std::cout << todd << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout  << std::endl<< "Should get a too high exception" << std::endl;
    try
    {
        Bureaucrat dirk(Bureaucrat::HIGHEST_GRADE, "Dirk");
        std::cout << dirk << std::endl;
        dirk.incGrade();
        std::cout << dirk << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl << "Should get a too low exception" << std::endl;
    try
    {
        Bureaucrat link(Bureaucrat::LOWEST_GRADE, "Link");
        std::cout << link << std::endl;
        link.decGrade();
        std::cout << link << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "Should get a too low exception" << std::endl;
    try
    {
        Bureaucrat zelda(Bureaucrat::LOWEST_GRADE + 1, "Zelda");
        std::cout << zelda << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl << "Should get a too high exception" << std::endl;
    try
    {
        Bureaucrat hilda(Bureaucrat::HIGHEST_GRADE - 1, "Hilda");
        std::cout << hilda << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
	return 0;
}