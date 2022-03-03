#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{

	public:

		Zombie(std::string name);
		Zombie( Zombie const & src );
		~Zombie();

		Zombie &		operator=( Zombie const & rhs );
		void announce( void );

	private:
		std::string _name;
};

std::ostream &			operator<<( std::ostream & o, Zombie const & i );

#endif /* ********************************************************** ZOMBIE_H */
