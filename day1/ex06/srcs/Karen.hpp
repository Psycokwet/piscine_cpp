#ifndef KAREN_HPP
# define KAREN_HPP

# include <iostream>
# include <string>

#define DEBUG	"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !"
#define INFO	"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !"
#define WARNING	"I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
#define ERROR	"This is unacceptable ! I want to speak to the manager now."

class Karen
{

	public:

		Karen( Karen const & src );
		Karen();
		~Karen();

		Karen &		operator=( Karen const & rhs );
		void complain( std::string level );

	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
};

std::ostream &			operator<<( std::ostream & o, Karen const & i );

#endif /* ********************************************************** KAREN_H */
