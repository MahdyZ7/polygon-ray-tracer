// #include "raytracing.hpp"

// int	vec_to_color(Vector vec)
// {
// 	int	color;

// 	color = 0;
// 	if (vec.x >= 255)
// 		color += 255 << 16;
// 	else
// 		color += (int)(vec.x) << 16 ;
// 	if (vec.y >= 255)
// 		color += 255 << 8;
// 	else
// 		color += (int)(vec.y) << 8;
// 	if (vec.z >= 255)
// 		color += 255;
// 	else
// 		color += (int)(vec.z);
// 	return (color);
// }

// float	compute_color(Vector *dir, Triangle *tri, Data *data, float close_t)
// {
// 	float	i;
// 	Vector	normal;
// 	Vector	hit_point;
// 	Vector	light_vec;

// 	i = 0;
// 	hit_point = vec_scalar_mult(dir, close_t);
// 	hit_point = vec_add(&(data->camera.view_point), &hit_point);
// 	normal = vec_sub(&hit_point, &(tri->center));
// 	light_vec = vec_sub(&(data->light.pos), &hit_point);
// 	i += data->amb_light.ratio;
// 	if (vec_dot(&normal, &light_vec) > 0)
// 		i += data->light.brightness * vec_dot(&normal, &light_vec)
// 			/ (vector_magnitude(&normal) * vector_magnitude(&light_vec));
// 	return (i);
// }

// Vector	compute_color_to_vec(
// 			Vector *dir, Triangle *tri, Data *data, float close_t)
// {
// 	Vector	i;
// 	Vector	normal;
// 	Vector	hit_point;
// 	Vector	light_vec;

// 	fill_single_vector(&i, 0, 0, 0);
// 	hit_point = vec_scalar_mult(dir, close_t);
// 	hit_point = vec_add(&(data->camera.view_point), &hit_point);
// 	normal = vec_sub(&hit_point, &(tri->center));
// 	light_vec = vec_sub(&(data->light.pos), &hit_point);
// 	vec_scalar_add(&i, data->amb_light.ratio);
// 	i.x += data->amb_light.ratio * data->amb_light.color.x;
// 	i.y += data->amb_light.ratio * data->amb_light.color.y;
// 	i.z += data->amb_light.ratio * data->amb_light.color.z;
// 	if (hit_other_object(hit_point, light_vec, data))
// 		return (i);
// 	if (vec_dot(&normal, &light_vec) > 0)
// 		i = add_sphere_spot_light(data, &normal, &light_vec, &i);
// 	return (i);
// }

// Vector	add_sphere_spot_light(
// 	Data *data, Vector *normal, Vector *light_vec, Vector *i)
// {
// 	i->x += data->light.brightness * data->light.color.x
// 		* vec_dot(normal, light_vec) / (vector_magnitude(normal)
// 			* vector_magnitude(light_vec));
// 	i->y += data->light.brightness * data->light.color.y
// 		* vec_dot(normal, light_vec) / (vector_magnitude(normal)
// 			* vector_magnitude(light_vec));
// 	i->z += data->light.brightness * data->light.color.z
// 		* vec_dot(normal, light_vec) / (vector_magnitude(normal)
// 			* vector_magnitude(light_vec));
// 	return (*i);
// }
