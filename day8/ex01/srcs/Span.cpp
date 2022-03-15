#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span(unsigned int N) : _N(N)
{
	
}

Span::Span( const Span & src ) : _N(src._N)
{

}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &				Span::operator=( Span const & rhs )
{
	if ( this != &rhs )
	{
		this->_N = rhs._N;
		this->_content = rhs._content;
	}
	return *this;
}

void Span::print(std::ostream & o) const
{
    o << "l = { ";
	std::vector<int>::const_iterator it;
	for (it = this->_content.begin(); it != this->_content.end(); ++it){
		o << "\t" << *it << std::endl;
	}
    o << "}; _N=" << this->_N << std::endl;
}

std::ostream &			operator<<( std::ostream & o, Span const & i )
{
	i.print(o);
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


void Span::addNumber(int value)
{
	if(this->_content.size() >= this->_N)
		throw TooMuchValuesException();
	this->_content.push_back(value);
}

void	Span::addRange( std::vector<int>::iterator begin,
		std::vector<int>::iterator end)
{
	if(end - begin >= this->_N)
		throw TooMuchValuesException();
	copy(begin, end, std::back_inserter(this->_content));
}

int Span::shortestSpan()
{
	if(this->_content.size() <= 1)
		throw NotEnoughValuesException();
	
	std::sort(this->_content.begin(), this->_content.end());

	std::vector<int>::iterator begin = this->_content.begin();
	std::vector<int>::iterator end = this->_content.end();
	int result = *(begin + 1) - *(begin);
	if(this->_content.size() == 1)
		return result;
	std::vector<int>::iterator it;
	for (it = begin; it != (end - 1); ++it){
		int tmp = *(it + 1) - *(it);
		if(tmp < result)
			result = tmp;
		if(result == 1)
			return result;
	}
	return result;
}

int Span::longestSpan()
{
	if(this->_content.size() <= 1)
		throw NotEnoughValuesException();
	std::sort(this->_content.begin(), this->_content.end());

	std::vector<int>::iterator begin = this->_content.begin();
	std::vector<int>::iterator end = this->_content.end();
	
	return *(end - 1) - *begin;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
