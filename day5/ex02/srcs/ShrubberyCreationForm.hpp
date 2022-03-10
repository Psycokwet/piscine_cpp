#ifndef SHRUBERRYCREATIONFORM_HPP
# define SHRUBERRYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include <string>
# include "AForm.hpp"


class ShrubberyCreationForm : virtual public AForm
{

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm( ShrubberyCreationForm const & src );
		virtual ~ShrubberyCreationForm();

		ShrubberyCreationForm &		operator=( ShrubberyCreationForm const & rhs );
		std::string getTarget() const;
		virtual void execute(Bureaucrat const & executor) const;
	private:
		static const int _SIGN_TRESHOLD = 137;
		static const int _EXE_TRESHOLD = 145;
        std::string _target;

};

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i );

#endif /* ************************************************************ SHRUBERRYCREATIONFORM_HPP */