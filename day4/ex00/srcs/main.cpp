#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	const WrongAnimal* metaWrong = new WrongAnimal();
	const WrongAnimal* catWrong = new WrongCat();
	const WrongCat* catWrong2 = new WrongCat();

	std::cout << metaWrong->getType() << std::endl;
	metaWrong->makeSound();
	std::cout << catWrong->getType() << std::endl;
	catWrong->makeSound();
	std::cout << catWrong2->getType() << "2" << std::endl;
	catWrong2->makeSound();
	delete metaWrong;
	delete catWrong;
	delete catWrong2;
	
	return 0;
}