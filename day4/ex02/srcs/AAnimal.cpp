#include "AAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AAnimal::AAnimal(): _type("AAnimal")
{
	std::cout << "New standard instance of " << *this << std::endl;
}

AAnimal::AAnimal(std::string type): _type(type)
{
	std::cout << "New standard instance of (heritage) " << *this << std::endl;
}

AAnimal::AAnimal( const AAnimal & src ) : _type(src.getType())
{
	std::cout << "New instance from source of " << *this << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AAnimal::~AAnimal()
{
	std::cout << "AAnimal is being destroyed "<< this->_type<< std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AAnimal &				AAnimal::operator=( AAnimal const & rhs )
{
	std::cout << "AAnimal is being assigned from other with " << rhs << std::endl;

	if ( this != &rhs )
	{
		this->_type = rhs._type;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AAnimal const & i )
{
	o << "AAnimal:" << i.getType() ;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void AAnimal::makeSound() const
{
	std::cout << "Weirds animals noises" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string AAnimal::getType() const
{
	return this->_type;
}


/* ************************************************************************** */