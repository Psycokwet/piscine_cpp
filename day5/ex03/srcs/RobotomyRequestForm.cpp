#include "RobotomyRequestForm.hpp"

#define FORM_NAME "RobotomyRequestForm"
/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm() : AForm(_SIGN_TRESHOLD, _EXE_TRESHOLD, FORM_NAME), _target("")
{
	std::srand(std::time(0)); // use current time as seed for random generator
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm(_SIGN_TRESHOLD, _EXE_TRESHOLD, FORM_NAME), _target(target)
{
	std::srand(std::time(0)); // use current time as seed for random generator
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ): AForm(_SIGN_TRESHOLD, _EXE_TRESHOLD, FORM_NAME), _target(src._target)
{
	std::srand(std::time(0)); // use current time as seed for random generator
}




/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_target = rhs._target;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i )
{
	o << "RobotomyRequestForm:" << i.getName() << " is signed :" << i.isSigned() << " grade exe :" << i.getGradeExe() << " grade sign :" << i.getGradeSign() << " target :" << i.getTarget() ;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    this->canFormBeExecuted(executor);
	std::cout << "Bzzzzt zzzzzzt ! Bzzt !" << std::endl;
	if ((std::rand() % 2) == true)
    	std::cout << this->_target + " have been robotomised" << std::endl;
	else
    	std::cout << this->_target + " have not been robotomised because of technical difficulties" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

/* ************************************************************************** */