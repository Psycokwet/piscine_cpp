#include <iostream>
#include <string>
# include <ctime>
# include <cstdlib>
# include <exception>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	int index = (std::rand() % 3);
	switch (index)
	{
	case 0:
		std::cout << "New A" << std::endl;
		return new A();
	case 1:
		std::cout << "New B" << std::endl;
		return new B();
	default:
		std::cout << "New C" << std::endl;
		return new C();	
	}
}
void identify(Base* p)
{
	std::string type;
	if (dynamic_cast<A*>(p))
		type = "A";
	else if (dynamic_cast<B*>(p))
		type = "B";
	else if (dynamic_cast<C*>(p))
		type = "C";
	std::cout << "Type *" + type << std::endl;
}
void identify(Base& p)
{
	std::string type;
	try
	{
		dynamic_cast<A&>(p);
		type = "A";
	}
	catch(std::exception exp) {
	}

	try
	{
		dynamic_cast<B&>(p);
		type = "B";
	}
	catch(std::exception exp) {
	}

	try
	{
		dynamic_cast<C&>(p);
		type = "C";
	}
	catch(std::exception exp) {
	}
	std::cout << "Type &" + type << std::endl;
}

int main()
{
	std::srand(std::time(0)); // use current time as seed for random generator
	Base* unknown = generate();
	(void)unknown;
	identify(unknown);
	identify(*unknown);
	return 0;
}