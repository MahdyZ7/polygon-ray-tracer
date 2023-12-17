#include "Fixed.hpp"

Fixed::Fixed(void):num(0)
{
	// std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int x)
{	
	// std::cout << "Int constructor called\n";
	num = x << frac;
	if (x < 0)
		num = num | 0x80000000;
	else
		num =  num & 0x7fffffff;
}

Fixed::Fixed(const float x)
{
	num = 0;
	num = num | ((int) roundf(x * (1 << frac)));
	// std::cout << "Float constructor called\n";
}

Fixed::Fixed(Fixed const &src)
{
	// std::cout << "Copy constructor called\n";
	*this = src;
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called\n";
}

Fixed &Fixed::operator=(Fixed const &cpy)
{
	// std::cout << "Copy assignment operator called\n";
	this->num = cpy.num;
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return(num);
}

void Fixed::setRawBits(int const raw)
{
	num = raw;
}

float Fixed::toFloat(void) const
{
	return(float (num) / float (1 << frac));
}

int Fixed::toInt(void) const
{
	return((num >> frac) + ((num & ((2 << frac) - 1)) && (num < 0)));
}

std::ostream& operator<<(std::ostream &os, Fixed const &n)
{
	os << n.toFloat();
	return (os);
}

//***********************************
//		compare operators			*
//***********************************

bool Fixed::operator>(Fixed const &cpy)  const
{
	if (this->num > cpy.num)
		return (true);
	return(false);
}

bool Fixed::operator>=(Fixed const &cpy)  const
{
	if (this->num >= cpy.num)
		return (true);
	return(false);
}

bool Fixed::operator<(Fixed const &cpy)  const
{
	if (this->num < cpy.num)
		return (true);
	return(false);
}

bool Fixed::operator<=(Fixed const &cpy)  const
{
	if (this->num <= cpy.num)
		return (true);
	return(false);
}

bool Fixed::operator==(Fixed const &cpy)  const
{
	if (this->num == cpy.num)
		return (true);
	return(false);
}

bool Fixed::operator!=(Fixed const &cpy)  const
{
	if (this->num != cpy.num)
		return (true);
	return(false);
}

//***********************************
//				operators			*
//***********************************

Fixed &Fixed::operator++() //prefix
{
	++num;
	return (*this);
}

Fixed Fixed::operator++(int) //postfix
{
	Fixed temp;
	temp.num = num++;
	return (temp);
}

Fixed &Fixed::operator--() //prefix
{
	--num;
	return (*this);
}

Fixed Fixed::operator--(int) //postfix
{
	Fixed temp;
	temp.num = num--;
	return (temp);
}

Fixed Fixed::operator+(Fixed const &alu) const
{
	Fixed temp;
	temp.num = this->num + alu.num;
	return (temp);
}

Fixed Fixed::operator-(Fixed const &alu) const
{
	Fixed temp;
	temp.num = this->num - alu.num;
	return (temp);
}

Fixed Fixed::operator*(Fixed const &alu) const
{
	Fixed temp;
	long prod = long (this->num) * long (alu.num);
	temp.num = prod >> frac;
	return (temp);
}

Fixed Fixed::operator/(Fixed const &alu) const
{
	Fixed temp;
	temp.num = long (this->num) * (1 << 24) / (long (alu.num) * (1 << 16));
	return (temp);
}

// non memeber functions

Fixed	Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed	Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return (a);
	return(b);
}