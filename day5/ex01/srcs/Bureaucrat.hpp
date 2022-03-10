#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class Form;

class Bureaucrat
{

	public:
		static const int HIGHEST_GRADE = 1;
		static const int LOWEST_GRADE = 150;
		Bureaucrat(int grade, std::string name);
		Bureaucrat();
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat();

		Bureaucrat &		operator=( Bureaucrat const & rhs );
		std::string getName() const;
		int getGrade() const;
		void incGrade();
		void decGrade();
		void signForm(Form &f);
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
		std::string const _name;
		int _grade;

};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */