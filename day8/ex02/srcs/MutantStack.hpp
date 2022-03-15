#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>
template<typename T>
class MutantStack: public std::stack<T>
{

public:

	MutantStack<T>() {}
	MutantStack<T>(const MutantStack<T> &src) {*this = src;}
	~MutantStack<T>() {}

	MutantStack<T>	&operator=( const MutantStack<T> &rhs ) {
		(void)rhs;
		return *this;
	}

	typedef typename std::stack<T>::container_type::iterator iterator;
	
	iterator	begin() {return this->c.begin();}
	iterator	end() {return this->c.end();}

private:

};

#endif /* ****************************************************** MUTANTSTACK_HPP */