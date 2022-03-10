#include "WrongCat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongCat::WrongCat(): WrongAnimal("WrongCat")
{
	std::cout << "New standard instance of " << *this << std::endl;
}

WrongCat::WrongCat( const WrongCat & src ) : WrongAnimal(src.getType())
{
	std::cout << "New instance from source of " << *this << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongCat::~WrongCat()
{
	std::cout << "WrongCat is being destroyed "<< this->_type<< std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongCat &				WrongCat::operator=( WrongCat const & rhs )
{
	std::cout << "WrongCat is being assigned from other with " << rhs << std::endl;

	if ( this != &rhs )
	{
		this->_type = rhs._type;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, WrongCat const & i )
{
	o << "WrongCat:" << i.getType() ;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void WrongCat::makeSound() const
{
	std::cout << "Wrong miaou !" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */