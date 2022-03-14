#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <string>

# define NOT_FOUND -1
template <typename T>
int easyfind(T container, int target)
{
	int i = 0;
	std::list<int>::iterator it;
	for (it = container.begin(); it != container.end(); ++it, i++){
		if (*it == target)
			return i;
	}
	return NOT_FOUND;
}



#endif /* **************************************************** EASYFIND_HPP */