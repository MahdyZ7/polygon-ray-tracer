#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <iostream>
#include "Vector.hpp"
class Triangle {

	public:
		Vector v0;
		Vector v1;
		Vector v2;
		Vector norm;
		Vector color;

	Triangle(): v0(), v1(), v2(), norm(), color(255,255,255) {}
	Triangle(Vector v_0, Vector v_1, Vector v_2): v0(v_0), v1(v_1), v2(v_2) {}
	Triangle(Vector v_0, Vector v_1, Vector v_2, Vector n): v0(v_0), v1(v_1), v2(v_2), norm(n), color(rand() % 256, rand() % 256, rand() % 256) {}
	Triangle(Vector v_0, Vector v_1, Vector v_2, Vector n, Vector c): v0(v_0), v1(v_1), v2(v_2), norm(n), color(c) {}
	Triangle(const Triangle &other): v0(other.v0), v1(other.v1), v2(other.v2), norm(other.norm), color(other.color){}
	~Triangle() {}

	Triangle	operator=(const Triangle &other);
	bool		operator==(const Triangle &v) const;
};

std::ostream& operator<<(std::ostream& os, const Triangle &other);

#endif