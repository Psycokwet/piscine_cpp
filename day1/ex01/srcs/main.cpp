#include "Zombie.hpp"

Zombie* zombieHorde(int n, std::string name);

int		main()
{
	int size_horde = 10;
	int i = 0;
	Zombie *horde = zombieHorde(size_horde, "Todd");
	while (i < size_horde)
	{
		horde[i].announce();
		i++;
	}
	delete [] horde;
	return 0;
}
