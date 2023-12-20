#include "Vector.hpp"

	Vector Vector::operator=(const Vector& other)
	{
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}
	Vector Vector::operator+(Vector v) 
	{
		return Vector(x + v.x, y + v.y, z + v.z);
	}
	Vector Vector::operator-(Vector v)
	{
		return Vector(x - v.x, y - v.y, z - v.z);
	}
	Vector Vector::operator*(Fixed s)
	{
		return Vector(x * s, y * s, z * s);
	}
	Vector Vector::operator/(Fixed s)
	{
		return Vector(x / s, y / s, z / s);
	}
	bool Vector::operator==(const Vector &v) const
	{
		return (x == v.x && y == v.y && z == v.z);
	}

	Fixed Vector::length()
	{
		// Fixed  length2 = x * x + y * y + z * z;
		// return sqrtf(length2);
		return sqrtf((x * x + y * y + z * z).toFloat());
	}
	Vector Vector::normalize()
	{
		Fixed l = length();
		return Vector(x / l, y / l, z / l);
	}
	Fixed Vector::dot(Vector v)
	{
		return (x * v.x + y * v.y + z * v.z);
	}
	Vector Vector::cross(Vector v)
	{
		return Vector(y * v.z - z * v.y, z * v.x
			- x * v.z, x * v.y - y * v.x);
	}
	Fixed Vector::dot(Vector v, Vector w)
	{
		return (v.x * w.x + v.y * w.y + v.z * w.z);
	}
	Vector Vector::cross(Vector v, Vector w)
	{
		return Vector(v.y * w.z - v.z * w.y, v.z * w.x
			- v.x * w.z, v.x * w.y - v.y * w.x);
	}
	Fixed Vector::length2()
	{
		return (x * x + y * y + z * z);
	}
	Vector Vector::sNormalize(Vector v)
	{
		Fixed l = v.length();
		return Vector(v.x / l, v.y / l, v.z / l);
	}
	

std::ostream& operator<<(std::ostream& os, const Vector &other)
{
	os << "(" << other.x << ", " << other.y << ", " << other.z << ")"; 
	return os;
}