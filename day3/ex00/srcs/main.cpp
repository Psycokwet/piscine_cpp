#include "ClapTrap.hpp"
#include <iostream>

int main( void )
{
	ClapTrap todd("Todd");
	ClapTrap dirk("Dirk Gently");
	ClapTrap pwet = dirk;
	pwet = dirk;

	todd.attack(dirk.getName());
	dirk.takeDamage(todd.getAttackDamages());
	std::cout << todd << std::endl;
	todd.beRepaired(42);
	std::cout << todd << std::endl;
	std::cout << dirk << std::endl;
	return 0;
}