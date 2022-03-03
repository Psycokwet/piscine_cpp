#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <stdlib.h>
# define MAX_FIELDS 5

class Contact
{

	public:

		~Contact();
		Contact( Contact const & src );
		Contact();

		Contact &		operator=( Contact const & rhs );
		
		void printFieldsLight( int id ) const;
		void printFieldsFull( int id ) const;
		void printFieldsFullLine( int id ) const;

		static Contact buildContact();
		static void printTitlesFull(void);
		static void printTitlesLight(void);
		static int getNbInstance();

	private:
		static void _printColumnContent(std::string value);
		Contact(std::string _fields[MAX_FIELDS]);
		static void _printTitles( int maxTitle );

		static int _nb_instances;
		void _printField(std::string field) const;
		std::string _fields[MAX_FIELDS];
		void _printFields( int maxField, int id ) const;
};





std::ostream &			operator<<( std::ostream & o, Contact const & i );

#endif /* ********************************************************* CONTACT_H */
