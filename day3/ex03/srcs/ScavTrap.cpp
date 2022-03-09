#include "ScavTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap() : ClapTrap("")
{
	this->_energy_points = 50;
	this->_hit_points = 100;
	this->_attack_damages = 20;
	std::cout << "ST: New instance of " << *this << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_energy_points = 50;
	this->_hit_points = 100;
	this->_attack_damages = 20;
	std::cout << "ST: New instance of " <<name<<":"<< *this << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap & src ) : ClapTrap(src.getName())
{
	this->_energy_points = 50;
	this->_hit_points = 100;
	this->_attack_damages = 20;
	std::cout << "ST: New instance from source of " << *this << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap()
{
	std::cout << "ST: ScavTrap is being destroyed "<< this->getName()<< std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScavTrap &				ScavTrap::operator=( ScavTrap const & rhs )
{
	std::cout << "ST: ScavTrap is being assigned from other with " << rhs << std::endl;

	if ( this != &rhs )
	{
		(ClapTrap)(*this) = (ClapTrap)(rhs);
		this->_energy_points = rhs.getEnergyPoints();
		this->_hit_points = rhs.getHitPoints();
		this->_attack_damages = rhs.getAttackDamages();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ScavTrap const & i )
{	
	o << "ST: ScavTrap:" << (ClapTrap)i;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void ScavTrap::guardGate()
{
	std::cout << "ST: Entering gate keeper mode for " << *this << std::endl;
}


void ScavTrap::attack(const std::string& target)
{
	if(!this->_doAction())
		return;
	std::cout << "ST: ScavTrap " << this->_name <<" attacks " << target <<", causing " << this->_attack_damages <<" points of damage!" <<std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
