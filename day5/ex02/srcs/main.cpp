#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

#include <iostream>

int main()
{
    std::cout << "Should sign and execute" << std::endl;
    try
    {
        Bureaucrat todd(42, "Todd");
        ShrubberyCreationForm f1("file");
        std::cout << todd << std::endl;
        std::cout << f1 << std::endl;
		todd.signForm(f1);
        std::cout << f1 << std::endl;
		todd.executeForm(f1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl << "Should sign but not execute" << std::endl;
    try
    {
        Bureaucrat todd(46, "Todd");
        RobotomyRequestForm f1("The doctor");
        std::cout << todd << std::endl;
        std::cout << f1 << std::endl;
		todd.signForm(f1);
        std::cout << f1 << std::endl;
		todd.executeForm(f1);
        std::cout << f1 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl << "Should sign and execute" << std::endl;
    try
    {
        Bureaucrat todd(42, "Todd");
        RobotomyRequestForm f1("The doctor");
        std::cout << todd << std::endl;
        std::cout << f1 << std::endl;
		todd.signForm(f1);
        std::cout << f1 << std::endl;
		todd.executeForm(f1);
        std::cout << f1 << std::endl;
		todd.executeForm(f1);
        std::cout << f1 << std::endl;
		todd.executeForm(f1);
        std::cout << f1 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl << "Should sign but not execute" << std::endl;
    try
    {
        Bureaucrat todd(25, "Todd");
        PresidentialPardonForm f1("Zaphod Beeblebrox");
        std::cout << todd << std::endl;
        std::cout << f1 << std::endl;
		todd.signForm(f1);
        std::cout << f1 << std::endl;
		todd.executeForm(f1);
        std::cout << f1 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl << "Should sign and execute" << std::endl;
    try
    {
        Bureaucrat todd(2, "Todd");
        PresidentialPardonForm f1("Zaphod Beeblebrox");
        std::cout << todd << std::endl;
        std::cout << f1 << std::endl;
		todd.signForm(f1);
        std::cout << f1 << std::endl;
		todd.executeForm(f1);
        std::cout << f1 << std::endl;
		todd.executeForm(f1);
        std::cout << f1 << std::endl;
		todd.executeForm(f1);
        std::cout << f1 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

	return 0;
}