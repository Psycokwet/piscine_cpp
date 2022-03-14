#ifndef AWESOME_HPP
# define AWESOME_HPP

# include <iostream>
# include <string>

class Awesome
{

	public:

		Awesome(void):_n(0) {}
		Awesome(int n):_n(n) {}

		Awesome &		operator=( Awesome const & a ){_n = a._n; return *this;}
		bool			operator==( Awesome const & rhs ){return this->_n == rhs._n;}
		bool			operator!=( Awesome const & rhs ){return this->_n != rhs._n;}
		bool			operator>=( Awesome const & rhs ){return this->_n >= rhs._n;}
		bool			operator<=( Awesome const & rhs ){return this->_n <= rhs._n;}
		bool			operator>( Awesome const & rhs ){return this->_n > rhs._n;}
		bool			operator<( Awesome const & rhs ){return this->_n < rhs._n;}
		int get_n() const {return _n;}
	private:
	int _n;
};

std::ostream &			operator<<( std::ostream & o, Awesome const & a ){ o<< a.get_n(); return o;}

#endif /* ********************************************************* AWESOME_H */