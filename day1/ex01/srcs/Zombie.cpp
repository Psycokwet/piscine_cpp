#include "Zombie.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Zombie::Zombie()
{
	std::cout << "New zombie unamed "<< std::endl;
}

Zombie::Zombie( const Zombie & src )
{
	(void)src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Zombie::~Zombie()
{
	std::cout << this->_name << " with id " << this->_id << ": has been destructed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Zombie &				Zombie::operator=( Zombie const & rhs )
{
	(void)rhs;
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Zombie const & i )
{
	(void)o;
	(void)i;
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


void Zombie::announce( void )
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void	Zombie::setName(std::string name)
{
	this->_name = name;
}
void	Zombie::setId(int id)
{
	this->_id = id;
}


/* ************************************************************************** */
