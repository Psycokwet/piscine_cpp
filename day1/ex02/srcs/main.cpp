# include <iostream>
# include <string>

int		main()
{
	std::string str= "HI THIS IS BRAIN";

	std::string *stringPTR = &str;
	std::string &stringREF = str;
	std::cout << "adresse de str:" << &str << ", adresse de stringPTR:" << &stringPTR << ", adresse de stringREF:" << &stringREF << std::endl;
	std::cout << "valeur de str:" << str << ", valeur de *stringPTR:" << *stringPTR << ", valeur de stringREF:" << stringREF << std::endl;
	return 0;
}
