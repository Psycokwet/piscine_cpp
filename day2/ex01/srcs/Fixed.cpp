#include "Fixed.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed()
{
	this->value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int value )
{
	this->value = value << Fixed::bits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float value )
{
	// this->value = value * (1 << Fixed::bits);
	this->value = roundf(value * (1 << Fixed::bits));
	std::cout << "Float constructor called" << std::endl;
}
Fixed::Fixed( const Fixed & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed &				Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		this->value = rhs.value;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Fixed const & i )
{
	o << i.toFloat();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return value;
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

float Fixed::toFloat( void ) const
{
	return ((float)this->value) / ((float)(1 << Fixed::bits));
}

int Fixed::toInt( void ) const
{
	return this->value >> Fixed::bits;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */