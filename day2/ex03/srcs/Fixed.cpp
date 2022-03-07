#include "Fixed.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed()
{
	this->value = 0;
}

Fixed::Fixed( const int value )
{
	this->value = value << Fixed::bits;
}

Fixed::Fixed( const float value )
{
	this->value = roundf(value * (1 << Fixed::bits));
}
Fixed::Fixed( const Fixed & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed &				Fixed::operator=( Fixed const & rhs )
{
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
	return value;
}

void Fixed::setRawBits( int const raw )
{
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

bool Fixed::operator>(Fixed const &other) const
{
	return this->value > other.value;
}

bool Fixed::operator<(Fixed const &other) const
{
	return this->value < other.value;
}

bool Fixed::operator>=(Fixed const &other) const
{
	return this->value >= other.value;
}

bool Fixed::operator<=(Fixed const &other) const
{
	return this->value <= other.value;
}

bool Fixed::operator==(Fixed const &other) const
{
	return this->value == other.value;
}

bool Fixed::operator!=(Fixed const &other) const
{
	return this->value != other.value;
}

Fixed Fixed::operator+(Fixed const &other)
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(Fixed const &other)
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(Fixed const &other)
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(Fixed const &other)
{
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed Fixed::operator++(int)
{
	Fixed res = Fixed(*this);
	operator++();
	return res;
}

Fixed  Fixed::operator++()
{
	this->value++;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed res = Fixed(*this);
	operator--();
	return res;
}

Fixed  Fixed::operator--()
{
	this->value--;
	return *this;
}

Fixed & Fixed::min(Fixed &a, Fixed &b)
{
	if(a < b)
		return a;
	return b;
}

Fixed const & Fixed::min(Fixed const &a, Fixed const &b)
{
	if(a < b)
		return a;
	return b;
}

Fixed & Fixed::max(Fixed &a, Fixed &b)
{
	if(a > b)
		return a;
	return b;
}

Fixed const & Fixed::max(Fixed const &a, Fixed const &b)
{
	if(a > b)
		return a;
	return b;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */