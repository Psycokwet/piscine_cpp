#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain 
{
	public:
		static const int _ideas_capacity = 100;
		Brain();
		Brain( Brain const & src );
		virtual ~Brain();

		Brain &		operator=( Brain const & rhs );
		void printIdeas(std::ostream & o) const;
		void addIdea(std::string idea);
	private:
		std::string _ideas[Brain::_ideas_capacity];
		int	_index_idea;
};

std::ostream &			operator<<( std::ostream & o, Brain const & i );

#endif /* ******************************************************** BRAIN_HPP */