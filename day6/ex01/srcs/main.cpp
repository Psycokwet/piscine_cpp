#include <iostream>
#include <stdint.h>

struct Data
{
	std::string		sValue;
	int				iValue;
};

uintptr_t serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

int main()
{
	Data d;
	d.iValue = 42;
	d.sValue = "I wanna be serialized !";
	uintptr_t serialized = serialize(&d);
	Data *d2 = deserialize(serialized);
	std::cout << serialized << std::endl;
	std::cout << d.iValue << ":" << d2->iValue << std::endl;
	std::cout << d.sValue << ":" << d2->sValue << std::endl;
	std::cout << &d << ":" << d2 << std::endl;
	return 0;
}