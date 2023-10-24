#include <cmath>
#include <iostream>
class Vector {

	public:
		float x;
		float y;
		float z;

	Vector(float x, float y, float z): x(x), y(y), z(z) {}
	Vector(float x, float y): x(x), y(y), z(0) {}
	Vector(float x): x(x), y(0), z(0) {}
	Vector(): x(0), y(0), z(0) {}
	Vector(const Vector &other): x(other.x), y(other.y), z(other.z){}
	~Vector() {}

	Vector	operator=(const Vector &other);
	Vector	operator+(Vector v);
	Vector	operator-(Vector v);
	Vector	operator*(float s);
	Vector	operator/(float s);
	bool	operator==(Vector v);
	float length();
	Vector normalize();
	float dot(Vector v);
	Vector cross(Vector v);
	static float dot(Vector v, Vector w);
	static Vector cross(Vector v, Vector w);
	float length2();
	Vector normalize2();
};

std::ostream& operator<<(std::ostream& os, const Vector &other);