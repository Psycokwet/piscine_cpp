#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <string>
# include "Fixed.hpp"


class Point
{

	public:
		Point();
		Point(const float x, const float y);

		Point( Point const & src );
		~Point();
		Fixed const getX() const;
		Fixed const getY() const;

		Point &		operator=( Point const & rhs );

	private:
		Fixed const x;
		Fixed const y;
};

std::ostream &			operator<<( std::ostream & o, Point const & i );
bool bsp( Point const a, Point const b, Point const c, Point const point);
#endif /* *********************************************************** POINT_H */
