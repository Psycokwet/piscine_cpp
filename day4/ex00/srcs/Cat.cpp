#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat(): Animal("Cat")
{
	std::cout << "New standard instance of " << *this << std::endl;
}

Cat::Cat( const Cat & src ) : Animal(src.getType())
{
	std::cout << "New instance from source of " << *this << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	std::cout << "Cat is being destroyed "<< this->_type<< std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &				Cat::operator=( Cat const & rhs )
{
	std::cout << "Cat is being assigned from other with " << rhs << std::endl;

	if ( this != &rhs )
	{
		this->_type = rhs._type;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Cat const & i )
{
	o << "Cat:" << i.getType() ;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Cat::makeSound() const
{
	std::cout << "Miaou !" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */