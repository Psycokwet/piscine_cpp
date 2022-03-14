#include <iostream>
#include <string>
#include "whatever.hpp"
#include "Awesome.hpp"


int main()
{
	{
		Awesome a(2), b(4);
		std::cout << a << " " << b << std::endl;
		swap (a, b);
		std::cout << a << " " << b << std::endl;
		std::cout << max(a, b) << std::endl;
		std::cout << min(a, b) << std::endl;
	}
	{
		int a = 12, b = 14;
		std::cout << a << " " << b << std::endl;
		swap (a, b);
		std::cout << a << " " << b << std::endl;
		std::cout << max(a, b) << std::endl;
		std::cout << min(a, b) << std::endl;
	}
	{
		int a = 22, b = 24;
		std::cout << a << " " << b << std::endl;
		swap<int>(a, b);
		std::cout << a << " " << b << std::endl;
		std::cout << max<int>(a, b) << std::endl;
		std::cout << min<int>(a, b) << std::endl;
	}
	{
		int a = 2;
		int b = 3;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		std::cout << "c = " << c << ", d = " << d << std::endl;
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	return 0;
}