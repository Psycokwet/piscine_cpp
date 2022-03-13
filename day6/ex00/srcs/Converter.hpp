#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <sstream>
# include <string>
# include <cctype>
# include <cmath>
# include <limits>

class Converter
{
	public:
		enum e_Type {
			eChar,
			eInt,
			eFloat,
			eDouble,
			illegal,
			notConverted
		};
		Converter(std::string const value = "");
		Converter(Converter const &other);
		virtual ~Converter();

		void print(std::ostream &out) const;

	private:
		Converter &operator=(Converter const &other);
		std::string _base;
		int _type;

		bool _isOk[illegal];
		int _ivalue;
		float _fvalue;
		double _dvalue;
		char _cvalue;

		void parse(void);
		void convert(void);

		operator char(void) const;
		operator int(void) const;
		operator float(void) const;
		operator double(void) const;
};

std::ostream &operator<<(std::ostream &out, Converter const &pr);

#endif
