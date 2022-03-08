#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap(std::string name):_name(name), _energy_points(10), _hit_points(10), _attack_damages(0)
{
	std::cout << "CT: New instance of " << *this << std::endl;
}
ClapTrap::ClapTrap():_name(""), _energy_points(10), _hit_points(10), _attack_damages(0)
{
	std::cout << "CT: New standard instance of " << *this << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap & src ) :_name(src._name), _energy_points(src._energy_points), _hit_points(src._hit_points), _attack_damages(src._attack_damages)
{
	std::cout << "CT: New instance from source of " << *this << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap()
{
	std::cout << "CT: ClapTrap is being destroyed "<< this->_name<< std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap &				ClapTrap::operator=( ClapTrap const & rhs )
{
	std::cout << "CT: ClapTrap is being assigned from other with " << rhs << std::endl;

	if ( this != &rhs )
	{
		this->_name = rhs._name;
		this->_attack_damages = rhs._attack_damages;
		this->_energy_points = rhs._energy_points;
		this->_hit_points = rhs._hit_points;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ClapTrap const & i )
{
	o << "CT: ClapTrap:" << i.getName() << ":" << i.getEnergyPoints()<<":" << i.getHitPoints() << ":" << i.getAttackDamages();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

bool ClapTrap::_doAction()
{
	if(this->_energy_points <= 0)
	{
		std::cout << "CT: ClapTrap " << this->_name <<" is out of energy points and can't perform any action" <<std::endl;
		return false;
	}
	if(this->_hit_points <= 0)
	{
		std::cout << "CT: ClapTrap " << this->_name <<" is out of hit points and can't perform any action" <<std::endl;
		return false;
	}
	this->_energy_points--;
	return true;
}

void ClapTrap::attack(const std::string& target)
{
	if(!this->_doAction())
		return;
	std::cout << "CT: ClapTrap " << this->_name <<" attacks " << target <<", causing " << this->_attack_damages <<" points of damage!" <<std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->_hit_points -= amount;
	std::cout << "CT: ClapTrap " << this->_name <<" is taking " << amount << " points of damages!" <<std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(!this->_doAction())
		return;
	this->_hit_points += amount;
	std::cout << "CT: ClapTrap " << this->_name <<" is being repaired with " << amount << " energie points" <<std::endl;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string ClapTrap::getName() const
{
	return this->_name;
}

int ClapTrap::getHitPoints() const
{
	return this->_hit_points;
}

int ClapTrap::getEnergyPoints() const
{
	return this->_energy_points;
}

unsigned int ClapTrap::getAttackDamages() const
{
	return this->_attack_damages;
}

/* ************************************************************************** */