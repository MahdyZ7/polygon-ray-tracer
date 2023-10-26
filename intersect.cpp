#include "raytracing.hpp"

float intersect_RayTriangle(Vector &origin, Vector &dir, Triangle &T, Vector &I)
{
	Vector    u, v, n;             // triangle vectors
	Vector    ray, w0, w;          // ray vectors
	float     r, a, b;             // params to calc ray-plane intersect

	// get triangle edge vectors and plane normal
	u = T.v1 - T.v0;
	v = T.v2 - T.v0;
	n = Vector::cross(u, v);             // cross product
	if (n.length() == 0)           // triangle is degenerate
		return INFINITY;                 // do not deal with this case

	w0 = origin - T.v0;
	a = -Vector::dot(n,w0);
	b = Vector::dot(n,dir);
	if (fabs(b) < SMALL_NUM) {     // ray is parallel to triangle plane
		if (a == 0)                // ray lies in triangle plane
			return 0;
		else return INFINITY;             // ray disjoint from plane
	}
	// get intersect point of ray with triangle plane
	r = a / b;
	if (r < 0.0)                   // ray goes away from triangle
		return INFINITY;                  // => no intersect

	I = origin + dir * r;           // intersect point of ray and plane

	// is I inside T?
	float    uu, uv, vv, wu, wv, D;
	uu = Vector::dot(u,u);
	uv = Vector::dot(u,v);
	vv = Vector::dot(v,v);
	w = I - T.v0;
	wu = Vector::dot(w,u);
	wv = Vector::dot(w,v);
	D = uv * uv - uu * vv;

	// get and test parametric coords
	float s, t;
	s = (uv * wv - vv * wu) / D;
	if (s < 0.0 || s > 1.0)        // I is outside T
		return INFINITY;
	t = (uv * wu - uu * wv) / D;
	if (t < 0.0 || (s + t) > 1.0)  // I is outside T
		return INFINITY;

	return r;                      // I is in T
}

Triangle	*find_closest_tri(
		Data &data, Vector &dir, Vector &hit_point)
{
	float		temp_t;
	Triangle	*closest_tri;
	float		closest_r;

	closest_tri = NULL;
	closest_r = INFINITY;
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
	Vector		color(0,255,0);
	Vector		hit_pos;
	Triangle	*closest_tri = NULL;
	Vector		result;
	Vector		m;

	closest_tri = find_closest_tri(data, dir, hit_pos);
	if (closest_tri != NULL)
	{
		// m = compute_color_to_vec(dir, closest_tri, data, closest_r);
		// color = vec_to_color(
		// 		vec_multiply_two_vectors(&(closest_tri->color), &m));
		std::srand(std::time(0));
		color = Vector(127,0,255);
	}
	return (color);
}