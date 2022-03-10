#include "WrongAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongAnimal::WrongAnimal(): _type("WrongAnimal")
{
	std::cout << "New standard instance of " << *this << std::endl;
}

WrongAnimal::WrongAnimal(std::string type): _type(type)
{
	std::cout << "New standard instance of (heritage) " << *this << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal & src ) : _type(src.getType())
{
	std::cout << "New instance from source of " << *this << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal is being destroyed "<< this->_type<< std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongAnimal &				WrongAnimal::operator=( WrongAnimal const & rhs )
{
	std::cout << "WrongAnimal is being assigned from other with " << rhs << std::endl;

	if ( this != &rhs )
	{
		this->_type = rhs._type;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, WrongAnimal const & i )
{
	o << "WrongAnimal:" << i.getType() ;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void WrongAnimal::makeSound() const
{
	std::cout << "Weirds wrong animals noises" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string WrongAnimal::getType() const
{
	return this->_type;
}


/* ************************************************************************** */