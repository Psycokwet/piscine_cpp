#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template <typename T>
void iter(T *array, int size, void(fun)(const T&))
{
	for(int i = 0; i < size ; i++)
		fun(array[i]);
}



#endif /* **************************************************** ITER_HPP */