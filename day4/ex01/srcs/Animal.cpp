#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal(): _type("Animal")
{
	std::cout << "New standard instance of " << *this << std::endl;
}

Animal::Animal(std::string type): _type(type)
{
	std::cout << "New standard instance of (heritage) " << *this << std::endl;
}

Animal::Animal( const Animal & src ) : _type(src.getType())
{
	std::cout << "New instance from source of " << *this << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal()
{
	std::cout << "Animal is being destroyed "<< this->_type<< std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal &				Animal::operator=( Animal const & rhs )
{
	std::cout << "Animal is being assigned from other with " << rhs << std::endl;

	if ( this != &rhs )
	{
		this->_type = rhs._type;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Animal const & i )
{
	o << "Animal:" << i.getType() ;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Animal::makeSound() const
{
	std::cout << "Weirds animals noises" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Animal::getType() const
{
	return this->_type;
}


/* ************************************************************************** */