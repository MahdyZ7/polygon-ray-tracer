#include "raytracing.hpp"

Vector	vec_to_color(Vector vec, Vector &mul)
{
	Vector	color;

	if (mul.x > 1)
		mul.x = 1;
	if (mul.y > 1)
		mul.y = 1;
	if (mul.z > 1)
		mul.z = 1;
	color = Vector(vec.x * mul.x, vec.y * mul.y, vec.z * mul.z);
	return (color);
}

void	add_spot_light(
	Data &data, Vector &normal, Vector &light_vec, Vector &i)
{
	i.x += data.spotlight.brightness * (data.spotlight.color.x).toFloat()
		* Vector::dot(normal, light_vec) / (normal.length()
			* light_vec.length());
	i.y += data.spotlight.brightness * (data.spotlight.color.y).toFloat()
		* Vector::dot(normal, light_vec) / (normal.length()
			* light_vec.length());
	i.z += data.spotlight.brightness * (data.spotlight.color.z).toFloat()
		* Vector::dot(normal, light_vec) / (normal.length()
			* light_vec.length());
}

Vector	compute_color_to_vec(
			Vector &dir, Triangle *tri, Data &data, Vector hit_point)
{
	Vector	i;
	Vector	light_vec;

	light_vec = data.spotlight.pos -  hit_point;
	i =  data.amblight.color * data.amblight.brightness;
	if (hit_other_object(hit_point, light_vec, data))
		return (i);
	if (Vector::dot(tri->norm, light_vec) > 0)
		add_spot_light(data, tri->norm, light_vec, i);
	return (i);
}

