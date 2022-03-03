#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{

	public:

		Zombie( Zombie const & src );
		Zombie();
		~Zombie();

		Zombie &		operator=( Zombie const & rhs );
		void announce( void );
		void	setName(std::string name);
		void	setId(int id);

	private:
		std::string _name;
		int _id;
};

std::ostream &			operator<<( std::ostream & o, Zombie const & i );

#endif /* ********************************************************** ZOMBIE_H */
