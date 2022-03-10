#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm( AForm const & src );
		AForm(int required_grade_sign, int required_grade_exe, std::string name);
		virtual ~AForm();

		AForm &		operator=( AForm const & rhs );
		virtual void beSigned(Bureaucrat &b) = 0;
		bool isSigned() const;
		std::string getName() const;
		int getGradeExe(void) const;
		int getGradeSign(void) const;
		virtual void execute(Bureaucrat const & executor) const = 0;

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
        class FormNotSignedYet : public std::exception
        {
            public:
                FormNotSignedYet(void) {}
                virtual const char *what() const throw()
                {
                    return "FormNotSignedYet";
                }
        };
	private:
		void testGrade(int grade);
		std::string const _name;
		bool _is_signed;
		int const _required_grade_sign;
		int const _required_grade_exe;
	protected:
		void canFormBeExecuted(Bureaucrat const & executor) const;


};

std::ostream &			operator<<( std::ostream & o, AForm const & i );

#endif /* ************************************************************ AFORM_H */