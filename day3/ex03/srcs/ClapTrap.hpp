#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap( ClapTrap const & src );
		virtual ~ClapTrap();

		ClapTrap &		operator=( ClapTrap const & rhs );
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		std::string getName() const;
		unsigned int getAttackDamages() const;
		int getHitPoints() const;
		int getEnergyPoints() const;
	protected:
		bool _doAction();
		std::string _name;
		int _energy_points;
		int	_hit_points;//pdv
		unsigned int _attack_damages;

};

std::ostream &			operator<<( std::ostream & o, ClapTrap const & i );

#endif /* ******************************************************** CLAPTRAP_H */