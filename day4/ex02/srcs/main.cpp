#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

# define ANIMALS_QUANTITY 4
int main()
{
	// const AAnimal a = new AAnimal();
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	delete j;//should not create a leak
	delete i;

	AAnimal	*animals[ANIMALS_QUANTITY];
	int counter = 0;
	while ( counter < (ANIMALS_QUANTITY / 2))
	{
		animals[counter] = new Cat();
		counter++;
	}
	while ( counter < (ANIMALS_QUANTITY))
	{
		animals[counter] = new Dog();
		counter++;
	}
	std::cout << "-----DEEP COPY CAT------ "  <<std::endl;
	counter = 0;
	Cat base;
	base.getBrain()->addIdea("Ah que cc bob");
	std::cout << "making a deep copy of " << base <<std::endl;
	Cat deep(base);
	std::cout <<std::endl << "original " << base << "result "  << deep <<std::endl;
	std::cout << "-----DEEP COPY DOG------ "  <<std::endl;
	counter = 0;
	Dog based;
	based.getBrain()->addIdea("Ah que cc bobDog");
	std::cout << "making a deep copy of " << based <<std::endl;
	Dog deepd = based;
	std::cout <<std::endl << "original " << based << "result "  << deepd <<std::endl;
	std::cout <<std::endl<< "-----NOW DELETING------ "  <<std::endl;
	while ( counter < (ANIMALS_QUANTITY))
	{
		delete animals[counter];
		counter++;
	}

	return 0;
}