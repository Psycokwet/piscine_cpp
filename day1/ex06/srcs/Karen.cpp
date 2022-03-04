#include "Karen.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Karen::Karen()
{
}

Karen::Karen( const Karen & src )
{
	(void)src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Karen::~Karen()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Karen &				Karen::operator=( Karen const & rhs )
{
	(void)rhs;
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Karen const & i )
{
	(void)o;
	(void)i;
	//o << "Value = " << i.getValue();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Karen::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl << DEBUG << std::endl;
}

void Karen::info(void)
{
	std::cout << "[ INFO ]" << std::endl << INFO << std::endl;
}

void Karen::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl << WARNING << std::endl;
}

void Karen::error(void)
{
	std::cout << "[ ERROR ]" << std::endl << ERROR << std::endl;
}

void Karen::complain(std::string level)
{
	std::string array[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int ilevel;
	for(ilevel = 0; ilevel < 4; ilevel++)
		if(level == array[ilevel])
			break;
	switch (ilevel)
	{
		case (0):
			this->debug();
		case (1):
			this->info();
		case (2):
			this->warning();
		case (3):
		{
			this->error();
			break;
		}
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
