#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

template <typename T>
class Array
{
	public:
		Array<T>(unsigned int size = 0):_size(size), _array(new T[size]())
		{}
		Array<T>( Array<T> const & src ):_size(src._size), _array(new T[size]())
		{
			for(unsigned int i; i< src._size; i++)
				this->_array[i] = src._array[i];
		}
		~Array<T>()
		{
			if (this->_array != NULL)
				delete [] this->_array;
		}

		Array<T> &		operator=( Array<T> const & rhs )
		{
			if (this == &rhs)
				return *this;
			this->_size = rhs._size;
			if (this->_array != NULL)
				delete [] this->_array;
			this->_array = new T[size]();
			for(unsigned int i; i < rhs._size; i++)
				*this->_array[i] = rhs._array[i];
			return *this;
		}

		T &operator[](size_t i) const
		{
			if (i < 0 || i >= this->_size)
				throw std::exception();
			return this->_array[i];
		}

		unsigned int size(void) const {return this->_size;}

	private:
		unsigned int _size;
		T *_array;

};


#endif /* *********************************************************** ARRAY_H */