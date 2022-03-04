# include <iostream>
# include <fstream>
# include <string>
# include "Karen.hpp"

int main(int ac, char **av)
{
	if(ac != 2)
	{
		std::cout << "error, incorrect number of args" << std::endl;
		return 0;
	}
	Karen k;
	k.complain(av[1]);
	return 0;
}
