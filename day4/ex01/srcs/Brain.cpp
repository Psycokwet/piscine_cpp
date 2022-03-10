#include "Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain(): _index_idea(0)
{
	std::cout << "New standard instance of " << *this << std::endl;
}

Brain::Brain( const Brain & src ): _index_idea(src._index_idea)
{
	for (int i = 0; i < src._index_idea ; i++)
		this->_ideas[i] = src._ideas[i];
	std::cout << "New instance from source of " << *this << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain()
{
	std::cout << "Brain is being destroyed " << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain &				Brain::operator=( Brain const & rhs )
{
	std::cout << "Brain is being assigned from other with " << rhs << std::endl;

	if ( this != &rhs )
	{
		for (int i = 0; i < rhs._index_idea ; i++)
			this->_ideas[i] = rhs._ideas[i];
		this->_index_idea = rhs._index_idea;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Brain const & i )
{
	o << "BrainAdress:" << &i << std::endl;
	o << "Brain:" << std::endl;
	i.printIdeas(o);
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Brain::printIdeas(std::ostream & o) const
{
	for (int i = 0; i < this->_index_idea ; i++)
		o << i << ":" << this->_ideas[i] << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void Brain::addIdea(std::string idea)
{
	if(_index_idea < Brain::_ideas_capacity)
		this->_ideas[this->_index_idea++] = idea;
}

/* ************************************************************************** */