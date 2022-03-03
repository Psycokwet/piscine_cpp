#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include "Contact.hpp"
# define MAX_CONTACTS 8

class PhoneBook
{

	public:

		PhoneBook();
		PhoneBook( PhoneBook const & src );
		~PhoneBook();

		PhoneBook &		operator=( PhoneBook const & rhs );
		void			start();

	private:
		void			add();
		void			search() const; 
		void			exit();
		void			printContacts(void (Contact::*fun)(int) const) const;
		void			printContactsFull() const;
		void			printContactsLight() const;
		bool do_exit;
		Contact contacts[MAX_CONTACTS];
		int index;
};

std::ostream &			operator<<( std::ostream & o, PhoneBook const & i );

#endif /* ******************************************************* PHONEBOOK_H */
