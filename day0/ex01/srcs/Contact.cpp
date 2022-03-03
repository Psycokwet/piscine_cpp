#include "Contact.hpp"

static const std::string	fields_name[MAX_FIELDS] = {
	"first name",
	"last name",
	"nickname",
	"phone number",
	"darkest secret"
};

int Contact::_nb_instances = 0;

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Contact::Contact()
{
	int i = 0;
	while (i < MAX_FIELDS)
	{
		this->_fields[i] = "";
		i++;
	}
}

Contact::Contact(std::string _fields[MAX_FIELDS])
{
	int i = 0;
	while (i < MAX_FIELDS)
	{
		this->_fields[i] = _fields[i];
		i++;
	}
	Contact::_nb_instances++;
}

Contact::Contact( const Contact & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Contact::~Contact()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Contact &				Contact::operator=( Contact const & rhs )
{
	(void)rhs;
	if ( this != &rhs )
	{
		int i = 0;
		while (i < MAX_FIELDS)
		{
			this->_fields[i] = rhs._fields[i];
			i++;
		}
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Contact const & i )
{
	(void)o;
	(void)i;
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

Contact Contact::buildContact()
{
	std::string _fields[MAX_FIELDS];
	int i = 0;
	while (i < MAX_FIELDS)
	{
		std::cin.clear();
		std::cout << "Please enter your " << fields_name[i] << std::endl;
		if(!std::getline(std::cin, _fields[i]))
			_fields[i] = "";
		i++;
	}
	return Contact(_fields);
}

void Contact::_printField(std::string field) const
{
	Contact::_printColumnContent(field);
}

void Contact::_printFields( int maxField, int id ) const
{
	int i = 0;

	std::cout << std::setw(10) << id << "|";
	while (i < maxField)
	{
		this->_printField(this->_fields[i]);
		if (++i < maxField)
			std::cout << "|";
	}
	std::cout << std::endl;
}

void Contact::printFieldsLight( int id ) const
{
	this->_printFields(3, id);
}

void Contact::printFieldsFull( int id ) const
{
	this->_printFields(MAX_FIELDS, id);
}

void Contact::printFieldsFullLine( int id ) const
{
	int i = 0;
	std::cout << "id\t\t" << id << std::endl;
	while (i < MAX_FIELDS)
	{
		std::cout << fields_name[i]+"\t" << this->_fields[i] << std::endl;
		i++;
	}
}

void Contact::_printColumnContent(std::string value)
{
	if(value.length() > 10)
	{
		value.resize(9);
		value = value + ".";
	}
	std::cout << std::setw(10) << value;
}

void Contact::_printTitles( int maxTitle )
{
	int i = 0;
	Contact::_printColumnContent("id");
	while (i < maxTitle)
	{
		std::cout << "|" ;
		Contact::_printColumnContent(fields_name[i]);
		++i;
	}
	std::cout << std::endl;
}

void Contact::printTitlesLight( void )
{
	Contact::_printTitles(3);
}

void Contact::printTitlesFull( void )
{
	Contact::_printTitles(MAX_FIELDS);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int Contact::getNbInstance()
{
	return Contact::_nb_instances;
}


/* ************************************************************************** */
