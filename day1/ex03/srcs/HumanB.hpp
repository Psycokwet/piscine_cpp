#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB
{

	public:

		HumanB(std::string name);
		HumanB( HumanB const & src );
		~HumanB();

		HumanB &		operator=( HumanB const & rhs );
		void attack() const;
		Weapon *getWeapon(void) const;
		void	setWeapon(Weapon &weapon);

	private:
		Weapon *_weapon;
		std::string _name;

};

std::ostream &			operator<<( std::ostream & o, HumanB const & i );

#endif /* ********************************************************** HUMANB_H */
