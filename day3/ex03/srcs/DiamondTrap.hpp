#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include <string>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : virtual public FragTrap, virtual public ScavTrap {int _energy_points, void attack(const std::string&);};
{

	public:

		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap( DiamondTrap const & src );
		virtual ~DiamondTrap();

		DiamondTrap &		operator=( DiamondTrap const & rhs );
		void whoAmI();
	private:
		std::string _name;
};

std::ostream &			operator<<( std::ostream & o, DiamondTrap const & i );

#endif /* ******************************************************** SCAVTRAP_H */