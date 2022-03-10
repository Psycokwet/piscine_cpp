#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal( WrongAnimal const & src );
		virtual ~WrongAnimal();

		WrongAnimal &		operator=( WrongAnimal const & rhs );
		void makeSound() const;
		std::string getType() const;
	protected:
		std::string _type;
		WrongAnimal(std::string type);
};

std::ostream &			operator<<( std::ostream & o, WrongAnimal const & i );

#endif /* ******************************************************** ANIMAL_HPP */