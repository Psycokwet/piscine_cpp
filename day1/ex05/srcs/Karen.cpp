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
	std::cout << DEBUG << std::endl;
}

void Karen::info(void)
{
	std::cout << INFO << std::endl;
}

void Karen::warning(void)
{
	std::cout << WARNING << std::endl;
}

void Karen::error(void)
{
	std::cout << ERROR << std::endl;
}

void Karen::complain(std::string level)
{
	void (Karen::* methPTR [])() = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};
	std::string array[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for(int i = 0; i < 4; i++)
		if(level == array[i])
			(this->*methPTR[i])();
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
