#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : virtual public AAnimal
{
	public:
		Cat();
		Cat( Cat const & src );
		virtual ~Cat();

		Cat &		operator=( Cat const & rhs );
		virtual void makeSound() const;
		Brain *getBrain() const;
	private:
		Brain *_brain;
};

std::ostream &			operator<<( std::ostream & o, Cat const & i );

#endif /* ******************************************************** CAT_HPP */