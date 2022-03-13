/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:47:28 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/05 16:14:10 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter(std::string const base):_base(base), _type(notConverted)
{
	for (int i = eChar; i < illegal; i++)
		this->_isOk[i] = true;
	this->parse();
	if (this->_type != illegal)
		this->convert();
	else
		for (int i = eChar; i < illegal; i++)
			this->_isOk[i] = false;
}

Converter::Converter(Converter const &other):
	_base(other._base), _type(other._type),
	_ivalue(other._ivalue), _fvalue(other._fvalue),
	_dvalue(other._dvalue), _cvalue(other._cvalue)
{
	for (int i = eChar; i < illegal; i++)
		this->_isOk[i] = other._isOk[i];
}

Converter::~Converter()
{
}

void Converter::parse(void)
{
	std::stringstream ss;
	size_t len = this->_base.length();
	size_t i = 0;

	if (len == 1 && !std::isdigit(this->_base[0]))
	{
		this->_type = eChar;
		this->_cvalue = this->_base[0];
		return ;
	}
	while (this->_base[i] == '+' || this->_base[i] == '-')
		ss << _base[i++];
	this->_type = eInt;
	for (; i < len && (std::isdigit(this->_base[i]) || this->_base[i] == '.' ); i++)
	{
		if (this->_base[i] == '.' && this->_type != eDouble)
			this->_type = eDouble;
		else if(this->_base[i] == '.')
		{
			this->_type = illegal;
			break;
		}
		ss << _base[i];
	}
	if (this->_base[i] == 'f' && i == len - 1 && this->_type == eDouble)
	{
		this->_type = eFloat;
		ss >> this->_fvalue;
		return ;
	}
	else if(i != len)
		this->_type = illegal;

	if (this->_type == eDouble)
	{
		ss >> this->_dvalue;
		return ;
	}
	if (this->_type == eInt)
	{
		long lvalue;
		ss >> lvalue;
		this->_ivalue = lvalue;
		if (ss.fail()
			|| lvalue > std::numeric_limits<int>::max()
			|| lvalue < std::numeric_limits<int>::min())
			this->_type = illegal;
		return ;
	}
	if (this->_type == illegal && (this->_base == "inff" || this->_base == "-inff" || this->_base == "+inff"
			|| this->_base == "nanf" || this->_base == "inf" ||  this->_base == "-inf" || this->_base == "+inf"
			|| this->_base == "nan"))
	{
		this->_fvalue = atof(this->_base.c_str());
		this->_type = eFloat;
		this->_isOk[eInt] = false;
		return ;
	}
}

void Converter::convert(void)
{	
	switch (this->_type)
	{
		case eChar:
			this->_ivalue = static_cast<int>(this->_cvalue);
			// fall through
		case eInt:
			this->_fvalue = static_cast<float>(this->_ivalue);
			this->_dvalue = static_cast<double>(this->_ivalue);
			this->_cvalue = static_cast<char>(this->_ivalue);
			break;
		case eFloat:
			this->_dvalue = static_cast<double>(this->_fvalue);
			// fall through
		case eDouble:
			this->_ivalue = static_cast<int>(this->_dvalue);
			this->_fvalue = static_cast<float>(this->_dvalue);
			this->_cvalue = static_cast<char>(this->_dvalue);
			break;
	}
	if (!this->_isOk[eInt] || this->_ivalue != this->_cvalue)
		this->_isOk[eChar] = false;
}

Converter &Converter::operator=(Converter const &other)
{
	(void)other;
	return (*this);
}

Converter::operator	char( void ) const
{
	return (this->_cvalue);
}

Converter::operator	int( void ) const
{
	return (this->_ivalue);
}

Converter::operator	float( void ) const
{
	return (this->_fvalue);
}

Converter::operator	double( void ) const
{
	return (this->_dvalue);
}

void Converter::print(std::ostream &out) const
{	
	std::stringstream ss;
	std::string tmp;
	ss << "char: ";
	if (!this->_isOk[eChar])
		ss << "impossible" ;
	else
	{
		char c = static_cast<char>(*this);
		if(isprint(c))
			ss << "'" << c << "'";
		else
			ss << "Non displayable";
	}
	ss << std::endl << "int: ";
	if (!this->_isOk[eInt])
		ss << "impossible";
	else
		ss << static_cast<int>(*this);
	
	ss << std::endl << "float: ";
	if (!this->_isOk[eFloat])
		ss << "impossible";
	else
	{
		ss << static_cast<float>(*this);
		if(this->_ivalue == this->_fvalue)
			ss << ".0";
		ss << "f";
	}
	ss << std::endl << "double: ";
	if (!this->_isOk[eDouble])
		ss << "impossible";
	else
	{
		ss << static_cast<double>(*this);
		if(this->_ivalue == this->_dvalue)
			ss << ".0";
	}
	out << ss.str() << std::endl;
}

std::ostream &operator<<(std::ostream &out, Converter const &pr)
{
	pr.print(out);
	return (out);
}
