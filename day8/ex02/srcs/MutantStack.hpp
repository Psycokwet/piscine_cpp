#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>

class MutantStack
{

	public:
		static const int HIGHEST_GRADE = 1;
		static const int LOWEST_GRADE = 150;
		MutantStack(int grade, std::string name);
		MutantStack();
		MutantStack( MutantStack const & src );
		virtual ~MutantStack();

		MutantStack &		operator=( MutantStack const & rhs );
		std::string getName() const;
		int getGrade() const;
		void incGrade();
		void decGrade();
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

std::ostream &			operator<<( std::ostream & o, MutantStack const & i );

#endif /* ****************************************************** MUTANTSTACK_HPP */