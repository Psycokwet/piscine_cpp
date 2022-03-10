#include "ShrubberyCreationForm.hpp"

#define FORM_NAME "ShruberryCreationForm"
/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(_SIGN_TRESHOLD, _EXE_TRESHOLD, FORM_NAME), _target("")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm(_SIGN_TRESHOLD, _EXE_TRESHOLD, FORM_NAME), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ): AForm(_SIGN_TRESHOLD, _EXE_TRESHOLD, FORM_NAME), _target(src._target)
{
}




/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_target = rhs._target;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i )
{
	o << "ShrubberyCreationForm:" << i.getName() << " is signed :" << i.isSigned() << " grade exe :" << i.getGradeExe() << " grade sign :" << i.getGradeSign() << " target :" << i.getTarget() ;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    this->canFormBeExecuted(executor);
    std::ofstream file((this->_target + "_shruberry").c_str());
    file << "                                  # #### ####\n";
	file << "                                ### \\/#|### |/####\n";
	file << "                               ##\\/#/ \\||/##/_/##/_#\n";
	file << "                             ###  \\/###|/ \\/ # ###\n";
	file << "                           ##_\\_#\\_\\## | #/###_/_####\n";
	file << "                          ## #### # \\ #| /  #### ##/##\n";
	file << "                           __#_--###`  |{,###---###-~\n";
	file << "                                     \\ }{\n";
	file << "                                      }}{\n";
	file << "                                      }}{\n";
	file << "                                 ejm  {{}\n";
	file << "                                , -=-~{ .-^- _\n";
	file << "                                      `}\n";
	file << "                                       {\n";
    file.close();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}

/* ************************************************************************** */