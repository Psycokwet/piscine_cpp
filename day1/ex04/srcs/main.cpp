# include <iostream>
# include <fstream>
# include <string>

void my_replace(std::string line, std::string to_replace, std::string newToken)
{
	std::string tmp = line;
	int index = tmp.find(to_replace);
	while(index > 0)
	{

		index = tmp.find(to_replace);
	}
}

int main(int ac, char **av)
{
	if(ac != 4)
	{
		std::cout << "error, incorrect number of args" << std::endl;
		return 0;
	}
	std::string filename = av[1];
	std::ifstream	ifs(filename.c_str());
	if (!ifs.is_open())
	{
		std::cout << "File innaccessible or non existing" << std::endl;
		return 0;
	}
	filename = filename + ".replace";
	std::ofstream	ofs(filename.c_str());
	if (!ofs.is_open())
	{
		std::cout << "File innaccessible" << std::endl;
		return 0;
	}
	std::string tmp;
	while (std::getline(ifs, tmp))
	{
		ofs << tmp << std::endl;
	}
	return 0;
}
