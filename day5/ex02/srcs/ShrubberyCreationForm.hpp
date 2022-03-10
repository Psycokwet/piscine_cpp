#ifndef SHRUBERRYCREATIONFORM_HPP
# define SHRUBERRYCREATIONFORM_HPP

# include <iostream>
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
		virtual void beSigned(Bureaucrat &b);
		std::string getTarget() const;

	private:
        std::string _target;

};

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i );

#endif /* ************************************************************ SHRUBERRYCREATIONFORM_HPP */