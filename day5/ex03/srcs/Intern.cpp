#include "Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
}

Intern::Intern( const Intern & src )
{
	(void)src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &				Intern::operator=( Intern const & rhs )
{
	(void)rhs;
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Intern const & i )
{
	(void)o;
	(void)i;
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

// typedef AForm* (Intern:: *pf)(std::string const &) const;

AForm *Intern::newFormShruberry(const std::string & target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::newFormRobotomy(const std::string & target) const
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::newFormPresidential(const std::string & target) const
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(const std::string & formName, const std::string & target) const
{
	AForm* (Intern:: *buildsMethods[])(std::string const &) const = {&Intern::newFormRobotomy, &Intern::newFormPresidential, &Intern::newFormShruberry};
	std::string requetsIds[] = {"robotomy request", "presidential request", "shruberry request"};
	
	for(int i = 0; i < 3; i++)
	{
		if(requetsIds[i] == formName)
			return((this->*buildsMethods[i])(target));
	}
	std::cout << "The form " + formName + " does not exist in database." << std::endl;
	return(NULL);
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */