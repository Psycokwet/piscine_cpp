#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{

	public:
		Animal();
		Animal(std::string type);
		Animal( Animal const & src );
		~Animal();

		Animal &		operator=( Animal const & rhs );
		virtual void makeSound();
	private:
		std::string _type;
		std::string getType() const
};

std::ostream &			operator<<( std::ostream & o, Animal const & i );

#endif /* ******************************************************** ANIMAL_HPP */