#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{

	public:

		Intern();
		Intern( Intern const & src );
		~Intern();

		Intern &		operator=( Intern const & rhs );
		AForm *makeForm(const std::string & formName, const std::string & target) const;

	private:
		AForm *newFormShruberry(const std::string & target) const;
		AForm *newFormRobotomy(const std::string & target) const;
		AForm *newFormPresidential(const std::string & target) const;
};

std::ostream &			operator<<( std::ostream & o, Intern const & i );

#endif /* ********************************************************** INTERN_H */