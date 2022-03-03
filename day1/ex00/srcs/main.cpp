#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int		main()
{
	Zombie *z = newZombie("Todd");
	z->announce();
	randomChump("Dirk Gently");
	delete z;
	return 0;
}
