#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <vector>

class Span
{

	public:

		Span(unsigned int N = 0);
		Span( Span const & src );
		~Span();

		Span &		operator=( Span const & rhs );

		void addNumber(int value);
		void addRange( std::vector<int>::iterator begin,
		std::vector<int>::iterator end);
		int shortestSpan();
		int longestSpan();
		void print(std::ostream & o) const;
        class NotEnoughValuesException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return "NotEnoughValuesException";
                }
        };
        class TooMuchValuesException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return "TooMuchValuesException";
                }
        };
	private:
		unsigned int _N;
		std::vector<int> _content;

};

std::ostream &			operator<<( std::ostream & o, Span const & i );

#endif /* *********************************************************** SPAN_HPP */
