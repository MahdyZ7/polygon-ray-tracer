#include "raytracing.hpp"

bool hit_other_object(Vector hit_point, Vector light_vec, Data &data)
{
	Fixed		temp_t;
	int			i;

	for (std::vector<Triangle>::iterator it = data.triangles.begin();
		it != data.triangles.end(); ++it)
	{
		temp_t = intersect_RayTriangle(data.cam.pos, light_vec, *it, hit_point);
		if (temp_t > Fixed(0.001f) && temp_t < Fixed(1.0f))
			return (1);
	}
	return (0);
}