#include "DiamondTrap.hpp"

/*
** ------------------------------- CONDTRUCTOR --------------------------------
*/

DiamondTrap::DiamondTrap() : ClapTrap("")
{
	this->_energy_points = 50;
	this->_hit_points = 100;
	this->_attack_damages = 20;
	std::cout << "DT: New instance of " << *this << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name)
{
	this->_energy_points = 50;
	this->_hit_points = 100;
	this->_attack_damages = 20;
	std::cout << "DT: New instance of " <<name<<":"<< *this << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap & src ) : ClapTrap(src.getName())
{
	this->_energy_points = 50;
	this->_hit_points = 100;
	this->_attack_damages = 20;
	std::cout << "DT: New instance from source of " << *this << std::endl;
}


/*
** -------------------------------- DEDTRUCTOR --------------------------------
*/

DiamondTrap::~DiamondTrap()
{
	std::cout << "DT: DiamondTrap is being destroyed "<< this->getName()<< std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

DiamondTrap &				DiamondTrap::operator=( DiamondTrap const & rhs )
{
	std::cout << "DT: DiamondTrap is being assigned from other with " << rhs << std::endl;

	if ( this != &rhs )
	{
		(ClapTrap)(*this) = (ClapTrap)(rhs);
		this->_energy_points = rhs.getEnergyPoints();
		this->_hit_points = rhs.getHitPoints();
		this->_attack_damages = rhs.getAttackDamages();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, DiamondTrap const & i )
{	
	o << "DT: DiamondTrap:" << (ClapTrap)i;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void DiamondTrap::whoAmI()
{
	std::cout << "DT: I don't know who i am " << *this << std::endl;
}


void DiamondTrap::attack(const std::string& target)
{
	if(!this->_doAction())
		return;
	std::cout << "DT: DiamondTrap " << this->_name <<" attacks " << target <<", causing " << this->_attack_damages <<" points of damage!" <<std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
