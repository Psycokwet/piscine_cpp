#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{

	public:

		Weapon();
		Weapon(std::string type);
		Weapon( Weapon const & src );
		~Weapon();

		Weapon &		operator=( Weapon const & rhs );
		std::string getType(void) const;
		void setType(std::string type);

	private:
		std::string _type;
};

std::ostream &			operator<<( std::ostream & o, Weapon const & i );

#endif /* ********************************************************** WEAPON_H */
