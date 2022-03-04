# include <iostream>
# include <fstream>
# include <string>

std::string my_replace(std::string line, std::string to_replace, std::string newToken)
{
	std::string tmp = line;
	std::string newLine = "";
	unsigned long index = tmp.find(to_replace);
	while(index !=std::string::npos)
	{
		newLine = newLine + tmp.substr(0, index) + newToken;
		tmp = tmp.substr(index + to_replace.length(), tmp.length() - index);
		index = tmp.find(to_replace);
	}
	return newLine + tmp;
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
		ofs << my_replace(tmp, av[2], av[3]) << std::endl;
	}
	return 0;
}
