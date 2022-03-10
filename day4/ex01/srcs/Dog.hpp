#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : virtual public Animal
{
	public:
		Dog();
		Dog( Dog const & src );
		virtual ~Dog();

		Dog &		operator=( Dog const & rhs );
		virtual void makeSound() const;
		Brain *getBrain() const;
	private:
		Brain *_brain;
};

std::ostream &			operator<<( std::ostream & o, Dog const & i );

#endif /* ******************************************************** DOG_HPP */