#include "PhoneBook.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PhoneBook::PhoneBook()
{
	this->index = 0;
	this->do_exit = false;
}

PhoneBook::PhoneBook( const PhoneBook & src )
{
	(void)src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PhoneBook::~PhoneBook()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PhoneBook &				PhoneBook::operator=( PhoneBook const & rhs )
{
	(void)rhs;
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, PhoneBook const & i )
{
	(void)o;
	(void)i;
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void			PhoneBook::add()
{
	if (this->index == MAX_CONTACTS)
		this->index = 0;
	this->contacts[this->index++] = Contact::buildContact();
	std::cout << "Contact added." << std::endl;
}

void			PhoneBook::exit()
{
	this->do_exit = true;
}

void			PhoneBook::printContactsFull() const
{
	Contact::printTitlesFull();
	PhoneBook::printContacts(&Contact::printFieldsFull);
}
void			PhoneBook::printContactsLight() const
{
	Contact::printTitlesLight();
	PhoneBook::printContacts(&Contact::printFieldsLight);
}

void			PhoneBook::printContacts(void (Contact::*fun)(int) const) const
{
	int i = 0;
	while (i < MAX_CONTACTS)
	{
		(this->contacts[i].*fun)(i);
		i++;
	}
}

void			PhoneBook::search() const
{
	std::string buff;
	this->printContactsLight();
	std::cout << "Choose index of phone book to read" << std::endl;
	if(!std::getline(std::cin, buff))
		return;
	const char *tmp = buff.c_str();
	int i = atoi(tmp);
	if (i != tmp[0] - '0' || i < 0 || i >= MAX_CONTACTS || i >= Contact::getNbInstance())
	{
		std::cout << "Bad selection " << buff << std::endl;
		return;
	}
	this->contacts[i].printFieldsFullLine(i);
}

void			PhoneBook::start()
{
	std::string buff;
	std::cout << "Wait for command ADD|EXIT|SEARCH " << std::endl;
	while (!this->do_exit && std::getline(std::cin, buff))
	{
		if (buff == "ADD")
			this->add();
		else if (buff== "EXIT")
			this->exit();
		else if (buff== "SEARCH")
			this->search();
	}
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */

int		main()
{
	PhoneBook pb;
	pb.start();
	return 0;
}
