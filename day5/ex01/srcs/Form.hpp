#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

	public:
		Form();
		Form( Form const & src );
		Form(int required_grade_sign, int required_grade_exe, std::string name);
		virtual ~Form();

		Form &		operator=( Form const & rhs );
		void beSigned(Bureaucrat &b);
		bool isSigned() const;
		std::string getName() const;
		int getGradeExe(void) const;
		int getGradeSign(void) const;

        class GradeTooLowException : public std::exception
        {
            public:
                GradeTooLowException(void) {}
                virtual const char *what() const throw()
                {
                    return "GradeTooLowException";
                }
        };
        class GradeTooHighException : public std::exception
        {
            public:
                GradeTooHighException(void) {}
                virtual const char *what() const throw()
                {
                    return "GradeTooHighException";
                }
        };

	private:
		void testGrade(int grade);
		std::string const _name;
		bool _is_signed;
		int const _required_grade_sign;
		int const _required_grade_exe;

};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */