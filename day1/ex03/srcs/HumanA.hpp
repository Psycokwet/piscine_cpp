#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanA
{

	public:


		HumanA(std::string name, Weapon &weapon);
		~HumanA();

		HumanA &		operator=( HumanA const & rhs );
		void attack() const;

	private:
		Weapon &_weapon;
		std::string _name;

};

std::ostream &			operator<<( std::ostream & o, HumanA const & i );

#endif /* ********************************************************** HUMANA_H */
