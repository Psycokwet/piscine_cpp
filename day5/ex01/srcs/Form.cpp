#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form(int required_grade_sign, int required_grade_exe, std::string name): _name(name), _is_signed(false), _required_grade_sign(required_grade_sign), _required_grade_exe(required_grade_exe)
{
	testGrade(required_grade_sign);
	testGrade(required_grade_exe);
}

Form::Form(): _name(""), _is_signed(false), _required_grade_sign(Bureaucrat::LOWEST_GRADE), _required_grade_exe(Bureaucrat::LOWEST_GRADE)
{
}

Form::Form( const Form & src ): _name(src._name), _is_signed(false), _required_grade_sign(src._required_grade_sign), _required_grade_exe(src._required_grade_exe)
{
}




/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
{
	if ( this != &rhs )
	{
		this->_is_signed = rhs._is_signed;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	o << "Form:" << i.getName() << " is signed :" << i.isSigned() << " grade exe :" << i.getGradeExe() << " grade sign :" << i.getGradeSign();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Form::beSigned(Bureaucrat &b)
{
	int grade = b.getGrade();
	if(this->isSigned())
		return;
	if(grade <= this->_required_grade_sign)
		this->_is_signed = true;
	else
		throw Form::GradeTooLowException();
}

void Form::testGrade(int grade)
{
	if(grade < Bureaucrat::HIGHEST_GRADE)
		throw Form::GradeTooHighException();
	if(grade > Bureaucrat::LOWEST_GRADE)
		throw Form::GradeTooLowException();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Form::getName() const
{
	return this->_name;
}
bool Form::isSigned() const
{
	return this->_is_signed;
}

int Form::getGradeExe(void) const
{
    return (this->_required_grade_exe);
}

int Form::getGradeSign(void) const
{
    return (this->_required_grade_sign);
}

/* ************************************************************************** */