#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat(int grade, std::string name): _name(name), _grade(LOWEST_GRADE)
{
	if(grade < Bureaucrat::HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	if(grade > Bureaucrat::LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(): _name(""), _grade(LOWEST_GRADE)
{
}

Bureaucrat::Bureaucrat( const Bureaucrat & src ): _name(src._name), _grade(src._grade)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	if ( this != &rhs )
	{
		this->_grade = rhs._grade;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << "Bureaucrat:" <<i.getName() << " with grade: " << i.getGrade();
    return (o);
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Bureaucrat::signForm(AForm &f)
{
	try
    {
		f.beSigned(*this);
        std::cout << *this << " has signed " << f <<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << *this << " could not sign " << f << " because " << e.what() << std::endl;
    }
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
std::string Bureaucrat::getName() const
{
	return this->_name;
}
int Bureaucrat::getGrade() const
{
	return this->_grade;
}
void Bureaucrat::incGrade(){
	if(this->_grade > Bureaucrat::HIGHEST_GRADE)
		this->_grade--;
	else throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decGrade(){
	if(this->_grade < Bureaucrat::LOWEST_GRADE)
		this->_grade++;
	else throw Bureaucrat::GradeTooLowException();
}

/* ************************************************************************** */