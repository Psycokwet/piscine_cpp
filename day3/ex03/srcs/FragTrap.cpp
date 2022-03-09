#include "FragTrap.hpp"

/*
** ------------------------------- CONFTRUCTOR --------------------------------
*/

FragTrap::FragTrap() : ClapTrap("")
{
	this->_energy_points = 100;
	this->_hit_points = 100;
	this->_attack_damages = 30;
	std::cout << "FT: New instance of " << *this << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_energy_points = 100;
	this->_hit_points = 100;
	this->_attack_damages = 30;
	std::cout << "FT: New instance of " <<name<<":"<< *this << std::endl;
}

FragTrap::FragTrap( const FragTrap & src ) : ClapTrap(src.getName())
{
	this->_energy_points = 100;
	this->_hit_points = 100;
	this->_attack_damages = 30;
	std::cout << "FT: New instance from source of " << *this << std::endl;
}


/*
** -------------------------------- DEFTRUCTOR --------------------------------
*/

FragTrap::~FragTrap()
{
	std::cout << "FT: FragTrap is being destroyed "<< this->getName()<< std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

FragTrap &				FragTrap::operator=( FragTrap const & rhs )
{
	std::cout << "FT: FragTrap is being assigned from other with " << rhs << std::endl;

	if ( this != &rhs )
	{
		(ClapTrap)(*this) = (ClapTrap)(rhs);
		this->_energy_points = rhs.getEnergyPoints();
		this->_hit_points = rhs.getHitPoints();
		this->_attack_damages = rhs.getAttackDamages();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, FragTrap const & i )
{	
	o << "FT: FragTrap:" << (ClapTrap)i;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void FragTrap::highFivesGuys()
{
	std::cout << "FT: Please, do a high five " << *this << std::endl;
}


void FragTrap::attack(const std::string& target)
{
	if(!this->_doAction())
		return;
	std::cout << "FT: FragTrap " << this->_name <<" attacks " << target <<", causing " << this->_attack_damages <<" points of damage!" <<std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
