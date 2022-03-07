#include "Point.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Point::Point() : x(Fixed(0)), y(Fixed(0))
{
}
Point::Point(const float x, const float y) : x(Fixed(x)), y(Fixed(y))
{
}

Point::Point( const Point & src ): x(src.x), y(src.y)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Point::~Point()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Point &				Point::operator=( Point const & rhs )
{
	(void)rhs;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Point const & i )
{
	o << "x = " << i.getX() << " y = " << i.getY();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

Fixed const Point::getX() const
{
	return this->x;
}
Fixed const Point::getY() const
{
	return this->y;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
