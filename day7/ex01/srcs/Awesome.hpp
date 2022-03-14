#ifndef AWESOME_HPP
# define AWESOME_HPP

# include <iostream>
# include <string>

class Awesome
{

	public:

		Awesome(void):_n(42) {}
		int get() const {return _n;}
	private:
		int _n;
};

std::ostream &			operator<<( std::ostream & o, Awesome const & a ){ o<< a.get(); return o;}


#endif /* ********************************************************* AWESOME_H */