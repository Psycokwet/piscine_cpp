#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog(): AAnimal("Dog"), _brain(new Brain())
{
	std::cout << "New standard instance of " << *this << std::endl;
}

Dog::Dog( const Dog & src ) : AAnimal(src.getType()), _brain(new Brain(*(src._brain)))
{
	std::cout << "New instance from source of " << *this << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog is being destroyed "<< this->_type<< std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &				Dog::operator=( Dog const & rhs )
{
	std::cout << "Dog is being assigned from other with " << rhs << std::endl;

	if ( this != &rhs )
	{
		this->_brain = rhs._brain;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Dog const & i )
{
	o << "Dog:" << i.getType() << *(i.getBrain());
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Dog::makeSound() const
{
	std::cout << "Miaou !" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
Brain *Dog::getBrain() const
{
	return this->_brain;
}


/* ************************************************************************** */