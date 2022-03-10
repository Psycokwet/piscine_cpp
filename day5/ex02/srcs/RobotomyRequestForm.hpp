#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <ctime>
# include <cstdlib>
# include "AForm.hpp"


class RobotomyRequestForm : virtual public AForm
{

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm( RobotomyRequestForm const & src );
		virtual ~RobotomyRequestForm();

		RobotomyRequestForm &		operator=( RobotomyRequestForm const & rhs );
		std::string getTarget() const;
		virtual void execute(Bureaucrat const & executor) const;
	private:
		static const int _SIGN_TRESHOLD = 72;
		static const int _EXE_TRESHOLD = 45;
        std::string _target;

};

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i );

#endif /* ************************************************************ ROBOTOMYREQUESTFORM_HPP */