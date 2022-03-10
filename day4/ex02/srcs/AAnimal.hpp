#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal
{
	public:
		AAnimal();
		AAnimal( AAnimal const & src );
		virtual ~AAnimal();

		AAnimal & operator=( AAnimal const & rhs );
		virtual void makeSound() const = 0;
		std::string getType() const;
	protected:
		std::string _type;
		AAnimal(std::string type);
};

std::ostream &			operator<<( std::ostream & o, AAnimal const & i );

#endif /* ******************************************************** AANIMAL_HPP */