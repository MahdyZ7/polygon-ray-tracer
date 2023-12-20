#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
	public:
		Fixed(void);
		Fixed(const int x);
		Fixed(const float x);
		Fixed(Fixed const &src);
		~Fixed(void);

		Fixed &operator=(Fixed const &cpy);
		Fixed operator+(Fixed const &alu) const;
		Fixed operator-(Fixed const &alu) const;
		Fixed operator*(Fixed const &alu) const;
		Fixed operator/(Fixed const &alu) const;

		Fixed operator+=(Fixed const &alu);

		Fixed &operator++(); //prefix
		Fixed operator++(int); //postfix
		Fixed &operator--(); //prefix
		Fixed operator--(int); //postfix

		bool operator>(Fixed const &cpy) const;
		bool operator>=(Fixed const &cpy) const;
		bool operator<(Fixed const &cpy) const;
		bool operator<=(Fixed const &cpy) const;
		bool operator==(Fixed const &cpy) const;
		bool operator!=(Fixed const &cpy) const;

		int		getRawBits( void ) const;
		void		setRawBits( int const raw );
		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed	max(Fixed const &a, Fixed const &b);
		static Fixed	min(Fixed const &a, Fixed const &b);
		private:
			int num;
			static const int frac = 8;
};

std::ostream& operator<<(std::ostream &os, Fixed const &n);

#endif 