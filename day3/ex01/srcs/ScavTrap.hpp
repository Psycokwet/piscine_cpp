#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{

	public:

		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap( ScavTrap const & src );
		virtual ~ScavTrap();

		ScavTrap &		operator=( ScavTrap const & rhs );
		void guardGate();
		void attack(const std::string& target);
	private:

};

std::ostream &			operator<<( std::ostream & o, ScavTrap const & i );

#endif /* ******************************************************** SCAVTRAP_H */