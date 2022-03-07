#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{

	public:
//constr/destr

		Fixed();
		Fixed( const int value );
		Fixed( const float value );
		Fixed( Fixed const & src );
		~Fixed();

//meths
		int getRawBits(void) const;
		void setRawBits( int const raw );

		float toFloat( void ) const;
		int toInt( void ) const;

//static meths
		static Fixed & min(Fixed &a, Fixed &b);
		static Fixed const & min(Fixed const &a, Fixed const &b);
		static Fixed & max(Fixed &a, Fixed &b);
		static Fixed const & max(Fixed const &a, Fixed const &b);

//surcharge
		Fixed &		operator=( Fixed const & rhs );

		bool operator>(Fixed const &other) const;
		bool operator<(Fixed const &other) const;
		bool operator>=(Fixed const &other) const;
		bool operator<=(Fixed const &other) const;
		bool operator==(Fixed const &other) const;
		bool operator!=(Fixed const &other) const;

		Fixed operator+(Fixed const &other);
		Fixed operator-(Fixed const &other);
		Fixed operator*(Fixed const &other);
		Fixed operator/(Fixed const &other);

		Fixed operator++(int);//post increment
		Fixed operator++();//pre increment
		Fixed operator--(int);//post decrement
		Fixed operator--();//pre decrement

	private:
		int value;
		static const int bits = 8;

};

std::ostream &			operator<<( std::ostream & o, Fixed const & i );

#endif /* *********************************************************** FIXED_H */
