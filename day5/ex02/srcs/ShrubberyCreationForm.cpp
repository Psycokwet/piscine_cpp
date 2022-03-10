#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(137, 145, "ShruberryCreationForm"), _target("")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm(137, 145, "ShruberryCreationForm"), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ): AForm(137, 145, "ShruberryCreationForm"), _target(src._target)
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
    file << "                                  # #### ####\
                                ### \\/#|### |/####\
                               ##\\/#/ \\||/##/_/##/_#\
                             ###  \\/###|/ \\/ # ###\
                           ##_\\_#\\_\\## | #/###_/_####\
                          ## #### # \\ #| /  #### ##/##\
                           __#_--###`  |{,###---###-~\
                                     \\ }{\
                                      }}{\
                                      }}{\
                                 ejm  {{}\
                                , -=-~{ .-^- _\
                                      `}\
                                       {\
"
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