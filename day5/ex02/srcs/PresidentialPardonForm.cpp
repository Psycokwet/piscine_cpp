#include "PresidentialPardonForm.hpp"

#define FORM_NAME "PresidentialPardonForm"
/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm() : AForm(_SIGN_TRESHOLD, _EXE_TRESHOLD, FORM_NAME), _target("")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm(_SIGN_TRESHOLD, _EXE_TRESHOLD, FORM_NAME), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src ): AForm(_SIGN_TRESHOLD, _EXE_TRESHOLD, FORM_NAME), _target(src._target)
{
}




/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm &				PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_target = rhs._target;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, PresidentialPardonForm const & i )
{
	o << "PresidentialPardonForm:" << i.getName() << " is signed :" << i.isSigned() << " grade exe :" << i.getGradeExe() << " grade sign :" << i.getGradeSign() << " target :" << i.getTarget() ;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    this->canFormBeExecuted(executor);
	std::cout << this->_target + " have been pardonned by " + executor.getName() << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string PresidentialPardonForm::getTarget() const
{
	return this->_target;
}

/* ************************************************************************** */