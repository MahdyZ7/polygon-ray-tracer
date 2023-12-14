#include "Triangle.hpp"

Triangle Triangle::operator=(const Triangle &other)
{
	if (this != &other)
	{
		v0 = other.v0;
		v1 = other.v1;
		v2 = other.v2;
		norm = other.norm;
		color = other.color;
	}
	return *this;
}

bool Triangle::operator==(const Triangle &other) const
{
	return (v0 == other.v0 && v1 == other.v1 && v2 == other.v2);
}

std::ostream& operator<<(std::ostream& os, const Triangle &other)
{
	os << "(" << other.v0 << ", " << other.v1 << ", " << other.v2 << " norm: " << other.norm << ")";
	return os;
}