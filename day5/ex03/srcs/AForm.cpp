#include "AForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AForm::AForm(int required_grade_sign, int required_grade_exe, std::string name): _name(name), _is_signed(false), _required_grade_sign(required_grade_sign), _required_grade_exe(required_grade_exe)
{
	testGrade(required_grade_sign);
	testGrade(required_grade_exe);
}

AForm::AForm(): _name(""), _is_signed(false), _required_grade_sign(Bureaucrat::LOWEST_GRADE), _required_grade_exe(Bureaucrat::LOWEST_GRADE)
{
}

AForm::AForm( const AForm & src ): _name(src._name), _is_signed(false), _required_grade_sign(src._required_grade_sign), _required_grade_exe(src._required_grade_exe)
{
}




/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AForm &				AForm::operator=( AForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_is_signed = rhs._is_signed;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AForm const & i )
{
	o << "AForm:" << i.getName() << " is signed :" << i.isSigned() << " grade exe :" << i.getGradeExe() << " grade sign :" << i.getGradeSign();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void AForm::beSigned(Bureaucrat &b)
{
	int grade = b.getGrade();
	if(this->isSigned())
		return;
	if(grade <= this->_required_grade_sign)
		this->_is_signed = true;
	else
		throw AForm::GradeTooLowException();
}

void AForm::testGrade(int grade)
{
	if(grade < Bureaucrat::HIGHEST_GRADE)
		throw AForm::GradeTooHighException();
	if(grade > Bureaucrat::LOWEST_GRADE)
		throw AForm::GradeTooLowException();
}

void AForm::canFormBeExecuted(Bureaucrat const & executor) const
{
	int grade = executor.getGrade();
	if(!this->isSigned())
		throw AForm::FormNotSignedYetException();
	if(grade > this->_required_grade_exe)
		throw AForm::GradeTooLowException();
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string AForm::getName() const
{
	return this->_name;
}
bool AForm::isSigned() const
{
	return this->_is_signed;
}

int AForm::getGradeExe(void) const
{
    return (this->_required_grade_exe);
}

int AForm::getGradeSign(void) const
{
    return (this->_required_grade_sign);
}

/* ************************************************************************** */