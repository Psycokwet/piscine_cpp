#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

#include <iostream>

int main()
{
    std::cout << "Should sign and execute" << std::endl;
	Intern someRandomIntern;
	AForm* f1;
    try
    {
        Bureaucrat todd(42, "Todd");
		f1 = someRandomIntern.makeForm("shruberry request", "Bender");
		if (f1 != NULL)
		{
			std::cout << todd << std::endl;
			std::cout << *f1 << std::endl;
			todd.signForm(*f1);
			std::cout << *f1 << std::endl;
			todd.executeForm(*f1);
			delete f1;
		}
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
		delete f1;
    }
    std::cout << std::endl << "Should sign but not execute" << std::endl;
    try
    {
        Bureaucrat todd(46, "Todd");
		f1 = someRandomIntern.makeForm("robotomy request", "Bender");
		if (f1 != NULL)
		{
			std::cout << todd << std::endl;
			std::cout << *f1 << std::endl;
			todd.signForm(*f1);
			std::cout << *f1 << std::endl;
			todd.executeForm(*f1);
			std::cout << *f1 << std::endl;
			delete f1;
		}
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
		delete f1;
    }
    std::cout << std::endl << "Should sign and execute" << std::endl;
    try
    {
        Bureaucrat todd(42, "Todd");
		f1 = someRandomIntern.makeForm("robotomy request", "Bender");
		if (f1 != NULL)
		{
			std::cout << todd << std::endl;
			std::cout << *f1 << std::endl;
			todd.signForm(*f1);
			std::cout << *f1 << std::endl;
			todd.executeForm(*f1);
			std::cout << *f1 << std::endl;
			todd.executeForm(*f1);
			std::cout << *f1 << std::endl;
			todd.executeForm(*f1);
			std::cout << *f1 << std::endl;
			delete f1;
		}
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
		delete f1;
    }

    std::cout << std::endl << "Should sign but not execute" << std::endl;
    try
    {
        Bureaucrat todd(25, "Todd");
		f1 = someRandomIntern.makeForm("presidential request", "Zaphod Beeblebrox");
		if (f1 != NULL)
		{
			std::cout << todd << std::endl;
			std::cout << *f1 << std::endl;
			todd.signForm(*f1);
			std::cout << *f1 << std::endl;
			todd.executeForm(*f1);
			std::cout << *f1 << std::endl;
			delete f1;
		}
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
		delete f1;
    }
    std::cout << std::endl << "Should sign and execute" << std::endl;
    try
    {
        Bureaucrat todd(2, "Todd");
		f1 = someRandomIntern.makeForm("presidential request", "Zaphod Beeblebrox");
		if (f1 != NULL)
		{
			std::cout << todd << std::endl;
			std::cout << *f1 << std::endl;
			todd.signForm(*f1);
			std::cout << *f1 << std::endl;
			todd.executeForm(*f1);
			std::cout << *f1 << std::endl;
			todd.executeForm(*f1);
			std::cout << *f1 << std::endl;
			todd.executeForm(*f1);
			std::cout << *f1 << std::endl;
			delete f1;
		}
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
		delete f1;
    }

    std::cout << std::endl << "Should be null" << std::endl;
	f1 = someRandomIntern.makeForm("pwett request", "Zaphod Beeblebrox");
	if (f1 != NULL)
	{
		std::cout << "Is not null" << std::endl;
		delete f1;
	}
	else
		std::cout << "Is null" << std::endl;
	return 0;
}