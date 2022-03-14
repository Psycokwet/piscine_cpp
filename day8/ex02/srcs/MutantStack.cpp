#include "MutantStack.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

MutantStack::MutantStack(int grade, std::string name): _name(name), _grade(LOWEST_GRADE)
{
	if(grade < MutantStack::HIGHEST_GRADE)
		throw MutantStack::GradeTooHighException();
	if(grade > MutantStack::LOWEST_GRADE)
		throw MutantStack::GradeTooLowException();
	this->_grade = grade;
}

MutantStack::MutantStack(): _name(""), _grade(LOWEST_GRADE)
{
}

MutantStack::MutantStack( const MutantStack & src ): _name(src._name), _grade(src._grade)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

MutantStack::~MutantStack()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

MutantStack &				MutantStack::operator=( MutantStack const & rhs )
{
	if ( this != &rhs )
	{
		this->_grade = rhs._grade;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, MutantStack const & i )
{
	o << "MutantStack:" << i.getName() << " with grade: " << i.getGrade();
    return (o);
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/
std::string MutantStack::getName() const
{
	return this->_name;
}
int MutantStack::getGrade() const
{
	return this->_grade;
}
void MutantStack::incGrade(){
	if(this->_grade > MutantStack::HIGHEST_GRADE)
		this->_grade--;
	else throw MutantStack::GradeTooHighException();
}

void MutantStack::decGrade(){
	if(this->_grade < MutantStack::LOWEST_GRADE)
		this->_grade++;
	else throw MutantStack::GradeTooLowException();
}

/* ************************************************************************** */