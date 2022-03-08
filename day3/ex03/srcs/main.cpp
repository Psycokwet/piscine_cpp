#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main( void )
{
	ClapTrap todd("Todd");
	ClapTrap dirk("Dirk Gently");
	ClapTrap pwet = dirk;
	pwet = dirk;
	std::cout << std::endl;
	ScavTrap link("Link");
	std::cout <<link<< std::endl;
	FragTrap zelda("Zelda");
	std::cout <<zelda<< std::endl;
	DiamondTrap hilda("Hilda");
	std::cout <<hilda<< std::endl;

	todd.attack(dirk.getName());
	dirk.takeDamage(todd.getAttackDamages());
	link.guardGate();
	link.attack(dirk.getName());
	dirk.takeDamage(link.getAttackDamages());
	zelda.highFivesGuys();
	
	hilda.highFivesGuys();
	hilda.attack(zelda.getName());
	std::cout << dirk << std::endl;
	std::cout << todd << std::endl;
	return 0;
}