#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <iostream>
#include "Vector.hpp"
class Triangle {

	public:
		Vector v0;
		Vector v1;
		Vector v2;

	Triangle(Vector v_0, Vector v_1, Vector v_2): v0(v_0), v1(v_1), v2(v_2) {}
	Triangle(): v0(), v1(), v2() {}
	Triangle(const Triangle &other): v0(other.v0), v1(other.v1), v2(other.v2){}
	~Triangle() {}

	Triangle	operator=(const Triangle &other);
	bool		operator==(const Triangle &v) const;
};

std::ostream& operator<<(std::ostream& os, const Triangle &other);

#endif