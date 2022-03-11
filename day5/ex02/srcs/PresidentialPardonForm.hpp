#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <fstream>
# include <string>
# include "AForm.hpp"


class PresidentialPardonForm : virtual public AForm
{

	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm( PresidentialPardonForm const & src );
		virtual ~PresidentialPardonForm();

		PresidentialPardonForm &		operator=( PresidentialPardonForm const & rhs );
		std::string getTarget() const;
		virtual void execute(Bureaucrat const & executor) const;
	private:
		static const int _SIGN_TRESHOLD = 25;
		static const int _EXE_TRESHOLD = 5;
        std::string _target;

		PresidentialPardonForm();

};

std::ostream &			operator<<( std::ostream & o, PresidentialPardonForm const & i );

#endif /* ************************************************************ PRESIDENTIALPARDONFORM_HPP */