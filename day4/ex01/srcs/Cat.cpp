#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat(): Animal("Cat"), _brain(new Brain())
{
	std::cout << "New standard instance of " << *this << std::endl;
}

Cat::Cat( const Cat & src ) : Animal(src.getType()), _brain(new Brain(*(src._brain)))
{
	std::cout << "New instance from source of " << *this << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	delete this->_brain;
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
		this->_brain = rhs._brain;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Cat const & i )
{
	o << "Cat:" << i.getType() << *(i.getBrain());
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
Brain *Cat::getBrain() const
{
	return this->_brain;
}


/* ************************************************************************** */