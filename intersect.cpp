#include "raytracing.hpp"

Fixed intersect_RayTriangle(Vector &origin, Vector &dir, Triangle &T, Vector &I)
{
	Vector    u, v, n;             // triangle vectors
	Vector    ray, w0, w;          // ray vectors
	Fixed     r, a, b;             // params to calc ray-plane intersect

	// get triangle edge vectors and plane normal
	u = T.v1 - T.v0;
	v = T.v2 - T.v0;
	n = Vector::cross(u, v);             // cross product
	if (n.length() == 0)           // triangle is degenerate
		return INF;                 // do not deal with this case

	w0 = origin - T.v0;
	a = a - Vector::dot(n,w0);
	b = Vector::dot(n,dir);
	if (b < Fixed(0.0001f) && b > Fixed(-0.0001f)) {     // ray is parallel to triangle plane
		if (a == 0)                // ray lies in triangle plane
			return 0;
		else return INF;             // ray disjoint from plane
	}
	// get intersect point of ray with triangle plane
	r = a / b;
	if (r < 0)                   // ray goes away from triangle
		return INF;                  // => no intersect

	I = origin + dir * r;           // intersect point of ray and plane

	// is I inside T?
	Fixed    uu, uv, vv, wu, wv, D;
	uu = Vector::dot(u,u);
	uv = Vector::dot(u,v);
	vv = Vector::dot(v,v);
	w = I - T.v0;
	wu = Vector::dot(w,u);
	wv = Vector::dot(w,v);
	D = uv * uv - uu * vv;

	// get and test parametric coords
	Fixed s, t;
	s = (uv * wv - vv * wu) / D;
	if (s < 0 || s > 1)        // I is outside T
		return INF;
	t = (uv * wu - uu * wv) / D;
	if (t < 0 || (s + t) > 1)  // I is outside T
		return INF;

	return r;                      // I is in T
}

Triangle	*find_closest_tri(
		Data &data, Vector &dir, Vector &hit_point)
{
	Fixed		temp_t;
	Triangle	*closest_tri;
	Fixed		closest_r;

	closest_tri = NULL;
	closest_r = INF;
	for (std::vector<Triangle>::iterator it = data.triangles.begin();
		it != data.triangles.end(); ++it)
	{
		temp_t = intersect_RayTriangle(data.cam.pos, dir, *it, hit_point);
		if (temp_t < closest_r)
		{
			closest_r = temp_t;
			closest_tri = &(*it);
		}
	}
	return (closest_tri);
}

Vector	trace_tri(Vector &dir, Data &data)
{
	Vector		color(255,255,255);
	Vector		hit_pos;
	Triangle	*closest_tri = NULL;
	Vector		result;
	Vector		mul;

	closest_tri = find_closest_tri(data, dir, hit_pos);
	if (closest_tri != NULL)
	{
		mul = compute_color_to_vec(dir, closest_tri, data, hit_pos);
		// std::cout << "color multiplier: " << mul << std::endl;
		// std::srand(std::time(0));
		// color = Vector(rand() % 256, rand() % 256, rand() % 256);
		return (vec_to_color(closest_tri->color , mul));
		// return (Vector(255,255,255));
		// color = Vector(127,0,255);
	}
	return (color);
}