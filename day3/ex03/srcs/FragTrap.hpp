#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{

	public:

		FragTrap();
		FragTrap(std::string name);
		FragTrap( FragTrap const & src );
		virtual ~FragTrap();

		FragTrap &		operator=( FragTrap const & rhs );
		void highFivesGuys(void);
		void attack(const std::string& target);
	private:

};

std::ostream &			operator<<( std::ostream & o, FragTrap const & i );

#endif /* ******************************************************** SCAVTRAP_H */