#include "HumanB.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

HumanB::HumanB(std::string name) : _name(name) {}

HumanB::HumanB( const HumanB & src )
{
	(void)src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

HumanB::~HumanB()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

HumanB &				HumanB::operator=( HumanB const & rhs )
{
	(void)rhs;
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, HumanB const & i )
{
	(void)o;
	(void)i;
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


void HumanB::attack() const 
{
	if (this->_weapon == NULL)
		return ;
	std::cout << this->_name <<  " attacks with their " << this->_weapon->getType() << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

/* ************************************************************************** */
